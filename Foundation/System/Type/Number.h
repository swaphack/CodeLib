#pragma once

namespace sys
{
	typedef float size_n;

	class Number
	{
	public:
		Number(size_n value);
		~Number(); 
	public:
		size_n getValue();
		void setValue(size_n value);

		virtual Number operator+(size_n value);
		virtual Number operator-(size_n value);
		virtual Number operator*(size_n value);
		virtual Number operator/(size_n value);

		virtual Number& operator+=(size_n value);
		virtual Number& operator-=(size_n value);
		virtual Number& operator*=(size_n value);
		virtual Number& operator/=(size_n value);

		virtual bool operator>(size_n value);
		virtual bool operator>=(size_n value);
		virtual bool operator<(size_n value);
		virtual bool operator==(size_n value);
	protected:
	private:
		size_n _value;
	};
}