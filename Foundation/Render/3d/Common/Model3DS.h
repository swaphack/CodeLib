#pragma once

#include "ModelFile.h"

#include <string>

namespace render
{
	/**
	*	3ds��ʽ ģ��
	*/
	class Model3DS : public ModelFile
	{
	public:
		Model3DS();
		virtual ~Model3DS();
	public:
		void load(const std::string& filepath);
	public:
		//virtual void draw();
	};
}