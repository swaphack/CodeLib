#include "LabelImage.h"
#include "system.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#define FREETYPE_PIXEL_UNIT 64
#define RGBA_PIXEL_UNIT 4

using namespace render;


//////////////////////////////////////////////////////////////////////////
// 每个字符存储的数据
struct FT_CHAR_DATA
{
	// 字符bit数据
	char* data;
	// 宽度
	int width;
	// 高度
	int height;

	// 步进宽度
	int advX;
	int advY;

	// 字形原点(0,0)到字形位图最左边象素的水平距离.它以整数象素的形式表示。 
	int deltaX;
	int deltaY;

	FT_CHAR_DATA();
	~FT_CHAR_DATA();

	void printString()
	{
		LOG("width %d, height %d\n", width, height);
		LOG("advX %d, advY %d\n", advX, advY);
		LOG("deltaX %d, deltaY %d\n", deltaX, deltaY);
		LOG("\n");
	}
};

FT_CHAR_DATA::FT_CHAR_DATA()
:data(nullptr)
, width(0)
, height(0)
{

}

FT_CHAR_DATA::~FT_CHAR_DATA()
{
	SAFE_FREE(data);
}

// 文本数据
class FT_LABEL
{
public:
	FT_LABEL();
	~FT_LABEL();
public:
	// 加载文本
	void load(const TextDefine& textDefine, LabelStream* stream);
protected:
	// 获取字符数据
	FT_CHAR_DATA* getCharData(ulong ch);
	// 加载字符数据
	FT_CHAR_DATA* loadChar(ulong ch, int fontSize);
	// 初始化FT模块
	void initFT(const char* filepath, int size);
	// 是否FT模块
	void disposeFT();
private:
	// 讲数据写入流中
	void writeStream(ulong ch, LabelStream* stream);
private:
	FT_Library    _library;
	FT_Face       _face;
	FT_Error      _error;
	int			  _lowY;
	static std::map<ulong, FT_CHAR_DATA> _datas;
};

//////////////////////////////////////////////////////////////////////////
std::map<ulong, FT_CHAR_DATA> FT_LABEL::_datas = std::map<ulong, FT_CHAR_DATA>();

FT_LABEL::FT_LABEL()
: _library(nullptr)
, _face(nullptr)
, _error(0)
, _lowY(0)
{
	
}

FT_LABEL::~FT_LABEL()
{
	
}

void FT_LABEL::load(const TextDefine& textDefine, LabelStream* stream)
{
	this->initFT(textDefine.filepath.c_str(), textDefine.fontSize);

	FT_CHAR_DATA* gData = loadChar(char('g'), textDefine.fontSize);
	if (gData == nullptr)
	{
		return;
	}
	_lowY = gData->deltaY;

	char* text = (char*)textDefine.text.c_str();
	wchar_t* dest = sys::BitHelper::convertToWideChar(text);
	wchar_t* ptr = dest;
	while (*ptr != 0)
	{
		this->loadChar(*ptr, textDefine.fontSize);
		ptr++;
	}

	stream->resetOffset();
	ptr = dest;
	while (*ptr != 0)
	{
		this->writeStream(*ptr, stream);
		ptr++;
	}

	delete (dest);
	this->disposeFT();
	_datas.clear();
}

FT_CHAR_DATA* FT_LABEL::getCharData(ulong ch)
{
	std::map<ulong, FT_CHAR_DATA>::iterator it = _datas.find(ch);
	if (it == _datas.end())
	{
		return nullptr;
	}

	return &it->second;
}

FT_CHAR_DATA* FT_LABEL::loadChar(ulong ch, int fontSize)
{
	FT_CHAR_DATA* data = getCharData(ch);
	if (data != nullptr)
	{
		return data;
	}

	_error = FT_Load_Char(_face, ch, FT_LOAD_RENDER);
	if (_error != 0)
	{
		return nullptr;
	}

	FT_Glyph glyph;
	_error = FT_Get_Glyph(_face->glyph, &glyph);
	if (_error != 0)
	{
		return nullptr;
	}
	_error = FT_Render_Glyph(_face->glyph, FT_RENDER_MODE_LCD);
	if (_error != 0)
	{
		return nullptr;
	}

	FT_BBox bbox;
	FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_PIXELS, &bbox);

	_error = FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
	if (_error != 0)
	{
		return nullptr;
	}
	FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
	FT_Bitmap& bitmap = bitmap_glyph->bitmap;

	if (bitmap.width == 0 || bitmap.rows == 0 || bitmap.buffer == nullptr)
	{
		return nullptr;
	}

	int width = bitmap.width;
	int height = bitmap.rows;

	data = &_datas[ch];
	data->width = width ;
	data->height = height;
	data->advX = _face->glyph->metrics.horiAdvance / 64;
	data->advY = _face->glyph->metrics.vertAdvance / 64;
	data->deltaX = _face->glyph->metrics.horiBearingX / 64;
	data->deltaY = bitmap_glyph->top - height;
	data->data = sys::StreamHelper::mallocStream((char*)bitmap.buffer, width * height);

	data->printString();

	return data;
}

void FT_LABEL::initFT(const char* filepath, int size)
{
	_error = FT_Init_FreeType(&_library);
	if (_error != 0)
	{
		return;
	}

	_error = FT_New_Face(_library, filepath, 0, &_face);
	if (_error != 0)
	{
		return;
	}

	_error = FT_Select_Charmap(_face, FT_ENCODING_UNICODE);
	if (_error != 0)
	{
		return;
	}

	_error = FT_Set_Pixel_Sizes(_face, size, size);
	if (_error != 0)
	{
		return;
	}
}

void FT_LABEL::disposeFT()
{
	if (_face)
	{
		FT_Done_Face(_face);
		_face = nullptr;
	}

	if (_library)
	{
		FT_Done_FreeType(_library);
		_library = nullptr;
	}
}

void FT_LABEL::writeStream(ulong ch, LabelStream* stream)
{
	FT_CHAR_DATA* data = getCharData(ch);
	if (data == nullptr)
	{
		return;
	}

	int width = data->width;
	int height = data->height;

	// 获取rgba数据
	char* pBuf = sys::StreamHelper::mallocStream(width * 4 * height);
	if (pBuf == nullptr)
	{
		return;
	}
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar _vl = data->data[i + width*j];
			if (_vl == 0)
			{
				pBuf[(4 * i + (height - j - 1) * width * 4)] = 0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 1] = 0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 2] = 0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 3] = 0;
			}
			else
			{
				pBuf[(4 * i + (height - j - 1) * width * 4)] = 255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 1] = 255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 2] = 255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 3] = _vl;
			}
		}
	}

	int advX = data->advX;
	int advY = data->advY;
	int deltaX = data->deltaX;
	int deltaY = data->deltaY - _lowY;

	stream->writeLabelBlock(width, height, deltaX, deltaY, advY, pBuf);

	sys::StreamHelper::freeStream(pBuf);
}

//////////////////////////////////////////////////////////////////////////
LabelStream::LabelStream()
:_offsetX(0)
, _offsetY(0)
, _lineHeight(0)
, _lowX(0)
, _lowY(0)
, _heightX(0)
, _heightY(0)
{

}

LabelStream::~LabelStream()
{

}

void LabelStream::resetOffset()
{
	_offsetX = 0;
	_offsetY = 0;
}

void LabelStream::writeLabelBlock(int width, int height, int deltaX, int deltaY, int advY, const char* buffer)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = advY;

	int newW = realWidth + _offsetX > getWidth() ? realWidth + _offsetX : getWidth();
	int newH = realHeight + _offsetY > getHeigth() ? realHeight + _offsetY : getHeigth();

	if (newW > getWidth() || newH > getHeigth())
	{
		this->initStream(newW, newH);
	}

	char* faceData = _data;
	for (int i = 0; i < height; i++)
	{
		memcpy(faceData + (i + _offsetY + deltaY) * _width + _offsetX, buffer + i * realWidth, realWidth);
	}

	_offsetX += realWidth;
}

//////////////////////////////////////////////////////////////////////////
LabelImage::LabelImage()
:_stream(nullptr)
{
	
}

LabelImage::~LabelImage()
{
	SAFE_DELETE(_stream);
}

void LabelImage::load(const TextDefine& textDefine)
{
	SAFE_DELETE(_stream);
	_stream = new LabelStream();

	FT_LABEL* label = new FT_LABEL();
	label->load(textDefine, _stream);
	SAFE_DELETE(label);

	this->setPixels((uchar*)_stream->getData());
	this->setWidth(_stream->getWidth() / 4);
	this->setHeight(_stream->getHeigth());
	this->setFormat(GL_RGBA);
	this->setInternalFormat(4);
}


