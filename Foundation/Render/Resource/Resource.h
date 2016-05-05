#pragma once

#include "IResourceLoader.h"

namespace render
{
	class Resource
	{
	public:
		template<typename T>
		static T* load(const char* filename);

		template<typename T>
		static T* load(const TextDefine& textDefine);

		template<typename T>
		static T* load(const MediaDefine& mediaDefine);
	};

	template<typename T>
	T* Resource::load(const char* filename)
	{
		T* t = new T();
		t->load(filename);
		return t;
	}

	template<typename T>
	T* Resource::load(const TextDefine& textDefine)
	{
		T* t = new T();
		t->load(textDefine);
		return t;
	}

	template<typename T>
	T* render::Resource::load(const MediaDefine& mediaDefine)
	{
		T* t = new T();
		t->load(mediaDefine);
		return t;
	}
}