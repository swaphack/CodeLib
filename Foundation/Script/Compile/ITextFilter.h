#pragma once

namespace script
{
	// ���ʹ��˽ӿ�
	class ITextFilter
	{
	public:
		virtual ~ITextFilter() {}
	public:
		/**
		*	�����Ƿ�ƥ��
		*/
		virtual bool match(const char* text, int& size) = 0;
	};
}