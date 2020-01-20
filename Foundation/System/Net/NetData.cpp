#include "NetData.h"

using namespace sys;


void NetData::insert(const char* data, int32_t len)
{
	char* newData = StreamHelper::mallocStream(len + size, (char*)data, len);
	memcpy(newData + len, this->data, this->size);

	this->init(newData, len + size);
}

void NetData::init(const char* value, int32_t len)
{
	// ÖØÖÃ
	StreamHelper::freeStream(this->data);
	this->data = StreamHelper::mallocStream(len, (char*)value, len);
	this->size = len;
	this->pos = 0;
}

int32_t NetData::getRemainSize()
{
	return size - pos;
}

const char* NetData::getCursorPtr()
{
	return data + pos;
}

NetData::~NetData()
{
	StreamHelper::freeStream(data);
}

NetData::NetData(const std::string& value) :NetData()
{
	this->init(value.c_str(), value.size());
}

NetData::NetData(const char* value, int32_t len) : NetData()
{
	this->init(value, len);
}

NetData::NetData()
{
	this->data = nullptr;
	this->size = size;
	this->pos = 0;
}
