#pragma once

#include <string>
#include <vector>
#include <functional>

namespace chem
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
}