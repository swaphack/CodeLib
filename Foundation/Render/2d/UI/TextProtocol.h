#pragma once

#include <string>

namespace render
{
	// 用于文本
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