#pragma once

namespace math
{
	/**
	*	对点进行排序
	*	左下角到右上角
	*/
	static inline int CompareFloat(const float& a, const float& b)
	{
		if (a < b) return -1;
		else if (a > b) return 1;
		else return 0;
	}

	/**
	*	对点进行排序
	*	左下角到右上角
	*/
	static inline int CompareInt(const int& a, const int& b)
	{
		if (a < b) return -1;
		else if (a > b) return 1;
		else return 0;
	}

	/**
	*	对点进行排序
	*	左下角到右上角
	*/
	static inline int CompareIntPtr(const void* a, const void* b)
	{
		return *(int*)a - *(int*)b;
	}

	/**
	*	对点进行排序的规则
	*	左下角到右上角
	*/
	struct CompareVector2
	{
		bool operator()(const Vector2& a, const Vector2& b) const
		{
			int ret0 = CompareFloat(a.getX(), b.getX());
			int ret1 = CompareFloat(a.getX(), b.getX());

			if (ret0 == -1) return true;
			else if (ret0 == 1) return false;
			else return ret1 == -1;
		}
	};

	/**
	*	对点进行排序的规则
	*	左下角到右上角
	*/
	struct CompareVector3
	{
		bool operator()(const Vector3& a, const Vector3& b)const
		{
			int ret0 = CompareFloat(a.getX(), b.getX());
			int ret1 = CompareFloat(a.getY(), b.getY());
			int ret2 = CompareFloat(a.getZ(), b.getZ());

			if (ret0 == -1) return true;
			else if (ret0 == 1) return false;
			else if (ret1 == -1) return true;
			else if (ret1 == 1) return false;
			else return ret2 == -1;
		}
	};
}