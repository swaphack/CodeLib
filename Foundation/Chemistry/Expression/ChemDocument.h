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
		static ChemDocument* getInstance();
		/**
		*	获取分子式的节点表达式
		*	需手动释放返回结果
		*/ 
		ChemNode* loadMolecular(const char* expression);
		// 获取化学公式的表达式
		/**
		*	释放节点
		*/
		void releaseNode();
	protected:
		/**
		*	解析表达式
		*/
		bool readExpression();
		/**
		*	读取块数据
		*	以"("开始，以")"结束
		*/
		CombineNode* readBlock();
		/**
		*	读取块数据
		*	以"("开始，以")"结束
		*/
		CombineNode* readNode();
	private:
		// 读取符号
		bool readSymbol(std::string& symbol);
		// 读取数字
		bool readNumber(std::string& number);
	private:
		// 游标
		char* _cursor;
		// 化学式
		ChemNode* _chemNode;
	};
}