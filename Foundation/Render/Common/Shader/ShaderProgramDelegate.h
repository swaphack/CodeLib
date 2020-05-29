#pragma once

#include <functional>

namespace render
{
	class ShaderProgram;
	class Node;
	class Mesh;

	typedef std::function<void(ShaderProgram* program)> ShaderProgramFunc;

	typedef std::function<void(Node* node, ShaderProgram* program)> ShaderProgramNFunc;

	typedef std::function<void(Node* node, Mesh* mesh, ShaderProgram* program)> ShaderProgramNMFunc;
}
