#pragma once

#include "DBTable.h"

using namespace db;


DBField::DBField()
:_type(EFT_NONE)
,_length(0)
{

}

DBField::~DBField()
{

}

void DBField::setType( FieldType type )
{
	_type = type;
}

FieldType DBField::getType() const
{
	return _type;
}

void DBField::setLength( int length )
{
	_length = length;
}

int DBField::getLength() const
{
	return _length;
}

//////////////////////////////////////////////////////////////////////////
DBTable::DBTable()
{

}

DBTable::~DBTable()
{

}

void DBTable::addKey( const std::string& key )
{
	_keys.insert(key);
}

void DBTable::removeKey( const std::string& key )
{
	_keys.erase(key);
}

void DBTable::clearKeys()
{
	_keys.clear();
}

const std::set<std::string>& DBTable::getKeys() const
{
	return _keys;
}

void DBTable::addField( DBField* field )
{
	ASSERT(field != nullptr);

	_fields[field->getName()] = field;

	_memFields.push_back(field);
}

void DBTable::addField( const std::string& name, FieldType type, bool key )
{
	this->addField(name, type, 0, key);
}

void DBTable::addField( const std::string& name, FieldType type, int length, bool key )
{
	DBField* field = new DBField();
	field->setName(name);
	field->setType(type);
	field->setLength(length);

	this->addField(field);

	if (key == true)
	{
		this->addKey(field->getName());
	}
}

void DBTable::removeField( const std::string& name )
{
	std::map<std::string, DBField*>::const_iterator iter1 = _fields.find(name);
	if (iter1 != _fields.end())
	{
		_fields.erase(iter1);
	}

	std::vector<DBField*>::const_iterator iter2 = _memFields.begin();
	while (iter2 != _memFields.end())
	{
		if ((*iter2)->getName().compare(name) == 0)
		{
			delete (*iter2);
			_memFields.erase(iter2);
			break;
		}
		iter2++;
	}
}

const DBField* DBTable::getField( const std::string& name ) const
{
	std::map<std::string, DBField*>::const_iterator iter = _fields.find(name);

	if (iter != _fields.end())
	{
		return iter->second;
	}

	return nullptr;
}

void DBTable::clearFields()
{
	_fields.clear();

	std::vector<DBField*>::const_iterator iter2 = _memFields.begin();
	while (iter2 != _memFields.end())
	{
		delete (*iter2);
		iter2++;
	}

	_memFields.clear();
}

const std::map<std::string, DBField*>& DBTable::getFields() const
{
	return _fields;
}

const std::vector<DBField*>& DBTable::getMemoryFields() const
{
	return _memFields;
}

