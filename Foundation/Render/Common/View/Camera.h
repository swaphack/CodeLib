#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// �����
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		void setPosition(float px, float py, float pz);
		const sys::Vector& getPosition();

		void setRotation(float rx, float ry, float rz);
		const sys::Vector& getRotation();

		void setScale(float sx, float sy, float sz);
		const sys::Vector& getScale();

		virtual void updateCamera();
	protected:
		// �����λ��
		sys::Vector _position;
		// �������ת�Ƕ�
		sys::Vector _rotation;
		// ���������
		sys::Vector _scale;
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