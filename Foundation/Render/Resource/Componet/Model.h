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
	class Model
	{
	public:
		Model();
		virtual ~Model();
	public:
		// ��ȡͼ���ʽ
		virtual ModelResourceFormat getModelFormat() { return EMRF_NONE; }

		virtual void load(const char* filename);
	protected:
	private:
	};
}