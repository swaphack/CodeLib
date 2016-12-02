#pragma once

#include <string>
#include <map>

namespace script
{
	class CodeBlock;

	// 语法分析，程序结构
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