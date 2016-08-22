#pragma once

#include "IConfigLoader.h"

#include <map>
#include <string>

namespace nature
{
	// ���ù���
	class ConfigManager
	{
	private:
		ConfigManager();
		~ConfigManager();
	public:
		static ConfigManager* getInstance();
		static void purgeInstance();
	public:
		// ����������������
		void loadAllDatas();
		// ��Ӽ��ؽӿ�
		void addLoader(const char* name, IConfigLoader* loader);
		// �Ƴ����ؽӿ�
		void removeLoader(const char* name);
		// �Ƴ����м��ؽӿ�
		void removeAllLoaders();
	private:
		static ConfigManager* s_pConfigManager;

		std::map<std::string, IConfigLoader*> _configLoaders;
	};
}