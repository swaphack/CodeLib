#pragma once

#include "Model.h"

#include <string>

namespace render
{
	/**
	*	3ds��ʽ ģ��
	*/
	class Model3DS : public Model
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