#pragma once

#include "Image/IImageLoader.h"
#include "Font/ILabelLoader.h"
#include "Media/IMediaLoader.h"
#include "Model/IModelLoader.h"

namespace sys
{
	class Loader
	{
	public:
		// �����ļ�
		template<typename T, typename = std::enable_if<std::is_base_of<IImageLoader, T>::value, T>::type>
		static T* loadImage(const std::string& filename)
		{
			T* t = new T();
			if (!t->load(filename))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
		// ����ģ��
		template<typename T, typename = std::enable_if<std::is_base_of<IModelLoader, T>::value, T>::type>
		static T* loadModel(const std::string& filename)
		{
			T* t = new T();
			if (!t->load(filename))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
		// ��������
		template<typename T, typename = std::enable_if<std::is_base_of<ILabelLoader, T>::value, T>::type>
		static T* loadLabel(const TextDefine& filename)
		{
			T* t = new T();
			if (!t->load(filename))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
		// ����ý��
		template<typename T, typename = std::enable_if<std::is_base_of<IMediaLoader, T>::value, T>::type>
		static T* loadMedia(const std::string& fullpath)
		{
			T* t = new T();
			if (!t->load(fullpath))
			{
				delete t;
				return nullptr;
			}
			return t;
		}
	};	
}