#pragma once

#include <string>

#include "Symbol.h"

namespace math
{
	// ����ϵͳ
	class SymbolSystem
	{
	public:
		SymbolSystem();
		virtual ~SymbolSystem();
	public:
		// ��ӷ���
		void addSymbol(Symbol* value);
		// �Ƴ�����
		void removeSymbol(Symbol* value);
		// �Ƿ����˷���
		bool hasSymbol(Symbol* value);
		// ������з���
		void clearAllSymbols();
	protected:
	private:
	};
}