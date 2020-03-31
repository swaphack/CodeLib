#pragma once

#include "system.h"
#include "Common/struct/import.h"
#include "ViewConfig.h"

namespace render
{
	// opengl ��ͼ
	class View : public DirtyProtocol
	{
	public:
		View();
		virtual ~View();
	public:
		const ViewConfig* getConfig();
		// �����Ӵ�λ��
		void setPosition(float x, float y);
		// ��ȡ�Ӵ�λ��
		const math::Vector2& getPosition();
		// �����Ӵ���С
		void setFrameSize(float width, float height);
		// ��ȡ�Ӵ���С
		const math::Size& getFrameSize();
		// ������ͼ
		void initView();
		// ������ͼ
		virtual void updateView();
	protected:
		// Ӧ������
		void applyConfig();
	protected:
		// �Ӵ�λ��
		math::Vector2 _position;
		// �Ӵ���С
		math::Size _size;
		// ��ͼ����
		ViewConfig _viewConfig;
	};
}