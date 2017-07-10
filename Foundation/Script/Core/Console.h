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
		// ��Ϣ
		void info(const char* text);
		// ����
		void warning(const char* text);
		// ����
		void error(const char* text);
		// ����
		void debug(const char* text);
		// ��ʾ
		void open();
		// �ر�
		void close();
		// ��ͣ
		void pause();
	};
}