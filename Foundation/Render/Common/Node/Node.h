#pragma once

#include "system.h"

#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

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
		void clearAllChildren();
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
		// ��ֵ����
		//virtual void calculate();
		// �������нڵ�
		virtual void visit();
		// ��ȡ��������
		ActionProxy* getActionProxy();

		// �Ƿ�͸��ڵ����
		bool isRelativeWithParent();
		// �����Ƿ�͸��ڵ����
		void setRelativeWithParent(bool status);

		// ����Ƿ�����
		bool containTouchPoint(float x, float y);
		// ��ȡ��������
		TouchProxy* getTouchProxy();

		const RectangeVertex& getRectVertex();
	protected:
		// ����,��д
		virtual void draw();
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
	protected:
		// opengl λ��
		sys::Vector _obPosition;
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
	};
}