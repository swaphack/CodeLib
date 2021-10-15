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
		* @param rect ��ʾ����
		* @param rotate �Ƿ�����ת
		*/
		static void setTexture2DCoords(RectVertex* texRect, const math::Rect& rect, bool rotate);

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
		*/
		static void setTexture2DFlip(float(*uvs)[8], bool bFlipX, bool bFlipY);

		/**
		*
		* ���þŹ���2d�������� ��ʱ��
		* @param scale9Vertex �������� out
		* @param rect ռ�ݵ�λ�úʹ�С
		* @param rotate �Ƿ���ת
		* @param margin ����
		*/
		static void setTexture2DScale9Coords(SimpleScale9Vertex* scale9Vertex, const math::Rect& rect, bool rotate, const math::Size& size, const sys::CSSMargin& margin);

		/**
		*
		* ���þŹ���2d������λ��
		* @param scale9Vertex �������� out
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		*/
		static void setTexture2DScale9Vertices(SimpleScale9Vertex* scale9Vertex, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, const sys::CSSMargin& margin);
		/**
		*
		* ���þŹ���2d2d�����㷭ת
		* @param uvs[32] ��������
		* @param bFlipX �Ƿ�ˮƽ��ת
		* @param bFlipY �Ƿ�ֱ��ת
		*/
		static void setTexture2DScale9Flip(float(*uvs)[32], bool bFlipX, bool bFlipY);
	};
}