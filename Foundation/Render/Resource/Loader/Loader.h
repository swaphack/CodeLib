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
		template<typename T, typename = std::enable_if<std::is_base_of<IResourceLoader, T>::value, T>::type>
		static T* load(const std::string& filename)
		{
			T* t = new T();
			if (!t->load(filename))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
		// 加载文字
		template<typename T, typename = std::enable_if<std::is_base_of<ILabelLoader, T>::value, T>::type>
		static T* load(const TextDefine& textDefine)
		{
			T* t = new T();
			if (!t->load(textDefine))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
		// 加载媒体
		template<typename T, typename = std::enable_if<std::is_base_of<IMediaLoader, T>::value, T>::type>
		static T* load(const MediaDefine& mediaDefine)
		{
			T* t = new T();
			if (!t->load(mediaDefine))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
	};	
}