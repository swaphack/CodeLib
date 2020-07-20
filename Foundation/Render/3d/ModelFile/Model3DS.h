#pragma once

#include "ModelFile.h"

#include <string>

namespace render
{
	/**
	*	3ds格式 模型
	*/
	class Model3DS : public ModelFile
	{
	public:
		Model3DS();
		virtual ~Model3DS();
	public:
		bool load(const std::string& filepath);
		bool loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}