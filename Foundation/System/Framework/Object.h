#pragma once

namespace sys
{
	class Object
	{
	public:
		Object(long id = 0);
		virtual ~Object();
	public:
		virtual long getID() const;

		void retain();

		void release();

		void disponse();

		void autoRelease();
	public:
		int RetainCount;
	private:
		long _id;
		bool _bAutoRelease;
	};
}