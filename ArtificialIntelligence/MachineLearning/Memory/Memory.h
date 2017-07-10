#pragma once

namespace ml
{
	class Memory
	{
	public:
		Memory();
		~Memory();
	public:
		template<class T>
		void serialize(T t);

		template<class T>
		T deserialize();
	protected:
	private:
	};
}