#pragma once

#include <map>
#include <string>

namespace search
{
	// ͳ��
	class Statistic
	{
	public:
		// �ؼ�����������
		std::map<std::string, int>	keySearchCounts;
	public:
		// ��ӹؼ��ֵĴ���
		void addSearchCount(const std::string& key, int count = 1);
		// ���ùټ��ӵ���������
		void setSearchCount(const std::string& key, int count);
	protected:
	private:
	};
}