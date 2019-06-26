#pragma once

#include "Base/Types.h"

namespace sys
{
	class IBlockParser;

	class TextParser
	{
	public:
		TextParser();
	public:
		// ��ӽ�����
		void AddParser(IBlockParser* parser);
		// �Ƴ�������
		void removeParser(IBlockParser* parser);
		// �Ƴ�����������
		void removeAllParsers();
		// ��ȡ����Ϣ
		bool readBlock(char* inPtr, std::vector<std::string>& outData);
	private:
		std::vector<IBlockParser*> _textParsers;
	};
}