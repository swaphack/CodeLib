#include "LabelLibrary.h"
#include "third_party.h"
#include "Base/macros.h"
#include "FaceLibrary.h"
#include "LabelStream.h"

sys::LabelLibrary::LabelLibrary()
{
	this->init();
}

sys::LabelLibrary::~LabelLibrary()
{
	this->dispose();
}

sys::FaceLibrary* sys::LabelLibrary::getFontLibrary(const std::string& filepath, int size)
{
	auto it1 = _fontLibs.find(filepath);
	if (it1 != _fontLibs.end())
	{
		auto it2 = it1->second.find(size);
		if (it2 != it1->second.end())
		{
			return it2->second;
		}
	}

	FaceLibrary* fontLib = new FaceLibrary();
	if (!fontLib->init(_library, filepath, size))
	{
		return nullptr;
	}
	_fontLibs[filepath][size] = fontLib;
	return fontLib;
}

bool sys::LabelLibrary::load(const TextDefine& textDefine, LabelStream* stream)
{
	auto lib = getFontLibrary(textDefine.filepath, textDefine.fontSize);
	if (lib == nullptr)
	{
		return false;
	}

	return lib->load(textDefine, stream);
}

void sys::LabelLibrary::cleanup()
{
	for (auto& item1 : _fontLibs)
	{
		for (auto& item2 : item1.second)
		{
			SAFE_DELETE(item2.second);
		}
	}
	_fontLibs.clear();
}

void sys::LabelLibrary::init()
{
	FT_Library library;
	auto error = FT_Init_FreeType(&library);
	if (error != 0)
	{
		PRINT("ERROR %s, %d", __FILE__, error);
		return;
	}

	_library = library;
}

void sys::LabelLibrary::dispose()
{
	this->cleanup();

	if (_library)
	{
		FT_Library library = (FT_Library)_library;
		FT_Done_FreeType(library);
		_library = nullptr;
	}
}
