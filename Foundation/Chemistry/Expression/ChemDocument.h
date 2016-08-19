#pragma once

#include <string>
#include "ChemNode.h"

namespace chem
{
	// 化学式文档
	class ChemDocument
	{
	public:
		ChemDocument();
		virtual ~ChemDocument();
	public:
		// 获取分子式的节点表达式
		ChemNode* loadMolecular(const char* expression);
		// 获取化学公式的表达式
	protected:
		ChemNode* readExpression();
		/**
		*	读取块数据
		*	以"("开始，以")"结束
		*/
		ChemNode* readBlock(bool& endBlock);
		// 读取符号
		bool readSymbol(std::string& symbol);
		// 读取数字
		bool readNumber(std::string& number);
	private:
		char* _cursor;
	};
}