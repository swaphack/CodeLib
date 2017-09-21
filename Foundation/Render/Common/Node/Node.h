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

#define CREATE_NODE(NODE_TYPE) createNode<NODE_TYPE>()

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

		const RectangeVertex& getRectVertex();
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
	protected:
		// opengl λ��
		sys::Vector3 _obPosition;
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
		RectangeVertex _rectVertex;
		// �ռ�����
		RectangeVertex _realSpaceVertex;
		// ֪ͨ
		Notify* _notify;
	};
}
