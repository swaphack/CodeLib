#pragma once

#include "../GL/import.h"

namespace render
{
	class GLTool
	{
	public:
		/**
		* ���ƾ�������
		* @param texID ����id
		* @param texRect �����ĸ���������
		*/
		static void drawRectVertex(const TextureRect* texRect);
		/**
		* ��������������
		* @param texID ����id
		* @param texRect �����ĸ���������
		*/
		static void drawTriangleVertex(const TextureRect* texRect);

		/**
		* ��������������
		* @param texID ����id
		* @param texRect �����ĸ���������
		* @param normal ����
		*/
		static void drawRectVertexWithNormal(const TextureRect* texRect, const sys::Vector& normal);

		/**
		* ������ɫ
		* @param red
		* @param green
		* @param blue
		* @param alpha
		*/
		static void setColor(uchar red, uchar green, uchar blue, uchar alpha);
		/**
		* ������ɫ
		* @param color
		*/
		static void setColor(sys::Color4B color);
		/**
		* ���ƾ���
		* @param rectVertex �����ĸ���������
		* @param type ����
		*/
		static void drawRect(const RectangeVertex* rectVertex, uint type);

		/**
		* ���ߵļ���
		* @param p1 ����1
		* @param p2 ����2
		* @param p3 ����3
		* @param normal ����
		*/
		static void calNormal(const sys::Vector& p1, const sys::Vector& p2, const sys::Vector& p3, sys::Vector& normal);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRect(const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor, RectangeVertex& rectVertex);

		/**
		* ��ʼ���
		* @param blend �������
		*/
		static void beginBlend(const BlendParam& blend);
		/**
		* ��ʼ���
		* @param src �������
		* @param dest �������
		*/
		static void beginBlend(int src, int dest);
		/**
		* ��Ͻ���
		*/
		static void endBlend();
	};
}