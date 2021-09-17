#pragma once

#include "3d/Common/ModelFile.h"
#include <string>

namespace render
{
	/**
	*	fbx格式 模型
	*/
	class ModelFbx : public ModelFile
	{
	public:
		ModelFbx();
		virtual ~ModelFbx();
	public:
		bool load(const std::string& filepath);
		bool loadAsyn(const std::string& filepath, const LoadedModelCallback& func = nullptr);
	};
}