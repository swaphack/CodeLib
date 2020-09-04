#pragma once

#include "system.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	���ش���
	*/
	class Pixel
	{
	public:
		Pixel();
		virtual ~Pixel();
	public:
		/**
		*	��ȡ���ػ�������
		*/
		const sys::MemoryData& getPixelData() const;
	public:
		/**
		*	����ָ��λ�õ�����
		*/ 
		void loadPointPixel(float x, float y);
		/**
		*	����ָ�����ε�����
		*/
		void loadRectPixel(float x, float y, float width, float height);
		
	public:
		/**
		*	����ָ�����ε�����
		*/
		static void loadRectPixel(float x, float y, float width, float height, ReadPixelDataFormat pixelFormat, ReadPixelDataType pixelType, void* ptr);
		/**
		*	��ȡָ��λ�õ�����
		*/
		static sys::Color4B readPixelColor(float x, float y);
		/**
		*	��ȡ��Ļ��ģ�����ֵ
		*/
		static void dumpStencil();
	private:
		// ���ػ�������
		sys::MemoryData _blockData;
	};
}