#include "ImageLabel.h"
#include "system.h"
#include "ext-config.h"

#define FREETYPE_PIXEL_UNIT 64
#define RGBA_PIXEL_UNIT 4

using namespace render;


//////////////////////////////////////////////////////////////////////////
// 每个字符存储的数据
struct FT_CHAR_DATA
{
	// 字符bit数据
	char* data;
	// 实际显示面积，宽度
	int width;
	int height;

	// 实际标准面积-步进,宽度
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
	sys::StreamHelper::freeStream(data);
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
	bool initFT(const char* filepath, int size);
	// 是否FT模块
	void disposeFT();
private:
	// 将数据写入流中
	void writeStream(uint64_t ch, LabelStream* stream, const sys::Color3B& color);
private:
	FT_Library    _library;
	FT_Face       _face;
	FT_Error      _error;
	int			  _lowY;
	int			  _fontSize;
	static std::map<uint64_t, FT_CHAR_DATA> _datas;
};

//////////////////////////////////////////////////////////////////////////
std::map<uint64_t, FT_CHAR_DATA> FT_LABEL::_datas = std::map<uint64_t, FT_CHAR_DATA>();

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
	this->clear();
}

bool FT_LABEL::load(const TextDefine& textDefine, LabelStream* stream)
{
	if (!this->initFT(textDefine.filepath.c_str(), (int)textDefine.fontSize))
	{
		return false;
	}

	FT_CHAR_DATA* gData = loadChar(char('g'), (int)textDefine.fontSize);
	if (gData == nullptr)
	{
		return false;
	}
	_lowY = gData->deltaY;
	_fontSize = (int)textDefine.fontSize;
	stream->setLineHeight(gData->advY);
	if (textDefine.text.empty())
	{
		return false;
	}
	char* text = (char*)textDefine.text.c_str();
	int length = -1;
	wchar_t* dest = sys::CharsetHelper::convertToWideChar(text, length);
	if (dest == nullptr || length == -1)
	{
		return false;
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
	data->advX = _face->glyph->metrics.horiAdvance / FREETYPE_PIXEL_UNIT;
	data->advY = _face->glyph->metrics.vertAdvance / FREETYPE_PIXEL_UNIT;
	data->deltaX = _face->glyph->metrics.horiBearingX / FREETYPE_PIXEL_UNIT;
	data->deltaY = bitmap_glyph->top - height;
	data->data = sys::StreamHelper::mallocStream((char*)bitmap.buffer, width * height);

	data->printString();

	return data;
}

bool FT_LABEL::initFT(const char* filepath, int size)
{
	_error = FT_Init_FreeType(&_library);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_New_Face(_library, filepath, 0, &_face);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_Select_Charmap(_face, FT_ENCODING_UNICODE);
	if (_error != 0)
	{
		return false;
	}

	_error = FT_Set_Pixel_Sizes(_face, size, size);
	if (_error != 0)
	{
		return false;
	}

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

void FT_LABEL::writeStream(uint64_t ch, LabelStream* stream, const sys::Color3B& color)
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

	// 获取rgba数据
	uint8_t* pBuf = (uint8_t*)sys::StreamHelper::mallocStream(width * RGBA_PIXEL_UNIT * height);
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
				_vl = data->data[i + width*j];
			}

			uint8_t bit = _vl == 0 ? 0 : 255;
			if (bit == 0)
			{
				memset(pBuf + RGBA_PIXEL_UNIT * i + (height - j - 1) * width * RGBA_PIXEL_UNIT,
					0, RGBA_PIXEL_UNIT);
			}
			else
			{
				uint8_t ary[RGBA_PIXEL_UNIT] = { color.red, color.green, color.blue, bit };
				memcpy(pBuf + RGBA_PIXEL_UNIT * i + (height - j - 1) * width * RGBA_PIXEL_UNIT,
					ary, RGBA_PIXEL_UNIT);
			}
		}
	}

	int deltaY = 0;

	if (data)
	{
		deltaY = data->deltaY - _lowY;
		deltaY = deltaY < 0 ? 0 : deltaY;
	}

	if (deltaY + height > stream->getLineHeight())
	{
		deltaY = stream->getLineHeight() - height;
	}

	if (stream->isFixWidth())
	{
		stream->writeMultiLineBlock(width, height, (char*)pBuf, deltaY);
	}
	else
	{
		stream->writeOneLineBlock(width, height, (char*)pBuf, deltaY);
	}

	sys::StreamHelper::freeStream(pBuf);
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
	_offsetY = 0;
}

void LabelStream::writeOneLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	int newW = realWidth + _offsetX > getWidth() ? realWidth + _offsetX : getWidth();

	if (newW > getWidth())
	{
		this->expendStream(newW, realHeight);
	}

	char* faceData = _data;
	for (int i = 0; i < height; i++)
	{
		memcpy(faceData + (i + _offsetY + deltaY) * _width + _offsetX, buffer + i * realWidth, realWidth);
	}

	_offsetX += realWidth;
}

void LabelStream::writeMultiLineBlock(int width, int height, const char* buffer, int deltaY)
{
	// 实际大小
	int realWidth = width * RGBA_PIXEL_UNIT;
	int realHeight = getLineHeight();

	int newW = realWidth + _offsetX > getWidth() ? realWidth + _offsetX : getWidth();

	if (newW <= getFixWidth())
	{// 可填充
		if (newW > getWidth())
		{
			this->expendStream(newW, getLineHeight());
		}
	}
	else
	{// 换行
		this->writeEndLine();
	}

	char* faceData = _data;
	for (int i = 0; i < height; i++)
	{
		memcpy(faceData + (i + _offsetY + deltaY) * _width + _offsetX, buffer + i * realWidth, realWidth);
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

	this->expendStream(getFixWidth(), getHeigth() + getLineHeight(),1,true);

	_offsetX = 0;
	_offsetY = 0;
}

void LabelStream::writeSpaceLine()
{
	if (isFixWidth() == false)
	{
		return;
	}
	_lineWidthStack.push(_offsetX);
	_lineWidthStack.push(0);
	this->expendStream(getFixWidth(), getHeigth() + 2 * getLineHeight(), 1, true);

	_offsetX = 0;
	_offsetY = 0;
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

	if (ha == EHA_LEFT)
	{// 默认左对齐
		while (!_lineWidthStack.empty())
		{
			_lineWidthStack.pop();
		}
	}
	else if (ha == EHA_CENTER)
	{// 居中对齐
		for (int i = 0; i < count; i++)
		{
			width = _lineWidthStack.top();
			offsetX = (getFixWidth() - width) * 0.5f;
			moveBlock(0, i * getLineHeight(), width, getLineHeight(), offsetX, i * getLineHeight());
			_lineWidthStack.pop();
		}
	}
	else if (ha == EHA_RIGHT)
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

void render::LabelStream::setLineHeight(sys::ss_t val)
{
	_lineHeight = val;
}

sys::ss_t render::LabelStream::getLineHeight() const
{
	return _lineHeight;
}

bool render::LabelStream::isFixWidth()
{
	return _fixWidth != 0;
}

sys::ss_t render::LabelStream::getFixWidth()
{
	return _fixWidth;
}

void render::LabelStream::setFixWidth(sys::ss_t width)
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

void ImageLabel::load(const TextDefine& textDefine)
{
	_stream->setFixWidth((sys::ss_t)textDefine.width * RGBA_PIXEL_UNIT);

	FT_LABEL* label = new FT_LABEL();
	if (!label->load(textDefine, _stream))
	{
		SAFE_DELETE(label);
		return;
	}
	SAFE_DELETE(label);

	if (_stream->isFixWidth())
	{
		_stream->format(textDefine.horizontalAlignment);
	}

	int count = _stream->getWidth() * _stream->getHeigth();
	uint8_t* destPixels = (uint8_t *)malloc(sizeof(uint8_t)* count);
	memcpy(destPixels, _stream->getData(), sizeof(uint8_t)* count);

	this->setPixels(destPixels, _stream->getWidth() / RGBA_PIXEL_UNIT, _stream->getHeigth(), RGBA_PIXEL_UNIT);
	this->setFormat(TexImageDataFormat::RGBA);
	this->setInternalFormat(TexImageInternalFormat::RGBA);

	free(destPixels);
	_stream->clear();
}


