#pragma once

#include "text.h"

namespace nature
{
	/**
	*	���ü���
	*/
	class IConfigLoader
	{
	public:
		virtual ~IConfigLoader() {}
	public:
		// ����
		virtual bool load() = 0;
		// �Ƿ����
		virtual bool isLoaded() = 0;
		// ��ȡ����·��
		virtual const char* getConfigPath() = 0;
	};
}