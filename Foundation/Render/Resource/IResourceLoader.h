#pragma once

#include "struct_common.h"

namespace render
{
	// ��Դ���ؽӿ�
	class IResourceLoader
	{
	public:
		virtual ~IResourceLoader(){}
	public:
		virtual void load(const char* filename) = 0;
	};

	// �����ı��ӿ�
	class ILabelLoader
	{
	public:
		virtual ~ILabelLoader() {}
	public:
		virtual void load(const TextDefine& textDefine) = 0;
	};

	// ���ض�ý��
	class IMediaLoader
	{
	public:
		virtual ~IMediaLoader() {}
	public:
		virtual void load(const MediaDefine& mediaDefine) = 0;
	};
}