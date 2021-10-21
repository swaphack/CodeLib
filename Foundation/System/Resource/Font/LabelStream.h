#pragma once

#include "Stream/MultiStream.h"
#include "TextDefine.h"
#include <stack>

namespace sys
{
	/**
	*	�ı���
	*
	*
	*		  _ _ x
	*		/|
	*	 z / |
	*		 y
	*/
	class LabelStream : public MultiStream
	{
	public:
		LabelStream();
		virtual ~LabelStream();
	public:
		// �����α�
		void resetOffset();
		// �̶����
		void setFixedWidth(uint32_t width);
		uint32_t getFixedWidth();

		// �̶����
		void setFixedHeight(uint32_t height);
		uint32_t getFixedHeight();

		// �̶����
		bool isFixedWidth();
		// �̶����
		bool isFixedHeight();
		// �и�
		uint32_t getLineHeight() const;
		void setLineHeight(uint32_t val);

		// д�뵥���ı�
		void writeOneLineBlock(int width, int height, const char* buffer, int deltaY);
		// д������ı�
		void writeMultiLineBlock(int width, int height, const char* buffer, int deltaY);
		// ����
		void writeEndLine();
		// ��һ��
		void writeSpaceLine();
		// ������д��
		void endStream();
		// ����ˮƽ���뷽ʽ
		void format(HorizontalAlignment ha);
	private:
		// д�뿪ʼ��λ��x
		int32_t _offsetX = 0;
		// д�뿪ʼ��λ��y
		int32_t _offsetY = 0;
		// �и�
		uint32_t _lineHeight = 0;
		// �̶����
		uint32_t _fixedWidth = 0;
		// �̶��߶�
		uint32_t _fixedHeight = 0;
		// �������ƫ��
		std::stack<int> _lineWidthStack;
	};
}
