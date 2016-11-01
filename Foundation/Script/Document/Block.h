#pragma once

#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;
	class Expression;
	// �����
	class Block
	{
	public:
		Block();
		virtual ~Block();
	public:
		// ���ÿ�����
		void setName(const char* name);
		// ��ȡ������
		const char* getName();
		// ����ӿ�
		void addBlock(Block* block);
		// ��ȡ�ӿ�
		Block* getBlock(const char* name);
		// �Ƴ��ӿ�
		void removeBlock(const char* name);
		// �Ƴ������ӿ�
		void removeAllBlocks();
		// ��ӱ��ʽ
		void addExpression(Expression* expression);
		// �Ƴ����б��ʽ
		void removeAllExpressions();
	private:
		typedef std::vector<Expression*>  Expressions;
		typedef std::map<std::string, Block*> Blocks;
		// ���ʽ
		Expressions m_pExpressions;
		// �ӿ�
		Blocks m_pBlocks;
		// ����
		std::string m_strName;
	};
}