#pragma once

#include "Document.h"

namespace script
{
	// �����ĵ�����
	class WordDocument : public Document
	{
	public:
		WordDocument();
		virtual ~WordDocument();
	public:
		// ����
		virtual bool parse();
	};
}