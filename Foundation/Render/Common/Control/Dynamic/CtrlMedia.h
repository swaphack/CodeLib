#pragma once

#include "CtrlAnimation.h"

namespace render
{
	// 媒体（包含图像和声音）
	class CtrlMedia : public CtrlAnimation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual void draw();
		// 设置媒体文件
		virtual void setMediaPath(const char* path);
	protected:
		// 重新计算参数
		virtual void initSelf();
		// 获取下一阵的纹理帧
		Texture2D* getNextTexture();
	private:
		// 媒体数据结构
		MediaDefine _mediaDefine;
		// 媒体数据
		Media* _media;
	};
}