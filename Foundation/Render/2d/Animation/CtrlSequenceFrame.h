#pragma once

#include "CtrlAnimation.h"

#include <string>

namespace render
{
	class Texture2D;
	// ����֡
	class CtrlSequenceFrame : public CtrlAnimation
	{
	public:
		CtrlSequenceFrame();
		virtual ~CtrlSequenceFrame();
	public:
		virtual bool init();

		virtual void draw();
	public:
		/** 
		*	��������֡ͼƬ��ַ��ͼƬ����
		*/
		void setFrameImagePath(const std::string& urlFormat, int count);
		/** 
		*	��ȡ����֡ͼƬ��ַ
		*/
		const std::string& getFrameImagePath();
		/** 
		*	��ȡ����֡ͼƬ����
		*/
		int getFrameImageCount();
	protected:
		/**
		*	��һ֡����
		*/
		virtual Texture2D* getNextTexture();
	private:
		/** 
		*	����֡ͼƬ��ַ
		*/
		std::string _frameImageUrl;
		/**
		*	ͼƬ����
		*/
		int _frameImageCount = 0;
	};
}