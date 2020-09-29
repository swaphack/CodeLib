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
		Tuple2()
		{}
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
		Tuple3()
		{}
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
		Tuple4()
		{}
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
		Tuple5()
		{}
		Tuple5(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5)
			:t1(t1), t2(t2), t3(t3), t4(t4), t5(t5)
		{}
	};

	template<typename T1, typename T2>
	inline Tuple2<typename T1, typename T2> make_tuple2(const T1& t1, const T2& t2)
	{
		return Tuple2<T1, T2>(t1, t2);
	}

	template<typename T1, typename T2, typename T3>
	inline Tuple3<typename T1, typename T2, typename T3> make_tuple3(const T1& t1, const T2& t2, const T3& t3)
	{
		return Tuple3<T1, T2, T3>(t1, t2, t3);
	}

	template<typename T1, typename T2, typename T3, typename T4>
	inline Tuple4<typename T1, typename T2, typename T3, typename T4> make_tuple4(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
	{
		return Tuple4<T1, T2, T3, T4>(t1, t2, t3, t4);
	}

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	inline Tuple5<typename T1, typename T2, typename T3, typename T4, typename T5> make_tuple5(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5)
	{
		return Tuple5<T1, T2, T3, T4, T5>(t1, t2, t3, t4, t5);
	}
}