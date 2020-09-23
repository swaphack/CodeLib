#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	// opengl �Ӵ�
	class ViewPort : public sys::DirtyProtocol
	{
	public:
		ViewPort();
		virtual ~ViewPort();
	public:
		// �����Ӵ�λ��
		void setViewPosition(float x, float y);
		// ��ȡ�Ӵ�λ��
		const math::Vector2& getViewPosition() const;
		// �����Ӵ���С
		void setViewSize(float width, float height);
		// ��ȡ�Ӵ���С
		const math::Size& getViewSize() const;
		// �����Ӵ���С
		void setViewRect(float x, float y, float width, float height);

	public:
		// �������Ӵ�
		void setSubViewRect(uint32_t index, float x, float y, float width, float height);
		// ��ȡ���Ӵ�
		math::Rect getSubViewRect(uint32_t index);
	public:
		// ������ͼ
		void initViewPort();
		// Ӧ������
		void applyConfig();
		// ������ͼ
		virtual void updateView();
	protected:
		// ��ͼ���ο�
		math::Rect _viewRect;
		// ����ͼ
		std::map<int, math::Rect> _subViewRect;
	};
}