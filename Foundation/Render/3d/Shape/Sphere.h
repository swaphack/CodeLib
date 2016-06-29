#pragma once

#include "../macros.h"

namespace render
{
#define SPHERE_HORIZONTAL_COUNT 20
#define SPHERE_VERTICAL_COUNT 20

	// 3dģ�ͻ�������
	class Sphere : public CtrlModel
	{
	public:
		Sphere();
		virtual ~Sphere();
	public:
		virtual void draw();

		// ������뾶
		void setRadius(float radius);
		// ��ȡ��뾶
		float getRadius();
	protected:
		virtual void initSelf();
	private:
		// ��뾶
		float _radius;
	};
}