#pragma once

#include "system.h"
#include "Notify.h"
#include "NodeProtocol.h"
#include "NotifyCenter.h"
#include "Common/Input/TouchProtocol.h"
#include "Common/Action/SchedulerProtocol.h"
#include <vector>

namespace render
{
	class ActionProxy;

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
		public DirectionProtocol,
		public TouchProtocol,
		public SchedulerProtocol,
		public DrawNodeProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		// ��ص��ã����������޸�ʱ֪ͨ
		virtual bool init();
		// �����ͻ���
		virtual void visit();
	public:
		// ���ø��ڵ�
		void setParent(Node* node);
		// ��ȡ���ڵ�
		Node* getParent() const;
		// �Ӹ��ڵ��Ƴ�
		virtual void removeFromParent();
		// ���ó���
		void setChildrenScene(Scene* scene);
	public:
		// ����ӽڵ�
		virtual void addChild(Node* node);
		// ����ӽڵ�
		virtual void addChild(Node* node, int zOrder);
		// �Ƴ��ӽڵ�
		void removeChild(Node* node);
		// �Ƴ������ӽڵ�
		void removeAllChildren();
		// ����id��ȡ�ӽڵ�
		Node* getChildByID(long id) const;
	public:
		// ���ñ�ǩ
		void setTag(int tag);
		// ��ȡ��ǩ
		int getTag() const;
		// ���ݱ�ǩ��ȡ�ӽڵ�
		Node* getChildByTag(int tag) const;
	public:
		// �������ƻ�ȡ�ӽڵ�
		Node* getChildByName(const std::string& name) const;
	public:
		// ��ȡ�ӽڵ����
		int getChildrenCount() const;
		// ��ȡ��һ���ӽڵ�
		Node* getFirstChild() const;
		// �������������ӽڵ�
		Node* getChildByIndex(int index) const;
		// �ӽڵ���������
		int indexOfChild(const Node* node) const;
		// �Ƿ���Ŀ��ĺ���ڵ�
		bool isDescendantsOf(const Node* parent) const;
	public:
		// ��������
		void setUserData(void* data);
		// ��ȡ����
		void* getUserData() const;
	public:
		// ����z������
		void setZOrder(int z);
		// ��ȡz������
		int getZOrder()  const;
	public:
		// ���ÿɼ���
		void setVisible(bool status);
		// �Ƿ�ɼ�
		bool isVisible()  const;
	public:
		// ��������
		void setSkipDraw(bool status);
		// �Ƿ���������
		bool isSkipDraw()  const;
	public:
		// ���½ڵ�, ���½ڵ��߼�
		virtual void updateNode();
	public:
		// ���ƽڵ� ����任->���Ժ�Ԥ����->���Ƶ�ǰ����
		virtual void drawNode();
		// ����ǰ
		virtual void beforeDrawNode();
		// ���ƺ�
		virtual void afterDrawNode();
	protected:
		// ����,��д
		virtual void draw();

		void drawAllChildren();
	public:
		// ��ȡ��������
		ActionProxy* getActionProxy();
		/**
		*	������ʱ��
		*/
		virtual void scheduleUpdate();
		/**
		*	�رն�ʱ��
		*/
		virtual void unscheduleUpdate();
		/**
		*	��ʱ����
		*/
		virtual void update(float dt);
	public:
		// �Ƿ�͸��ڵ����
		bool isRelativeWithParent();
		// �����Ƿ�͸��ڵ����
		void setRelativeWithParent(bool status);
	public:
		// �������
		const math::Matrix4x4& getWorldMatrix() const;
		// ��Ը��ڵ�ľ���
		const math::Matrix4x4& getLocalMatrix() const;
		// ����������ת��Ϊ��������
		math::Vector3 convertWorldPostitionToLocal(const math::Vector3& point) const;
		// ����������ת��Ϊ��������
		math::Vector3 convertLocalPostitionToWorld(const math::Vector3& point) const;
	public:
		// �Ƿ��������ڸĽڵ���
		virtual bool containTouchPoint(const math::Vector2& touchPoint);
	protected:
		// �Ƿ��������ڸĽڵ���
		virtual bool containPoint(const math::Vector2& touchPoint);
	public:
		virtual bool isInFrontOf(const TouchProtocol* target) const;
	protected:
		// ��Ŀ��ڵ��ǰ��
		bool isInFrontOfNode(const Node* target) const;
	protected:
		// ���¿ռ����
		virtual void startUpdateTranform();
		// ��ת�ռ����
		virtual void endUpdateTranform();
	public:
		// ����¼�����
		void addNotifyListener(NodeNotifyType id, const NotifyDelegate& func);
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
		NodeNotify* _notify = nullptr;
		// ����ڸ��ڵ�ľ���
		math::Matrix4x4 _localMatrix;
		// �����
		math::Matrix4x4 _localInverseMatrix;
		// ʵ������������ϵ�еľ���
		math::Matrix4x4 _worldMatrix;
		// ʵ������������ϵ�е������
		math::Matrix4x4 _worldInverseMatrix;
	protected:
		// ��������
		ActionProxy* _actionProxy = nullptr;
		
	};


#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<render::Node, T>::value, T>::type>
	T* createNode()
	{
		T* temp = new T();
		if (temp == nullptr)
		{
			return nullptr;
		}
		if (temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}
