#pragma once

#include "Symbol.h"

namespace math
{
	// ���Ŷ���
	class SymbolDefine
	{
	public:
		SymbolDefine();
		virtual ~SymbolDefine();
	public:
		// ������Ŷ����ַ���
		bool loadString(const char* value);

		const Symbol* getSymbol();
	protected:
	private:
		// ����
		Symbol* _symbol;
		// �����������
		int _inputVarCount;
		// �������ֵ
		float* _inputValue;
		// ������������
		int _outputVarCount;
		// ��������ֵ
		float* _outputValue;
	};
}