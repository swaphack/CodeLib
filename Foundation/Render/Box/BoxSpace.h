#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class BoxDrawProtocol;
	class BoxDraw;
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
		*	��С���δ�С
		*/
		void setMinRectSize(int width, int height);
	public:
		/**
		*	��ȡ�����ĺ��ӱ��
		*/
		int getBoxIncreaseID();
	public:
		/**
		*	���
		*/
		void addBox(BoxDrawProtocol* box);
		/**
		*	���º���
		*/
		void updateBox(BoxDrawProtocol* box);
		/**
		*	�Ƴ�
		*/
		void removeBox(BoxDrawProtocol* box);
		/**
		*	�Ƴ����к���
		*/
		void removeAllBoxes();
		/**
		*	��ȡ���к���
		*/
		const std::map<int, BoxDrawProtocol*>& getAllBoxes() const;
	public:
		/**
		*	����������
		*/
		bool containsTouchPoint(const math::Vector2& touchPoint, std::vector<BoxDrawProtocol*>& boxes);
		/**
		*	���������ĺ�����Ϣ
		*/
		bool getBoxesOfSharedPoint(const math::Vector3& worldPoint, std::vector<BoxDrawProtocol*>& boxes);
	protected:
		/**
		*	ע���¼�
		*/
		void registerBoxEvent(BoxDrawProtocol* box);
		/**
		*	�Ƴ��¼�
		*/
		void unregisterBoxEvent(BoxDrawProtocol* box);
		/**
		*	��ȡ��ֵ
		*/
		std::string getRectKey(const math::Rect& rect);
	private:
		// ����
		std::map<int, BoxDrawProtocol*> _boxes;
		// ���ӻ���
		BoxDraw* _boxDraw = nullptr;
		// ���ӱ��
		int _increaseBoxID = 0;
		// ��С���δ�С
		int _minRectWidth = 20;
		int _minRectHeight = 20;
	};

#define G_BOXSPACE sys::Instance<render::BoxSpace>::getInstance()
}