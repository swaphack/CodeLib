#pragma once


#include "macros.h"

#include "Memory/MemoryData.h"

namespace sys
{
	/* ��ά������
	*
	*	1. ���ݴ洢�ķ�ʽ, ˳��x->y->z
	*	2.������ʽ�����ȴ����zȡ�棬��������ȡ��
	*	�����и��ƣ� �����渴�ƣ�ʵ��ȫ������
	*
	*
	*	  - - -
	*	/     /|
	*	- - -  | 
	*  |     | /
	*   - - -  
	*	
	*	 y
	*	 | 
	*	 | _ _ x
	*	/
	*  z
	*/
	class MultiStream
	{
	public:
		MultiStream();
		virtual ~MultiStream();
	public:
		// ��ʼ����
		void initSteam(uint32_t width, uint32_t height, uint32_t depth = 1);
		// ��չ��������о����ݣ�������Ҳ���Ƶ�������
		void expendStream(uint32_t width, uint32_t height, uint32_t depth = 1, bool bBottom = true);

		// �����ж�ȡһ��2ά����
		void readBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, MemoryData& outData, uint32_t z = 0);
		// д��һ��2ά���ݵ�����
		void writeBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z = 0);
		// д��һ��2ά���ݵ�����,y����ת
		void writeBlockWithReverseY(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z = 0);
		// �ƶ��ڴ���
		void moveBlock(uint32_t srcX, uint32_t srcY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY, uint32_t z = 0);

		// ����ڴ�������
		void resetBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t z = 0);

		// �����ж�ȡһ��3ά����
		void readBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, char* outData);
		// д��һ��3ά���ݵ�����
		void writeBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, const char* inData);
		// �ƶ��ڴ���
		void moveBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, uint32_t offsetX, uint32_t offsetY, uint32_t offsetZ);

		// ��ȡ���
		inline uint32_t getWidth() const { return _width; }
		// ��ȡ�߶�
		inline uint32_t getHeigth() const { return _heigth; }
		// ��ȡ���
		inline uint32_t getDepth() const { return _depth; }
		// ��ȡ����
		inline const char* getData() const { return (char*)_data.getValue(); }

		void clear();
	protected:
		// ����
		MemoryData _data;
		// ���
		uint32_t _width = 0;
		// �߶�
		uint32_t _heigth = 0;
		// ���
		uint32_t _depth = 0;
	};
}