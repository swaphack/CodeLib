#pragma once
#include "Memory/MemoryData.h"
#include <string>
#include "TextDefine.h"

namespace sys
{
	// 每个字符存储的数据
	struct FT_CHAR_DATA
	{
	public:
		// 实际显示面积，宽度
		int width = 0;
		int height = 0;

		// 实际标准面积-步进,宽度
		int advX = 0;
		int advY = 0;

		// 字形原点(0,0)到字形位图最左边象素的水平距离.它以整数象素的形式表示。 
		int deltaX = 0;
		int deltaY = 0;

		// 字符bit数据
		MemoryData data;
	public:
		FT_CHAR_DATA();
		~FT_CHAR_DATA();
	};

	class LabelStream;

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
	protected:
		// 获取字符数据
		FT_CHAR_DATA* getCharData(uint64_t ch);
		// 加载字符数据
		FT_CHAR_DATA* loadChar(uint64_t ch, int fontSize);
		// 是否FT模块
		void dispose();
	private:
		// 将数据写入流中
		void writeStream(uint64_t ch, LabelStream* stream, const phy::Color3B& color);
	private:
		void* _face = nullptr;
		int	_fontSize = 0;
		bool _border = false;
		std::map<uint64_t, FT_CHAR_DATA> _datas;
	};
}