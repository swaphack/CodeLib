#pragma once
#include "../interface/IField.h"

namespace game
{
	class Field : public IField
	{
	public:
		Field(float width, float height);
	public:
		virtual float getWidth() const;

		virtual float getHeight() const;

		virtual bool contains(const Point& point);
	private:
		float m_width;
		float m_height;
	};
}