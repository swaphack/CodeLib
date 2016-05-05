#pragma once

#include "../Tool/import.h"

#include <map>
#include <set>
#include <string>

namespace db
{
	// 数据字段结构
	class DBField
	{
	public:
		DBField();
		~DBField();
	public:
		// 设置字段名称
		void setName(const char* name);
		// 获取字段名称
		const char* getName() const;
		// 设置字段值类型
		void setType(FieldType type);
		// 获取字段值类型
		FieldType getType() const;
		// 设置字段值长度
		void setLength(int length);
		// 获取字段值长度
		int getLength() const;
	protected:
		// 字段名称
		std::string _name;
		// 字段值类型
		FieldType _type;
		// 字段值长度
		int _length;
	};

	//////////////////////////////////////////////////////////////////////////
	// 数据表结构
	class DBTable
	{
	public:
		DBTable();
		~DBTable();
	public:
		// 设置表名称
		void setName(const char* name);
		// 获取表名称
		const char* getName() const;
		// 添加关键字
		void addKey(const char* key);
		// 移除关键字
		void removeKey(const char* key);
		// 清空关键字
		void clearKeys();
		// 获取关键字
		const std::set<std::string>& getKeys() const;
		
		// 添加字段
		void addField(DBField* field);
		// 添加字段，标明是否是关键字
		void addField(const char* name, FieldType type, bool key = false);
		// 添加字段，标明是否是关键字(带有长度，适用于字符串)
		void addField(const char* name, FieldType type, int length, bool key = false);
		// 移除字段
		void removeField(const char* name);
		// 查找字段
		const DBField* getField(const char* name) const;
		// 清空字段
		void clearFields();
		// 获取字段
		const std::map<std::string, DBField*>& getFields() const;
		// 获取顺序存储字段
		const std::vector<DBField*>& getMemoryFields() const;
	protected:
		// 表名称
		std::string _name;
		// 关键字
		std::set<std::string> _keys;
		// 字段
		std::map<std::string, DBField*> _fields;
		// 顺序存储字段
		std::vector<DBField*> _memFields;
	};
}