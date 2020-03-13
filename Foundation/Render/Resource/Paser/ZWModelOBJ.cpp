//////////////////////////////////////////////////////////////////////////
// Class ZWModelOBJ  - by ZwqXin (2008 - 2011) 
// http://www.zwqxin.com
// Last Update: 2011.2
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <algorithm>
#include <map>
#include "ZWModelOBJ.h"

#define MAX_LINE   255
#define VERTEX_OF_FACE     3

ZWModelOBJ::ZWModelOBJ() : m_FilePointer(NULL),
						   m_nCurObjectCount(0),
						   m_nCurMaterialCount(0)
{

}

ZWModelOBJ::~ZWModelOBJ()
{
	//�ͷ�VBO
	for(unsigned int i = 0; i < m_Model3DS.t3DObjVec.size(); i++) 
	{
		glDeleteBuffers(1, &m_Model3DS.t3DObjVec[i].nPosVBO);
		glDeleteBuffers(1, &m_Model3DS.t3DObjVec[i].nNormVBO);
		glDeleteBuffers(1, &m_Model3DS.t3DObjVec[i].nTexcoordVBO);
		glDeleteBuffers(1, &m_Model3DS.t3DObjVec[i].nIndexVBO);
	}
	m_Model3DS.t3DObjVec.clear();
	m_Model3DS.tMatInfoVec.clear();
}

void ZWModelOBJ::CleanImportedData()
{
	for(unsigned int i = 0; i < m_Model3DS.t3DObjVec.size(); i++)
	{	
		m_Model3DS.t3DObjVec[i].PosVerts.clear();
		m_Model3DS.t3DObjVec[i].Normals.clear();
		m_Model3DS.t3DObjVec[i].Texcoords.clear();
		m_Model3DS.t3DObjVec[i].Indexes.clear();
	}
}


bool ZWModelOBJ::ImportModel(wchar_t *strFileName, GLuint usage)
{
	wchar_t szPathFileName[MAX_PATH] = {0};
	if(m_szResourceDirectory)
	{
		wcscat_s(szPathFileName, sizeof(szPathFileName) / sizeof(wchar_t), m_szResourceDirectory);
	}
	wcscat_s(szPathFileName, sizeof(szPathFileName) / sizeof(wchar_t), strFileName);

	_wfopen_s(&m_FilePointer, szPathFileName, L"rb");

	// ȷ������õ��ļ�ָ��Ϸ�
	if(!m_FilePointer) 
	{
		wchar_t strMessage[MAX_NAME] = {0};
		swprintf_s(strMessage, sizeof(strMessage) / sizeof(wchar_t), L"�޷��ҵ��ļ�: %s!", szPathFileName);
		::MessageBox(NULL, strMessage, L"Error", MB_OK);
		return false;
	}

	m_nCurObjectCount   = 0;
	m_nCurMaterialCount = 0;

	// �����ļ���Ϣ
	ProcessFileInfo(&m_Model3DS);

	m_Model3DS.bIsTextured = true;

	// �رմ򿪵��ļ�
	fclose(m_FilePointer);

	m_VPositionVec.clear();
	m_VNormalVec.clear();
	m_VTexcoordVec.clear();
	m_VObjectIndexMap.clear();

	//��VBO
	for(unsigned int i = 0; i < m_Model3DS.t3DObjVec.size(); i++) 
	{
		if(!m_Model3DS.t3DObjVec[i].PosVerts.empty())
		{
			glGenBuffers(1, &m_Model3DS.t3DObjVec[i].nPosVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nPosVBO);
			glBufferData(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].PosVerts.size() * sizeof(Vector3), 
				(GLvoid*)&m_Model3DS.t3DObjVec[i].PosVerts[0], usage);
		}

		if(!m_Model3DS.t3DObjVec[i].bHasNormal)
		{
			// ���㶥��ķ�����
			ComputeNormals(&m_Model3DS.t3DObjVec[i]);

			m_Model3DS.t3DObjVec[i].bHasNormal = true;
		}

		if(!m_Model3DS.t3DObjVec[i].Normals.empty())
		{
			glGenBuffers(1, &m_Model3DS.t3DObjVec[i].nNormVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nNormVBO);
			glBufferData(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].Normals.size() * sizeof(Vector3), 
				(GLvoid*)&m_Model3DS.t3DObjVec[i].Normals[0], usage);
		}

		if(m_Model3DS.t3DObjVec[i].bHasTexture && !m_Model3DS.t3DObjVec[i].Texcoords.empty())
		{
			glGenBuffers(1, &m_Model3DS.t3DObjVec[i].nTexcoordVBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nTexcoordVBO);
			glBufferData(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].Texcoords.size() * sizeof(TexCoord), 
				(GLvoid*)&m_Model3DS.t3DObjVec[i].Texcoords[0], usage);
		}

		if(!m_Model3DS.t3DObjVec[i].Indexes.empty())
		{
			glGenBuffers(1, &m_Model3DS.t3DObjVec[i].nIndexVBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nIndexVBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].Indexes.size() * sizeof(unsigned short), 
				(GLvoid*)&m_Model3DS.t3DObjVec[i].Indexes[0], usage);

			m_Model3DS.t3DObjVec[i].nNumIndexes = m_Model3DS.t3DObjVec[i].Indexes.size();
		}
	}
	CleanImportedData();

	return true;
}

//  ����obj�ļ��еĶ���ģ����
void ZWModelOBJ::ProcessFileInfo(t3DModel *pModel)
{
	char strBuff[MAX_LINE]	= {0};
	char chKeyword          = 0;

	while(EOF != fscanf_s(m_FilePointer, "%s", strBuff, MAX_LINE))
	{
		// ���obj�ļ��еĵ�ǰ�еĵ�һ���ַ�
		chKeyword = strBuff[0];

		switch(chKeyword)
		{
		case 'm':     //�ж϶���mtllib, ָʾ���ʿ��ļ�
			{
				if(0 == strcmp(strBuff, "mtllib"))
				{
					wchar_t wszPath[MAX_PATH]  = {0};

					if(m_szResourceDirectory)
					{
						wcscpy_s(wszPath, sizeof(wszPath) / sizeof(wchar_t), m_szResourceDirectory);
					}
					size_t nCurPathLen = wcslen(wszPath);

					fscanf_s(m_FilePointer, "%s", strBuff, MAX_LINE);

					memset(&wszPath[nCurPathLen], 0, (MAX_PATH - nCurPathLen) * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, strBuff, -1, &wszPath[nCurPathLen], (MAX_PATH - nCurPathLen));

					ProcessMtlFileInfo(pModel, wszPath);
				}

				// ������������µ����ݣ����ļ�ָ�뵽��һ��
				fgets(strBuff, MAX_LINE, m_FilePointer);
			}
			break;
		case 'u':     //�ж϶���usemtl, ָʾ�µĶ���(���ܰ��������g), ָʾ����
			{
				if(0 == strcmp(strBuff, "usemtl"))
				{
					t3DObject newObject = {0};
					newObject.bHasTexture  = false;
					newObject.bHasNormal   = false;

					fscanf_s(m_FilePointer, "%s", strBuff, MAX_LINE);

					newObject.nMaterialID = FindMtlID(pModel, strBuff);

					pModel->t3DObjVec.push_back(newObject);

					++m_nCurObjectCount;

					m_VObjectIndexMap.clear();
				}

				// ������������µ����ݣ����ļ�ָ�뵽��һ��
				fgets(strBuff, MAX_LINE, m_FilePointer);
			}
			break;
		case 'v':      // �������'v' (���������ݿ����Ƕ���/������/��������)
			{
				// ��������Ϣ - ���� ("v")�������� ("vn")���������� ("vt")
				ProcessVertexInfo(strBuff[1]);
			}
			break;
		case 'f':      // �������'f'(�����Ϣ)
			{
				if(0 == m_nCurObjectCount) //����һ���޲������
				{
					t3DObject newObject = {0};
					pModel->t3DObjVec.push_back(newObject);
					++m_nCurObjectCount;
				}

				ProcessFaceInfo(pModel);
			}
			break;
		default:
			// �Թ����е�����
			fgets(strBuff, MAX_LINE, m_FilePointer);
			break;
		}
	}
}


//  ����ĺ������붥����Ϣ('v'��ָ���㣬'vt'ָUV����)
void ZWModelOBJ::ProcessVertexInfo(char chKeyword)
{
	char strBuff[MAX_LINE]	= {0};

	if('\0' == chKeyword)				// �����\0������Ƕ���("v")
	{
		Vector3  vNewVertex;

		// ���붥�����꣬��ʽ��"v x y z"
		fscanf_s(m_FilePointer, "%f %f %f", &vNewVertex.x, &vNewVertex.y, &vNewVertex.z);

		// ���һ���µĶ��㵽�����б���
		m_VPositionVec.push_back(vNewVertex);
	}
	else if('t' == chKeyword)			// �����'t'����ض�����������("vt")
	{
		TexCoord vNewTexCoord;

		// �����������꣬��ʽ��"vt u v"
		fscanf_s(m_FilePointer, "%f %f", &vNewTexCoord.u, &vNewTexCoord.v);

		// ���һ���µ��������굽�б���
		m_VTexcoordVec.push_back(vNewTexCoord);
	}
	else if('n' == chKeyword)		// ��������Ƿ�����("vn")
	{
		Vector3  vNewNormal;

		// ���뷨�ߣ���ʽ��"vn x y z"
		fscanf_s(m_FilePointer, "%f %f %f", &vNewNormal.x, &vNewNormal.y, &vNewNormal.z);

		// ���һ���µ��������굽�б���
		m_VNormalVec.push_back(vNewNormal);
	}
	
	// ����������µ����ݣ����ļ�ָ��ָ����һ��
	fgets(strBuff, MAX_LINE, m_FilePointer);
}

bool operator<(const ZWModelOBJ::tVertInfo &vertInfo1, const ZWModelOBJ::tVertInfo &vertInfo2)
{
	if(vertInfo1.vPos.x != vertInfo2.vPos.x)
	{
		return vertInfo1.vPos.x < vertInfo2.vPos.x;
	}
	else if(vertInfo1.vPos.y != vertInfo2.vPos.y)
	{
		return vertInfo1.vPos.y < vertInfo2.vPos.y;
	}
	else if(vertInfo1.vPos.z != vertInfo2.vPos.z)
	{
		return vertInfo1.vPos.z < vertInfo2.vPos.z;
	}
	else if(vertInfo1.vTexcoord.u != vertInfo2.vTexcoord.u)
	{
		return vertInfo1.vTexcoord.u < vertInfo2.vTexcoord.u;
	}
	else if(vertInfo1.vTexcoord.v != vertInfo2.vTexcoord.v)
	{
		return vertInfo1.vTexcoord.v < vertInfo2.vTexcoord.v;
	}
	if(vertInfo1.vNormal.x != vertInfo2.vNormal.x)
	{
		return vertInfo1.vNormal.x < vertInfo2.vNormal.x;
	}
	else if(vertInfo1.vNormal.y != vertInfo2.vNormal.y)
	{
		return vertInfo1.vNormal.y < vertInfo2.vNormal.y;
	}
	else
	{
		return vertInfo1.vNormal.z < vertInfo2.vNormal.z;
	}
}

//  ����ĺ�����������Ϣ
void ZWModelOBJ::ProcessFaceInfo(t3DModel *pModel)
{
	if(m_nCurObjectCount <= 0)
	{
		return;
	}

	t3DObject *pCurObj = &pModel->t3DObjVec[m_nCurObjectCount - 1];

	char strBuff[MAX_LINE]	= {0};
	unsigned int vIdx = 0, tIdx = 0, nIdx = 0;
	Vector3  vPosVert;
	TexCoord vTexcoord;
	Vector3  vNormal(0, 1, 0);
	size_t   nDistance = 0;

	fscanf_s(m_FilePointer, "%s", strBuff, MAX_LINE);

	if(strstr(strBuff, "//")) //  ��ʽv//n
	{
		if(!pCurObj->bHasNormal)
		{
			pCurObj->bHasNormal = true;
		}
		sscanf_s(strBuff, "%d//%d", &vIdx, &nIdx);

		int nCounter = 0;
		do 
		{
			++nCounter;
			if(nCounter > 3)
			{
				//Type - 123 134
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 3]);
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 2]);
				nCounter = 3;
			}

			std::map<tVertInfo, unsigned short>::iterator pFindPos 
				= m_VObjectIndexMap.find(tVertInfo(m_VPositionVec[vIdx - 1], vTexcoord, m_VNormalVec[nIdx - 1]));

			if(m_VObjectIndexMap.end() != pFindPos)
			{
				pCurObj->Indexes.push_back(pFindPos->second);
			}
			else
			{
				pCurObj->PosVerts.push_back(m_VPositionVec[vIdx - 1]);
				pCurObj->Texcoords.push_back(vTexcoord); //blank
				pCurObj->Normals.push_back(m_VNormalVec[nIdx - 1]);

				pCurObj->Indexes.push_back(pCurObj->PosVerts.size() - 1);

				m_VObjectIndexMap.insert(std::pair<tVertInfo, unsigned short>(
					tVertInfo(m_VPositionVec[vIdx - 1], vTexcoord, m_VNormalVec[nIdx - 1]), pCurObj->PosVerts.size() - 1));
			}
		} while (2 == fscanf_s(m_FilePointer, "%d//%d", &vIdx, &nIdx));
	}
	else if(3 == sscanf_s(strBuff, "%d/%d/%d", &vIdx, &tIdx, &nIdx)) //  ��ʽv/t/n
	{
		if(!pCurObj->bHasTexture)
		{
			pCurObj->bHasTexture = true;
		}
		if(!pCurObj->bHasNormal)
		{
			pCurObj->bHasNormal = true;
		}

		int nCounter = 0;
		do 
		{
			++nCounter;
			if(nCounter > 3)
			{
				//Type - 123 134
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 3]);
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 2]);
				nCounter = 3;
			}

			std::map<tVertInfo, unsigned short>::iterator pFindPos 
				= m_VObjectIndexMap.find(tVertInfo(m_VPositionVec[vIdx - 1], m_VTexcoordVec[tIdx - 1], m_VNormalVec[nIdx - 1]));

			if(m_VObjectIndexMap.end() != pFindPos)
			{
				pCurObj->Indexes.push_back(pFindPos->second);
			}
			else
			{
				pCurObj->PosVerts.push_back(m_VPositionVec[vIdx - 1]);
				pCurObj->Texcoords.push_back(m_VTexcoordVec[tIdx - 1]);
				pCurObj->Normals.push_back(m_VNormalVec[nIdx - 1]);

				pCurObj->Indexes.push_back(pCurObj->PosVerts.size() - 1);

				m_VObjectIndexMap.insert(std::pair<tVertInfo, unsigned short>(
					tVertInfo(m_VPositionVec[vIdx - 1], m_VTexcoordVec[tIdx - 1], m_VNormalVec[nIdx - 1]), 
					pCurObj->PosVerts.size() - 1));
			}
		} while (3 == fscanf_s(m_FilePointer, "%d/%d/%d", &vIdx, &tIdx, &nIdx));
	}
	else if(2 == sscanf_s(strBuff, "%d/%d", &vIdx, &tIdx)) //  ��ʽv/t
	{
		if(!pCurObj->bHasTexture)
		{
			pCurObj->bHasTexture = true;
		}

		int nCounter = 0;
		do 
		{
			++nCounter;
			if(nCounter > 3)
			{
				//Type - 123 134
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 3]);
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 2]);
				nCounter = 3;
			}

			std::map<tVertInfo, unsigned short>::iterator pFindPos 
				= m_VObjectIndexMap.find(tVertInfo(m_VPositionVec[vIdx - 1], m_VTexcoordVec[tIdx - 1], vNormal));

			if(m_VObjectIndexMap.end() != pFindPos)
			{
				pCurObj->Indexes.push_back(pFindPos->second);
			}
			else
			{
				pCurObj->PosVerts.push_back(m_VPositionVec[vIdx - 1]);
				pCurObj->Texcoords.push_back(m_VTexcoordVec[tIdx - 1]);
				pCurObj->Normals.push_back(vNormal); //UNIT_Y

				pCurObj->Indexes.push_back(pCurObj->PosVerts.size() - 1);

				m_VObjectIndexMap.insert(std::pair<tVertInfo, unsigned short>(
					tVertInfo(m_VPositionVec[vIdx - 1], m_VTexcoordVec[tIdx - 1], vNormal), pCurObj->PosVerts.size() - 1));
			}
		} while (2 == fscanf_s(m_FilePointer, "%d/%d", &vIdx, &tIdx));
	}
	else  //  ��ʽv
	{
		int nCounter = 0;
		do 
		{
			++nCounter;
			if(nCounter > 3)
			{
				//Type - 123 134
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 3]);
				pCurObj->Indexes.push_back(pCurObj->Indexes[pCurObj->Indexes.size() - 2]);
				nCounter = 3;
			}

			std::map<tVertInfo, unsigned short>::iterator pFindPos 
				= m_VObjectIndexMap.find(tVertInfo(m_VPositionVec[vIdx - 1], vTexcoord, vNormal));

			if(m_VObjectIndexMap.end() != pFindPos)
			{
				pCurObj->Indexes.push_back(nDistance);
			}
			else
			{
				pCurObj->PosVerts.push_back(m_VPositionVec[vIdx - 1]);
				pCurObj->Texcoords.push_back(vTexcoord);//BLANK
				pCurObj->Normals.push_back(vNormal); //UNIT_Y

				pCurObj->Indexes.push_back(pCurObj->PosVerts.size() - 1);

				m_VObjectIndexMap.insert(std::pair<tVertInfo, unsigned short>(
					tVertInfo(m_VPositionVec[vIdx - 1], vTexcoord, vNormal), pCurObj->PosVerts.size() - 1));
			}
		} while (1 == fscanf_s(m_FilePointer, "%d", &vIdx));
	}
}

void ZWModelOBJ::ProcessMtlFileInfo(t3DModel *pModel, wchar_t *szMtlFileName)
{
	FILE *pMTLFilePointer = NULL;
	_wfopen_s(&pMTLFilePointer, szMtlFileName, L"rb");

	if(!pMTLFilePointer)
	{
		wchar_t strMessage[MAX_NAME] = {0};
		swprintf_s(strMessage, sizeof(strMessage) / sizeof(wchar_t), L"�޷��ҵ��ļ�: %s!", szMtlFileName);
		::MessageBox(NULL, strMessage, L"Error", MB_OK);
		return;
	}

	char chKeyword             = 0;
	char strBuff[MAX_LINE]	   = {0};
	wchar_t wszPath[MAX_PATH]  = {0};      // ����·��
	size_t  nCurPathLen        = 0;

	if(m_szResourceDirectory)
	{
		wcscpy_s(wszPath, sizeof(wszPath) / sizeof(wchar_t), m_szResourceDirectory);
		nCurPathLen = wcslen(wszPath);
	}

	while(EOF != fscanf_s(pMTLFilePointer, "%s", strBuff, MAX_LINE))
	{
		chKeyword = strBuff[0];

		switch(chKeyword)
		{
		case 'n': 
			{
				if(0 == strcmp(strBuff, "newmtl"))
				{
					fscanf_s(pMTLFilePointer, "%s", strBuff, MAX_LINE);

					tMaterialInfo newMaterial = {0};
					strcpy_s(newMaterial.strName, sizeof(newMaterial.strName) / sizeof(char), strBuff);

					newMaterial.fShiness = 60.0f;
					newMaterial.crAmbient[0] = newMaterial.crAmbient[1] = newMaterial.crAmbient[2] = newMaterial.crAmbient[3] = 1.0f;
					newMaterial.crDiffuse[0] = newMaterial.crDiffuse[1] = newMaterial.crDiffuse[2] = newMaterial.crDiffuse[3] = 1.0f;

					pModel->tMatInfoVec.push_back(newMaterial);

					++m_nCurMaterialCount;
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		case 'K': 
		case 'k': 
			{
				if(m_nCurMaterialCount > 0)
				{
					GLfloat *pCol = NULL;
					chKeyword = strBuff[1];
					switch(chKeyword)
					{
					case 'a': 
						pCol = pModel->tMatInfoVec[m_nCurMaterialCount - 1].crAmbient;
						fscanf_s(pMTLFilePointer, "%f %f %f", &pCol[0], &pCol[1], &pCol[2]);
						break;
					case 'd': 
						pCol = pModel->tMatInfoVec[m_nCurMaterialCount - 1].crDiffuse;
						fscanf_s(pMTLFilePointer, "%f %f %f", &pCol[0], &pCol[1], &pCol[2]);
						break;
					case 's': 
						pCol = pModel->tMatInfoVec[m_nCurMaterialCount - 1].crSpecular;
						fscanf_s(pMTLFilePointer, "%f %f %f", &pCol[0], &pCol[1], &pCol[2]);
						break;
					default:
						break;
					}
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		case 'T':
			//if('f' == strBuff[1])
			//{
			//  fgets(strBuff, MAX_LINE, m_FilePointer);
			//	break;
			//}
			if('r' != strBuff[1])
			{
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
				break;
			}
		case 'd':
			{
				if(m_nCurMaterialCount > 0)
				{
					GLfloat fAlpha = 1.0f;
					fscanf_s(pMTLFilePointer, "%f", &fAlpha);
					pModel->tMatInfoVec[m_nCurMaterialCount - 1].crAmbient[3]  = 
					pModel->tMatInfoVec[m_nCurMaterialCount - 1].crDiffuse[3]  = 
					pModel->tMatInfoVec[m_nCurMaterialCount - 1].crSpecular[3] = fAlpha;
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		case 'N':
			{
				if(m_nCurMaterialCount > 0)
				{
					chKeyword = strBuff[1];
					switch(chKeyword)
					{
					case 's': 
						fscanf_s(pMTLFilePointer, "%f", &pModel->tMatInfoVec[m_nCurMaterialCount - 1].fShiness);
						pModel->tMatInfoVec[m_nCurMaterialCount - 1].fShiness /= 1000.0f;
						pModel->tMatInfoVec[m_nCurMaterialCount - 1].fShiness *= 128.0f;
						break;
					case 'i': 
						break;
					default:
						break;
					}
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		case 'm':
			{
				if(m_nCurMaterialCount > 0 && 'a' == strBuff[1] && 'p' == strBuff[2])
				{
					chKeyword = strBuff[5];
					if('d' == chKeyword || 's' == chKeyword)
					{
						char chEd = 0;
						bool bDecideClamp = false, bEnClamp = false;
						do 
						{
							fscanf_s(pMTLFilePointer, "%s", strBuff, MAX_LINE);
							chEd = fgetc(pMTLFilePointer);

							if(0 == strcmp(strBuff, "-clamp"))
							{
								bDecideClamp = true;
							}
							if(bDecideClamp && 0 == strcmp(strBuff, "on"))
							{
								bEnClamp = true;
							}
						} while(!strchr(strBuff, '.') && '\r' != chEd && '\n' != chEd);

						memset(&wszPath[nCurPathLen], 0, (MAX_PATH - nCurPathLen) * sizeof(wchar_t));
						MultiByteToWideChar(CP_ACP, 0, strBuff, -1, &wszPath[nCurPathLen], (MAX_PATH - nCurPathLen));

						GLuint nTex = LoadModelTexture(wszPath, bEnClamp ? GL_CLAMP_TO_EDGE : GL_REPEAT);

						if('d' == chKeyword)
						{
							pModel->tMatInfoVec[m_nCurMaterialCount - 1].nDiffuseMap = nTex;
							
							if(nTex > 0)
							{
								pModel->tMatInfoVec[m_nCurMaterialCount - 1].TexObjDiffuseMap = GL_TEXTURE0;
							}
						}
						else if('s' == chKeyword)
						{
							pModel->tMatInfoVec[m_nCurMaterialCount - 1].nSpecularMap = nTex;
						}
					}
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		case 'b':
			{
				if('u' == strBuff[1] && 'm' == strBuff[2] && 'p' == strBuff[3])
				{
					char chEd = 0;
					do 
					{
						fscanf_s(pMTLFilePointer, "%s", strBuff, MAX_LINE);
						chEd = fgetc(pMTLFilePointer);
					} while(!strchr(strBuff, '.') && '\r' != chEd && '\n' != chEd);

					int nUndefiedUserID = ZWTextureMgr::GetInstancePtr()->GenerateUnspecifiedUserID();

					memset(&wszPath[nCurPathLen], 0, (MAX_PATH - nCurPathLen) * sizeof(wchar_t));
					MultiByteToWideChar(CP_ACP, 0, strBuff, -1, &wszPath[nCurPathLen], (MAX_PATH - nCurPathLen));

					pModel->tMatInfoVec[m_nCurMaterialCount - 1].nBumpMap
						= ZWTextureMgr::GetInstancePtr()->LoadGLTexture2D(nUndefiedUserID, wszPath);
				}
				fgets(strBuff, MAX_LINE, pMTLFilePointer);
			}
			break;
		default:
			fgets(strBuff, MAX_LINE, pMTLFilePointer);
			break;
		}
	}

	fclose(pMTLFilePointer);
}

int ZWModelOBJ::FindMtlID(t3DModel *pModel, char *szMtlName)
{
	for(unsigned int j = 0; j < pModel->tMatInfoVec.size(); ++j)
	{
		if(0 == strcmp(pModel->tMatInfoVec[j].strName, szMtlName))
		{
			return j;
		}
	}
	return -1;
}

GLuint ZWModelOBJ::GetMaterialMapHandle(GLuint nMapType, char *szMaterialName)
{ 
	for(unsigned int j = 0; j < m_Model3DS.tMatInfoVec.size(); ++j)
	{
		if(0 == strcmp(m_Model3DS.tMatInfoVec[j].strName, szMaterialName))
		{
			switch(nMapType)
			{
			case MAP_DIFFUSE:
				return m_Model3DS.tMatInfoVec[j].nDiffuseMap;
			case MAP_SPECULAR:
				return m_Model3DS.tMatInfoVec[j].nSpecularMap;
			case MAP_BUMP:
				return m_Model3DS.tMatInfoVec[j].nBumpMap;
			default:
				return 0;
			}
		}
	}
	return 0; 
}
bool ZWModelOBJ::SetEnableMaterialMap(GLuint nMapType, GLuint nTextureObject)
{
	if(nTextureObject < GL_TEXTURE0 || nTextureObject > GL_TEXTURE31)
	{
		return false;
	}

	for(unsigned int j = 0; j < m_Model3DS.tMatInfoVec.size(); ++j)
	{	
		if(nTextureObject == m_Model3DS.tMatInfoVec[j].TexObjDiffuseMap  ||
		   nTextureObject == m_Model3DS.tMatInfoVec[j].TexObjSpecularMap ||
		   nTextureObject == m_Model3DS.tMatInfoVec[j].TexObjBumpMap)
		{
			return false;
		}

		switch(nMapType)
		{
		case MAP_DIFFUSE:
			if(m_Model3DS.tMatInfoVec[j].nDiffuseMap > 0)
			{
				m_Model3DS.tMatInfoVec[j].TexObjDiffuseMap = nTextureObject;
			}
			break;
		case MAP_SPECULAR:
			if(m_Model3DS.tMatInfoVec[j].nSpecularMap > 0)
			{
				m_Model3DS.tMatInfoVec[j].TexObjSpecularMap = nTextureObject;
			}
			break;
		case MAP_BUMP:
			if(m_Model3DS.tMatInfoVec[j].nBumpMap > 0)
			{
				m_Model3DS.tMatInfoVec[j].TexObjBumpMap = nTextureObject;
			}
			break;
		default:
			return false;
		}
	}
	return true;
}

// ����ĺ������ڼ������Ķ��㷨����, ����ķ�������Ҫ�����������
void ZWModelOBJ::ComputeNormals(t3DObject *t3DObj)
{
	Vector3 vVector1, vVector2, vPoly[3];

	// ������Ҫ�Ĵ洢�ռ�
	Vector3 *pTempNormals  = new Vector3 [t3DObj->Indexes.size() / VERTEX_OF_FACE];
	memset(pTempNormals,     0, t3DObj->Indexes.size() * sizeof(Vector3) / VERTEX_OF_FACE);

	// ���������������
	for(unsigned int j = 0; j < t3DObj->Indexes.size(); j += VERTEX_OF_FACE)
	{                        
		vPoly[0] = t3DObj->PosVerts[t3DObj->Indexes[j]];
		vPoly[1] = t3DObj->PosVerts[t3DObj->Indexes[j + 1]];
		vPoly[2] = t3DObj->PosVerts[t3DObj->Indexes[j + 2]];

		// ������ķ�����

		vVector1 = (vPoly[0] - vPoly[2]);    // ��ö���ε�ʸ��
		vVector2 = (vPoly[2] - vPoly[1]);    // ��ö���εĵڶ���ʸ��
		pTempNormals[j / VERTEX_OF_FACE] = vVector1.CrossProd(vVector2);  // ������ķǹ淶��������
	}

	// �����󶥵㷨����
	Vector3 vSum(0);
	int shared=0;

	// �������еĶ���
	for (unsigned int i = 0; i < t3DObj->PosVerts.size(); ++i)     
	{
		shared = 0;
		vSum.set(0, 0, 0);

		for (unsigned int j = 0; j < t3DObj->Indexes.size(); j += VERTEX_OF_FACE)  // �������е���������
		{                                                // �жϸõ��Ƿ����������湲��
			if (t3DObj->Indexes[j    ] == i || 
				t3DObj->Indexes[j + 1] == i || 
				t3DObj->Indexes[j + 2] == i)
			{
				vSum = (vSum + pTempNormals[j / VERTEX_OF_FACE]); //ָʾ����j���ڵ��淨����
				shared++;                
			}
		} 

		if(shared)
		{
			t3DObj->Normals[i] = (vSum / GLfloat(-shared));
		}

		// �淶�����Ķ��㷨��
		(t3DObj->Normals[i]).normalize();                   
	}

	delete [] pTempNormals;
}

///////////////////////////////////////////////////����ģ��
void ZWModelOBJ::DrawModel()
{
	// ����ģ�������еĶ���
	for(unsigned int i = 0; i < m_Model3DS.t3DObjVec.size(); i++) 
	{
		// ��õ�ǰ��ʾ�Ķ���
		t3DObject *t3DObj = &m_Model3DS.t3DObjVec[i];

		// �жϸö����Ƿ�������ӳ��
		if(t3DObj->bHasTexture && m_Model3DS.bIsTextured && t3DObj->nMaterialID >= 0) 
		{  
			glColor3ub(255, 255, 255);

			// ������ӳ��
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjDiffuseMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjDiffuseMap);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].nDiffuseMap);
			}
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjSpecularMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjSpecularMap);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].nSpecularMap);
			}
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjBumpMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjBumpMap);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].nSpecularMap);
			}
		} 
		else 
		{
			// �ر�����ӳ��
			glDisable(GL_TEXTURE_2D);
			if(-1 != t3DObj->nMaterialID)
			{
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].crAmbient);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].crDiffuse);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].crSpecular);
				glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].fShiness);

				glColor4fv(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].crDiffuse);
			}
			else
			{
				glColor3ub(255, 255, 255);
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nPosVBO);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, NULL);

		glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nNormVBO);
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, NULL);

		if(m_Model3DS.t3DObjVec[i].nTexcoordVBO)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nTexcoordVBO);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, 0, NULL);
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Model3DS.t3DObjVec[i].nIndexVBO);

		glDrawElements(GL_TRIANGLES, m_Model3DS.t3DObjVec[i].nNumIndexes, GL_UNSIGNED_SHORT, NULL);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, NULL);


		if(t3DObj->bHasTexture && m_Model3DS.bIsTextured && t3DObj->nMaterialID >= 0) 
		{ 
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjBumpMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjBumpMap);
				glDisable(GL_TEXTURE_2D);
			}
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjSpecularMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjSpecularMap);
				glDisable(GL_TEXTURE_2D);
			}
			if(NULL != m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjDiffuseMap)
			{
				glActiveTexture(m_Model3DS.tMatInfoVec[t3DObj->nMaterialID].TexObjDiffuseMap);
				glDisable(GL_TEXTURE_2D);
			}
		}
	}
}
