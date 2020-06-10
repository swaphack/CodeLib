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
		bool load(const std::string& filepath);
		bool loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback = nullptr);
	};
}