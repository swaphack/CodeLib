#pragma once

#include "TouchDelegate.h"
#include <map>
#include <vector>
#include <set>

namespace render
{
	class Node;
	class Camera;
	class Scene;

	class TouchProtocol
	{
	public:
		TouchProtocol();
		virtual ~TouchProtocol();
	public:
		// ���ÿɵ����
		void setTouchEnabled(bool status);
		// �Ƿ�ɵ��
		bool isTouchEnabled();
	public:
		// �������ɵ��
		void setTouchSwallowed(bool status);
		// �Ƿ����ɵ��
		bool isTouchSwallowed();

		// �����Ƿ�ü�
		void setClippingEnabled(bool status);
		// �Ƿ�ü�
		bool isClippingEnabled();
	public:
		virtual bool isInFrontOf(const TouchProtocol* target) const;
	public:
		// �Ƿ��������ڸĽڵ���,����д
		virtual bool containTouchPoint(const math::Vector2& touchPoint);
	public:// ��������
		virtual bool onTouchBegan(const math::Vector2& touchPoint);
		virtual bool onTouchMoved(const math::Vector2& touchPoint);
		virtual bool onTouchEnded(const math::Vector2& touchPoint);
		virtual void onTouchCanceled(const math::Vector2& touchPoint);
	public:
		// ��Ӵ����¼�
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchDelegate(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchDelegates();
	public:
		// ��Ӵ����¼�
		void addTouchFunc(TouchType type, TouchFunc func);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchFunc(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchFuncs();
	public:
		// �ɷ������¼�
		void dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint);
	private:
		//�ɵ��
		bool _bTouchEnabled = false;
		// ���ɵ��
		bool _bTouchSwallowed = false;
		// �ü��ڵ�
		bool _bClippingEnabled = false;

		std::map<TouchType, std::vector<TouchDelegate>> _touchDelegates;
		std::map<TouchType, std::vector<TouchFunc>> _touchFuncs;
	};



	// ����
	class DrawNodeProtocol
	{
	public:
		DrawNodeProtocol();
		virtual ~DrawNodeProtocol();
	public:
		/**
		*	���������
		*/
		void setCamera(const Camera* camera);
		/**
		*	��ȡ�����
		*/
		Camera* getCamera() const;
	public:
		// ������������
		void setScene(Scene* scene);
		// ��ȡ����
		Scene* getScene() const;
	protected:
		// ���������
		Camera* _camera = nullptr;
		// ����
		Scene* _scene = nullptr;
	};
}