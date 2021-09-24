#pragma once


#include "Common/DrawNode/DrawNode3D.h"

namespace render
{
	/**
	*	����
	*/
	class Terrian : public DrawNode3D
	{
	public:
		Terrian();
		virtual ~Terrian();
	public:
		virtual bool init();
	public:
		/**
		*	���õ������
		*/
		void setTerrianSize(float width, float height);
		/**
		*	���õ��ο��
		*/
		void setTerrianWidth(float width);
		/**
		*	��ȡ���ο��
		*/
		float getTerrianWidth() const;
		/**
		*	���õ��γ���
		*/
		void setTerrianLength(float length);
		/**
		*	��ȡ���γ���
		*/
		float getTerrianLength() const;
		/**
		*	���õ��θ߶�
		*/
		void setTerrianHeight(float minHeight, float maxHeight);
		/**
		*	���÷ֻ�����
		*/
		void setFractalCount(int count);
		/**
		*	��ȡ�ֻ�����
		*/
		int getFractalCount() const;
	protected:
		void onTerrianChange();
	protected:
		math::Size _terrianSize;
		math::FloatInterval _terrianHeight;
		int _fractalCount = 1;
	};
}