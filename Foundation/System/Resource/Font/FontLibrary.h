#pragma once

#include "Base/Instance.h"
#include "TextDefine.h"


namespace sys
{
	class FaceLibrary;
	class LabelStream;
	class ImageDetail;
	class FontCharDetail;

	/**
	*	�����
	*/
	class FontLibrary
	{
	public:
		FontLibrary();
		~FontLibrary();
	public:
		// �����ı�
		bool load(const TextDefine& textDefine, LabelStream* stream);
		// �����ı�
		bool load(const TextDefine& textDefine, int& lineHeight, std::map<std::string, FontCharDetail*>& mapData);
		// ��ȡ��ĸ��Ϣ
		const FontCharDetail* getCharDetail(const std::string& filepath, int size, uint64_t ch);
		// ���
		void cleanup();
	protected:
		void init();
		// ��ȡ�����
		FaceLibrary* getFontLibrary(const std::string& filepath, int size);

		void dispose();
	private:
		void*  _library = nullptr;
		// �����
		std::map<std::string, std::map<int, FaceLibrary*>> _fontLibs;
	};

#define G_FONT_LIB sys::Instance<sys::FontLibrary>::getInstance()
}