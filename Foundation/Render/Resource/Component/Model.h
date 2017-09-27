#pragma once

#include "system.h"

namespace render
{
	// ģ����Դ��ʽ
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
	};

	// 3dģ��
	class Model3D
	{
	public:
		Model3D();
		virtual ~Model3D();
	public:
		// ��ȡͼ���ʽ
		virtual ModelResourceFormat getModelFormat() { return EMRF_NONE; }

		virtual void load(const char* filename);
	protected:
	private:
	};
}