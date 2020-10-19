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
		/**
		*	��ȡԪ��
		*/
		template<typename T>
		T* getWidget() const
		{
			if (getWidget() == nullptr)
			{
				return nullptr;
			}
			return getWidget()->as<T>();
		}
		/**
		*	���ú����Ƿ�ɼ�
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	�Ƿ������
		*/
		bool containPoint(float x, float y);
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
	};
}