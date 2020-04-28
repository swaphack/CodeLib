#pragma once

#include "ShaderVariable.h"

namespace render
{
	class ShaderUniformBlock : public ShaderVariable
	{
	public:
		ShaderUniformBlock();
		virtual ~ShaderUniformBlock();
	public:
		void initUniformBlock();
	public:
		void setValue(const std::string& name, void* data);
	protected:
		void clearData();
	private:
		int _blockSize = 0;
		char* _blockData = nullptr;

		int _indexCount = 0;
		uint32_t* _indices = nullptr;
		int* _offsets = nullptr;
		int* _sizes = nullptr;
		int* _types = nullptr;
	};
}