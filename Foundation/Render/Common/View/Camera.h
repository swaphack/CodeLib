#pragma once

#include "Common/Node/Node.h"
#include "DimensionsType.h"
#include "ViewParameter.h"

namespace render
{
	class Scene;

	/**
	*	�����
	*	ͶӰ����[-1, 1]
	*/
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		virtual bool init();
	public:
		// ����ά��
		void setDimensions(DimensionsType d);
		// ��ȡά��
		DimensionsType getDimensions() const;
		// ���ƽڵ�
		void updateCameraView();
	public:
		// �����Ӵ�����
		void setViewPort(float left, float right, float bottom, float top);
		// ������Ұ����
		void setViewDistance(float zNear, float zFar);
		// ��ȡ�Ӵ�����
		const ViewParameter& getViewParameter() const;
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
		// ��ȡ����
		math::Ray getRayFromScreenPoint(const math::Vector2& screenPoint) const;
	public:
		// ���Ƴ���
		void drawScene(Node* scene);
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
		// ά��
		DimensionsType _dimensions = DimensionsType::TWO;
		// ͶӰ����
		math::Matrix4x4 _projectMatrix;
		// ��ͼ����
		math::Matrix4x4 _viewMatrix;
		// 2d��Ұ����
		ViewParameter _viewParameter;
	};
}