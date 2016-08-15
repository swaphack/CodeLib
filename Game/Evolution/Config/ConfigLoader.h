#pragma once

#include "IConfigLoader.h"

#include <string>

namespace nature
{
	class ConfigLoader : public IConfigLoader
	{
	public:
		ConfigLoader();
		virtual ~ConfigLoader();
	public:
		// ����
		virtual bool load();
		// �Ƿ����
		virtual bool isLoaded();
		// ��ȡ����·��
		virtual const char* getConfigPath();
	protected:
		void setLoadStatus(bool status);
		void setConfigPath(const char* path);
	private:
		// �Ƿ�������
		bool _bLoaded;
		// ����·��
		std::string _configPath;
	};

	/**
	* Ԫ�����ñ�
	*/
	class ElementConfig : public ConfigLoader
	{
	public:
		ElementConfig();
		virtual ~ElementConfig();
	public:
		virtual bool load();
	};
}