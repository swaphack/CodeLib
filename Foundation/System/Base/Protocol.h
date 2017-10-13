#pragma once

#include <string>

namespace sys
{
	class Name
	{
	public:
		Name() {}
		virtual ~Name() {}
	public:
		void setName(const char* name)
		{
			if (name)
			{
				_name = name;
			}
		}

		void setName(const std::string& name)
		{
			_name = name;
		}

		const char* getName() const
		{
			return _name.c_str();
		}
	private:
		std::string _name;
	};

	class Identify
	{
	public:
		Identify() :_id(0) {}
		virtual ~Identify() {}
	public:
		void setID(int id)
		{
			_id = id;
		}
		int getID()
		{
			return _id;
		}
	private:
		int _id;
	};
}