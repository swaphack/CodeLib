#pragma once

#include "Animation.h"

namespace sys
{
	class MediaDetail;
}

namespace render
{
	class Texture2D;
	class DrawTexture2D;
	class CtrlAudioSourceClip;

	// 媒体（包含图像和声音）
	class Media : public Animation
	{
	public:
		Media();
		virtual ~Media();
	public:
		virtual bool init();
	public:
		// 开始
		virtual void start();
		// 恢复
		virtual void pause();
		// 暂停
		virtual void resume();
		// 结束
		virtual void stop();
	public:
		// 加载媒体文件
		void loadFromURL(const std::string& url, bool defaultSize = true);
	protected:
		// 获取下一阵的纹理帧
		Texture2D* getNextTexture();
	private:
		// 媒体数据结构
		std::string _filepath;
		// 媒体数据
		sys::MediaDetail* _media;
		// 音效
		CtrlAudioSourceClip* _ctrlAudio;
		DrawTexture2D* _drawNode = nullptr;
	};
}