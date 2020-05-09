#pragma once


#include "CtrlWidget.h"

#include "mathlib.h"

namespace render
{
	class Texture2D;
	class Material;
	class Mesh;

	// 帧图片，默认逆时针绘制
	class CtrlFrame : public CtrlWidget
	{
	public:
		CtrlFrame();
		virtual ~CtrlFrame();
	public:
		virtual bool init();
	public:
		// 设置图片纹理
		void setTexture(const Texture2D* texture);
		// 设置图片纹理
		void setTextureWithRect(const Texture2D* texture);
		// 设置要显示的纹理区域
		void setTexRect(const math::Rect& rect);
		// 设置水平翻转
		void setFlipX(bool status);
		// 是否水平翻转
		bool isFlipX();
		// 设置垂直翻转
		void setFlipY(bool status);
		// 是否垂直翻转
		bool isFlipY();
		// 是否顺时针
		bool isCounter();
		// 设置是否顺时针
		void setCounter(bool status);
	public:
		Material* getMaterial();
		Mesh* getMesh();
	protected:
		virtual void drawSample();
	protected:
		void onTextureChange();

		void drawSampleWithClientArray();
		void drawSampleWithBufferObject();

		void initBufferObject();
		void updateBufferData();
	protected:
		// 纹理坐标
		TextureRectVertex _texRect;
		// 是否水平翻转
		bool _bFlipX;
		// 是否垂直翻转
		bool _bFlipY;
		// 材质
		Material* _material = nullptr;
		// 网格
		Mesh* _mesh = nullptr;
	};
}