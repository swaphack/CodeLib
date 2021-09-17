#pragma once

#include "Common/Node/Node.h"
#include "DimensionsType.h"
#include "Common/View/ViewParameter.h"
#include "mathlib.h"

namespace render
{
	class Scene;
	class DebugDraw;

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
		// ���Ի���
		DebugDraw* getDebugDraw() const;
		// ��ͼ�����Ƿ���ʾ
		void setViewDrawVisible(bool bVisible);
		// ��ȡ����
		math::Vector3 convertScreenPointToCameraPosition(const math::Vector2& screenPoint) const;
		// ��ȡ������������
		math::Vector3 convertScreenPointToWorldPosition(const math::Vector2& screenPoint) const;
		// ��ȡ����
		math::Ray convertScreenPointToCameraRay(const math::Vector2& screenPoint) const;
		// ��ȡ������������
		math::Ray convertScreenPointToWorldRay(const math::Vector2& screenPoint) const;
		// ����������תΪ��������
		math::Ray convertLocalRayToWorldRay(const math::Ray localRay) const;
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
		// ���Ի���
		DebugDraw* _debugDraw = nullptr;
		// ��ͼ��ת����
		DebugDraw* _viewShapeDraw = nullptr;
	};
}