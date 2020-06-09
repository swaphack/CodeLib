#pragma once

#include "ModelFile.h"
#include <string>

namespace render
{
	/**
	*	obj格式 模型
	*/
	class ModelObj : public ModelFile
	{
	public:
		ModelObj();
		virtual ~ModelObj();
	public:
		void load(const std::string& filepath);
		void loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}