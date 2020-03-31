#pragma once

#include "Model.h"
#include <string>

namespace render
{
	/**
	*	fbx格式 模型
	*/
	class ModelFbx : public Model
	{
	public:
		ModelFbx();
		virtual ~ModelFbx();
	public:
		void load(const std::string& filepath);
	};
}