#pragma once

#include "system.h"

namespace math
{
	class ScriptLoader
	{
	public:
		ScriptLoader();
		virtual ~ScriptLoader();
	public:
		// �����ļ�
		bool loadFile(const char* filepath);
		// �����ַ���
		bool loadString(const char* value);
	protected:
	private:
	};

#define G_SCRIPTLOADER sys::Instance<ScriptLoader>::getInstance()
}