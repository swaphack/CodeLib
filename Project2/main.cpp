#pragma once

#include <cstdio>
#include <cmath>
#include <vector>

#define MAX_VALUE 1000

typedef std::vector<int> PrimeValue;

class PrimeSet 
{
public:
	PrimeSet(){}
	~PrimeSet(){}
public:
	PrimeValue::iterator valueBegin() 
	{ 
		return _values.begin(); 
	}
	PrimeValue::iterator valueEnd() 
	{ 
		return _values.end(); 
	}
	void append(int value)
	{
		_values.push_back(value);
	}
	bool isPrime(int value)
	{
		if (value < 2)
		{
			return false;
		}
		int s = floor(sqrt(value));
		for (int i = 2; i <= s; i++)
		{
			if (value % i == 0)
			{
				return false;
			}
		}

		return true;
	}

	bool checkIsPrimeInSet(int value)
	{
		PrimeValue::iterator iter = _values.begin();
		while (iter != _values.end())
		{
			if (value == (*iter))
			{
				return true;
			}
			if (value % (*iter) == 0)
			{
				return false;
			}
		}

		return false;
	}
protected:
private:
	PrimeValue _values;
};

void testPrime()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	PrimeSet cls;

	for (int i = 2; i < MAX_VALUE; i++)
	{
		if (cls.isPrime(i))
		{
			cls.append(i);
		}
	}

	PrimeValue::iterator iter;
	int count;
	for (int i = 2; i < MAX_VALUE; i++)
	{
		iter = cls.valueBegin();
		count = 0;
		while (iter != cls.valueEnd())
		{
			if (*iter > i)
			{
				break;
			}
			count++;
			iter++;
		}
		printf("number %d: %d\n", i, count);
	}
}

std::string mak_p(size_t ctr, const std::string& word, const std::string& ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main(int argc, char** argv)
{
	std::string m = "hello, kety!";
	std::string& md = m;

	std::string n = "s";
	std::string& nd = n;

	const std::string& s = mak_p(1, m, n);

	printf("%s", s.c_str());
	
	return 0;
}