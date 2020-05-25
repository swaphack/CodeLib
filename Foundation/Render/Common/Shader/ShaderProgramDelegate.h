#pragma once

#include <functional>

namespace render
{
	class ShaderProgram;

	typedef std::function<void(ShaderProgram* program)> ShaderProgramFunc;
}
