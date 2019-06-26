#include "Set.h"
#include "Random.h"

#include <cstdint>

namespace maths
{
	// ¸ÅÂÊ
	namespace probability
	{
		class Item
		{
		public:
			Item(uint64_t value);
			~Item();
		public:
			void setValue(uint64_t value);
			uint64_t getValue();
		private:
			uint64_t m_nValue;
		};

		class Items : public Set<Item>
		{
		public:
			virtual bool operator == (const Items& other)
			{
				Items& temp = (Items&)other;
				if (this->empty() && temp.empty())
				{
					return true;
				}

				if (this->count() != temp.count())
				{
					return false;
				}

				for (size_t i = 0; i < this->count(); i++)
				{
					if (!this->contains(temp.item(i)))
					{
						return false;
					}
				}
				return true;
			}
		};

		class Event;
		class Space : public Set<uint64_t>
		{
		public:
			bool pickOne(uint64_t count, Items& e)
			{
				e.clear();
				if (count == 0)
				{
					return false;
				}
				while (count > 0)
				{
					uint64_t rand = Random::randNumber(this->count());
					e.append(this->item(rand));
					count--;
				}

				return true;
			}
			bool pick(uint64_t count, Event& e)
			{
				e.clear();

				if (count == 0)
				{
					return false;
				}	


			}
		};  
	}
}