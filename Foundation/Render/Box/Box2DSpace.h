#pragma once

#include <map>
#include "mathlib.h"

namespace render
{
	class Box2DProtocol;
	/**
	*	�ɼ���2d����
	*/
	class Box2DSpace
	{
	public:
		Box2DSpace();
		virtual ~Box2DSpace();
	public:
		/**
		*	��ʼ�����ӷ�Χ
		*/
		void init(const math::Vector2& pos, const math::Size& size);
	public:
		/**
		*	��С���δ�С
		*/
		void setMinBoxSize(int width, int height);
	public:
		/**
		*	���
		*/
		void addBox(Box2DProtocol* box);
		/**
		*	�Ƴ�
		*/
		void removeBox(Box2DProtocol* box);
		/**
		*	�Ƴ�
		*/
		void removeBox(int boxID);
		/**
		*	����
		*/
		bool containBox(int boxID);
		/**
		*	�Ƴ����к���
		*/
		void removeAllBoxes();
	public:
		/**
		*	�Ƿ���������
		*/
		bool containsTouchPoint(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint);
		/**
		*	���������ĺ�����Ϣ
		*/
		bool getBoxesOfIncludedPoint(int nID, const math::Vector3& worldPoint, std::map<int, render::Box2DProtocol*>& boxes);
	private:
		// ����
		std::map<int, Box2DProtocol*> _boxes;
		// ����
		math::Rect _rootRect;
		// ��С���δ�С
		int _minRectWidth = 20;
		int _minRectHeight = 20;
	};
}
