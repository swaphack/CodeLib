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
	*	��������(World)��λ�ú���ת��Ϣ���ǻ�����������ϵ��,��Ļ��������Ϊ��0��0��,x,y,z��Χ[-1,1]
	*	�۲�����(Eye)����ͼ�й۲�Ļ���ʼ������������ṩ�ģ������������һ������ϵҲ����"Eye Space"�����������ǰ����������ԭ��λ�ã�
	*	�ӿ�����(ViewPort)���ӿ��������Ϸ��ʾ�Ļ�����������ģ�View Port��������������Ϸ��������꣬���½�Ϊ(0,0),���Ͻ�Ϊ��1,1)
	*	��Ļ����(Screen)����Ļ���꿪ʼ�����س��Ϲ�ϵ�ˣ�Ҳ����˵��Ļ����ͷֱ����йأ���Ļ�����½�Ϊ(0,0),�����Ͻ�Ϊ(screen.width,screen.height)
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
		// ͶӰ
		math::Vector3 project(const math::Vector2& worldPoint) const;
		// ��ͶӰ
		math::Vector3 unproject(const math::Vector2& viewPoint) const;

		// ��Ļ����תΪ��ͼ����
		math::Ray convertScreenPointToLocalRay(const math::Vector2& screenPoint) const;
		// ��Ļ����תΪ��ͼ����
		math::Ray convertScreenPointToWorldRay(const math::Vector2& screenPoint) const;
		// ��Ļ����תΪ��ͼ����
		math::Vector3 convertScreenToViewPort(const math::Vector2& screenPoint) const;
		// ��Ļ����תΪ��������
		math::Vector3 convertScreenToWorldPoint(const math::Vector2& screenPoint) const;

		// ��ͼ����תΪ����
		math::Ray convertViewPortPointToRay(const math::Vector3& viewPortPoint) const;
		// ��ͼ����תΪ��������
		math::Vector3 convertViewPortToWorldPoint(const math::Vector3& viewPortPoint) const;
		// ��ͼ����תΪ��Ļ����
		math::Vector3 convertViewPortToScreenPoint(const math::Vector2& viewPortPoint) const;

		// ��������תΪ��ͼ����
		math::Vector3 convertWorldToViewPort(const math::Vector3& worldPoint) const;
		// ��������תΪ��Ļ����
		math::Vector3 convertWorldToScreenPoint(const math::Vector2& worldPoint) const;
	public:
		// ���Ƴ���
		void drawScene(Node* scene);
		// ���¿ռ�λ��
		virtual void visit();
	protected:
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