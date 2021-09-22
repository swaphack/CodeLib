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
		// �����Ӵ���С
		void setViewRect(float x, float y, float width, float height);
	public:
		// �������Ӵ�
		void setSubViewRect(uint32_t index, float x, float y, float width, float height);
		// ��ȡ���Ӵ�
		math::Rect getSubViewRect(uint32_t index) const;
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