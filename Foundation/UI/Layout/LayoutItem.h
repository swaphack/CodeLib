#pragma once

#include "macros.h"

namespace ui
{
	class LayoutEx;
	/**
	*	������, ������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��widget�ļ�����Ϣ
	*/
	class LayoutItem : public sys::Object, public sys::Name
	{
	public:
		LayoutItem();
		virtual ~LayoutItem();
	public: // �̶����������
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
		void setOrgin(float x, float y);
		/**
		*	���ü���λ��
		*/
		void setOrgin(const sys::Vector2& position);
		/**
		*	��ȡ����λ��
		*/
		sys::Vector2 getOrgin();
		/**
		*	���ü������
		*/
		void setSize(float width, float height);
		/**
		*	���ü������
		*/
		void setSize(const sys::Size& size);
		/**
		*	��ȡ�������
		*/
		sys::Size getSize();
		/**
		*	����Ԫ��
		*/
		void setWidget(Widget* widget);
		/**
		*	��ȡԪ��
		*/
		Widget* getWidget();
	public: // ���������صķ���
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItem* item);
	public: // ������������
		/**
		*	���þ��ο��Ƿ�ɼ�
		*/
		void setBoxVisible(bool status);
		/**
		*	���ο��Ƿ�ɼ�
		*/
		bool isBoxVisible();
		/**
		*	���þ��ο���ʾ��ɫ
		*/
		void setBoxColor(const sys::Color4B& color);
		/**
		*	��ȡ���ο���ʾ��ɫ
		*/
		const sys::Color4B& getBoxColor();
		/**
		*	����Ԫ���ļ�����Ϣ
		*/
		void setWidgetGeomerty(const sys::Rect& geometry);
	protected:
		// ������Ϣ
		sys::Rect m_rGeometry;
		// ���ο���ɫ
		sys::Color4B m_cBoxColor;
		// �Ƿ���ʾ���ο�
		bool m_bBoxVisible;
		// ������
		Widget* m_pWidget;
	};
}