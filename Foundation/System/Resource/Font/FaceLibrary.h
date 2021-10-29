#pragma once
#include "Memory/MemoryData.h"
#include <string>
#include "TextDefine.h"
#include "Resource/Image/ImageDetail.h"

namespace sys
{
	class LabelStream;
	class ImageDetail;
	class FontCharDetail;

	/**
	*	单面（固定大小）字体库
	*/ 
	class FaceLibrary
	{
	public:
		FaceLibrary();
		~FaceLibrary();
	public:
		// 初始化FT模块
		bool init(void* lib, const std::string& filepath, int size);
	public:
		void setBorder(bool border);
		bool isBorder() const;
	public:
		// 加载文本
		bool load(const TextDefine& textDefine, LabelStream* stream);
		// 加载字符
		bool load(const TextDefine& textDefine, int& lineHeight, std::map<std::string, FontCharDetail*>& mapData);
		// 获取字符数据
		const FontCharDetail* getCharData(uint64_t ch) const;
		// 获取字符数据
		FontCharDetail* getCharData(uint64_t ch);
		// 释放
		void dispose();
	protected:
		// 加载字符数据
		FontCharDetail* loadChar(uint64_t ch, int fontSize);
	private:
		// 将数据写入流中
		void writeStream(uint64_t ch, LabelStream* stream, const phy::Color3B& color);
	private:
		void* _face = nullptr;
		int	_fontSize = 0;
		bool _border = false;
		std::map<uint64_t, FontCharDetail*> _datas;
	};
}