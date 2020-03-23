#pragma once

#include "Common/Node/Node.h"
#include "../struct/import.h"

namespace render
{
	// ά��ģʽ
	enum CameraDimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

	// �Ӵ�����
	struct CameraParams
	{
		float xLeft = 0;
		float xRight = 0;
		float yBottom = 0;
		float yTop = 0;
		float zNear = 0;
		float zFar = 0;
	};

	// �����
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		static Camera* getMainCamera();
		static void setMainCamera(CameraDimensions d);
	public:
		virtual bool init();
	public:
		// ��ȡά��
		CameraDimensions getDimensions();
	public:
		// �����Ӵ�����
		void setParams(float left, float right, float bottom, float top, float zNear, float zFar);
		// ��ȡ�Ӵ�����
		const CameraParams& getParams();
	protected:
		// ���¿ռ�λ��
		virtual void updateTranform();
		// ����ά��
		void setDimensions(CameraDimensions d);
	private:
		// ������ͷ
		static Camera* _mainCamera;
		// ά��
		CameraDimensions _dimensions;
		// ����
		CameraParams _cameraParams;
	};

	// 2d ����ͷ
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	};
	// 3d ����ͷ
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
		// �����׼ָ��λ��
		virtual void lookAt(const math::Vector3& position);
	};
}