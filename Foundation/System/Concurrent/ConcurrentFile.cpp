#include "ConcurrentFile.h"

using namespace sys;


ConcurrentFile::ConcurrentFile(const std::string& filepath)
{
	_fptr = fopen(filepath.c_str(), "wb+");
	if (_fptr == nullptr)
	{
		return;
	}

	setReadFunc([this](ReadData* data){
		if (_fptr == nullptr || data->data == nullptr)
		{
			return;
		}
		int32 size = data->size;
		fseek(_fptr, data->offset, SEEK_SET);
		char* buff = (char*)malloc(size * sizeof(char));
		memset(buff, 0, size);
		data->size = fread(buff, size, 1, _fptr);
		memcpy(data->data, buff, size);
		free(buff);
	});

	setWriteFunc([this](WriteData* data) {
		if (_fptr == nullptr || data->data == nullptr || data->size <= 0)
		{
			return;
		}

		fseek(_fptr, 0, SEEK_END);
		fwrite(data->data, data->size, 1, _fptr);
	});
}

ConcurrentFile::~ConcurrentFile()
{
	if (_fptr)
	{
		fclose(_fptr);
	}
}