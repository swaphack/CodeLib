#pragma once

#include "system.h"
#include "Resource/Loader/ILabelLoader.h"
#include "Resource/Detail/ImageDetail.h"
#include "Resource/Config/TextDefine.h"

#include <stack>

namespace render
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
	class LabelStream : public sys::MultiStream
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
		uint32_t _offsetX;
		// д�뿪ʼ��λ��y
		uint32_t _offsetY;
		// �и�
		uint32_t _lineHeight;
		// �̶����
		uint32_t _fixWidth;

		std::stack<int> _lineWidthStack;
	};

	// �ı�ͼƬ
	// �ı����ͼƬ��ֻ����ͼƬ�����ɣ�������ʵ�ʰڷŵ�λ��
	class ImageLabel : public ImageDetail, public ILabelLoader
	{
	public:
		ImageLabel();
		virtual ~ImageLabel();
	public:
		// �����ı�
		virtual void load(const TextDefine& textDefine);
	private:
		LabelStream* _stream;
	};
}