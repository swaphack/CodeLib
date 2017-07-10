#include "Word.h"
using namespace ll;

Word::Word(const Text& value)
{
	_value = value;
	_hashID = s_HashID++;
}

Word::Word(const Text& value, const WordMeaning& meaning)
:Word(value)
{
	_meaning = meaning;
}

int Word::hashID() const
{
	return _hashID;
}

const Text& Word::value() const
{
	return _value;
}

const char Word::index() const
{
	if (empty())
	{
		return 0;
	}

	return _value[0];
}

bool Word::empty() const
{
	return _value.empty();
}

void Word::release()
{

}

