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
		enum class CameraType
		{
			TWO,
			THREE,
			DESIGN,
		};
	public:
		Cameras();
		virtual ~Cameras();
	public:
		// 3d�����
		Camera* getCamera3D() const;
		// 3d�����
		void setCamera3D(Camera* camera);
		// 2d�����
		Camera* getCamera2D() const;
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
	protected:
		void updateViewSize();
		// ���������
		void setCamera(CameraType eType, Camera* camera);
		// ��ȡ�����
		Camera* getCamera(CameraType eType) const;
	private:
		// �����
		std::map<CameraType, Camera*> _cameras;
	private:
		math::Vector4 _viewPort;
	};

#define G_CAMERAS sys::Instance<render::Cameras>::getInstance()
}