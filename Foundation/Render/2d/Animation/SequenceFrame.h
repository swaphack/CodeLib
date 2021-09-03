#pragma once

#include "Animation.h"

#include <string>

namespace render
{
	class Texture2D;
	class DrawNode;
	class DrawTexture2D;

	// 序列帧
	class SequenceFrame : public Animation
	{
	public:
		SequenceFrame();
		virtual ~SequenceFrame();
	public:
		virtual bool init();

		virtual void draw();
	public:
		/** 
		*	设置序列帧图片地址和图片张数
		*/
		void setFrameImagePath(const std::string& urlFormat, int count);
		/** 
		*	获取序列帧图片地址
		*/
		const std::string& getFrameImagePath();
		/** 
		*	获取序列帧图片张数
		*/
		int getFrameImageCount();
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
		/**
		*	渲染节点
		*/
		DrawNode* getRenderNode();
	protected:
		/**
		*	下一帧纹理
		*/
		virtual Texture2D* getNextTexture();
	private:
		/** 
		*	序列帧图片地址
		*/
		std::string _frameImageUrl;
		/**
		*	图片张数
		*/
		int _frameImageCount = 0;
	private:
		DrawTexture2D* _drawNode = nullptr;
	};
}