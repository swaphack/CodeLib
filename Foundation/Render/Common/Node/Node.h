#pragma once

#include "system.h"
#include "Notify.h"
#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T>
	T* createNode()
	{
		T* temp = new T();
		if (temp && temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}

	/**
	glLoadIdentity();
	glMultMatrixf(M);           //glScale*();
	glMultMatrixf(N);           //glRotate*()
	glMultMatrixf(L);           //glTranslate*();

	1.��OpenGL�����е���ͼ�任��ģ�ͱ任 ����4��4����
	ÿ��������glMultiMatrix*(N),���߱任����,glTranslate*(),glRotate*(),�ȶ��ǰ�һ���µ�4��4�����뵱ǰ�ľ���M��ˣ�
	��ͬ���ǣ��任����glTranslate*(),glRotate*()�Ȼ���ݺ�����������һ��4��4����Ҳ��ΪN���������������ͬ�Ľ����M��N��
	ע�������˳�򣬺����ľ������ҳ˵�ǰ����

	2.��Ϊ��opengl�������ʾ��ʽ�ǣ�[x,y,z]T(��ʾת��)��������������£�[x,y,z,w]T��׼����[x/w,y/w,z/w,1.0]T ��;����˾���Ҳ�������ȱ�ʾ�ġ�
	��������������������ڵ�V,���ʾΪ:M��N��V�����������˵�������[4��4] * [4��1].
	*/
	// ���ƽڵ�
	class Node : 
		public sys::Object, 
		public sys::Name,
		public DirtyProtocol, 
		public SpaceProtocol,
		public BodyProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
		// ���ø��ڵ�
		void setParent(Node* node);
		// ��ȡ���ڵ�
		Node* getParent();
		// �Ӹ��ڵ��Ƴ�
		void removeFromParent();
		// ����ӽڵ�
		void addChild(Node* node);
		// �Ƴ��ӽڵ�
		void removeChild(Node* node);
		// �Ƴ������ӽڵ�
		void removeAllChildren();
		// ����id��ȡ�ֽڵ�
		Node* getChildByID(long id);

		// ���ñ�ǩ
		void setTag(int tag);
		// ��ȡ��ǩ
		int getTag();
		// ���ݱ�ǩ��ȡ�ֽڵ�
		Node* getChildByTag(int tag);

		// �������ƻ�ȡ�ֽڵ�
		Node* getChildByName(const char* name); 
		// ��ȡ��һ���ӽڵ�
		Node* getFirstChild();

		std::vector<sys::Object*>::iterator beginChild();
		std::vector<sys::Object*>::iterator endChild();

		// ��������
		void setUserData(void* data);
		// ��ȡ����
		void* getUserData();

		// ����z������
		void setZOrder(float z);
		// ��ȡz������
		float getZOrder();

		// ���ÿɼ���
		void setVisible(bool status);
		// �Ƿ�ɼ�
		bool isVisible();
		// ����,��д
		virtual void draw();
		// �������нڵ�
		virtual void visit();
		// ��ȡ��������
		ActionProxy* getActionProxy();

		// �Ƿ�͸��ڵ����
		bool isRelativeWithParent();
		// �����Ƿ�͸��ڵ����
		void setRelativeWithParent(bool status);

		// ����Ƿ�����
		virtual bool containTouchPoint(float x, float y);
		// ��ȡ��������
		TouchProxy* getTouchProxy();
		// ���ζ���
		const RectVertex& getRectVertex();
		// ����
		const math::Matrix44& getRealMatrix();
		// ����
		const math::Matrix44& getMatrix();
	protected:
		// ���¿ռ�λ��
		virtual void updateTranform();
		// �����Լ�
		virtual void updateSelf();
		// ���³�ʼ���Լ�
		virtual void initSelf();
		// ���ӽڵ��������
		virtual void sortChildren();
		// �ռ���������
		virtual void calRealSpaceInfo();
		// �ռ����Է����ı�
		virtual void onSpaceChange();
		// �������Է����ı�
		virtual void onBodyChange();
		// �ӽڵ㷢���ı�
		virtual void onChildrenChange();
	private:
		void calRealSpaceByMatrix();
		void calRealSpaceByValue();
	protected:
		// opengl λ��
		math::Vector3 _obPosition;
		// ��ת�Ƕ�
		math::Vector3 _obRotation;
		// ��ǩ
		int _tag;
		// ����
		std::string _name;
		// ����
		void* _userData;
		// z������
		float _zOrder;
		// ���ڵ�
		Node* _parent;
		// �ӽڵ�
		sys::List _children;
		// �Ƿ�ɼ�
		bool _bVisibled;
		// �Ƿ�ɵ��
		bool _bTouchEnabled;
		// �Ƿ�͸��ڵ����
		bool _bRelative;
		// ��������
		ActionProxy* _actionProxy;
		// ��������
		TouchProxy* _touchProxy;
		// ���ο�
		RectVertex _rectVertex;
		// �ռ����꣨ʵ�ʣ�
		RectVertex _realSpaceVertex;
		// ʵ������ռ���Ϣ
		BodySpace _realBodySpace;
		// ֪ͨ
		Notify* _notify;
		// ʹ�þ�������
		bool _bUseMatrix = true;
		// ����
		math::Matrix44 _mat44;
		// ʵ��
		math::Matrix44 _realMat44;
	};
}
