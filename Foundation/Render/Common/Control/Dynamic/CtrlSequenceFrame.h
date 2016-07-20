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
		virtual void draw();
		// ��������֡ͼƬ��ַ��ͼƬ����
		void setFramePath(const char* urlFormat, int count);
	protected:
		virtual void initSelf();
		virtual Texture2D* getNextTexture();
	private:
		// ����֡ͼƬ��ַ
		std::string _frameUrlFormat;
		// ͼƬ����
		int _frameCount;
	};
}