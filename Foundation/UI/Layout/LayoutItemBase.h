#pragma once

#include "system.h"
#include "render.h"

namespace ui
{
	class LayoutItemBase : public sys::Object, public sys::Name
	{
	public:
		LayoutItemBase();
		virtual ~LayoutItemBase();
	public:
		/**
		*	����Ԫ��
		*/
		void setWidget(render::CtrlWidget* widget);
		/**
		*	��ȡԪ��
		*/
		render::CtrlWidget* getWidget() const;
	public: // ������������
	/**
	*	���þ��ο��Ƿ�ɼ�
	*/
		void setBoxVisible(bool status);
		/**
		*	���ο��Ƿ�ɼ�
		*/
		bool isBoxVisible() const;
		/**
		*	���þ��ο���ʾ��ɫ
		*/
		void setBoxColor(const sys::Color4B& color);
		/**
		*	��ȡ���ο���ʾ��ɫ
		*/
		const sys::Color4B& getBoxColor() const;
	public: // ���������صķ���
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItemBase* item);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
	protected:
		// ������
		render::CtrlWidget* m_pWidget = nullptr;
		// ���ο���ɫ
		sys::Color4B m_cBoxColor;
		// �Ƿ���ʾ���ο�
		bool m_bBoxVisible = false;
	};
}