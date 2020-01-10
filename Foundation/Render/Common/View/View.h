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
		const math::Vector2& getPosition();
		// �����Ӵ���С
		void setFrameSize(float width, float height);
		// ��ȡ�Ӵ���С
		const math::Size& getFrameSize();
		// ���������
		void setCamera(Camera* camera);
		// ��ȡ�����
		Camera* getCamera();
		// �������ű�
		void setScale(float x, float y, float z);
		// ��ȡ���ű�
		math::Vector3 getScale();
		// ������ͼ
		void initView();
		// ������ͼ
		virtual void updateView();
	protected:
		// �Ӵ�λ��
		math::Vector2 _position;
		// �Ӵ���С
		math::Size _size;
		// ��ͼ����
		ViewConfig _viewConfig;
		// �����
		Camera* _camera;
		// �������ű�
		math::Vector3 _scale;
	};
}