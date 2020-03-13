#include "File3DS.h"
#include "ext-config.h"

using namespace render;

static int log_level = LIB3DS_LOG_INFO;

static long
fileio_seek_func(void *self, long offset, Lib3dsIoSeek origin) {
	FILE *f = (FILE*)self;
	int o;
	switch (origin) {
	case LIB3DS_SEEK_SET:
		o = SEEK_SET;
		break;

	case LIB3DS_SEEK_CUR:
		o = SEEK_CUR;
		break;

	case LIB3DS_SEEK_END:
		o = SEEK_END;
		break;
	}
	return (fseek(f, offset, o));
}


static long
fileio_tell_func(void *self) {
	FILE *f = (FILE*)self;
	return(ftell(f));
}


static size_t
fileio_read_func(void *self, void *buffer, size_t size) {
	FILE *f = (FILE*)self;
	return (fread(buffer, 1, size, f));
}


static size_t
fileio_write_func(void *self, const void *buffer, size_t size) {
	FILE *f = (FILE*)self;
	return (fwrite(buffer, 1, size, f));
}


static void
fileio_log_func(void *self, Lib3dsLogLevel level, int indent, const char *msg)
{
	static const char * level_str[] = {
		"ERROR", "WARN", "INFO", "DEBUG"
	};
	if (log_level >= level) {
		int i;
		printf("%5s : ", level_str[level]);
		for (i = 1; i < indent; ++i) printf("\t");
		printf("%s\n", msg);
	}
}

//////////////////////////////////////////////////////////////////////////
File3DS::File3DS()
{

}

File3DS::~File3DS()
{
	this->cleanup();
}

void File3DS::load(const char* filename)
{
	this->cleanup();

	FILE *file;
	Lib3dsIo io;
	int result;

	file = fopen(filename, "rb");
	if (!file) {
		PRINT("***ERROR***\nFile not found: %s\n", filename);
		return;
	}

	_fileInfo = lib3ds_file_new();

	memset(&io, 0, sizeof(io));
	io.self = file;
	io.seek_func = fileio_seek_func;
	io.tell_func = fileio_tell_func;
	io.read_func = fileio_read_func;
	io.write_func = fileio_write_func;
	//io.log_func = fileio_log_func;

	result = lib3ds_file_read(_fileInfo, &io);

	fclose(file);

	if (!result) {
		PRINT("***ERROR***\nLoading file failed: %s\n", filename);
		this->cleanup();
	}
}

const Lib3dsFile* File3DS::get3dsFile()
{
	return _fileInfo;
}

void File3DS::cleanup()
{
	if (_fileInfo != nullptr)
	{
		lib3ds_file_free(_fileInfo);
		_fileInfo = nullptr;
	}
}
