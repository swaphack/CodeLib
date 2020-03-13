//////////////////////////////////////////////////////////////////////////
// Class ZWModelBase  - by ZwqXin (2008 - 2011) 
// http://www.zwqxin.com
// Last Update: 2011.2
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ZWModelBase.h"

ZWModelBase::ZWModelBase() : m_vModelPosition(Vector3(0)),
						     m_vModelRotation(Vector3(0)),
						     m_vModelSize(Vector3(1.0f)),
							 m_nStaticDisplayList(0),
							 m_szResourceDirectory(NULL)
{

}

ZWModelBase::~ZWModelBase()
{	

}

void ZWModelBase::RenderModel()
{
	glPushAttrib(GL_CURRENT_BIT);//保存现有属性
	glPushMatrix();

	glTranslatef(m_vModelPosition.x, m_vModelPosition.y, m_vModelPosition.z);
	glScalef(m_vModelSize.x,  m_vModelSize.y,  m_vModelSize.z);
	glRotatef(m_vModelRotation.x,1,0,0);
	glRotatef(m_vModelRotation.z,0,0,1);
	glRotatef(m_vModelRotation.y,0,1,0);

	if(m_nStaticDisplayList)
	{
		glCallList(m_nStaticDisplayList);
	}
	else
	{
		DrawModel();
	}

	glPopMatrix();
	glPopAttrib();          //恢复前一属性

}

void ZWModelBase::SetStaticGeometry(bool bStatic)
{
	if(!bStatic && m_nStaticDisplayList)
	{
		glDeleteLists(m_nStaticDisplayList, 1);

		m_nStaticDisplayList = 0;
	}
	else if(bStatic && !m_nStaticDisplayList)
	{
		m_nStaticDisplayList = glGenLists(1);

		glNewList(m_nStaticDisplayList, GL_COMPILE);

		DrawModel();

		glEndList();
	}
}

GLuint ZWModelBase::LoadModelTexture(wchar_t *szTexPathName, GLint nTexWrapMode)
{
	int nUndefiedUserID = ZWTextureMgr::GetInstancePtr()->GenerateUnspecifiedUserID();

	return  ZWTextureMgr::GetInstancePtr()->LoadGLTexture2D(nUndefiedUserID, szTexPathName, 
		GL_RGBA, GL_UNSIGNED_BYTE, nTexWrapMode);
}

