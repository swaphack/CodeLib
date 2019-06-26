
namespace maths
{
	class Random
	{
	public:
		// ��������
		static void setSeed(int seed);
		// ���һ������
		static int randNumber(int min, int max);
		// ���һ������
		static int randNumber(int max);
		// ���һ������
		static int randNumber();
		// ���һ��������[0,1]
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