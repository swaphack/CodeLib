#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class BoxProtocol;
	class Box2DProtocol;
	class Box3DProtocol;
	class BoxDraw;
	class Box2DSpace;
	class Box3DSpace;

	/**
	*	��Χ�пռ�
	*/
	class BoxSpace : public sys::Object
	{
	public:
		BoxSpace();
		virtual ~BoxSpace();
	public:
		/**
		*	���ӻ��ƽڵ�
		*/
		void setBoxDraw(BoxDraw* boxDraw);
		/**
		*	���ӻ��ƽڵ�
		*/
		BoxDraw* getBoxDraw();
	public:
		/**
		*	2d���ֵľ��δ�С
		*/
		void setMinBox2DSize(int width, int height);
		/**
		*	3d���ֵľ��δ�С
		*/
		void setMinBox3DSize(int width, int height, int depth);
	public:
		/**
		*	��ȡ�����ĺ��ӱ��
		*/
		int getBoxIncreaseID();
	public:
		/**
		*	���
		*/
		void addBox(BoxProtocol* box);
		/**
		*	���º���
		*/
		void updateBox(BoxProtocol* box);
		/**
		*	�Ƴ�
		*/
		void removeBox(BoxProtocol* box);
		/**
		*	�Ƴ����к���
		*/
		void removeAllBoxes();
		/**
		*	��ȡ���к���
		*/
		const std::map<int, BoxProtocol*>& getAllBoxes() const;
	public:
		/**
		*	����������
		*/
		bool containsTouchPoint(const math::Vector2& touchPoint, std::vector<BoxProtocol*>& boxes);
		/**
		*	���������ĺ�����Ϣ
		*/
		bool getBoxesOfIncludedPoint(const math::Vector3& worldPoint, std::vector<BoxProtocol*>& boxes);
		/**
		*	�Ƿ���������
		*/
		bool containsTouchPoint2D(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint);
		/**
		*	���������ĺ�����Ϣ
		*/
		bool containsTouchPoint3D(Box3DProtocol* boxProtocol, const math::Vector2& touchPoint);
	protected:
		/**
		*	ע���¼�
		*/
		void registerBoxEvent(BoxProtocol* box);
		/**
		*	�Ƴ��¼�
		*/
		void unregisterBoxEvent(BoxProtocol* box);
		/**
		*	��ȡ��ֵ
		*/
		std::string getRectKey(const math::Rect& rect);
	private:
		// ����
		std::map<int, BoxProtocol*> _boxes;
		// ���ӻ���
		BoxDraw* _boxDraw = nullptr;
		// ���ӱ��
		int _increaseBoxID = 0;

		Box2DSpace* _2dSpace;
		Box3DSpace* _3dSpace;
	};

#define G_BOXSPACE sys::Instance<render::BoxSpace>::getInstance()
}