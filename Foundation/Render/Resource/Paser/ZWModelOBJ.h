//////////////////////////////////////////////////////////////////////////
// Class ZWModelOBJ  - by ZwqXin (2008 - 2011) 
// http://www.zwqxin.com
// Last Update: 2011.2
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector> 
#include <map> 
#include "ZWModelBase.h"

class ZWModelOBJ : public ZWModelBase
{
public:
	typedef TexCoordValue TexCoord;
	typedef Vector3Value Vector3;

	enum
	{
		MAP_DIFFUSE,
		MAP_SPECULAR,
		MAP_BUMP
	};

	//��ʶ��������Ľṹ��
	typedef struct tagVertInfo
	{
		tagVertInfo(const Vector3 &pos, const TexCoord &tc, const Vector3 &norm)
		{ vPos = pos; vTexcoord = tc; vNormal = norm; }
		Vector3  vPos;
		TexCoord vTexcoord;
		Vector3  vNormal;
	}tVertInfo;

	// ������Ϣ�ṹ��
	typedef struct tagMaterialInfo
	{
		char      strName[MAX_NAME];   // ��������
		GLfloat   crAmbient[4];
		GLfloat   crDiffuse[4];
		GLfloat   crSpecular[4];
		GLfloat   fShiness;
		GLuint    nDiffuseMap;
		GLuint    nSpecularMap;
		GLuint    nBumpMap;
		GLuint    TexObjDiffuseMap;
		GLuint    TexObjSpecularMap;
		GLuint    TexObjBumpMap;
	}tMaterialInfo;


	// ������Ϣ�ṹ��
	typedef struct tag3DObject 
	{
		int                         nMaterialID;       // ����ID
		bool                        bHasTexture;       // �Ƿ��������ӳ��
		bool                        bHasNormal;        // �Ƿ���з���
		std::vector<Vector3>        PosVerts;          // ����Ķ���
		std::vector<Vector3>        Normals;           // ����ķ�����
		std::vector<TexCoord>       Texcoords;         // ����UV����
		std::vector<unsigned short> Indexes;           // ����Ķ�������
		unsigned int                nNumIndexes;       // ������Ŀ
		GLuint                      nPosVBO;
		GLuint                      nNormVBO;
		GLuint                      nTexcoordVBO;
		GLuint                      nIndexVBO;
	}t3DObject;

	// ģ����Ϣ�ṹ��
	typedef struct tag3DModel 
	{
		bool  bIsTextured;                        //�Ƿ�ʹ������
		std::vector<tMaterialInfo> tMatInfoVec;   // ������Ϣ
		std::vector<t3DObject>     t3DObjVec;     // ģ���ж�����Ϣ
	}t3DModel;


	ZWModelOBJ();              
	virtual ~ZWModelOBJ();

	virtual bool ImportModel(wchar_t *strFileName, GLuint usage = GL_STREAM_DRAW);

	virtual GLuint GetMaterialMapHandle(GLuint nMapType, char *szMaterialName);

	virtual bool   SetEnableMaterialMap(GLuint nMapType, GLuint nTextureObject = GL_TEXTURE0);

	virtual void   SetEnableModelTexture(bool bEnable){ m_Model3DS.bIsTextured = bEnable; }

	const t3DModel &GetModelInstance() { return m_Model3DS; }
private:
	//����ģ��
	virtual void DrawModel();

	// �������
	void ProcessFileInfo(t3DModel *pModel);
	// ������ֶ�����Ϣ
	void ProcessVertexInfo(char chKeyword);
	// ��������Ϣ
	void ProcessFaceInfo(t3DModel *pModel);
	//������ʿ���Ϣ
	void ProcessMtlFileInfo(t3DModel *pModel, wchar_t *szMtlFileName);
    //��mtllib���ʿ���Ѱ��mtl���� ȡ�ò���ID
	int FindMtlID(t3DModel *pModel, char *szMtlName);
	// ������󶥵�ķ�����
	void ComputeNormals(t3DObject *t3DObj);
	// �ͷ��ڴ�ռ�
	void CleanImportedData();

	FILE    *m_FilePointer;

	t3DModel m_Model3DS;

	int  m_nCurObjectCount;
	int  m_nCurMaterialCount;

	// ����λ������Ⱥ
	std::vector<Vector3>   m_VPositionVec;
	// ������������Ⱥ
	std::vector<TexCoord>  m_VTexcoordVec;
	// ���㷨������Ⱥ
	std::vector<Vector3>  m_VNormalVec;
    // ���浱ǰ���������
	std::map<tVertInfo, unsigned short> m_VObjectIndexMap;
};


