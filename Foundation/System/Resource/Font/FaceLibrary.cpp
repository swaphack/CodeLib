#include "FaceLibrary.h"
#include "third_party.h"
#include "LabelStream.h"
#include "Text/CharsetHelper.h"
#include "Base/macros.h"
#include "Resource/Image/ImageDetail.h"

using namespace sys;

#define FREETYPE_PIXEL_UNIT 64
#define RGBA_PIXEL_UNIT 4

sys::FT_CHAR_DATA::FT_CHAR_DATA()
{
}

sys::FT_CHAR_DATA::~FT_CHAR_DATA()
{
}
//////////////////////////////////////////////////////////////////////////
FaceLibrary::FaceLibrary()
	:  _face(nullptr)
	, _fontSize(0)
{

}

FaceLibrary::~FaceLibrary()
{
	this->dispose();
	_datas.clear();
}

void sys::FaceLibrary::setBorder(bool border)
{
	_border = border;
}

bool sys::FaceLibrary::isBorder() const
{
	return _border;
}

bool FaceLibrary::load(const TextDefine& textDefine, LabelStream* stream)
{
	if (_face == nullptr) return false;

	_border = textDefine.border;
	_fontSize = (int)textDefine.fontSize;

	FT_Face face = (FT_Face)_face;
	float scalY = 1.0f * face->max_advance_height / face->units_per_EM;
	stream->setLineHeight(ceil(scalY * _fontSize));
	if (textDefine.text.empty())
	{
		return false;
	}
	int length = -1;
	wchar_t* dest = CharsetHelper::convertToWideCharWnd(textDefine.text.c_str(), length);
	if (dest == nullptr || length == -1)
	{
		return false;
	}

	uint32_t rect_width = 0;
	uint32_t rect_height = 0;

	bool bFixedWidth = stream->isFixedWidth();
	if (bFixedWidth) 
		rect_width = stream->getFixedWidth();

	rect_height = stream->getLineHeight();

	wchar_t* ptr = dest;
	int offset_width = 0;
	int offset = 0;

	while (*ptr != 0 && offset < length)
	{
		uint64_t ch = *ptr;
		if (ch == '\n')
		{
			if (bFixedWidth)
			{
				offset_width = 0;
				rect_height += stream->getLineHeight();
			}
			ptr++;
			offset++;
			continue;
		}
		FT_CHAR_DATA* data = this->loadChar(ch, (int)textDefine.fontSize);
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

	stream->initSteam(rect_width, rect_height, 1);
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

	free(dest);

	return true;
}

bool sys::FaceLibrary::load(const TextDefine& textDefine, std::map<std::string, ImageDetail*>& mapData)
{
	if (_face == nullptr) return false;

	if (textDefine.text.empty())
	{
		return false;
	}
	int length = -1;
	wchar_t* dest = CharsetHelper::convertToWideCharWnd(textDefine.text.c_str(), length);
	if (dest == nullptr || length == -1)
	{
		return false;
	}
	_fontSize = (int)textDefine.fontSize;
	wchar_t* ptr = dest;
	int offset = 0;
	while (*ptr != 0 && offset < length)
	{
		uint64_t ch = *ptr;
		if (ch == '\n')
		{
			ptr++;
			offset++;
			continue;
		}

		FT_CHAR_DATA* data = this->loadChar(ch, (int)textDefine.fontSize);
		if (data)
		{
			sys::ImageDetail* detail = new sys::ImageDetail();
			detail->setDataFormat(sys::ImageDataFormat::RED);
			detail->setPixels(data->data, data->width, data->height, 1);
			mapData[getCString("%ld", ch)] = detail;
		}
		ptr++;
		offset++;
	}
	free(dest);
	return true;
}

FT_CHAR_DATA* FaceLibrary::getCharData(uint64_t ch)
{
	auto it = _datas.find(ch);
	if (it == _datas.end())
	{
		return nullptr;
	}

	return &it->second;
}

FT_CHAR_DATA* FaceLibrary::loadChar(uint64_t ch, int fontSize)
{
	if (_face == nullptr) return nullptr;

	FT_CHAR_DATA* data = getCharData(ch);
	if (data != nullptr)
	{
		return data;
	}
	FT_Face face = (FT_Face)_face;
	auto error = FT_Load_Char(face, ch, FT_LOAD_RENDER);
	if (error != 0)
	{
		return nullptr;
	}

	FT_Glyph glyph;
	error = FT_Get_Glyph(face->glyph, &glyph);
	if (error != 0)
	{
		return nullptr;
	}
	error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_LCD);
	if (error != 0)
	{
		return nullptr;
	}

	FT_BBox bbox;
	FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_PIXELS, &bbox);

	FT_Vector origin;
	origin.x = 0;
	origin.y = 0;

	error = FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, &origin, 1);
	if (error != 0)
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

	float scaleY = 1.0f * face->max_advance_height / face->units_per_EM;

	data = &_datas[ch];
	data->width = width;
	data->height = height;
	data->advX = face->glyph->metrics.horiAdvance / FREETYPE_PIXEL_UNIT;
	data->advY = face->glyph->metrics.vertAdvance / FREETYPE_PIXEL_UNIT;
	data->deltaX = bbox.xMin;
	data->deltaY = bbox.yMin - _fontSize * face->descender / face->units_per_EM * scaleY;
	data->data.init(width * height, (char*)bitmap.buffer);

	if (data->deltaY < 0)
	{
		PRINT("Error: deltaY value is < 0");
	}

	return data;
}

bool FaceLibrary::init(void* lib, const std::string& filepath, int size)
{
	if (lib == nullptr || filepath.empty() || size == 0)
	{
		return false;
	}

	FT_Face face = nullptr;
	auto error = FT_New_Face((FT_Library)lib, filepath.c_str(), 0, &face);
	if (error != 0)
	{
		PRINT("ERROR %s, %d", __FILE__, error);
		return false;
	}
	
	error = FT_Select_Charmap(face, FT_ENCODING_UNICODE);
	if (error != 0)
	{
		PRINT("ERROR %s, %d", __FILE__, error);
		return false;
	}

	error = FT_Set_Pixel_Sizes(face, 0, size);
	if (error != 0)
	{
		PRINT("ERROR %s, %d", __FILE__, error);
		return false;
	}
	_face = face;
	return true;
}

void FaceLibrary::dispose()
{
	if (_face)
	{
		FT_Face face = (FT_Face)_face;
		FT_Done_Face(face);
		_face = nullptr;
	}
}

void FaceLibrary::writeStream(uint64_t ch, LabelStream* stream, const phy::Color3B& color)
{
	if (stream == nullptr) return;

	if (ch == '\n')
	{
		if (stream->isFixedWidth())
		{
			stream->writeEndLine();
		}
		return;
	}
	FT_CHAR_DATA* data = getCharData(ch);
	int width = static_cast<int>(_fontSize * 0.5f);
	int height = _fontSize;
	int charWidth = width;
	int deltaX = 0;

	if (data)
	{
		width = data->width;
		height = data->height;

		charWidth = width;
		deltaX = 0;
	}

	MemoryData memData(charWidth * RGBA_PIXEL_UNIT * height);

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
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * charWidth + i + deltaX), RGBA_PIXEL_UNIT, (char*)ary);
			}
			else
			{
				uint8_t ary[RGBA_PIXEL_UNIT] = { color.getRed(), color.getGreen(), color.getBlue(), bit };
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * charWidth + i + deltaX), RGBA_PIXEL_UNIT, (char*)ary);
			}
		}
	}

	int deltaY = 0;
	if (data)
	{
		deltaY = data->deltaY;
	}
	deltaY = deltaY < 0 ? 0 : deltaY;

	if (stream->isFixedWidth())
	{
		stream->writeMultiLineBlock(charWidth, height, (char*)pBuf, deltaY);
	}
	else
	{
		stream->writeOneLineBlock(charWidth, height, (char*)pBuf, deltaY);
	}
}
