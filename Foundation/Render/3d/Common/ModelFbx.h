#pragma once

#include "ModelFile.h"
#include <string>

namespace render
{
	/**
	*	fbx��ʽ ģ��
	*/
	class ModelFbx : public ModelFile
	{
	public:
		ModelFbx();
		virtual ~ModelFbx();
	public:
		void load(const std::string& filepath);
	};
}