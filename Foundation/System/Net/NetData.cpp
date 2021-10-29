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

NetData::NetData(const NetData& value)
:NetData(value.data)
{
	
}

NetData::NetData(const MemoryData& value)
{
	this->init((const char*)data.getValue(), data.getLength());
}

uint32_t NetData::getSize() const
{
	return data.getSize();
}

const char* NetData::getPtr() const
{
	return data.getPtr();
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

int32_t NetData::getRemainSize() const
{
	return data.getLength() - pos;
}

const char* NetData::getCursorPtr() const
{
	return data.getPtr(pos);
}



