#pragma once

#include "Model.h"
#include <string>

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