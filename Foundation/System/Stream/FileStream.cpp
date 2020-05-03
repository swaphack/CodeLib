#include "FileStream.h"
#include "StreamBase.h"
#include "IO/File.h"
#include "Base/macros.h"

using namespace sys;

FileStream::FileStream()
:Stream(new StreamBaseRef())
{
}

FileStream::FileStream(const std::string& filepath)
:Stream(new StreamBaseRef())
{
	this->load(filepath);
}


FileStream::~FileStream()
{
	SAFE_DELETE(_baseStream);
}

void FileStream::load(const std::string& filepath)
{
	if (filepath.empty())
	{
		return;
	}

	size_t size = 0;
	char* data = File::read(filepath, size);
	if (data == nullptr)
	{
		return;
	}

	this->setData(data, size);
}

void FileStream::save(const std::string& filepath)
{
	if (filepath.empty())
	{
		return;
	}
	size_t writtenSize = 0;
	File::write(filepath, this->getData(), this->getLength(), writtenSize);
}

