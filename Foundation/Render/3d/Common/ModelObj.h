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
		void load(const std::string& filepath);
		void loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}