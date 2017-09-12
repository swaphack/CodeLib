#pragma once

#include "system.h"
#include "web.h"

#include <vector>
#include <map>
#include <string>

namespace hs
{
	// ���ݿ������
	class DBManager
	{
	private:
		DBManager();
		~DBManager();
	public:
		static DBManager* getInstance();
		/** 
		*	��ʼ��
		*	@param url ���ݿ��ļ���ַ
		*	@param dbType ���ݿ�����
		*/
		bool init(const web::DBAuthor& info, int dbType = 0);
		/**
		*	���ر�
		*	@param readTableNames Ҫ��ȡ�ı�
		*/
		bool load(const std::vector<std::string>& readTableNames);
		/**
		*	���±�����
		*	@param tableName ������
		*	@param conditions �����������ֶ�����ֵ
		*	@param values �ı���ֶ�����ֵ
		*/
		bool update(const char* tableName, const std::map<std::string, std::string>& conditions, const std::map<std::string, std::string>& values);
		/**
		*	��������
		*	@param tableName ������
		*	@param values �ı���ֶ�����ֵ
		*/
		bool insert(const char* tableName, const std::map<std::string, std::string>& values);
		/**
		*	��������
		*	@param tableName ������
		*	@param values ���ҵ��ֶ�����ֵ
		*/
		sys::IDataRecord* find(const char* tableName, const std::map<std::string, std::string>& values);
	protected:
		// ���һ��������
		void addDataSheet(const char* tableName, sys::DataSheet* pDataSheet);
		// �Ƴ�һ��������
		void removeDataSheet(const char* tableName);
		// ��ȡһ��������
		sys::DataSheet* getDataSheet(const char* tableName);
		// �Ƴ����б�����
		void clearDataSheets();
		// ���»���
		bool updateMemory(const char* tableName, const std::map<std::string, std::string>& keys, const std::map<std::string, std::string>& values);
		// ��ӵ�����
		bool insertMemory(const char* tableName, const std::map<std::string, std::string>& values);
	private:
		// ���ݿ�sqlite
		web::DBProxy* _dbProxy;
		// ���ݱ�
		std::map<std::string, sys::DataSheet*> _tableSheet;
	};
}