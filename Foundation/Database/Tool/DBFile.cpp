#include "DBFile.h"

using namespace db;

DBFileReader::DBFileReader()
{
}

std::string DBFileReader::readDBString()
{
	int size = this->readInt32();
	char* data = this->readString(size);
	std::string value = std::string(data, size);

	return value;
}

bool DBFileReader::load(const char* filepath)
{
	int64_t size = 0;
	char* data = sys::File::read(filepath, size);
	if (data == nullptr)
	{
		return false;
	}
	this->setData(data, size);
	return true;
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
	this->writeInt32(value.size());
	this->writeString(value.c_str());
}

bool DBFileWriter::save(const char* filepath)
{
	int64_t writtenSize;
	return sys::File::write(filepath, this->getData(), this->getLength(), writtenSize);
}