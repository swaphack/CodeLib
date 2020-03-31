#pragma once
#include "macros.h"
namespace render
{
	/**
	*	����
	*/
	class GLSetting
	{
	public:
		/**
		*	��Ч��
		*/
		static void setFogHint(HintMode type);
		/**
		*	ƬԪ��ɫ��
		*/
		static void setFragmentShaderDerivativeHint(HintMode type);
		/**
		*	����mipmap
		*/
		static void setGenerateMipMapHint(HintMode type);
		/**
		*	�߶�ƽ��
		*/
		static void setLineSmoothHint(HintMode type);
		/**
		*	͸�ӽ���
		*/
		static void setPerspectiveCorrectionHint(HintMode type);
		/**
		*	��ƽ��
		*/
		static void setPointSmoothHint(HintMode type);
		/**
		*	�����ƽ��
		*/
		static void setPolygonSmoothHint(HintMode type);
		/**
		*	����ѹ��
		*/
		static void setTextureCompressionHint(HintMode type);
	public:
		/**
		*	��Ӱ��ʽ
		*/
		static void setShadeModel(ShadingModel model);
		/**
		*	�������ʽ
		*/
		static void setPolygonMode(PolygonFaceMode mode, PolygonMode type);
	};
}