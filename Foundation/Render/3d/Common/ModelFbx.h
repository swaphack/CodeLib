#pragma once

#include "Model.h"
#include <string>

namespace render
{
	/**
	*	fbx��ʽ ģ��
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