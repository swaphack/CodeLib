#include "DBFileh.h"

using namespace db;

DBFileReader::DBFileReader( const char* filepath )
{
	long size = 0;
	char* data = sys::File::read(filepath, size);
	if (data == nullptr)
	{
		return;
	}

	char* newData = sys::StreamHelper::mallocStream(data, size);
	this->setData(newData, size);
	SAFE_FREE(data);
}

std::string DBFileReader::readDBString()
{
	int size = this->readInt();
	char* data = this->readString(size);
	std::string value = std::string(data, size);

	return value;
}

DBFileReader::~DBFileReader()
{

}

//////////////////////////////////////////////////////////////////////////
DBFileWriter::DBFileWriter()
{

}

DBFileWriter::~DBFileWriter()
{

}

void DBFileWriter::writeDBString(const std::string& value)
{
	this->writeInt(value.size());
	this->writeString(value.c_str());
}

void DBFileWriter::save( const char* filepath )
{
	sys::File::write(filepath, this->getData(), this->getLength());
}