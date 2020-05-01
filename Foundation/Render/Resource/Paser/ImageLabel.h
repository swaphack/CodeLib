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

		void setFixWidth(sys::ss_t width);
		sys::ss_t getFixWidth();
		// �̶����
		bool isFixWidth();

		// �и�
		sys::ss_t getLineHeight() const;
		void setLineHeight(sys::ss_t val);

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
		sys::ss_t _offsetX;
		// д�뿪ʼ��λ��y
		sys::ss_t _offsetY;
		// �и�
		sys::ss_t _lineHeight;
		// �̶����
		sys::ss_t _fixWidth;

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