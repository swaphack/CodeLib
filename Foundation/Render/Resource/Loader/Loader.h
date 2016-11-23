#pragma once

#include "IResourceLoader.h"
#include "ILabelLoader.h"
#include "IMediaLoader.h"

namespace render
{
	class Loader
	{
	public:
		// �����ļ�
		template<typename T>
		static T* load(const char* filename);
		// ��������
		template<typename T>
		static T* load(const TextDefine& textDefine);
		// ����ý��
		template<typename T>
		static T* load(const MediaDefine& mediaDefine);
	};

	template<typename T>
	T* Loader::load(const char* filename)
	{
		T* t = new T();
		t->load(filename);
		return t;
	}

	template<typename T>
	T* Loader::load(const TextDefine& textDefine)
	{
		T* t = new T();
		t->load(textDefine);
		return t;
	}

	template<typename T>
	T* Loader::load(const MediaDefine& mediaDefine)
	{
		T* t = new T();
		t->load(mediaDefine);
		return t;
	}
}