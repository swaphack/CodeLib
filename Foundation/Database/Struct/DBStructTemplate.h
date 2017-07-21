#pragma once

#include "system.h"
#include "DBTable.h"
#include "DBContent.h"
#include <vector>

namespace db
{
	// ���ݽṹ
	// �����ṹ�Ĵ���
	class DBStructTemplate
	{
	private:
		/*
		* ���������ṹ��ͷ�ļ�
		*
		* @param filename ͷ�ļ�����
		* @param structFileNames �����Ľṹ�ļ�����
		*/
		static void createStructCPPFile(const char* filename, const std::map<std::string, DBTable>& structFiles);

		/*
		* ��ṹ�����ݶ�ȡ
		* �洢�ļ���{ ��ṹ���� }+
		*/
		static void readTableStruct(const char* filename, std::map<std::string, DBTable>& dbTables);

		/*
		* ��ṹ�����ݴ洢
		* �洢�ļ���{ ��ṹ���� }+
		*/
		static void writeTableStruct(const char* filename, const std::map<std::string, DBTable>& dbTables);
	public:
		/*
		* �������ݽṹ
		* 
		*/
		static void createStructCode(std::string headFilename, const DBContent* content);
		/*
		* ����ṹ
		* 
		*/
		static void saveContent(std::string filename, const DBContent* content);
		/*
		* ���ؽṹ
		* 
		*/
		static void loadContent(std::string filename, DBContent* content);
	};
}