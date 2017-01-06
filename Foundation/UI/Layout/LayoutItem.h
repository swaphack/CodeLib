#pragma once

#include "macros.h"

#include "SizePolicy.h"

namespace ui
{
	class Layout;

	static const int LAYOUT_SIZE_MIN_WIDTH = 0;
	static const int LAYOUT_SIZE_MIN_HEIGHT = 0;
	static const int LAYOUT_SIZE_MAX_WIDTH = 65536;
	static const int LAYOUT_SIZE_MAX_HEIGHT = 65536;

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
		void setOrgin(const sys::Point& position);
		/**
		*	��ȡ����λ��
		*/
		sys::Point getOrgin();
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
		*	��ȡ��С�������Ϣ
		*/
		const sys::Size& getMinSize();
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(float width, float height);
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(const sys::Size& size);
		/**
		*	��ȡ��󳤿����Ϣ
		*/
		const sys::Size& getMaxSize();
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(float width, float height);
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(const sys::Size& size);
		/**
		*	����Ԫ��
		*/
		void setWidget(Widget* widget);
		/**
		*	��ȡԪ��
		*/
		Widget* getWidget();
		/**
		*	���ò���
		*/
		void setLayout(Layout* layout);
		/**
		*	��ȡ����
		*/
		Layout* getLayout();
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		SizePolicy& getSizePolicy();
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		void setSizePolicy(const SizePolicy& policy);
	public: // ���������صķ���
		/**
		*	���ò�����ļ�����Ϣ
		*/
		virtual void setLayoutGeometry(const sys::Rect& rect);
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual sys::Size getLayoutMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual sys::Size getLayoutMaxSize();
		/**
		*	���ƶ���
		*/
		virtual bool copy(LayoutItem* item);
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
		// ��С���
		sys::Size m_sMinSize;
		// ������
		sys::Size m_sMaxSize;
		// ���ο���ɫ
		sys::Color4B m_rectColor;
		// �Ƿ���ʾ���ο�
		bool m_bBoxVisible;
		// ������
		Widget* m_pWidget;
		// ����
		Layout* m_pLayout;
		// ��С��������
		SizePolicy m_spAdjust;
	};
}