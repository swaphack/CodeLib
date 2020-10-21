#pragma once

#include "Stream/MultiStream.h"
#include "TextDefine.h"
#include "ILabelLoader.h"
#include "../Image/ImageDetail.h"
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

		void setFixWidth(uint32_t width);
		uint32_t getFixWidth();
		// �̶����
		bool isFixWidth();

		// �и�
		uint32_t getLineHeight() const;
		void setLineHeight(uint32_t val);

		// д�뵱���ı�
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
		int32_t _offsetX;
		// д�뿪ʼ��λ��y
		int32_t _offsetY;
		// �и�
		uint32_t _lineHeight;
		// �̶����
		uint32_t _fixWidth;

		std::stack<int> _lineWidthStack;
	};

	// �ı�ͼƬ
	// �ı����ͼƬ��ֻ����ͼƬ�����ɣ�������ʵ�ʰڷŵ�λ��
	class LabelImage : public ImageDetail, public ILabelLoader
	{
	public:
		LabelImage();
		virtual ~LabelImage();
	public:
		// �����ı�
		virtual bool load(const TextDefine& textDefine);
	private:
		LabelStream* _stream;
	};
}