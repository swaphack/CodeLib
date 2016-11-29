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
		virtual bool init();

		virtual void draw();
		// 设置序列帧图片地址和图片张数
		void setFrameImagePath(const char* urlFormat, int count);
		// 获取序列帧图片地址
		const char* getFrameImagePath();
		// 获取序列帧图片张数
		int getFrameImageCount();
	protected:
		virtual void initSelf();
		virtual Texture2D* getNextTexture();
	private:
		// 序列帧图片地址
		std::string _frameImageUrl;
		// 图片张数
		int _frameImageCount;
	};
}