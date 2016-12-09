#pragma once

#include "macros.h"

namespace ui
{
	/**
	*	ui����Ԫ�� �������ؼ�ת�޵��м���
	*	������Ϣ�������½�Ϊԭ�㣬����ָ������ľ���
	*
	*/ 
	class Widget : public sys::Object
	{
	public:
		Widget();
		virtual ~Widget();
	public:
		/**
		*	������Ϣ
		*/
		const sys::Rect& getGeometry();
		/**
		*	���ü�����Ϣ
		*/
		void setGeometry(const sys::Rect& rect);
		/**
		*	���ü�����Ϣ
		*/
		void setGeometry(float x, float y, float width, float height);
		/**
		*	���ü���λ��
		*/
		void setPosition(float x, float y);
		/**
		*	���ü������
		*/
		void setSize(float width, float height);
		/**
		*	��ȡ��С�������Ϣ
		*/
		const sys::Size& getMinSize();
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(float width, float height);
		/**
		*	��ȡ��󳤿����Ϣ
		*/
		const sys::Size& getMaxSize();
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(float width, float height);
	protected:
		// ������Ϣ
		sys::Rect m_rGeometry;
		// ��С���
		sys::Size m_sMinSize;
		// ������
		sys::Size m_sMaxSize;
		// ���ο���ɫ
		sys::Color4B _rectColor;
		// �Ƿ���ʾ���ο�
		bool _bBoxVisible;
	};
}