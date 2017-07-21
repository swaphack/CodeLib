#pragma once

#include "Console.h"
#include "Message.h"

#include <functional>
#include <vector>

namespace script
{
#define C_INFO(cond, text) Console::getInstance()->info(cond, text);
#define C_WARNING(cond, text) Console::getInstance()->warning(cond, text);
#define C_ERROR(cond, text) Console::getInstance()->error(cond, text);
#define C_DEBUG(cond, text) Console::getInstance()->debug(cond, text);

//////////////////////////////////////////////////////////////////////////
#define GET_TEXT(id) Message::getInstance()->getText(id)

//////////////////////////////////////////////////////////////////////////
class Environment;
Environment* getEnv();

//////////////////////////////////////////////////////////////////////////
class Variable;
typedef std::function<bool(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)> EXPRESSION_HANDLER;

}