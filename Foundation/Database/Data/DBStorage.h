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
	// 数据存储
	// 数据方面
	class DBStorage
	{
	public:
		/*
		*	数组数据的加载
		*	应该包含
		*	1.存储数据的文件路径
		*	2.导出后存放的内存空间
		*/
		template<typename T>
		static void loadDataFromFile(const char* filename, std::vector<T>& datas);

		/*
		*	数组数据的保存
		*	应该包含
		*	1.存储数据的文件路径
		*	2.存储的数据
		*/
		template<typename T>
		static void saveDataToFile(const char* filename, const std::vector<T>& datas);

		/*
		*	字典数据的加载
		*	应该包含
		*	1.存储数据的文件路径
		*	2.导出后存放的内存空间
		*/
		template<typename T>
		static void loadDataFromFile(const char* filename, std::map<int, T>& datas);

		/*
		*	字典数据的保存
		*	应该包含
		*	1.存储数据的文件路径
		*	2.存储的数据
		*/
		template<typename T>
		static void saveDataToFile(const char* filename, const std::map<int, T>& datas);
	public:
		/*
		*	加载表数据配置
		*	@param dbConfigs first=>db name, second=>db filepath
		*/
		static void readDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs);
		/*
		*	保存表数据配置
		*	@param dbConfigs first=>db name, second=>db filepath
		*/
		static void writeDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs);
	public:
		/*
		*	加载表数据
		*/
		static void loadSheetFromFile(const char* filename, DBSheet* sheet);

		/*
		*	保存表数据
		*/
		
		static void saveSheetToFile(const char* filename, const DBSheet* sheet);

		/*
		*	获取表的关键字
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