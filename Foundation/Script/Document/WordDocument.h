#pragma once

#include "Document.h"

namespace script
{
	// 单词文档解析
	class WordDocument : public Document
	{
	public:
		WordDocument();
		virtual ~WordDocument();
	public:
		// 解析
		virtual bool parse();
	};
}