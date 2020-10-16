#pragma once

#include "Layout/LayoutItemBase.h"
#include "macros.h"

namespace ui
{
	class Layout;

	static const int LAYOUT_SIZE_MIN_WIDTH = 0;
	static const int LAYOUT_SIZE_MIN_HEIGHT = 0;
	static const int LAYOUT_SIZE_MAX_WIDTH = 65536;
	static const int LAYOUT_SIZE_MAX_HEIGHT = 65536;

	/**
	*	������, ������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��Widget�ļ�����Ϣ
	*/
	class LayoutItemEx : public LayoutItemBase
	{
	public:
		LayoutItemEx();
		virtual ~LayoutItemEx();
	public: // �̶����������
		/**
		*	��ȡ��С�������Ϣ
		*/
		const math::Size& getMinSize() const;
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(float width, float height);
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(const math::Size& size);
		/**
		*	��ȡ��󳤿����Ϣ
		*/
		const math::Size& getMaxSize() const;
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(float width, float height);
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(const math::Size& size);
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		const SizePolicy& getSizePolicy() const;
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		void setSizePolicy(const SizePolicy& policy);
	public:
		/**
		*	Ĭ�Ͼ��ο�
		*/
		const math::Rect& getLayoutRect() const;
		/**
		*	Ĭ�Ͼ��ο�
		*/
		void setLayoutRect(const math::Rect& rect);
		/**
		*	Ĭ�Ͼ��ο�
		*/
		void setLayoutRect(const math::Vector2& position, const math::Size& size);
		/**
		*	Ĭ�ϴ�С
		*/
		const math::Size& getGeometry() const;
		/**
		*	Ĭ��λ��
		*/
		const math::Vector2& getPosition() const;
	public: // ���������صķ���
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual math::Size getLayoutMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual math::Size getLayoutMaxSize();
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItemEx* item);
	protected:
		// ���ο�
		math::Rect m_sDefaultRect;
		// ��С���
		math::Size m_sMinSize;
		// ������
		math::Size m_sMaxSize;
		// ��С��������
		SizePolicy m_spAdjust;
	};
}