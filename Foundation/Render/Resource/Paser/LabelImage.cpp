#include "LabelImage.h"
#include "system.h"


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
// 		PRINT("width %d, height %d\n", width, height);
// 		PRINT("advX %d, advY %d\n", advX, advY);
// 		PRINT("deltaX %d, deltaY %d\n", deltaX, deltaY);
// 		PRINT("\n");
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
	// 将数据写入流中
	void writeStream(ulong ch, LabelStream* stream);
private:
	FT_Library    _library;
	FT_Face       _face;
	FT_Error      _error;
	int			  _lowY;
	int			  _fontSize;
	static std::map<ulong, FT_CHAR_DATA> _datas;
};

//////////////////////////////////////////////////////////////////////////
std::map<ulong, FT_CHAR_DATA> FT_LABEL::_datas = std::map<ulong, FT_CHAR_DATA>();

FT_LABEL::FT_LABEL()
: _library(nullptr)
, _face(nullptr)
, _error(0)
, _lowY(0)
, _fontSize(0)
{
	
}

FT_LABEL::~FT_LABEL()
{
	
}

void FT_LABEL::load(const TextDefine& textDefine, LabelStream* stream)
{
	this->initFT(textDefine.filepath.c_str(), (int)textDefine.fontSize);

	FT_CHAR_DATA* gData = loadChar(char('g'), (int)textDefine.fontSize);
	if (gData == nullptr)
	{
		return;
	}
	_lowY = gData->deltaY;
	_fontSize = (int)textDefine.fontSize;

	if (textDefine.text.empty())
	{
		return;
	}
	char* text = (char*)textDefine.text.c_str();
	int length = -1;
	wchar_t* dest = sys::BitHelper::convertToWideChar(text, length);
	if (dest == nullptr || length == -1)
	{
		return;
	}
 	wchar_t* ptr = dest;
	int offset = 0;
	while (*ptr != 0 && offset < length)
	{
		this->loadChar(*ptr, (int)textDefine.fontSize);
		ptr++;
		offset++;
	}

	stream->resetOffset();
	ptr = dest;
	offset = 0;
	while (*ptr != 0 && offset < length)
	{
		this->writeStream(*ptr, stream);
		ptr++;
		offset++;
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

	FT_Vector  origin;
	origin.x = 0;
	origin.y = 0;

	_error = FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, &origin, 1);
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
	if (ch == '\n')
	{
		return;
	}
	FT_CHAR_DATA* data = getCharData(ch);
	int width = static_cast<int>(_fontSize * 0.5f);
	int height = _fontSize;

	if (data)
	{
		width = data->width;
		height = data->height;
	}

	// 获取rgba数据
	uchar* pBuf = (uchar*)sys::StreamHelper::mallocStream(width * 4 * height);
	if (pBuf == nullptr)
	{
		return;
	}
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar _vl = 0;
			if (data)
			{
				_vl = data->data[i + width*j];
			}
			if (_vl == 0)
			{
				pBuf[(4 * i + (height - j - 1) * width * 4)] = (uchar)0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 1] = (uchar)0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 2] = (uchar)0;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 3] = (uchar)0;
			}
			else
			{
				pBuf[(4 * i + (height - j - 1) * width * 4)] = (uchar)255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 1] = (uchar)255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 2] = (uchar)255;
				pBuf[(4 * i + (height - j - 1) * width * 4) + 3] = (uchar)_vl;
			}
		}
	}

	int advX = _fontSize;
	int advY = _fontSize;
	int deltaX = 0;
	int deltaY = 0;

	if (data)
	{
		advX = data->advX;
		advY = data->advY;
		deltaX = data->deltaX;
		deltaY = data->deltaY - _lowY;

		deltaY = deltaY < 0 ? 0 : deltaY;
	}

	if (deltaY + height > advY)
	{
		deltaY = advY - height;
	}

	stream->writeLabelBlock(width, height, deltaX, deltaY, advY, (char*)pBuf);

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


