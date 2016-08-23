#pragma once

#include <string>
#include <vector>
#include <map>
#include <cstdlib>

#include "../Struct/import.h"
#include "DBSheet.h"
#include "system.h"

namespace db
{
	// ���ݴ洢
	// ���ݷ���
	class DBStorage
	{
	public:
		/*
		*	�������ݵļ���
		*	Ӧ�ð���
		*	1.�洢���ݵ��ļ�·��
		*	2.�������ŵ��ڴ�ռ�
		*/
		template<typename T>
		static void loadDataFromFile(const char* filename, std::vector<T>& datas);

		/*
		*	�������ݵı���
		*	Ӧ�ð���
		*	1.�洢���ݵ��ļ�·��
		*	2.�洢������
		*/
		template<typename T>
		static void saveDataToFile(const char* filename, const std::vector<T>& datas);

		/*
		*	�ֵ����ݵļ���
		*	Ӧ�ð���
		*	1.�洢���ݵ��ļ�·��
		*	2.�������ŵ��ڴ�ռ�
		*/
		template<typename T>
		static void loadDataFromFile(const char* filename, std::map<int, T>& datas);

		/*
		*	�ֵ����ݵı���
		*	Ӧ�ð���
		*	1.�洢���ݵ��ļ�·��
		*	2.�洢������
		*/
		template<typename T>
		static void saveDataToFile(const char* filename, const std::map<int, T>& datas);
	public:
		/*
		*	���ر���������
		*	@param dbConfigs first=>db name, second=>db filepath
		*/
		static void readDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs);
		/*
		*	�������������
		*	@param dbConfigs first=>db name, second=>db filepath
		*/
		static void writeDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs);
	public:
		/*
		*	���ر�����
		*/
		static void loadSheetFromFile(const char* filename, DBSheet* sheet);

		/*
		*	���������
		*/
		
		static void saveSheetToFile(const char* filename, const DBSheet* sheet);

		/*
		*	��ȡ��Ĺؼ���
		*/
		static int getHashKey(const DBTable* table, DBRecord* record, int defaultKey);
	};

	template<typename T>
	void DBStorage::loadDataFromFile( const char* filename, std::vector<T>& datas )
	{
		if (filename == nullptr)
		{
			return;
		}

		long size = 0;
		char* data = sys::File::read(filename, size);

		if (data == nullptr)
		{
			return;
		}

		StreamReader reader = StreamReader(data, size);
		SAFE_FREE(data);

		size = reader.readInt();
		for (int i = 0; i < size; i++)
		{
			T t = reader.read<T>();
			datas.push_back(t);
		}
	}

	template<typename T>
	void DBStorage::saveDataToFile( const char* filename, const std::vector<T>& datas )
	{
		if (filename == nullptr)
		{
			return;
		}

		StreamWriter writer;
		writer.writeInt(datas.size());

		std::vector<T>::const_iterator iter = datas.begin();
		while (iter != datas.end())
		{
			writer.write<T>((*iter));
			iter++;
		}

		sys::File::write(filename, writer.getData(), writer.getLength());
	}

	template<typename T>
	void DBStorage::loadDataFromFile( const char* filename, std::map<int, T>& datas )
	{
		if (filename == nullptr)
		{
			return;
		}

		long size = 0;
		char* data = sys::File::read(filename, size);
		if (data == nullptr)
		{
			return;
		}

		StreamReader reader = StreamReader(data, size);
		SAFE_FREE(data);

		size = reader.readInt();
		for (int i = 0; i < size; i++)
		{
			int key = reader.readInt();
			T t = reader.read<T>();
			datas[key] = t;
		}		
	}

	template<typename T>
	void DBStorage::saveDataToFile( const char* filename, const std::map<int, T>& datas )
	{
		if (filename == nullptr)
		{
			return;
		}

		StreamWriter writer;

		writer.writeInt(datas.size());
		std::map<int, T>::const_iterator iter = datas.begin();
		while (iter != datas.end())
		{
			writer.writeInt(iter->first);
			writer.write<T>(iter->second);
			iter++;
		}

		sys::File::write(filename, writer.getData(), writer.getLength());
	}
}