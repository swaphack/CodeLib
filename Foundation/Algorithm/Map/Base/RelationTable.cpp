#include "RelationTable.h"

alg::map::RelationTable::RelationTable()
{
}

alg::map::RelationTable::RelationTable(uint32_t count)
{
	this->init(count, count);
}

alg::map::RelationTable::RelationTable(uint32_t column, const uint32_t row)
{
	this->init(column, row);
}

alg::map::RelationTable::~RelationTable()
{
	this->cleanup();
}

void alg::map::RelationTable::setValue(uint32_t i, uint32_t j, uint8_t value)
{
	if (i < _row && j < _column)
	{
		_relation[i * _column + j] = value;
	}
}

uint8_t alg::map::RelationTable::getValue(uint32_t i, uint32_t j) const
{
	if (i < _row && j < _column)
	{
		return _relation[i * _column + j];
	}

	return 0;
}

bool alg::map::RelationTable::getColumnValues(uint32_t column, uint8_t value, std::vector<uint32_t>& relations) const
{
	if (column >= _column)
	{
		return false;
	}

	relations.resize(_row);

	for (size_t i = 0; i < _row; i++)
	{
		if (getValue(i, column) == value)
		{
			relations.push_back(i);
		}
	}

	return relations.size() > 0;
}

bool alg::map::RelationTable::getRowValues(uint32_t row, uint8_t value, std::vector<uint32_t>& relations) const
{
	if (row >= _row)
	{
		return false;
	}

	int startIndex = row * _column;
	relations.resize(_column);
	memcpy(&relations[0], _relation + startIndex, _column * sizeof(uint8_t));
	return true;
}

bool alg::map::RelationTable::equal(uint32_t i, uint32_t j, uint8_t value) const
{
	return getValue(i, j) == value || getValue(j, i) == value;
}

void alg::map::RelationTable::init(uint32_t column, const uint32_t row)
{
	cleanup();
	_column = column;
	_row = row;
	int size = column * row * sizeof(uint8_t);
	if (size == 0) return;
	_relation = (uint8_t*)malloc(size);
	if (_relation != nullptr) memset(_relation, 0, size);
}

void alg::map::RelationTable::cleanup()
{
	if (_relation != nullptr)
	{
		free(_relation);
		_relation = nullptr;
		_column = 0;
		_row = 0;
	}
}

int alg::map::RelationTable::getColumn() const
{
	return _column;
}

int alg::map::RelationTable::getRow() const
{
	return _row;
}
