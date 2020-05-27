#pragma once

#include "Common/struct/import.h"

namespace render
{
	class VertexTool
	{
	public:
		/**
		*
		* ����2d�������� ��ʱ��
		* @param texRect �������� out
		* @param size �����С
		* @param rect ��ʾ����
		*/
		static void setTexture2DCoords(RectVertex* texRect, const math::Size& size, const math::Rect& rect);

		/**
		*
		* ����2d������λ��
		* @param texRect �������� out
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		*/
		static void setTexture2DVertices(RectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);

		/**
		*
		* ����3d������λ��
		* @param texcube �������� out
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		*/
		static void setTexture3DVertices(CubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);
		/**
		*
		* ����2d�����㷭ת
		* @param uvs[8] ��������
		* @param bFlipX �Ƿ�ˮƽ��ת
		* @param bFlipY �Ƿ�ֱ��ת
		* @param outUVs[8] ��������
		*/
		static void setTexture2DFlip(float* uvs, bool bFlipX, bool bFlipY);
	};
}