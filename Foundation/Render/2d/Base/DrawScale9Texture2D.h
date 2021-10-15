#pragma once

#include "mathlib.h"
#include "Common/struct/vertex_common.h"
#include "Common/DrawNode/DrawNode2D.h"
#include "Common/DrawNode/DrawProtocol.h"
#include "Common/Texture/TexFrame.h"

namespace render
{
	// 帧图片，默认逆时针绘制
	class DrawScale9Texture2D :
		public DrawNode2D
	{
	public:
		DrawScale9Texture2D();
		virtual ~DrawScale9Texture2D();
	public:
		virtual bool init();
	public:
		// 混合读取方式，纹理或者纹理碎片
		void loadImage(const std::string& mixFilePath);
		// 设置图片纹理
		void loadTexture(const std::string& filepath);
		// 设置图片纹理
		void loadTexture(const Texture* texture);
		// 根据碎片范围加载图片
		void loadTexture(const Texture* texture, const sys::TextureChip& chip);
		// 根据碎片名字加载图片
		void loadTextureChip(const std::string& chipname);
		// 设置成纹理大小
		void setNativeTextureSize();
	public:
		// 设置纹理坐标
		void setUV(const math::Rect& rect, const math::Size& size, bool rotate = false);
		/**
		*	设置纹理帧
		*/
		void setTexFrame(const TexFrame* texFrame);
	public:
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
		/**
		*	白边
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	白边
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	白边
		*/
		const sys::CSSMargin& getMargin() const;
	protected:
		void onScale9BodyChange();
		void onScale9ImageChange();
	protected:
		virtual void updateScale9ImageMeshData();
	protected:
		// 是否水平翻转
		bool _bFlipX = false;
		// 是否垂直翻转
		bool _bFlipY = false;
		// 纹理帧
		TexFrame* _texFrame = nullptr;
		/**
		*	白边参数
		*/
		sys::CSSMargin _scale9Margin;
		/**
		*	顶点信息
		*/
		render::SimpleScale9Vertex _scale9Vertex;
	};
}
