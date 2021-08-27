#pragma once

#include <string>

namespace math
{
	/**
	*	´óÊı
	*/
	class BigNumber
	{
	public:
		BigNumber(const std::string& number)
		{
			_number = number;
		}
		~BigNumber()
		{

		}
	public:

	private:
		std::string _number;
	};
}