#pragma once

#include "mathlib.h"
#include "Common/struct/vertex_common.h"
#include "Common/DrawNode/DrawNode2D.h"
#include "Common/DrawNode/DrawProtocol.h"
#include "Common/Texture/TexFrame.h"

namespace render
{
	// ֡ͼƬ��Ĭ����ʱ�����
	class DrawScale9Texture2D :
		public DrawNode2D
	{
	public:
		DrawScale9Texture2D();
		virtual ~DrawScale9Texture2D();
	public:
		virtual bool init();
	public:
		// ����ͼƬ����
		void setTextureWithRect(const std::string& filepath);
		// ����ͼƬ����
		void setTextureWithRect(const Texture* texture);
	public:
		// ������������
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
		/**
		*	�ױ�
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	�ױ�
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	�ױ�
		*/
		const sys::CSSMargin& getMargin() const;
	protected:
		void onScale9BodyChange();
		void onScale9ImageChange();
	protected:
		virtual void updateScale9ImageMeshData();
	protected:
		// �Ƿ�ˮƽ��ת
		bool _bFlipX = false;
		// �Ƿ�ֱ��ת
		bool _bFlipY = false;
		/**
		*	�ױ߲���
		*/
		sys::CSSMargin _scale9Margin;
		/**
		*	������Ϣ
		*/
		render::SimpleScale9Vertex _scale9Vertex;
	};
}
