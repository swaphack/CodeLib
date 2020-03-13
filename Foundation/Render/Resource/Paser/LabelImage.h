#pragma once

#include "system.h"
#include "macros.h"

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

		void setFixWidth(sys::ss_t width) { _fixWidth = width; }
		sys::ss_t getFixWidth() { return _fixWidth; }
		// �̶����
		bool isFixWidth() { return _fixWidth != 0; }

		// �и�
		sys::ss_t getLineHeight() const { return _lineHeight; }
		void setLineHeight(sys::ss_t val) { _lineHeight = val; }

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
	class LabelImage : public ImageDetail, public ILabelLoader
	{
	public:
		LabelImage();
		virtual ~LabelImage();
	public:
		// �����ı�
		virtual void load(const TextDefine& textDefine);
	private:
		LabelStream* _stream;
	};
}