#pragma once

#include "system.h"

#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"
//#include "../Touch/TouchProxy.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

	// ���ƽڵ�
	class Node : public sys::Object, public DirtyProtocol
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

		// ��������
		void setUserData(void* data);
		// ��ȡ����
		void* getUserData();

		// ����z������
		void setZOrder(float z);
		// ��ȡz������
		float getZOrder();
		// ��������
		void setPosition(float x, float y, float z);
		// ��ȡ����
		const sys::Vector& getPosition();
		// �������ű�
		void setScale(float x, float y, float z);
		// ��ȡ���ű�
		const sys::Vector& getScale();
		// ������תϵ��
		void setRotation(float x, float y, float z);
		// ��ȡ��תϵ��
		const sys::Vector& getRotation();

		// �������
		void setAnchorPoint(float x, float y, float z);
		// ��ȡ���
		const sys::Vector& getAnchorPoint();
		// �������
		void setVolume(float w, float h, float d);
		// ��ȡ���
		const sys::Volume& getVolume();

		// ���ÿɼ���
		void setVisible(bool status);
		// �Ƿ�ɼ�
		bool isVisible();
		
		// ����
		virtual void draw();
		// �������нڵ�
		virtual void visit();
		// ��ȡ��������
		ActionProxy* getActionProxy();

		// �Ƿ�͸��ڵ����
		bool isRelativeWithParent();
		// �����Ƿ�͸��ڵ����
		void setRelativeWithParent(bool status);

		// ���þ��ο��Ƿ�ɼ�
		void setRectVisible(bool status);
		// ���þ��ο���ʾ��ɫ
		void setRectColor(const sys::Color4B& color);

		// ����Ƿ�����
		bool containTouchPoint(float x, float y);
		// ��ȡ��������
		TouchProxy* getTouchProxy();
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
		// ��ʾ��������
		void drawRect();
	protected:
		sys::Vector _obPosition;
		// ��ǩ
		int _tag;
		// ����
		void* _userData;
		// z������
		float _zOrder;
		// λ������
		sys::Vector _position;
		// ���ű�
		sys::Vector _scale;
		// ��ת
		sys::Vector _rotation;

		// ê��
		sys::Vector _anchor;
		// ���
		sys::Volume _volume;
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
		// ���ο���ɫ
		sys::Color4B _rectColor;
		// �Ƿ���ʾ���ο�
		bool _bShowRect;
		// �ռ�����
		RectangeVertex _realSpaceVertex;
	};
}