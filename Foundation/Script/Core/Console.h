#pragma once

namespace script
{
	// ���
	class Console
	{
	private:
		Console();
		virtual ~Console();
	public:
		static Console* getInstance();
	public:
		// ��Ϣ
		void info(bool condition, const char* text);
		// ����
		void warning(bool condition, const char* text);
		// ����
		void error(bool condition, const char* text);
		// ����
		void debug(bool condition, const char* text);
	};
}