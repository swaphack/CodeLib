#pragma once

#include "Common/Node/Node.h"

namespace render
{
	// ά��ģʽ
	enum class CameraDimensions
	{
		TWO,
		THREE
	};

	// �Ӵ�����
	struct ViewParameter
	{
		float xLeft = 0;
		float xRight = 0;
		float yBottom = 0;
		float yTop = 0;
		float zNear = 0.1f;
		float zFar = 1000;
	};

	// �����
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		static Camera* getMainCamera();
		static void setMainCamera(Camera* camera);
	public:
		virtual bool init();
	public:
		// ����ά��
		void setDimensions(CameraDimensions d);
		// ��ȡά��
		CameraDimensions getDimensions() const;
		// ���ƽڵ�
		virtual void drawNode();
	public:
		// �����Ӵ�����
		void setViewPort(float left, float right, float bottom, float top);
		// ������Ұ����
		void setViewDistance(float zNear, float zFar);
		// ��ȡ�Ӵ�����
		const ViewParameter& getViewParameter() const;
		// ��ȡ�Ӵ�����
		const ViewParameter& get2DViewParameter() const;
		// ��ȡ�Ӵ�����
		const ViewParameter& get3DViewParameter() const;
	public:
		// ͶӰ����
		const math::Matrix4x4& getProjectMatrix() const;
		// ��ͼ����
		const math::Matrix4x4& getViewMatrix() const;
	public:
		// ͶӰ����
		math::Matrix4x4 getProjectMatrix(float znear, float zfar);
		// �����׼ָ��λ��
		math::Matrix4x4 lookAt(const math::Vector3& position);
		// �����׼����λ��
		math::Matrix4x4 lookAtCenter();
		// ���ĵ�λ��
		math::Vector3 getCenterPosition();
	public:
		// ���¿ռ�λ��
		virtual void visit();
	protected:
		virtual void updateView();
		// ���¿ռ����
		virtual void startUpdateTranform();
		// ��ת�ռ����
		virtual void endUpdateTranform();
		//�Ӵ���С�����ı�
		virtual void updateViewPort();

		void onCameraSpaceChange();
	protected:
		// ������ͷ
		static Camera* _mainCamera;
		// ά��
		CameraDimensions _dimensions = CameraDimensions::TWO;
		// ͶӰ����
		math::Matrix4x4 _projectMatrix;
		// ��ͼ����
		math::Matrix4x4 _viewMatrix;
		// 2d��Ұ����
		ViewParameter _viewParameter2D;
		// 3D��Ұ����
		ViewParameter _viewParameter3D;
	};
}