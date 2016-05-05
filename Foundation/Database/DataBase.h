#pragma once

#include "Data/import.h"
#include "Query/import.h"
#include "Struct/import.h"
#include "Tool/import.h"

#include <string>

namespace db
{
	struct DBConfig
	{
	public:
		// ���ݽṹ�ļ�·��
		std::string dbStructFilepath;
		// ���ʽ�ļ�·��
		std::string dbTableFilepath;
		// �����������ļ�·��
		std::string dbDataFilepath;
		
		DBConfig();

		// ����·������
		void reset();

		// ����·������
		void load(const char* configFilepath);
		// ����·������
		void save(const char* configFilepath);
	};

	class DataBase
	{
	public:
		DataBase();
		virtual ~DataBase();
	public:
		// ��ȡ�����ļ�
		DBConfig* getConfig();
		// ��ȡ���ݿ�����Ŀ¼
		DBContent* getContent();
		// ��ȡ���ݲֿ�
		DBWarehouse* getWarehouse();

		// �������ݿ�
		void loadDB(const char* configFilepath);
		// �������ݿ�
		void loadDB(const DBConfig& dbConfig);
		// ��������
		void saveDB(const char* configFilepath);
	protected:
		// �������ݿ�����Ŀ¼
		void loadContent(const char* filepath);
		// ��������
		void loadData(const char* filepath);
		// �������ݿ�����Ŀ¼
		void saveContent(const char* filepath);
		// ��������
		void saveData(const char* filepath);
	private:
		// �����ļ�
		DBConfig _config;
		// ���ݿ�����Ŀ¼
		DBContent _content;
		// ���ݲֿ�
		DBWarehouse _warehouse;
	};
}