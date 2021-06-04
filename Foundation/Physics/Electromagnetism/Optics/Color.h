#pragma once

#include <cstdint>
#include "mathlib.h"

namespace phy
{
	/// <summary>
	/// ��ɫ
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	class Color3 : public math::Vector<T, 3>
	{
		const int Length = 3;
		typedef math::Vector<T, 3> base;
	public:
		Color3() {}
		virtual ~Color3() {}
	public:
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color3& color)
		{
			for (int i = 0; i < Length; i++)
			{
				if (base::getValue(i) != color[i])
				{
					return false;
				}
			}

			return true;
		}
		/**
		*	���
		*/
		Color3 operator*(const Color3& value) const
		{
			Color3 target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] *= value[i];
			}
			return target;
		}
		/**
		*	���
		*/
		Color3 operator/(const Color3& value) const
		{
			Color3 target = *this;
			for (int i = 0; i < Length; i++)
			{
				assert(value[i] != 0);
				target[i] /= value[i];
			}
			return target;
		}

		/**
		*	���
		*/
		Color3& operator*=(const Color3& value)
		{
			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) * value[i]);
			}
			return *this;
		}
		/**
		*	���
		*/
		Color3& operator/=(const Color3& value)
		{
			for (int i = 0; i < Length; i++)
			{
				assert(value[i] != 0);

				base::setValue(i, base::getValue(i) / value[i]);
			}
			return *this;
		}
	};

	/// <summary>
	/// ��ɫ
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	class Color4 : public math::Vector<T, 4>
	{
		const int Length = 4;
		typedef math::Vector<T, 4> base;
	public:
		Color4() {}
		virtual ~Color4() {}
	public:
		/**
		*	�Ƿ����
		*/
		bool isEquals(const Color4& color)
		{
			for (int i = 0; i < Length; i++)
			{
				if (base::getValue(i) != color[i])
				{
					return false;
				}
			}

			return true;
		}
		/**
		*	���
		*/
		Color4 operator*(const Color4& value) const
		{
			Color4 target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] *= value[i];
			}
			return target;
		}
		/**
		*	���
		*/
		Color4 operator/(const Color4& value) const
		{
			Color4 target = *this;
			for (int i = 0; i < Length; i++)
			{
				assert(value[i] != 0);
				target[i] /= value[i];
			}
			return target;
		}

		/**
		*	���
		*/
		Color4& operator*=(const Color4& value)
		{
			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) * value[i]);
			}
			return *this;
		}
		/**
		*	���
		*/
		Color4& operator/=(const Color4& value)
		{
			for (int i = 0; i < Length; i++)
			{
				assert(value[i] != 0);

				base::setValue(i, base::getValue(i) / value[i]);
			}
			return *this;
		}
	};
}
