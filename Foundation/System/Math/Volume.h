#pragma once

namespace sys
{
	struct Volume
	{
		float width;
		float height;
		float deep;

		Volume() :width(0), height(0), deep(0){}
		Volume(float w, float h, float d = 0) :width(w), height(h), deep(d){}

		void add(const Volume& volume)
		{
			width += volume.width;
			height += volume.height;
			deep += volume.deep;
		}

		void sub(const Volume& volume)
		{
			width -= volume.width;
			height -= volume.height;
			deep -= volume.deep;
		}

		void mult(const Vector& scale)
		{
			width *= scale.x;
			height *= scale.y;
			deep *= scale.z;
		}

		void div(const Volume& volume)
		{
			width /= volume.width;
			height /= volume.height;
			deep /= volume.deep;
		}

		void mult(const float ratio)
		{
			width *= ratio;
			height *= ratio;
			deep *= ratio;
		}

		bool isZero()
		{
			return width == 0.0f && height == 0.0f && deep == 0.0f;
		}

		virtual void operator=(const Volume& volume)
		{
			width = volume.width;
			height = volume.height;
			deep = volume.deep;
		}

		static Volume Zero;
		static Volume One;
	};
	__declspec(selectany) Volume Volume::Zero;
	__declspec(selectany) Volume Volume::One = Volume(1,1,1);
}