#pragma once

#include "Base/Types.h"
#include "StreamBase.h"

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
		void initSteam(ss_t width, ss_t height, ss_t deep = 1);
		// ��չ��������о����ݣ�������Ҳ���Ƶ�������
		void expendStream(ss_t width, ss_t height, ss_t deep = 1, bool bBottom = false);

		// �����ж�ȡһ��2ά����
		void readBlock(ss_t x, ss_t y, ss_t width, ss_t height, char* outData, ss_t z = 0);
		// д��һ��2ά���ݵ�����
		void writeBlock(ss_t x, ss_t y, ss_t width, ss_t height, const char* inData, ss_t z = 0);
		// �ƶ��ڴ���
		void moveBlock(ss_t srcX, ss_t srcY, ss_t width, ss_t height, ss_t destX, ss_t destY, ss_t z = 0);

		// ����ڴ�������
		void resetBlock(ss_t x, ss_t y, ss_t width, ss_t height, ss_t z = 0);

		// �����ж�ȡһ��3ά����
		void readBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, char* outData);
		// д��һ��3ά���ݵ�����
		void writeBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, const char* inData);
		// �ƶ��ڴ���
		void moveBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, ss_t offsetX, ss_t offsetY, ss_t offsetZ);

		// ��ȡ���
		inline ss_t getWidth() const { return _width; }
		// ��ȡ�߶�
		inline ss_t getHeigth() const { return _heigth; }
		// ��ȡ���
		inline ss_t getDeep() const { return _deep; }
		// ��ȡ����
		inline const char* getData() const { return _data; }

		void clear();
	protected:
		// ����
		char* _data;
		// ���
		ss_t _width;
		// �߶�
		ss_t _heigth;
		// ���
		ss_t _deep;
	};
}