#include "FaceLibrary.h"
#include "third_party.h"
#include "LabelStream.h"
#include "Text/CharsetHelper.h"
#include "Base/macros.h"
#include "Resource/Image/ImageDetail.h"
#include "FontCharDetail.h"

using namespace sys;

#define FREETYPE_PIXEL_UNIT 64
#define RGBA_PIXEL_UNIT 4

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
		FontCharDetail* data = this->loadChar(ch, (int)textDefine.fontSize);
		int font_width = static_cast<int>(_fontSize * 0.5f);
		int font_height = _fontSize;

		if (data)
		{
			font_width = data->getWidth();
			font_height = data->getHeight();
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

bool sys::FaceLibrary::load(const TextDefine& textDefine, int& lineHeight, std::map<std::string, FontCharDetail*>& mapData)
{
	if (_face == nullptr) return false;

	if (textDefine.text.empty())
	{
		return false;
	}
	_border = textDefine.border;
	_fontSize = (int)textDefine.fontSize;

	FT_Face face = (FT_Face)_face;
	float scalY = 1.0f * face->max_advance_height / face->units_per_EM;
	lineHeight = ceil(scalY * _fontSize);

	int length = -1;
	wchar_t* dest = CharsetHelper::convertToWideCharWnd(textDefine.text.c_str(), length);
	if (dest == nullptr || length == -1)
	{
		return false;
	}
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

		FontCharDetail* data = this->loadChar(ch, (int)textDefine.fontSize);
		if (data)
		{
			sys::FontCharDetail* detail = CREATE_OBJECT(sys::FontCharDetail);
			if (detail)
			{
				detail->setAdvance(data->getAdvanceX(), data->getAdvanceY());
				detail->setDelta(data->getDeltaX(), data->getDeltaY());
				detail->setDataFormat(data->getDataFormat());
				detail->setPixels(data->getPtr(0), data->getWidth(), data->getHeight(), ImageDetail::getUnitSize(data->getDataFormat()));
				SAFE_RETAIN(detail);
				mapData[getCString("%ld", ch)] = detail;
			}
			
		}
		ptr++;
		offset++;
	}
	free(dest);
	return true;
}

const FontCharDetail* FaceLibrary::getCharData(uint64_t ch) const
{
	auto it = _datas.find(ch);
	if (it == _datas.end())
	{
		return nullptr;
	}

	return it->second;
}

FontCharDetail* sys::FaceLibrary::getCharData(uint64_t ch)
{
	auto it = _datas.find(ch);
	if (it == _datas.end())
	{
		return nullptr;
	}

	return it->second;
}

FontCharDetail* FaceLibrary::loadChar(uint64_t ch, int fontSize)
{
	if (_face == nullptr) return nullptr;

	FontCharDetail* data = getCharData(ch);
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

	data = CREATE_OBJECT(FontCharDetail);
	data->setDataFormat(sys::ImageDataFormat::RED);
	data->setAdvance(face->glyph->metrics.horiAdvance / FREETYPE_PIXEL_UNIT, face->glyph->metrics.vertAdvance / FREETYPE_PIXEL_UNIT);
	data->setDelta(bbox.xMin, bbox.yMin - _fontSize * face->descender / face->units_per_EM * scaleY);
	data->setPixels(bitmap.buffer, width, height, sys::ImageDetail::getUnitSize(sys::ImageDataFormat::RED));

	if (data->getDeltaY() < 0)
	{
		PRINTLN("Error: deltaY value is < 0");
	}
	data->retain();
	_datas[ch] = data;
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
		PRINTLN("ERROR %s, %d", __FILE__, error);
		return false;
	}
	
	error = FT_Select_Charmap(face, FT_ENCODING_UNICODE);
	if (error != 0)
	{
		PRINTLN("ERROR %s, %d", __FILE__, error);
		return false;
	}

	error = FT_Set_Pixel_Sizes(face, 0, size);
	if (error != 0)
	{
		PRINTLN("ERROR %s, %d", __FILE__, error);
		return false;
	}
	_face = face;
	return true;
}

void FaceLibrary::dispose()
{
	for (auto item : _datas)
	{
		SAFE_RELEASE(item.second);
	}
	_datas.clear();
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
	FontCharDetail* data = getCharData(ch);
	int width = static_cast<int>(_fontSize * 0.5f);
	int height = _fontSize;
	int charWidth = width;
	int deltaX = 0;

	if (data)
	{
		width = data->getWidth();
		height = data->getHeight();

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

	uint8_t ary0[RGBA_PIXEL_UNIT] = { 0, 0, 0, 0 };
	uint8_t ary1[RGBA_PIXEL_UNIT] = { color.getRed(), color.getGreen(), color.getBlue(), 0 };
	uint8_t _vl = 0;
	uint8_t bit = 0;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			_vl = 0;
			if (data) _vl = data->getValue(i + width * j);
			if (_border) _vl = 255;

			bit = _vl == 0 ? 0 : _vl;
			if (bit == 0)
			{
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * charWidth + i + deltaX), RGBA_PIXEL_UNIT, (char*)ary0);
			}
			else
			{
				ary1[3] = bit;
				memData.set(RGBA_PIXEL_UNIT * ((height - j - 1) * charWidth + i + deltaX), RGBA_PIXEL_UNIT, (char*)ary1);
			}
		}
	}

	int deltaY = 0;
	if (data)
	{
		deltaY = data->getDeltaY();
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
