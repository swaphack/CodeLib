#pragma once

#include "system.h"

#include <vector>
#include <map>
#include <string>

namespace web
{
	class DBProxy
	{
	public:
		DBProxy(sys::IDataBase* db);
		~DBProxy();
	public:
		/** 
		*	���ر�����
		*	@param readTableNames Ҫ��ȡ�ı����� {�������ؼ���}
		*	@param tableSheet �����󻺴�ĵط�
		*/
		bool load(const std::map<std::string, std::string>& readTableNames, std::map<std::string, sys::DataSheet*>& tableSheet);
		/**
		*	��������
		*	@param tableName ������
		*	@param values �ı���ֶ�����ֵ
		*/
		bool insert(const std::string& tableName, const std::map<std::string, std::string>& values);
		/**
		*	ɾ������
		*	@param tableName ������
		*	@param conditions ����{�ֶ�����ֵ}
		*/
		bool del(const std::string& tableName, const std::map<std::string, std::string>& conditions);
		/**
		*	���±�����
		*	@param tableName ������
		*	@param conditions ����{�ֶ�����ֵ}
		*	@param values �ı���ֶ�����ֵ
		*/
		bool update(const std::string& tableName, const std::map<std::string, std::string>& conditions, const std::map<std::string, std::string>& values);
		/**
		*	���±�����
		*	@param strSQL sql���
		*	@param pDataSheet �洢�ص�����
		*/
		bool exec(const std::string& strSQL, sys::IDataSheet* pDataSheet = nullptr);
	private:
		sys::IDataBase* _db;
	};
}