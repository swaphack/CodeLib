#pragma once

#include "ModelFile.h"
#include <string>

namespace render
{
	/**
	*	obj��ʽ ģ��
	*/
	class ModelObj : public ModelFile
	{
	public:
		ModelObj();
		virtual ~ModelObj();
	public:
		bool load(const std::string& filepath);
		bool loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}