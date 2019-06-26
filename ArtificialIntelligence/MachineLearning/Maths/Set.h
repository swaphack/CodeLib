#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>

namespace maths
{
	// 集合
	template<typename T>
	class Set
	{
	public:
		Set<T>();
		Set<T>(Set<T>& data);
		~Set<T>();
	public:
		// 添加
		bool append(const T& t);
		// 移除
		bool remove(const T& t);
		// 选择项
		T& item(uint64_t index);
		// 数据
		const T* data() const;
		// 数据
		T* data();
		// 数量
		uint64_t count() const;
		// 数量
		uint64_t count();
		// 包含
		bool contains(const T& t);
		// 包含
		bool contains(const Set<T>& data);

		// 相等
		bool equal(const Set<T>& data);

		// 交集
		Set<T> intersectSet(const Set<T>& data);
		// 并集
		Set<T> unionSet(const Set<T>& data);
		// 差集
		Set<T> differentSet(const Set<T>& data);

		// 空集
		bool empty();

		// 清除
		void clear();

		// 赋值
		Set<T>& operator=(const Set<T>& data);

		// 差集
		Set<T>& operator-=(const Set<T>& data);
	protected:
		void resize(uint64_t nCapacity);
	private:
		T* m_pData = nullptr;
		// 个数
		uint64_t m_nCount = 0;
		// 分配空间
		uint64_t m_nCapacity = 0;
	};

	template<typename T>
	void Set<T>::resize(uint64_t nCapacity)
	{
		if (nCapacity <= m_nCapacity)
		{
			return;
		}

		int nSize = sizeof(T);
		T* pData = new T[nCapacity];
		memset(pData, 0, nCapacity * nSize);
		if (m_pData != nullptr && m_nCount > 0)
		{
			memcpy(pData, m_pData, m_nCount * nSize);
			delete m_pData;
		}

		m_pData = pData;
		m_nCapacity = nCapacity;
	}

	template<typename T>
	Set<T>& Set<T>::operator-=(const Set<T>& data)
	{
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (this->contains(t))
			{
				this->remove(t);
			}
		}

		return *this;
	}

	template<typename T>
	Set<T>& Set<T>::operator=(const Set<T>& data)
	{
		this->clear();
		Set<T>& temp = (Set<T>&)data;
		if (temp.empty())
		{
			return *this;
		}
		uint64_t nCount = temp.count();
		this->resize(nCount);

		m_nCount = nCount;
		int nSize = sizeof(T);
		memcpy(m_pData, temp.data(), nCount * nSize);

		return *this;
	}

	template<typename T>
	void Set<T>::clear()
	{
		if (m_pData != nullptr)
		{
			delete[] m_pData;
			m_pData = nullptr;
			m_nCount = 0;
			m_nCapacity = 0;
		}
	}

	template<typename T>
	bool Set<T>::empty()
	{
		return m_pData == nullptr || m_nCount == 0;
	}

	template<typename T>
	Set<T> Set<T>::differentSet(const Set<T>& data)
	{
		Set<T> target;
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < m_nCount; i++)
		{
			target.append(m_pData[i]);
		}

		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (data.contains(t))
			{
				target.remove(t);
			}
		}

		return target;
	}

	template<typename T>
	Set<T> Set<T>::unionSet(const Set<T>& data)
	{
		Set<T> target;
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < m_nCount; i++)
		{
			target.append(m_pData[i]);
		}

		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (!target.contains(t))
			{
				target.append(t);
			}
		}

		return target;
	}

	template<typename T>
	Set<T> Set<T>::intersectSet(const Set<T>& data)
	{
		Set<T> target;
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (this->contains(t))
			{
				target.append(t);
			}
		}

		return target;
	}

	template<typename T>
	bool Set<T>::equal(const Set<T>& data)
	{
		if (data.empty() && this.empty())
		{
			return true;
		}
		if (data.count() != this->count())
		{
			return false;
		}
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (!this->contains(t))
			{
				return false;
			}
		}

		return true;
	}

	template<typename T>
	bool Set<T>::contains(const Set<T>& data)
	{
		if (data.empty())
		{
			return true;
		}
		Set<T>& temp = (Set<T>&)data;
		for (size_t i = 0; i < data.count(); i++)
		{
			T& t = temp.item(i);
			if (!this->contains(t))
			{
				return false;
			}
		}

		return true;
	}

	template<typename T>
	bool Set<T>::contains(const T& t)
	{
		if (this->empty())
		{
			return false;
		}

		for (size_t i = 0; i < m_nCount; i++)
		{
			if (m_pData[i] == t)
			{
				return true;
			}
		}

		return false;
	}

	template<typename T>
	uint64_t Set<T>::count()
	{
		return m_nCount;
	}

	template<typename T>
	uint64_t Set<T>::count() const
	{
		return m_nCount;
	}

	template<typename T>
	T* Set<T>::data()
	{
		return m_pData;
	}

	template<typename T>
	const T* Set<T>::data() const
	{
		return m_pData;
	}

	template<typename T>
	T& Set<T>::item(uint64_t index)
	{
		assert(!this->empty());

		assert(index >= 0 && index < m_nCount);

		return m_pData[index];
	}

	template<typename T>
	bool Set<T>::remove(const T& t)
	{
		if (this->empty())
		{
			return false;
		}

		uint64_t nIndex = -1;
		for (size_t i = 0; i < m_nCount; i++)
		{
			if (m_pData[i] == t)
			{
				nIndex = i;
				break;
			}
		}

		if (nIndex != -1)
		{
			for (size_t i = nIndex; i < m_nCount - 1; i++)
			{
				m_pData[i] = m_pData[i + 1];
			}

			m_nCount--;
		}

		return true;
	}

	template<typename T>
	bool Set<T>::append(const T& t)
	{
		if (this->contains(t))
		{
			return false;
		}

		if (m_nCount + 1 > m_nCapacity)
		{
			if (m_nCapacity == 0)
			{
				this->resize(m_nCount + 1);
			}
			else
			{
				this->resize(m_nCapacity * 2);
			}
		}

		m_pData[m_nCount] = t;
		m_nCount++;

		return true;
	}

	template<typename T>
	Set<T>::~Set<T>()
	{
		this->clear();
	}

	template<typename T>
	Set<T>::Set<T>(Set<T>& data)
	{
		*this = data;
	}

	template<typename T>
	Set<T>::Set<T>()
	{
		m_pData = nullptr;
		m_nCount = 0;
		this->resize(2);
	}
}