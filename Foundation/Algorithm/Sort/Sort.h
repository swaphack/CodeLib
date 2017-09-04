#pragma once

#include <functional>

namespace alg
{
	template<typename T>
	class Sort
	{
	public:
		typedef std::function<int(const T& a, const T& b)> CompareFunc;

		// ≤Â»Î≈≈–Ú
		static bool InsertionSort(T* values, int count, CompareFunc func);

		// πÈ≤¢≈≈–Ú
		static bool MergeSort(T* values, int count, CompareFunc func);
	private:
		static bool MS_Merge(T* values, int p, int r, int q, CompareFunc func);
		static bool MS_SORT(T* values, int p, int q, CompareFunc func);

	};

	template<typename T>
	bool Sort<T>::MS_SORT(T* values, int p, int q, CompareFunc func)
	{
		if (q <= p || func == nullptr)
		{
			return false;
		}

		int r = (int)ceil((p + q) / 2);

		bool bRet = true;
		bRet &= MS_SORT(values, p, r, func);
		bRet &= MS_SORT(values, r + 1, q, func);
		bRet &= MS_Merge(values, p, r, q, func);

		return bRet;
	}

	template<typename T>
	bool Sort<T>::MS_Merge(T* values, int p, int r, int q, CompareFunc func)
	{
		if (values == nullptr || r < p || q < r || func == nullptr)
		{
			return false;
		}

		int size = q - p + 1;
		T* tempArr = new T[q - p + 1];

		int i = p, j = r + 1, k = 0;
		while (i != r + 1 && j != q + 1)
		{
			if (values[i] > values[j])
				tempArr[k++] = values[j++];
			else
				tempArr[k++] = values[i++];
		}
		while (i != r + 1)
			tempArr[k++] = values[i++];
		while (j != q + 1)
			tempArr[k++] = values[j++];
		for (i = p, k = 0; i <= q; i++, k++)
			values[i] = tempArr[k];

		delete tempArr;
	}

	template<typename T>
	bool Sort<T>::MergeSort(T* values, int count, CompareFunc func)
	{
		if (values == nullptr || count <= 0 || func == nullptr)
		{
			return false;
		}

		return MS_SORT(values, 0, count - 1, func);
	}

	template<typename T>
	bool Sort<T>::InsertionSort(T* values, int count, CompareFunc func)
	{
		if (values == nullptr || count <= 0 || func == nullptr)
		{
			return false;
		}

		for (int i = 1; i < count; i++)
		{
			T temp = values[i];
			int j = i - 1;
			while (j >= 0 && func(temp, values[j]) == -1)
			{
				values[j + 1] = values[j];
				j--;
			}
			values[j + 1] = temp;
		}

		return true;
	}

}