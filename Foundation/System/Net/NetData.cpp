#include "NetData.h"
#include "Stream/StreamHelper.h"

using namespace sys;

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
	this->pos = 0;
}

sys::NetData::NetData(const NetData& value)
:NetData(value.data)
{
	
}

sys::NetData::NetData(const MemoryData& value)
{
	this->init((const char*)data.getValue(), data.getLength());
}

uint32_t sys::NetData::getSize()
{
	return data.getSize();
}

const char* sys::NetData::getPtr()
{
	return (const char*)data.getPtr();
}

NetData::~NetData()
{
}


void NetData::insert(const char* value, int32_t len)
{
	this->data.insert(this->data.getLength(), len, value);
	pos = 0;
}

void NetData::init(const char* value, int32_t len)
{
	data.init(len, value);

	pos = 0;
}

int32_t NetData::getRemainSize()
{
	return data.getLength() - pos;
}

const char* NetData::getCursorPtr()
{
	return (const char*)data.getPtr(pos);
}



