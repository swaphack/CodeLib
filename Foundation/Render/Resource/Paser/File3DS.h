#pragma once

#include <math.h>
#include "macros.h"

struct Lib3dsFile;

namespace render
{
	class File3DS : public IResourceLoader
	{
	public:
		File3DS();								// ��ʼ�����ݳ�Ա
		virtual ~File3DS();
	public:
		virtual void load(const char* filename);
	public: 
		const Lib3dsFile* get3dsFile();
		void cleanup();
	private:
		Lib3dsFile* _fileInfo = nullptr;
	};
}