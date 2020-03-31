#pragma once

#include "Common/struct/import.h"

namespace render
{
	class TextureTool
	{
	public:
		/**
		*
		* ����2d�������� ˳ʱ��
		* @param texRect �������� out
		* @param size �����С
		* @param rect ��ʾ����
		*/ 
		static void setTexture2DCounterCoords(TextureRect* texRect, const math::Size& size, const math::Rect& rect);

		/**
		*
		* ����2d�������� ��ʱ��
		* @param texRect �������� out
		* @param size �����С
		* @param rect ��ʾ����
		*/
		static void setTexture2DCoords(TextureRect* texRect, const math::Size& size, const math::Rect& rect);

		/**
		*
		* ����2d������λ��
		* @param texRect �������� out
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		*/
		static void setTexture2DVertexts(TextureRect* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);

		/**
		* ����3d��������
		* @param texcube �������� out
		* @param size �����С
		* @param rect ��ʾ����
		*/
		/*static void setTexture3DCoords(TextureCube* texcube, const math::Size& size, const math::Rect& rect);*/

		/**
		*
		* ����3d������λ��
		* @param texcube �������� out
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		*/
		static void setTexture3DVertexts(TextureCube* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);
		/**
		*
		* ����2d�����㷭ת
		* @param texcube �������� out
		* @param bFlipX �Ƿ�ˮƽ��ת
		* @param bFlipY �Ƿ�ֱ��ת
		*/
		static void setTexture2DFlip(TextureRect* texRect, bool bFlipX, bool bFlipY);
	};
}