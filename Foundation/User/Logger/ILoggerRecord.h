#pragma once

namespace user
{
	class ILoggerRecord
	{
	public:
		virtual long getID() = 0;

		virtual const char* getString() = 0;
	};

	template<class T>
	class IGenerateLoggerRecord
	{
	public:
		virtual ILoggerRecord* generateRecord(T* t) = 0;
	protected:
	private:
	};
}