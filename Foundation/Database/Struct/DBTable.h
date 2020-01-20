#pragma once

#include "../Tool/import.h"

#include <map>
#include <set>
#include <string>

namespace db
{
	// �����ֶνṹ
	class DBField : public sys::Name
	{
	public:
		DBField();
		~DBField();
	public:
		// �����ֶ�ֵ����
		void setType(FieldType type);
		// ��ȡ�ֶ�ֵ����
		FieldType getType() const;
		// �����ֶ�ֵ����
		void setLength(int length);
		// ��ȡ�ֶ�ֵ����
		int getLength() const;
	protected:
		// �ֶ�ֵ����
		FieldType _type;
		// �ֶ�ֵ����
		int _length;
	};

	//////////////////////////////////////////////////////////////////////////
	// ���ݱ�ṹ
	class DBTable : public sys::Name
	{
	public:
		DBTable();
		~DBTable();
	public:
		// ��ӹؼ���
		void addKey(const std::string& key);
		// �Ƴ��ؼ���
		void removeKey(const std::string& key);
		// ��չؼ���
		void clearKeys();
		// ��ȡ�ؼ���
		const std::set<std::string>& getKeys() const;
		
		// ����ֶ�
		void addField(DBField* field);
		// ����ֶΣ������Ƿ��ǹؼ���
		void addField(const std::string& name, FieldType type, bool key = false);
		// ����ֶΣ������Ƿ��ǹؼ���(���г��ȣ��������ַ���)
		void addField(const std::string& name, FieldType type, int length, bool key = false);
		// �Ƴ��ֶ�
		void removeField(const std::string& name);
		// �����ֶ�
		const DBField* getField(const std::string& name) const;
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