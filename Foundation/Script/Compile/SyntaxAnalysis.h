#pragma once

#include <string>
#include <map>

namespace script
{
	class CodeBlock;

	// �﷨����������ṹ
	class SyntaxAnalysis
	{
	public:
		SyntaxAnalysis();
		~SyntaxAnalysis();
	public:
	protected:
	private:
		typedef std::map<std::string, CodeBlock> CodeBlocks;
	};
}