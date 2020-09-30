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
		/**
		*	设置文本内容
		*/
		virtual void setString(const std::string& text);
		/**
		*	获取文本内容
		*/
		const std::string& getString() const;
	private:
		std::string _textBody;
	};
}