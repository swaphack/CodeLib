#pragma once

#include <string>

namespace render
{
	// �����ı�
	class TextProtocol
	{
	public:
		TextProtocol();
		virtual ~TextProtocol();
	public:
		/**
		*	�����ı�����
		*/
		virtual void setString(const std::string& text);
		/**
		*	��ȡ�ı�����
		*/
		const std::string& getString() const;
	private:
		std::string _textBody;
	};
}