#pragma once

#include "mathlib.h"
#include "Common/struct/vertex_common.h"
#include "Common/DrawNode/DrawNode2D.h"
#include "Common/DrawNode/DrawProtocol.h"
#include "Common/Texture/TexFrame.h"

namespace render
{
	// ֡ͼƬ��Ĭ����ʱ�����
	class DrawTexture2D : 
		public DrawNode2D
	{
	public:
		DrawTexture2D();
		virtual ~DrawTexture2D();
	public:
		virtual bool init();
	public:
		// ��϶�ȡ��ʽ���������������Ƭ
		void loadImage(const std::string& mixFilePath);
		// ����ͼƬ·������
		void loadTexture(const std::string& filepath);
		// �����������
		void loadTexture(const Texture* texture);
		// ������Ƭ��Χ����ͼƬ
		void loadTexture(const Texture* texture, const sys::TextureChip& chip);
		// ������Ƭ���ּ���ͼƬ
		void loadTextureChip(const std::string& chipname);
		// ���ó������С
		void setNativeTextureSize();
		// �������
		void cleanTexture();
	public:
		/**
		*	������������
		*/
		void setUV(const math::Rect& rect, const math::Size& size, bool rotate = false);
		/**
		*	��������֡
		*/
		void setTexFrame(const TexFrame* texFrame);
	public:
		// ����ˮƽ��ת
		void setFlipX(bool status);
		// �Ƿ�ˮƽ��ת
		bool isFlipX();
		// ���ô�ֱ��ת
		void setFlipY(bool status);
		// �Ƿ�ֱ��ת
		bool isFlipY();
	protected:
		/**
		*	�����������UV
		*/
		void updateUVWithTexture();
		/**
		*	������������
		*/
		virtual void updateTexture2DMeshData();
	protected:
		// �Ƿ�ˮƽ��ת
		bool _bFlipX = false;
		// �Ƿ�ֱ��ת
		bool _bFlipY = false;
		// ����֡
		TexFrame* _texFrame = nullptr;
	};
}
