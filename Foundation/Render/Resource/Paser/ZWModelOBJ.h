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

	//标识独立顶点的结构体
	typedef struct tagVertInfo
	{
		tagVertInfo(const Vector3 &pos, const TexCoord &tc, const Vector3 &norm)
		{ vPos = pos; vTexcoord = tc; vNormal = norm; }
		Vector3  vPos;
		TexCoord vTexcoord;
		Vector3  vNormal;
	}tVertInfo;

	// 材质信息结构体
	typedef struct tagMaterialInfo
	{
		char      strName[MAX_NAME];   // 纹理名称
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


	// 对象信息结构体
	typedef struct tag3DObject 
	{
		int                         nMaterialID;       // 纹理ID
		bool                        bHasTexture;       // 是否具有纹理映射
		bool                        bHasNormal;        // 是否具有法线
		std::vector<Vector3>        PosVerts;          // 对象的顶点
		std::vector<Vector3>        Normals;           // 对象的法向量
		std::vector<TexCoord>       Texcoords;         // 纹理UV坐标
		std::vector<unsigned short> Indexes;           // 对象的顶点索引
		unsigned int                nNumIndexes;       // 索引数目
		GLuint                      nPosVBO;
		GLuint                      nNormVBO;
		GLuint                      nTexcoordVBO;
		GLuint                      nIndexVBO;
	}t3DObject;

	// 模型信息结构体
	typedef struct tag3DModel 
	{
		bool  bIsTextured;                        //是否使用纹理
		std::vector<tMaterialInfo> tMatInfoVec;   // 材质信息
		std::vector<t3DObject>     t3DObjVec;     // 模型中对象信息
	}t3DModel;


	ZWModelOBJ();              
	virtual ~ZWModelOBJ();

	virtual bool ImportModel(wchar_t *strFileName, GLuint usage = GL_STREAM_DRAW);

	virtual GLuint GetMaterialMapHandle(GLuint nMapType, char *szMaterialName);

	virtual bool   SetEnableMaterialMap(GLuint nMapType, GLuint nTextureObject = GL_TEXTURE0);

	virtual void   SetEnableModelTexture(bool bEnable){ m_Model3DS.bIsTextured = bEnable; }

	const t3DModel &GetModelInstance() { return m_Model3DS; }
private:
	//绘制模型
	virtual void DrawModel();

	// 读入对象
	void ProcessFileInfo(t3DModel *pModel);
	// 读入各种顶点信息
	void ProcessVertexInfo(char chKeyword);
	// 读入面信息
	void ProcessFaceInfo(t3DModel *pModel);
	//读入材质库信息
	void ProcessMtlFileInfo(t3DModel *pModel, wchar_t *szMtlFileName);
    //在mtllib材质库中寻找mtl名称 取得材质ID
	int FindMtlID(t3DModel *pModel, char *szMtlName);
	// 计算对象顶点的法向量
	void ComputeNormals(t3DObject *t3DObj);
	// 释放内存空间
	void CleanImportedData();

	FILE    *m_FilePointer;

	t3DModel m_Model3DS;

	int  m_nCurObjectCount;
	int  m_nCurMaterialCount;

	// 顶点位置数据群
	std::vector<Vector3>   m_VPositionVec;
	// 纹理坐标数据群
	std::vector<TexCoord>  m_VTexcoordVec;
	// 顶点法线数据群
	std::vector<Vector3>  m_VNormalVec;
    // 缓存当前对象的索引
	std::map<tVertInfo, unsigned short> m_VObjectIndexMap;
};


