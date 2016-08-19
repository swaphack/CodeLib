#pragma once

#include <string>
#include <vector>
#include <functional>

namespace chem
{
	// ��ѧʽ�ڵ�
	class ChemNode
	{
	public:
		// ����
		std::string symbol;
		// ����
		std::string count;

		// ��һ���ڵ�
		std::vector<ChemNode*> next;

		// �ڲ��ڵ�
		ChemNode* inner;
		// �ڲ��ڵ�����
		std::string innerCount;
	public:
		ChemNode();
		~ChemNode();
	public:
		void foreach(std::function<void(const std::string& symbol, const std::string& number)> func);
		// ����
		void disponse();
	};
}