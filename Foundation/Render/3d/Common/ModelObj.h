#pragma once

#include "Model.h"
#include <string>

namespace render
{
	/**
	*	obj格式 模型
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