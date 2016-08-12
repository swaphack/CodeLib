#pragma once

#include <string>
#include <vector>
#include <functional>

namespace nature
{
	// 化学式节点
	class ChemNode
	{
	public:
		// 符号
		std::string symbol;
		// 数量
		std::string count;

		// 下一个节点
		std::vector<ChemNode*> next;

		// 内部节点
		ChemNode* inner;
		// 内部节点数量
		std::string innerCount;
	public:
		ChemNode();
		~ChemNode();
	public:
		void foreach(std::function<void(const std::string& symbol, const std::string& number)> func);
		// 销毁
		void disponse();
	};

	// 化学式文档
	class ChemDocument
	{
	public:
		ChemDocument();
		virtual ~ChemDocument();
	public:
		// 获取分子式式的节点表达式
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