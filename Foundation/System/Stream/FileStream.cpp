#include "FileStream.h"
#include "StreamBase.h"

#include "Base/import.h"

using namespace sys;

FileStream::FileStream()
:Stream(new StreamBaseRef())
{
}

FileStream::FileStream(const char* filepath)
:Stream(new StreamBaseRef())
{
	this->load(filepath);
}


FileStream::~FileStream()
{
	SAFE_DELETE(_baseStream);
}

void FileStream::load(const char* filepath)
{
	if (filepath == nullptr)
	{
		return;
	}

	int64_t size = 0;
	char* data = File::read(filepath, size);
	if (data == nullptr)
	{
		return;
	}

	this->setData(data, size);
}

void FileStream::save(const char* filepath)
{
	if (filepath == nullptr)
	{
		return;
	}
	int64_t writtenSize = 0;
	File::write(filepath, this->getData(), this->getLength(), writtenSize);
}

