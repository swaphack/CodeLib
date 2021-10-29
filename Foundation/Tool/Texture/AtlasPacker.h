#pragma once

#include <string>
#include <set>
#include <map>

#include "mathlib.h"
#include "system.h"

namespace tool
{
	// ������
	class AtlasPacker
	{
	public:
		AtlasPacker();
		virtual ~AtlasPacker();
	public:
		/**
		*	���ô�С
		*/
		void setSize(int width, int height);
		/**
		*	��ȡ���
		*/
		int getWidth() const;
		/**
		*	��ȡ�߶�
		*/
		int getHeight() const;
		/**
		*	y�ᷴ��
		*/
		void setReverseY(bool reverse);
		/**
		*	��ȡy�ᷴ��
		*/
		bool isReverseY() const;
	public:
		/**
		*	�����rgba 32λpngͼƬ
		*/
		void saveImage(const std::string& imgFilePath, uint8_t* data, sys::ImageDataFormat format = sys::ImageDataFormat::RGBA);
	protected:
		// ��С
		math::IntSize _size;
		// y���Ƿ��෴
		bool _reverseY = false;
	};
}