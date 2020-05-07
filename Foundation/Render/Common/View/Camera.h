#pragma once

#include "Common/Node/Node.h"

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
		void setViewPortParams(float left, float right, float bottom, float top, float zNear, float zFar);
		// ��ȡ�Ӵ�����
		const CameraParams& getViewPortParams();
	public:
		// ���¿ռ�λ��
		virtual void visit();
	protected:
		virtual void updateView();
		// ���¿ռ����
		virtual void updateTranform();
		// ��ת�ռ����
		virtual void inverseTranform();
		//�Ӵ���С�����ı�
		virtual void updateViewPort();
	protected:
		// ����ά��
		void setDimensions(CameraDimensions d);
	protected:
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
	public:
		virtual void updateView();
	protected:
		//�Ӵ���С�����ı�
		virtual void updateViewPort();
	};
	// 3d ����ͷ
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
		virtual void updateView();
	public:
		// �����׼ָ��λ��
		virtual void lookAt(const math::Vector3& position);
	protected:
		//�Ӵ���С�����ı�
		virtual void updateViewPort();
	};
}