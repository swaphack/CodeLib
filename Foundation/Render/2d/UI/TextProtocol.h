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
		void setString(const std::string& text);
		const std::string& getString();
	private:
		std::string _textBody;
	};
}