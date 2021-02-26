#include "TextProtocol.h"

using namespace ui;
TextProtocol::TextProtocol()
	:_textBody("")
{

}

TextProtocol::~TextProtocol()
{

}

void TextProtocol::setString(const std::string& text)
{
	_textBody = text;
}

const std::string& TextProtocol::getString() const
{
	return _textBody;
}