#pragma once

#include "CtrlAnimation.h"

namespace render
{
	// 序列帧
	class CtrlSequenceFrame : public CtrlAnimation
	{
	public:
		CtrlSequenceFrame();
		virtual ~CtrlSequenceFrame();
	public:
		virtual void draw();
		// 设置序列帧图片地址和图片张数
		void setFramePath(const char* urlFormat, int count);
	protected:
		virtual void initSelf();
		virtual Texture2D* getNextTexture();
	private:
		// 序列帧图片地址
		std::string _frameUrlFormat;
		// 图片张数
		int _frameCount;
	};
}