#pragma once

#include "../Tool/import.h"

#include <map>
#include <set>
#include <string>

namespace db
{
	// �����ֶνṹ
	class DBField
	{
	public:
		DBField();
		~DBField();
	public:
		// �����ֶ�����
		void setName(const char* name);
		// ��ȡ�ֶ�����
		const char* getName() const;
		// �����ֶ�ֵ����
		void setType(FieldType type);
		// ��ȡ�ֶ�ֵ����
		FieldType getType() const;
		// �����ֶ�ֵ����
		void setLength(int length);
		// ��ȡ�ֶ�ֵ����
		int getLength() const;
	protected:
		// �ֶ�����
		std::string _name;
		// �ֶ�ֵ����
		FieldType _type;
		// �ֶ�ֵ����
		int _length;
	};

	//////////////////////////////////////////////////////////////////////////
	// ���ݱ�ṹ
	class DBTable
	{
	public:
		DBTable();
		~DBTable();
	public:
		// ���ñ�����
		void setName(const char* name);
		// ��ȡ������
		const char* getName() const;
		// ��ӹؼ���
		void addKey(const char* key);
		// �Ƴ��ؼ���
		void removeKey(const char* key);
		// ��չؼ���
		void clearKeys();
		// ��ȡ�ؼ���
		const std::set<std::string>& getKeys() const;
		
		// ����ֶ�
		void addField(DBField* field);
		// ����ֶΣ������Ƿ��ǹؼ���
		void addField(const char* name, FieldType type, bool key = false);
		// ����ֶΣ������Ƿ��ǹؼ���(���г��ȣ��������ַ���)
		void addField(const char* name, FieldType type, int length, bool key = false);
		// �Ƴ��ֶ�
		void removeField(const char* name);
		// �����ֶ�
		const DBField* getField(const char* name) const;
		// ����ֶ�
		void clearFields();
		// ��ȡ�ֶ�
		const std::map<std::string, DBField*>& getFields() const;
		// ��ȡ˳��洢�ֶ�
		const std::vector<DBField*>& getMemoryFields() const;
	protected:
		// ������
		std::string _name;
		// �ؼ���
		std::set<std::string> _keys;
		// �ֶ�
		std::map<std::string, DBField*> _fields;
		// ˳��洢�ֶ�
		std::vector<DBField*> _memFields;
	};
}