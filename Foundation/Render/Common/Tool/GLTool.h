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
		static void setColor(const sys::Color4B& color);
		/**
		* ���ƾ���
		* @param rectVertex �����ĸ���������
		* @param type ����
		*/
		static void drawRect(const RectangeVertex* rectVertex, uint type);

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