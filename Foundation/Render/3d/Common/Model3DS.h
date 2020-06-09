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
		void load(const std::string& filepath);
		void loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}