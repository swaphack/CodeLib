#pragma once

namespace math
{
	/**
	*	�Ե��������
	*	���½ǵ����Ͻ�
	*/
	static inline int CompareFloat(const float& a, const float& b)
	{
		if (a < b) return -1;
		else if (a > b) return 1;
		else return 0;
	}

	/**
	*	�Ե��������
	*	���½ǵ����Ͻ�
	*/
	static inline int CompareInt(const int& a, const int& b)
	{
		if (a < b) return -1;
		else if (a > b) return 1;
		else return 0;
	}

	/**
	*	�Ե��������
	*	���½ǵ����Ͻ�
	*/
	static inline int CompareIntPtr(const void* a, const void* b)
	{
		return *(int*)a - *(int*)b;
	}

	/**
	*	�Ե��������Ĺ���
	*	���½ǵ����Ͻ�
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
	*	�Ե��������Ĺ���
	*	���½ǵ����Ͻ�
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