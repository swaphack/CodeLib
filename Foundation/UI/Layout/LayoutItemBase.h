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
		template<typename T, typename = std::enable_if<std::is_base_of<render::CtrlWidget, T>::value, T>::type>
		T* getCastWidget() const
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
	public: 
		/**
		*	�Զ�������С
		*/
		void autoResize();
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItemBase* item);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
	public:
		/**
		*	��ȡ���������
		*/
		const render::RectPoints* getRectPoints() const;
	protected:
		// ������
		render::CtrlWidget* m_pWidget = nullptr;

		// ���ڵ��С
		math::Size m_sParentSize;
	};
}