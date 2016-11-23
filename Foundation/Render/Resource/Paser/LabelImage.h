#pragma once

#include "system.h"
#include "macros.h"

namespace render
{
	// �ı���
	class LabelStream : public sys::MultiStream
	{
	public:
		LabelStream();
		virtual ~LabelStream();
	public:
		// �����α�
		void resetOffset();

		// д�뿪ʼ��λ��x
		sys::ss_t getOffsetX() const { return _offsetX; }
		void setOffsetX(sys::ss_t val) { _offsetX = val; }
		// д�뿪ʼ��λ��y
		sys::ss_t getOffsetY() const { return _offsetY; }
		void setOffsetY(sys::ss_t val) { _offsetY = val; }
		// �и�
		sys::ss_t getLineHeight() const { return _lineHeight; }
		void setLineHeight(sys::ss_t val) { _lineHeight = val; }

		sys::ss_t getLowX() const { return _lowX; }
		void setLowX(sys::ss_t val) { _lowX = val; }

		sys::ss_t getLowY() const { return _lowY; }
		void setLowY(sys::ss_t val) { _lowY = val; }

		sys::ss_t getHeightX() const { return _heightX; }
		void setHeightX(sys::ss_t val) { _heightX = val; }

		sys::ss_t getHeightY() const { return _heightY; }
		void setHeightY(sys::ss_t val) { _heightY = val; }
		// д���ı���
		void writeLabelBlock(int width, int height, int deltaX, int deltaY, int advY, const char* buffer);
	private:
		// ��Ϊ�ı������Ĳ���
		// ��Сx
		sys::ss_t _lowX;
		// ��Сy
		sys::ss_t _lowY;
		// ���x
		sys::ss_t _heightX;
		// ���y
		sys::ss_t _heightY;

		// д�뿪ʼ��λ��x
		sys::ss_t _offsetX;
		// д�뿪ʼ��λ��y
		sys::ss_t _offsetY;
		// �и�
		sys::ss_t _lineHeight;
	};

	// �ı�ͼƬ
	// �ı����ͼƬ��ֻ����ͼƬ�����ɣ�������ʵ�ʰڷŵ�λ��
	class LabelImage : public Image, public ILabelLoader
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