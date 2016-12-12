#pragma once

#include "macros.h"

#include "SizePolicy.h"

namespace ui
{
	class Layout;

	/**
	*	������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��widget�ļ�����Ϣ
	*/
	class LayoutItem : public sys::Object
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
		void setPosition(float x, float y);
		/**
		*	���ü���λ��
		*/
		void setPosition(const sys::Point& position);
		/**
		*	��ȡ����λ��
		*/
		sys::Point getPosition();
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
		void setMaxSize(float width, float height);
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
	public: // ���������صķ���
		/**
		*	���ò�����ļ�����Ϣ
		*/
		virtual void setLayoutItemGeometry(const sys::Rect& rect);
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual sys::Size getLayoutItemMaxSize();
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

	// ����
	enum Orientation
	{
		// ˮƽ
		EO_Horizontal,
		// ��ֱ
		EO_Vertial,
	};

	/**
	*	������������
	*/
	class LayoutSpacerItem : public LayoutItem
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	���ÿ������
		*/
		void setOrientation(Orientation eType);
		/**
		*	��ȡ�������
		*/
		Orientation getOrientation();
	protected:
		// �������
		Orientation m_eOrientation;
	};

	/**
	*	Ԫ�������Ԫ���ڽ���λ�úʹ�С�趨
	*/
	class LayoutWidgetItem : public LayoutItem
	{
	public:
		LayoutWidgetItem(Widget* widget);
		virtual ~LayoutWidgetItem();
	public:
	};
}