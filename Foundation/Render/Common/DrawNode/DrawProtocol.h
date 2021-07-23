#pragma once

#include <cstdint>

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Camera;

	// 用于颜色设置
	class ColorProtocol
	{
	public:
		ColorProtocol();
		virtual ~ColorProtocol();
	public:
		// 设置颜色
		void setColor(uint8_t r, uint8_t g, uint8_t b);
		// 设置颜色
		void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		// 设置颜色
		void setColor(float r, float g, float b);
		// 设置颜色
		void setColor(float r, float g, float b, float a);
		// 设置颜色
		void setColor(const phy::Color4B& color);
		// 设置颜色
		void setColor(const phy::Color3B& color);
		// 设置颜色
		void setColor(const phy::Color4F& color);
		// 设置颜色
		void setColor(const phy::Color3F& color);
		// 获取颜色
		const phy::Color4B& getColor() const;
	protected:
		virtual void onColorChange() {};
	protected:
		// 混合
		phy::Color4B _color;
	};

	// 不透明度设置
	class OpacityProtocol
	{
	public:
		OpacityProtocol();
		virtual ~OpacityProtocol();
	public:
		// 设置不透明度
		void setOpacity(uint8_t opacity);
		// 设置不透明度
		uint8_t getOpacity();
	protected:
		// 不透明度
		uint8_t _opacity = 255;
	};

	// 混合参数
	struct BlendParam
	{
		BlendingFactorSrc src = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;

		BlendParam();

		BlendParam(BlendingFactorSrc src, BlendingFactorDest dest);

		BlendParam& operator=(const BlendParam& blend);
	};

	// 混合
	class BlendProtocol
	{
	public:
		BlendProtocol();
		virtual ~BlendProtocol();
	public:
		// 设置混合条件
		void setBlend(BlendingFactorSrc src, BlendingFactorDest dest);
		// 设置混合条件
		void setBlend(const BlendParam& blend);
		// 设置颜色
		void setBlendColor(const phy::Color3B& color);
		// 设置颜色
		void setBlendColor(const phy::Color3F& color);
		// 设置颜色
		void setBlendColor(const phy::Color4B& color);
		// 设置颜色
		void setBlendColor(const phy::Color4F& color);
		// 获取混合参数
		const BlendParam& getBlend();
	protected:
		virtual void onBlendChange() {};
	protected:
		// 混合参数
		BlendParam _blendParam;
		// 混合颜色
		phy::Color4F _blendColor;
	};
}
