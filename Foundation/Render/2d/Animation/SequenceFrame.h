#pragma once

#include "Animation.h"

#include <string>

namespace render
{
	class Texture2D;
	class DrawNode;
	class DrawTexture2D;

	// ����֡
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
		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
		/**
		*	��Ⱦ�ڵ�
		*/
		DrawNode* getRenderNode();
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
	private:
		DrawTexture2D* _drawNode = nullptr;
	};
}