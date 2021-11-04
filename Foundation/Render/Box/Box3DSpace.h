#pragma once

#include <map>
#include "mathlib.h"

namespace render
{
	class Box3DProtocol;
	/**
	*	�ɼ���2d����
	*/
	class Box3DSpace
	{
	public:
		Box3DSpace();
		virtual ~Box3DSpace();
	public:
		/**
		*	��ʼ�����ӷ�Χ
		*/
		void init(const math::Vector2& pos, const math::Size& size);
	public:
		/**
		*	��С���δ�С
		*/
		void setMinBoxSize(int width, int height, int depth);
	public:
		/**
		*	���
		*/
		void addBox(Box3DProtocol* box);
		/**
		*	�Ƴ�
		*/
		void removeBox(Box3DProtocol* box);
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
		bool containsTouchPoint(Box3DProtocol* boxProtocol, const math::Vector2& touchPoint);
		/**
		*	���������ĺ�����Ϣ
		*/
		bool getBoxesOfIncludedPoint(int nID, const math::Vector3& worldPoint, std::map<int, render::Box3DProtocol*>& boxes);
	private:
		// ����
		std::map<int, Box3DProtocol*> _boxes;

		// ��С���δ�С
		int _minRectWidth = 20;
		int _minRectHeight = 20;
		int _minRectDepth = 20;
	};
}
