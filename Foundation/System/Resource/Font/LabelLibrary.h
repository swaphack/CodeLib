#pragma once

#include "Base/Instance.h"
#include "TextDefine.h"


namespace sys
{
	class FaceLibrary;
	class LabelStream;
	class ImageDetail;

	/**
	*	�ı���
	*/
	class LabelLibrary
	{
	public:
		LabelLibrary();
		~LabelLibrary();
	public:
		// �����ı�
		bool load(const TextDefine& textDefine, LabelStream* stream);
		// �����ı�
		bool load(const TextDefine& textDefine, std::map<std::string, ImageDetail*>& mapData);
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

#define G_FONT_LIB sys::Instance<sys::LabelLibrary>::getInstance()
}