#pragma once

#include "TextDefine.h"
#include "ILabelLoader.h"
#include "../Image/ImageDetail.h"
namespace sys
{
	class LabelStream;

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
		LabelStream* _stream = nullptr;
	};
}