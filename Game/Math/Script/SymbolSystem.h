#pragma once

#include <string>

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
		void addSymbol(const char* value);
		// �Ƴ�����
		void removeSymbol(const char* value);
		// �Ƿ����˷���
		bool hasSymbol(const char* value);
		// ������з���
		void clearAllSymbols();
	protected:
	private:
	};
}