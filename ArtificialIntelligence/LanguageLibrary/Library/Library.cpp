#include "Library.h"
#include "Dictionary.h"
using namespace ll;

Library::Library()
{
	_dictionary = new Dictionary();
}

Library::~Library()
{
	delete _dictionary;
}

Dictionary* Library::getDictionary()
{
	return _dictionary;
}

