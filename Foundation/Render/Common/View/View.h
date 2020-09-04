#pragma once

#include "system.h"

namespace render
{
	// opengl ��ͼ
	class View : public sys::DirtyProtocol
	{
	public:
		View();
		virtual ~View();
	public:
		// �����Ӵ�λ��
		void setPosition(float x, float y);
		// ��ȡ�Ӵ�λ��
		const math::Vector2& getPosition();
		// �����Ӵ���С
		void setFrameSize(float width, float height);
		// ��ȡ�Ӵ���С
		const math::Size& getFrameSize();
	public:
		// ������ͼ
		void initViewPort();
		// Ӧ������
		void applyConfig();
		// ������ͼ
		virtual void updateView();
	protected:
		// �Ӵ�λ��
		math::Vector2 _position;
		// �Ӵ���С
		math::Size _size;
	};
}