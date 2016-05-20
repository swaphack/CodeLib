#pragma once

#include "../../Common/common.h"

namespace render
{
	// 3dģ�ͻ�������
	class Sphere : public Node
	{
	public:
		Sphere();
		virtual ~Sphere();
	public:
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