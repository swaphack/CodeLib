#include "ImageLabel.h"
#include "../extensions.h"
#include "Memory/MemoryData.h"
#include "Text/CharsetHelper.h"
#include "Base/macros.h"
#include <map>
#include <cstdint>
#define FREETYPE_PIXEL_UNIT 64
#define RGBA_PIXEL_UNIT 4

using namespace sys;


//////////////////////////////////////////////////////////////////////////
// 每个字符存储的数据
struct FT_CHAR_DATA
{
	// 字符bit数据
	MemoryData data;
	// 实际显示面积，宽度
	int width = 0;
	int height = 0;

	// 实际标准面积-步进,宽度
	int advX = 0;
	int advY = 0;

	// 字形原点(0,0)到字形位图最左边象素的水平距离.它以整数象素的形式表示。 
	int deltaX = 0;
	int deltaY = 0;

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
:width(0)
, height(0)
{

}

FT_CHAR_DATA::~FT_CHAR_DATA()
{
}

// 文本数据
class FT_LABEL
{
public:
	FT_LABEL();
	~FT_LABEL();
public:
	// 加载文本
	bool load(const TextDefine& textDefine, LabelStream* stream);
	// 清空缓存
	void clear();
protected:
	// 获取字符数据
	FT_CHAR_DATA* getCharData(uint64_t ch);
	// 加载字符数据
	FT_CHAR_DATA* loadChar(uint64_t ch, int fontSize);
	// 初始化FT模块
	bool initFT(const std::string& filepath, int size, bool bBorder = false);
	// 是否FT模块
	void disposeFT();
private:
	// 将数据写入流中
	void writeStream(uint64_t ch, LabelStream* stream, const Color3B& color);
private:
	FT_Library    _library;
	FT_Face       _face;
	FT_Error      _error;
	int	_fontSize = 0;
	bool _border = false;
	static std::map<uint64_t, FT_CHAR_DATA> _datas;
};

//////////////////////////////////////////////////////////////////////////
std::map<uint64_t, FT_CHAR_DATA> FT_LABEL::_datas = std::map<uint64_t, FT_CHAR_DATA>();

FT_LABEL::FT_LABEL()
: _library(nullptr)
, _face(nullptr)
, _error(0)
, _fontSize(0)
{
	
}

FT_LABEL::~FT_LABEL()
{
	this->clear();
}

bool FT_LABEL::load(const TextDefine& textDefine, LabelStream* stream)
{
	if (!this->initFT(textDefine.filepath.c_str(), (int)textDefine.fontSize, textDefine.border))
	{
		return false;
	}

	_fontSize = (int)textDefine.fontSize;
	float scalY = 1.0f * _face->max_advance_height / _face->units_per_EM;
	stream->setLineHeight(ceil(scalY * _fontSize));
	if (textDefine.text.empty())
	{
		return false;
	}
	char* text = (char*)textDefine.text.c_str();
	int length = -1;
	wchar_t* dest = CharsetHelper::convertToWideCharWnd(text, length);
	if (dest == nullptr || length == -1)
	{
		return false;
	}

	uint32_t rect_width = 0;
	uint32_t rect_height = 0;
	bool bFixedWidth = stream->isFixWidth();
	if (bFixedWidth)
	{
		rect_width = stream->getFixWidth();
	}
	rect_height = stream->getLineHeight();

	int offset_width = 0;

 	wchar_t* ptr = dest;
	int offset = 0;
	while (*ptr != 0 && offset < length)
	{
		this->loadChar(*ptr, (int)textDefine.fontSize);

		uint64_t ch = *ptr;
		if (ch == '\n')
		{
			if (bFixedWidth)
			{
				offset_width = 0;
				rect_height += stream->getLineHeight();
			}
			continue;
		}
		FT_CHAR_DATA* data = getCharData(ch);
		int font_width = static_cast<int>(_fontSize * 0.5f);
		int font_height = _fontSize;

		if (data)
		{
			font_width = data->width;
			font_height = data->height;
		}

		font_width *= RGBA_PIXEL_UNIT;
		if (bFixedWidth)
		{
			if (offset_width + font_width > rect_width)
			{
				offset_width = 0;
				rect_height += stream->getLineHeight();
			}
		}
		else
		{
			rect_width += font_width;
		}
		
		offset_width += font_width;

		ptr++;
		offset++;
	}

	stream->initSteam(rect_width * RGBA_PIXEL_UNIT, rect_height, 1);
	stream->resetOffset();
	ptr = dest;
	offset = 0;
	while (*ptr != 0 && offset < length)
	{
		this->writeStream(*ptr, stream, textDefine.color);
		ptr++;
		offset++;
	}

	stream->endStream();

	free (dest);
	this->disposeFT();
	_datas.clear();

	return true;
}

void FT_LABEL::clear()
{
}

FT_CHAR_DATA* FT_LABEL::getCharData(uint64_t ch)
{
	std::map<uint64_t, FT_CHAR_DATA>::iterator it = _datas.find(ch);
	if (it == _datas.end())
	{
		return nullptr;
	}

	return &it->second;
}

FT_CHAR_DATA* FT_LABEL::loadChar(uint64_t ch, int fontSize)
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

	FT_Vector origin;
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

	float scaleY = 1.0f * _face->max_advance_height / _face->units_per_EM;

	data = &_datas[ch];
	data->width = width ;
	data->height = height;
	data->advX = _face->glyph->metrics.horiAdvance / FREETYPE_PIXEL_UNIT;
	data->advY = _face->glyph->metrics.vertAdvance / FREETYPE_PIXEL_UNIT;
	data->deltaX = bbox.xMin;
	data->deltaY = bbox.yMin - _fontSize * _face->descender / _face->units_per_EM * scaleY;
	data->data.init(width * height, (char*)bitmap.buffer);

	if (data->deltaY < 0)
	{
		int a = 1;
	}

	return data;
}

bool FT_LABEL::initFT(const std::string& filepath, int size, bool bBorder)
{
	_error = FT_Init_FreeType(&_library);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_New_Face(_library, filepath.c_str(), 0, &_face);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_Select_Charmap(_face, FT_ENCODING_UNICODE);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_Set_Pixel_Sizes(_face, 0, size);
	if (_error != 0)
	{
		return false;
	}

	_border = bBorder;

	return true;
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

void FT_LABEL::writeStream(uint64_t ch, LabelStream* stream, const Color3B& color)
{
	if (ch == '\n')
	{
		if (stream->isFixWidth())
		{
			stream->writeEndLine();
		}
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

	MemoryData memData(width * RGBA_PIXEL_UNIT * height);

	// 获取rgba数据
	char* pBuf = memData.getPtr();
	if (pBuf == nullptr)
	{
		return;
	}
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uint8_t _vl = 0;
			if (data)
			{
				_vl = data->data.getValue(i + width * j);
			}

			if (_border)
			{
				_vl = 255;
			}

			uint8_t bit = _vl == 0 ? 0 : _vl;
			if (bit == 0)
			{
				uint8_t ary[RGBA_PIXEL_UNIT] = { 0, 0, 0, 0 };
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * width + i), RGBA_PIXEL_UNIT, (char*)ary);
			}
			else
			{
				uint8_t ary[RGBA_PIXEL_UNIT] = { color.red, color.green, color.blue, bit };
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * width + i), RGBA_PIXEL_UNIT, (char*)ary);
			}
		}
	}

	int deltaY = 0;
	if (data)
	{
		deltaY = data->deltaY;
	}
	deltaY = deltaY < 0 ? 0 : deltaY;

	if (stream->isFixWidth())
	{
		stream->writeMultiLineBlock(width, height, (char*)pBuf, deltaY);
	}
	else
	{
		stream->writeOneLineBlock(width, height, (char*)pBuf, deltaY);
	}
}

//////////////////////////////////////////////////////////////////////////
LabelStream::LabelStream()
:_offsetX(0)
, _offsetY(0)
, _lineHeight(0)
, _fixWidth(0)
{

}

LabelStream::~LabelStream()
{

}

void LabelStream::resetOffset()
{
	_offsetX = 0;
	_offsetY = getHeigth() - getLineHeight();
}

void LabelStream::writeOneLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	char* faceData = _data.getPtr();
	for (int i = 0; i < height; i++)
	{
		_data.set((i + _offsetY + deltaY) * _width + _offsetX, realWidth, buffer + i * realWidth);
	}

	_offsetX += realWidth;
}

void LabelStream::writeMultiLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	if (_offsetX + realWidth > getFixWidth())
	{
		this->writeSpaceLine();
	}

	char* faceData = _data.getPtr();
	for (int i = 0; i < height; i++)
	{
		_data.set((i + _offsetY + deltaY) * _width + _offsetX, realWidth, buffer + i * realWidth);
	}

	_offsetX += realWidth;
}

void LabelStream::writeEndLine()
{
	if (isFixWidth() == false)
	{
		return;
	}

	_lineWidthStack.push(_offsetX);

	_offsetX = 0;
	_offsetY -= getLineHeight();
}

void LabelStream::writeSpaceLine()
{
	if (isFixWidth() == false)
	{
		return;
	}
	_lineWidthStack.push(_offsetX);

	_offsetX = 0;
	_offsetY -= getLineHeight();
}

void LabelStream::endStream()
{
	_lineWidthStack.push(_offsetX);
}

void LabelStream::format(HorizontalAlignment ha)
{
	if (_lineWidthStack.empty() || isFixWidth() == false)
	{
		return;
	}

	int count = _heigth / getLineHeight();
	int width = 0;
	int offsetX = 0;

	if (ha == HorizontalAlignment::LEFT)
	{// 默认左对齐
		while (!_lineWidthStack.empty())
		{
			_lineWidthStack.pop();
		}
	}
	else if (ha == HorizontalAlignment::CENTER)
	{// 居中对齐
		for (int i = 0; i < count; i++)
		{
			width = _lineWidthStack.top();
			offsetX = (getFixWidth() - width) * 0.5f;
			offsetX -= offsetX % 4;
			if (offsetX < 0)
			{
				offsetX = 0;
			}
			moveBlock(0, i * getLineHeight(), width, getLineHeight(), offsetX, i * getLineHeight());
			_lineWidthStack.pop();
		}
	}
	else if (ha == HorizontalAlignment::RIGHT)
	{// 右对齐
		for (int i = 0; i < count; i++)
		{
			width = _lineWidthStack.top();
			offsetX = getFixWidth() - width;
			moveBlock(0, i * getLineHeight(), width, getLineHeight(), offsetX, i * getLineHeight());
			_lineWidthStack.pop();
		}
	}
}

void LabelStream::setLineHeight(uint32_t val)
{
	_lineHeight = val;
}

uint32_t LabelStream::getLineHeight() const
{
	return _lineHeight;
}

bool LabelStream::isFixWidth()
{
	return _fixWidth != 0;
}

uint32_t LabelStream::getFixWidth()
{
	return _fixWidth;
}

void LabelStream::setFixWidth(uint32_t width)
{
	_fixWidth = width;
}



//////////////////////////////////////////////////////////////////////////
ImageLabel::ImageLabel()
{
	_stream = new LabelStream();
}

ImageLabel::~ImageLabel()
{
	SAFE_DELETE(_stream);
}

bool ImageLabel::load(const TextDefine& textDefine)
{
	uint32_t fixeWidth = (uint32_t)textDefine.width * RGBA_PIXEL_UNIT;
	if (fixeWidth > 0)
	{
		_stream->setFixWidth(fixeWidth);
	}
	FT_LABEL* label = new FT_LABEL();
	if (!label->load(textDefine, _stream))
	{
		SAFE_DELETE(label);
		return false;
	}
	SAFE_DELETE(label);

	if (_stream->isFixWidth())
	{
		_stream->format(textDefine.horizontalAlignment);
	}

	this->setPixels((uint8_t*)_stream->getData(), _stream->getWidth() / RGBA_PIXEL_UNIT, _stream->getHeigth(), RGBA_PIXEL_UNIT);
	this->setDataFormat(ImageDataFormat::RGBA);

	_stream->clear();

	return true;
}


