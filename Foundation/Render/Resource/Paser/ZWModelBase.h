//////////////////////////////////////////////////////////////////////////
// Class ZWModelBase  - by ZwqXin (2008 - 2011) 
// http://www.zwqxin.com
// Last Update: 2011.2
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <GL/GLEW.h>
#include "ZWTextureMgr.h"
#include "ZWVector3.h" 

#define MAX_NAME     255

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

class ZWModelBase
{
public:
	ZWModelBase();              
	virtual ~ZWModelBase() = 0;
 
	virtual bool ImportModel(wchar_t *strFileName, GLuint usage = GL_STREAM_DRAW) = 0{ return true; }

	void RenderModel();

	inline void SetModelResourceDirectory(wchar_t *szDirectory){ m_szResourceDirectory = szDirectory; }

    inline void SetModelPosition(GLfloat pos_x, GLfloat pos_y, GLfloat pos_z)
	{
		m_vModelPosition.x = pos_x;
		m_vModelPosition.y = pos_y;				
		m_vModelPosition.z = pos_z;
	}
	inline void SetModelRotation(GLfloat rot_x, GLfloat rot_y, GLfloat rot_z)
	{
		m_vModelRotation.x = rot_x;
		m_vModelRotation.y = rot_y;
		m_vModelRotation.z = rot_z;
	}
	inline void SetModelSize    (GLfloat size)
	{
		m_vModelSize.x = m_vModelSize.y = m_vModelSize.z = size;     
	}

	inline void SetModelPosition(Vector3 pos3){ m_vModelPosition = pos3; }
	inline void SetModelRotation(Vector3 rot3){ m_vModelRotation = rot3; }
    inline void SetModelSize    (Vector3 size){ m_vModelSize = size;     }


	inline Vector3 GetPosition() const{ return m_vModelPosition; }
	inline Vector3 GetRotation() const{ return m_vModelRotation; }
	inline Vector3 GetSize()     const{ return m_vModelSize; }

	virtual GLuint GetMaterialMapHandle(GLuint nMapType, char *szMaterialName) = 0{ return 0; }

	virtual bool   SetEnableMaterialMap(GLuint nMapType, GLuint nTextureObject = GL_TEXTURE0) = 0{ return false; }

	virtual void   SetEnableModelTexture(bool bEnable) = 0{}

	void SetStaticGeometry(bool bStatic = true);
    
protected:
	//»æÖÆÄ£ÐÍ
	virtual void DrawModel() = 0{}

	GLuint LoadModelTexture(wchar_t *szTexPathName, GLint nTexWrapMode = GL_REPEAT);

	wchar_t *m_szResourceDirectory;

	GLuint  m_nStaticDisplayList;

	Vector3 m_vModelPosition;
	Vector3 m_vModelRotation;
	Vector3 m_vModelSize;
};



