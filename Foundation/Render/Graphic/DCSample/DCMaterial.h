#pragma once

#include "macros.h"

namespace render
{
	/**
	*	��������
	*/
	class DCMaterial : public DrawCommand
	{
	public:
		// ������
		float Ambient[4];
		// �����
		float Diffuse[4];
		// �����
		float Specular[4];
		// ����ָ��
		float Shiness = 0;
		// �������ɫ
		float Emission[4];
	public:
		DCMaterial();
		virtual ~DCMaterial();
	public:
		virtual void draw();
	public:
		static DCMaterial* create(float* ambient, float* diffuse, float* specular, float shiness, float* emission);
	};
}