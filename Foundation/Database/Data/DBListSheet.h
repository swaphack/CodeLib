#pragma once

#include <vector>

namespace db
{
	// ������, ����洢
	template<typename _VALUE>
	class DBListSheet
	{
	public:
		DBListSheet();
		virtual ~DBListSheet();
	public:
		// ���һ����¼
		void addRecord(_VALUE value);
		// �Ƴ�һ����¼
		void removeRecord(_VALUE value);
		// �Ƴ�ָ��λ�õļ�¼
		void removeRecord(int index);
		// ��ȡ��¼����������������ڣ�����-1
		int getIndex(_VALUE value);
		// ��ȡָ������λ�õ�ֵ
		const _VALUE* getRecord(int index) const;
		// ��¼����
		int count();
		// �����������
		void clear();
	public:
		typename std::vector<_VALUE> ValueVector;

		ValueVector::iterator begin();
		ValueVector::iterator end();
	private:
		ValueVector _records;
	};

	template<typename _VALUE>
	db::DBListSheet<_VALUE>::DBListSheet()
	{

	}

	template<typename _VALUE>
	db::DBListSheet<_VALUE>::~DBListSheet()
	{
		this->clear();
	}

	template<typename _VALUE>
	void db::DBListSheet<_VALUE>::addRecord( _VALUE value )
	{
		this->_records.push_back(value);
	}

	template<typename _VALUE>
	void db::DBListSheet<_VALUE>::removeRecord( _VALUE value )
	{
		this->_records.erase(value);
	}

	template<typename _VALUE>
	void db::DBListSheet<_VALUE>::removeRecord( int index )
	{
		this->_records.erase(index);
	}

	template<typename _VALUE>
	int db::DBListSheet<_VALUE>::getIndex( _VALUE value )
	{
		int size = this->count();

		for (int i = 0; i != size; i ++)
		{
			if (this->_records[i] == value)
			{
				return i;
			}
		}

		return -1;
	}

	template<typename _VALUE>
	const _VALUE* db::DBListSheet<_VALUE>::getRecord( int index ) const
	{
		if (i < 0 || i >= this->count()) 
		{
			return nullptr;
		}

		return &this->_records[index];
	}

	template<typename _VALUE>
	int db::DBListSheet<_VALUE>::count()
	{
		return this->_records.size();
	}

	template<typename _VALUE>
	void db::DBListSheet<_VALUE>::clear()
	{
		return this->_records.clear();
	}

	template<typename _VALUE>
	ValueVector::iterator db::DBListSheet<_VALUE>::begin()
	{
		return this->_records.begin();
	}

	template<typename _VALUE>
	ValueVector::iterator db::DBListSheet<_VALUE>::end()
	{
		return this->_records.end();
	}

}