#pragma once

#include "macros.h"
#include "ui_common.h"

namespace ui
{
	class Layout;
	/**
	*	������, ������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��CtrlWidget�ļ�����Ϣ
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
		const math::Rect& getGeometry();
		/**
		*	���ü�����Ϣ
		*/
		void setGeometry(const math::Rect& rect);
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
		void setOrgin(const math::Vector2& position);
		/**
		*	��ȡ����λ��
		*/
		math::Vector2 getOrgin();
		/**
		*	���ü������
		*/
		void setSize(float width, float height);
		/**
		*	���ü������
		*/
		void setSize(const math::Size& size);
		/**
		*	��ȡ�������
		*/
		math::Size getSize();
		/**
		*	����Ԫ��
		*/
		void setWidget(render::CtrlWidget* widget);
		/**
		*	��ȡԪ��
		*/
		render::CtrlWidget* getWidget();
		/**
		*	����ê��λ��
		*/
		void setAnchorPoint(const math::Vector2& anchorPoint);
		/**
		*	��ȡê��λ��
		*/
		const math::Vector2& getAnchorPoint() const;
	public: // ���������صķ���
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItem* item);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Rect& rect);
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
		void setWidgetGeomerty(const math::Rect& geometry, const math::Vector2& anchorPoint);
	public:
		void showWidgetInfo();
	protected:
		void calAnchorPoint(float& x, float& y);
	protected:
		// ������Ϣ
		math::Rect m_rGeometry;
		// ê��λ��
		math::Vector2 m_vAnchorPoint;
		// ���ο���ɫ
		sys::Color4B m_cBoxColor;
		// �Ƿ���ʾ���ο�
		bool m_bBoxVisible = false;
		// ������
		render::CtrlWidget* m_pWidget = nullptr;
	};
}