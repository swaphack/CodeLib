#pragma once

#include "system.h"
#include "Notify.h"
#include "NodeProtocol.h"
#include <vector>

namespace render
{
	class ActionProxy;
	class TouchProxy;

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
		public sys::DirtyProtocol,
		public SpaceProtocol,
		public BodyProtocol,
		public DirectionProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
	public:
		// ���ø��ڵ�
		void setParent(Node* node);
		// ��ȡ���ڵ�
		Node* getParent();
		// �Ӹ��ڵ��Ƴ�
		void removeFromParent();
	public:
		// ����ӽڵ�
		void addChild(Node* node);
		// ����ӽڵ�
		void addChild(Node* node, int zOrder);
		// �Ƴ��ӽڵ�
		void removeChild(Node* node);
		// �Ƴ������ӽڵ�
		void removeAllChildren();
		// ����id��ȡ�ֽڵ�
		Node* getChildByID(long id);
	public:
		// ���ñ�ǩ
		void setTag(int tag);
		// ��ȡ��ǩ
		int getTag();
		// ���ݱ�ǩ��ȡ�ֽڵ�
		Node* getChildByTag(int tag);
	public:
		// �������ƻ�ȡ�ֽڵ�
		Node* getChildByName(const std::string& name); 
	public:
		// ��ȡ��һ���ӽڵ�
		Node* getFirstChild();
	public:
		// ��������
		void setUserData(void* data);
		// ��ȡ����
		void* getUserData();
	public:
		// ����z������
		void setZOrder(int z);
		// ��ȡz������
		int getZOrder();
	public:
		// ���ÿɼ���
		void setVisible(bool status);
		// �Ƿ�ɼ�
		bool isVisible();
	public:
		// ��������
		void setSkipDraw(bool status);
		// �Ƿ���������
		bool isSkipDraw();
	public:
		// ���½ڵ�, ���½ڵ��߼�
		virtual void updateNode();
	public:
		// ���ƽڵ� ����任->���Ժ�Ԥ����->���Ƶ�ǰ����
		virtual void drawNode();

		virtual void beforeDrawNode();

		virtual void afterDrawNode();
	protected:
		// ����,��д
		virtual void draw();

		void drawAllChildren();
	public:
		// ��ȡ��������
		ActionProxy* getActionProxy();
	public:
		// �Ƿ�͸��ڵ����
		bool isRelativeWithParent();
		// �����Ƿ�͸��ڵ����
		void setRelativeWithParent(bool status);
	public:
		// ��ȡ��������
		TouchProxy* getTouchProxy();
	public:
		// �������
		const math::Matrix4x4& getWorldMatrix() const;
		// ��Ը��ڵ�ľ���
		const math::Matrix4x4& getLocalMatrix() const;
		// ����������ת��Ϊ��������
		math::Vector3 convertWorldPostitionToLocal(const math::Vector3& point);
		// ����������ת��Ϊ��������
		math::Vector3 convertLocalPostitionToWorld(const math::Vector3& point);

		virtual bool containTouchPoint(float x, float y) { return false; }
	protected:
		// ���¿ռ����
		virtual void startUpdateTranform();
		// ��ת�ռ����
		virtual void endUpdateTranform();
	public:
		void addNotify(NodeNotifyType id, const NotifyDelegate& func);
		// ���¼�֪ͨ�����нڵ�
		void notifyToAll(NodeNotifyType id);
		// ���¼�֪ͨ���ڵ�
		void notify(NodeNotifyType id);
		// �㲥�¼�
		void broadcastFunc(const std::function<void(Node*)>& func, bool recursive = false);
	protected:
		void notifyEvents();
	protected:
		// ���ӽڵ��������
		virtual void sortChildren();
		// �ռ���������
		virtual void calSpaceData();
		// �ռ����Է����ı�
		virtual void onSpaceChange();
		// �������Է����ı�
		virtual void onBodyChange();
		// �ӽڵ㷢���ı�
		virtual void onChildrenChange();
	private:
		// ʹ�þ������ռ�仯����
		void calRealSpaceByMatrix();
		// ������ת��ķ���
		void calDirectionWithRotate();
	protected:
		// opengl λ��
		math::Vector3 _obPosition;
		// opengl ��ת�Ƕ�
		math::Vector3 _obRotation;
		// ��ǩ
		int _tag = 0;
		// ����
		void* _userData = nullptr;
		// z������
		int _zOrder = 0;
		// ���ڵ�
		Node* _parent = nullptr;
		// �ӽڵ�
		std::vector<Node*> _children;
		// ��������
		bool _bSkipDraw = false;
		// �Ƿ�ɼ�
		bool _bVisibled = false;
		// �Ƿ�ɵ��
		bool _bTouchEnabled = false;
		// �Ƿ�͸��ڵ����
		bool _bRelativeToParent = false;
		// ֪ͨ
		Notify<NodeNotifyType>* _notify;
		// ����ڸ��ڵ�ľ���
		math::Matrix4x4 _localMatrix;
		// �����
		math::Matrix4x4 _localInverseMatrix;
		// ʵ������������ϵ�еľ���
		math::Matrix4x4 _worldMatrix;
	private:
		// ��������
		ActionProxy* _actionProxy;
		// ��������
		TouchProxy* _touchProxy;
		
	};


#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value, T>::type>
	T* createNode()
	{
		T* temp = new T();
		if (temp == nullptr)
		{
			return nullptr;
		}
		if (temp && temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}
