#pragma once

namespace render
{
	// �Ӵ�����
	struct ViewParameter
	{
	public:
		float xLeft = 0;
		float xRight = 0;
		float yBottom = 0;
		float yTop = 0;
		float zNear = 0.1f;
		float zFar = 1000;
	public:
		inline float getWidth() const { return xRight - xLeft; }
		inline float getHeight() const { return yTop - yBottom; }
		inline float getDepth() const { return zFar; }

		/**
		*	��ȡ��Ļ���� x,y,z [-1,1] ֮��
		*/
		inline math::Vector3 getScreenPosition(const math::Vector3& percent)
		{
			float w = getWidth();
			float h = getHeight();
			float d = getDepth();

			return math::Vector3(
				(percent.getX() + 0.5f) * w,
				(percent.getY() + 0.5f) * h,
				(percent.getZ() + 0.5f) * d);
		}
	};
}
