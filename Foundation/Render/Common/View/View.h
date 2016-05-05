#pragma once

#include "system.h"
#include "ViewConfig.h"
#include "Camera.h"
#include "../GL/import.h"

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
		const sys::Point& getPosition();
		// �����Ӵ���С
		void setFrameSize(float width, float height);
		// ��ȡ�Ӵ���С
		const sys::Size& getFrameSize();
		// ���������
		void setCamera(Camera* camera);
		// ��ȡ�����
		Camera* getCamera();
		// ������ͼ
		void initView();
		// ������ͼ
		virtual void updateView();
	protected:
		// �Ӵ�λ��
		sys::Point _position;
		// �Ӵ���С
		sys::Size _size;
		// ��ͼ����
		ViewConfig _viewConfig;
		// �����
		Camera* _camera;
	};
}