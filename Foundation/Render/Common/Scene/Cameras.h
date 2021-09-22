#pragma once

#include "system.h"

namespace render
{
	class Camera;
	class Node;

	/**
	*	�����������
	*/
	class Cameras : public sys::Object
	{
	public:
		Cameras();
		virtual ~Cameras();
	public:
		// 3d�����
		Camera* getCamera3D();
		// 3d�����
		void setCamera3D(Camera* camera);
		// 2d�����
		Camera* getCamera2D();
		// 2d�����
		void setCamera2D(Camera* camera);
		// ���ʱ����ͷ
		void setDesignCamera(Camera* camera);
		// ���ʱ����ͷ
		Camera* getDesignCamera() const;
		// ����ʱ����ͷ
		Camera* getRunningCamera3D() const;
		// �����Ӵ�����
		void setViewPort(float left, float right, float bottom, float top);
	public:
		/**
		*	���Ƴ���
		*/
		void drawScene(Node* scene);
	private:
		// 2d
		Camera* _camera2D = nullptr;
		// 3d
		Camera* _camera3D = nullptr;
		// ���ʱ������ͷ
		Camera* _designCamera = nullptr;
	};

#define G_CAMERAS sys::Instance<Cameras>::getInstance()
}