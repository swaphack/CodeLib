#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// �����
	class Camera : public sys::Object,
		public DirtyProtocol,
		public SpaceProtocol,
		public BodyProtocol
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		virtual void updateCamera();
		// �����׼ָ��λ��
		virtual void lookAt(const sys::Vector3& position);
	protected:
		virtual void onSpaceChange();
	protected:
		// �����λ��
		//sys::Vector _position;
		// �������ת�Ƕ�
		//sys::Vector _rotation;
		// ���������
		//sys::Vector _scale;
		// opengl λ��
		sys::Vector3 _obPosition;
	};
	// 2d ����ͷ
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	public:
		// ������ͼ
		virtual void updateCamera();
	};
	// 3d ����ͷ
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
		// ������ͼ
		virtual void updateCamera();
	};
}