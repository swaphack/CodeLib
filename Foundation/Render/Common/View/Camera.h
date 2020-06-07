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
	public:
		// ͶӰ����
		const math::Matrix44& getProjectMatrix() const;
		// ��ͼ����
		const math::Matrix44& getViewMatrix() const;
	public:
		// �����׼ָ��λ��
		math::Matrix44 lookAt(const math::Vector3& position);
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
	protected:
		// ������ͷ
		static Camera* _mainCamera;
		// ά��
		CameraDimensions _dimensions = CameraDimensions::TWO;
		// ͶӰ����
		math::Matrix44 _projectMat;
		// 2d��Ұ����
		ViewParameter _viewParameter2D;
		// 3D��Ұ����
		ViewParameter _viewParameter3D;
	};
}