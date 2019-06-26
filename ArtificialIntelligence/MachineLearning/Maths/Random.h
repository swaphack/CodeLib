
namespace maths
{
	class Random
	{
	public:
		// 设置种子
		static void setSeed(int seed);
		// 随机一个整数
		static int randNumber(int min, int max);
		// 随机一个整数
		static int randNumber(int max);
		// 随机一个整数
		static int randNumber();
		// 随机一个浮点数[0,1]
		static float randFloat();

		template<typename T>
		static T rand(T data[], int length);
	private:
	};

	template<typename T>
	T Random::rand(T data[], int length)
	{
		if (data == nullptr)
		{
			return default(T);
		}

		int index = randNumber(length);

		return data[index];
	}

}