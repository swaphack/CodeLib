#pragma once

#include <string>

namespace sys
{
	// �ı���
	class IBlockParser
	{
	public:
		// �����ı���
		virtual bool readBlock(char* inPtr, std::string& outData) = 0;
	};

	// ����һ���ı�
	class LineParser : IBlockParser
	{
	public:
		// �����ı���
		virtual bool readBlock(char* inPtr, std::string& outData);
	};
}