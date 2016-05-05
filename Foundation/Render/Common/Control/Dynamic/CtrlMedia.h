#pragma once

#include "macros.h"
#include <map>

namespace render
{
	// 媒体（包含图像和声音）
	class CtrlMedia : public Animation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual void draw();

		// 设置媒体文件
		virtual void setMediaPath(const char* path);
		// 设置当前帧
		void setFrame(int frame);
		// 获取当前帧
		int getFrame();
	protected:
		// 重新计算参数
		virtual void initSelf();
		// 定时更新事件
		virtual void updateSelf(float interval);
		// 获取下一阵的纹理帧
		Texture2D* getNextTexture();
		// 移除所有纹理
		void removeAllTextures();
	private:
		// 媒体数据结构
		MediaDefine _mediaDefine;
		// 媒体数据
		Media* _media;
		// 帧纹理缓存 {帧， 纹理}
		std::map<mf_s, Texture2D*> _texures;
		// 当前纹理坐标
		TextureRect _texRect;
		// 当前纹理帧
		TexFrame* _texFrame;
		// 当前帧
		float _frame;
	};
}