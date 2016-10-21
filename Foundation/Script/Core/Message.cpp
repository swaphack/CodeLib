#include "Message.h"

using namespace script;

static Message* s_pMessage;

Message::Message()
{

}

Message::~Message()
{

}

Message* Message::getInstance()
{
	if (s_pMessage == nullptr)
	{
		s_pMessage = new Message();
	}

	return s_pMessage;
}

void Message::clear()
{
	m_pTexts.clear();
}

const char* Message::getText(int nID)
{
	std::map<int, std::string>::const_iterator iter = m_pTexts.find(nID);
	if (iter == m_pTexts.end())
	{
		return "";
	}

	return iter->second.c_str();
}

void Message::addText(int nID, const char* text)
{
	if (text == nullptr)
	{
		return;
	}

	m_pTexts[nID] = text;
}