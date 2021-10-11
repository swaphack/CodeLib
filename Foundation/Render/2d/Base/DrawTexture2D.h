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
		// ����ͼƬ����
		void setTextureWithRect(const std::string& filepath);
		// ����ͼƬ����
		void setTextureWithRect(const Texture* texture);
	public:
		/**
		*	������������
		*/
		void setUV(const math::Rect& rect, const math::Size& size);
		/**
		*	��������֡
		*/
		void setTexFrame(const TexFrame& texFrame);
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
	};
}
