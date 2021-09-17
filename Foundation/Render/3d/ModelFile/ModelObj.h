#pragma once

#include "3d/Common/ModelFile.h"
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
		bool loadAsyn(const std::string& filepath, const LoadedModelCallback& func = nullptr);
	};
}