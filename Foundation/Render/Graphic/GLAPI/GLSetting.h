#pragma once
#include "macros.h"
namespace render
{
	/**
	*	设置
	*/
	class GLSetting
	{
	public:
		/**
		*	雾化效果
		*/
		static void setFogHint(HintMode type);
		/**
		*	片元着色器
		*/
		static void setFragmentShaderDerivativeHint(HintMode type);
		/**
		*	生成mipmap
		*/
		static void setGenerateMipMapHint(HintMode type);
		/**
		*	线段平滑
		*/
		static void setLineSmoothHint(HintMode type);
		/**
		*	透视矫正
		*/
		static void setPerspectiveCorrectionHint(HintMode type);
		/**
		*	点平滑
		*/
		static void setPointSmoothHint(HintMode type);
		/**
		*	多边形平滑
		*/
		static void setPolygonSmoothHint(HintMode type);
		/**
		*	纹理压缩
		*/
		static void setTextureCompressionHint(HintMode type);
	public:
		/**
		*	阴影样式
		*/
		static void setShadeModel(ShadingModel model);
		/**
		*	多边形样式
		*/
		static void setPolygonMode(PolygonFaceMode mode, PolygonMode type);
	};
}