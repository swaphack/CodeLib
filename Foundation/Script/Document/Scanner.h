#pragma once

namespace script
{
	class Block;
	class Expression;

	// �ĵ�ɨ����
	class Scanner
	{
	public:
		Scanner();
	public:
		// ���ô����
		void setBlock(Block* block);
		// ����ı�
		bool read(const char* ptr, int size);
	protected:
		// ����
		bool parse();
		// ��ȡ�����
		Block* readBlock();
		// ��ȡ���ʽ
		Expression* readExpression();
	private:
		// �ı�����ָ��
		char* m_pContent;
		// ƫ��λ��
		int m_nOffset;
		// �ı���С
		int m_nSize;
		// �����
		Block* m_pBlock;
	};
}