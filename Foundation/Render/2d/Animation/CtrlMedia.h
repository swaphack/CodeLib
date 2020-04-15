#pragma once

#include "CtrlAnimation.h"
#include "Resource/Config/MediaDefine.h"

namespace render
{
	class Texture2D;
	class MediaDetail;
	class CtrlAudioSourceClip;

	// 媒体（包含图像和声音）
	class CtrlMedia : public CtrlAnimation
	{
	public:
		CtrlMedia();
		virtual ~CtrlMedia();
	public:
		virtual bool init();

		virtual void draw();
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
		// 设置媒体文件
		void setMediaPath(const char* path, bool defaultSize = true);
	protected:
		// 获取下一阵的纹理帧
		Texture2D* getNextTexture();
	private:
		// 媒体数据结构
		MediaDefine _mediaDefine;
		// 媒体数据
		MediaDetail* _media;
		// 音效
		CtrlAudioSourceClip* _ctrlAudio;
	};
}