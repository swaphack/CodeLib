#pragma once

#include "Model.h"

namespace render
{
	/**
	*	obj��ʽ ģ��
	*/
	class ModelObj : public Model
	{
	public:
		ModelObj();
		virtual ~ModelObj();
	public:
		void load(const std::string& filepath);
	};
}