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
		template<typename T, typename = std::enable_if<std::is_base_of<IResourceLoader, T>::value, T>::type>
		static T* load(const std::string& filename)
		{
			T* t = new T();
			t->load(filename);
			return t;
		}
		// ��������
		template<typename T, typename = std::enable_if<std::is_base_of<ILabelLoader, T>::value, T>::type>
		static T* load(const TextDefine& textDefine)
		{
			T* t = new T();
			t->load(textDefine);
			return t;
		}
		// ����ý��
		template<typename T, typename = std::enable_if<std::is_base_of<IMediaLoader, T>::value, T>::type>
		static T* load(const MediaDefine& mediaDefine)
		{
			T* t = new T();
			t->load(mediaDefine);
			return t;
		}
	};	
}