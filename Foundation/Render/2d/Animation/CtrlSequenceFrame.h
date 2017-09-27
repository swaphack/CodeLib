#pragma once

#include "CtrlAnimation.h"

namespace render
{
	// ����֡
	class CtrlSequenceFrame : public CtrlAnimation
	{
	public:
		CtrlSequenceFrame();
		virtual ~CtrlSequenceFrame();
	public:
		virtual bool init();

		virtual void draw();
		// ��������֡ͼƬ��ַ��ͼƬ����
		void setFrameImagePath(const char* urlFormat, int count);
		// ��ȡ����֡ͼƬ��ַ
		const char* getFrameImagePath();
		// ��ȡ����֡ͼƬ����
		int getFrameImageCount();
	protected:
		virtual void initSelf();
		virtual Texture2D* getNextTexture();
	private:
		// ����֡ͼƬ��ַ
		std::string _frameImageUrl;
		// ͼƬ����
		int _frameImageCount;
	};
}