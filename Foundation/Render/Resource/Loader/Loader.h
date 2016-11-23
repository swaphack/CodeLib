#pragma once

#include "IResourceLoader.h"
#include "ILabelLoader.h"
#include "IMediaLoader.h"

namespace render
{
	class Loader
	{
	public:
		// 加载文件
		template<typename T>
		static T* load(const char* filename);
		// 加载文字
		template<typename T>
		static T* load(const TextDefine& textDefine);
		// 加载媒体
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