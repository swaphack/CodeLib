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
		const sys::Vector2& getPosition();
		// �����Ӵ���С
		void setFrameSize(float width, float height);
		// ��ȡ�Ӵ���С
		const sys::Size& getFrameSize();
		// ���������
		void setCamera(Camera* camera);
		// ��ȡ�����
		Camera* getCamera();
		// �������ű�
		void setScale(float x, float y, float z);
		// ��ȡ���ű�
		sys::Vector3 getScale();
		// ������ͼ
		void initView();
		// ������ͼ
		virtual void updateView();
	protected:
		// �Ӵ�λ��
		sys::Vector2 _position;
		// �Ӵ���С
		sys::Size _size;
		// ��ͼ����
		ViewConfig _viewConfig;
		// �����
		Camera* _camera;
		// �������ű�
		sys::Vector3 _scale;
	};
}