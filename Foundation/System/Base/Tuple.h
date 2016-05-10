#pragma once

namespace sys
{
	template<typename T1, typename T2>
	class Tuple2
	{
	public:
		T1 t1;
		T2 t2;
	public:
		Tuple2(T1 t1, T2 t2) 
			:t1(t1), t2(t2)
		{}
	};

	template<typename T1, typename T2, typename T3>
	class Tuple3
	{
	public:
		T1 t1;
		T2 t2;
		T3 t3;
	public:
		Tuple3(T1 t1, T2 t2, T3 t3) 
			:t1(t1), t2(t2), t3(t3)
		{}
	};

	template<typename T1, typename T2, typename T3, typename T4>
	class Tuple4
	{
	public:
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
	public:
		Tuple4(T1 t1, T2 t2, T3 t3, T4 t4) 
			:t1(t1), t2(t2), t3(t3), t4(t4) 
		{}
	};

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	class Tuple5
	{
	public:
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
		T5 t5;
	public:
		Tuple5(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5)
			:t1(t1), t2(t2), t3(t3), t4(t4), t5(t5)
		{}
	};
}