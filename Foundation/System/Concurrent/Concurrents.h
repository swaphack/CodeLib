#pragma once

namespace sys
{
	class Concurrent;

	// 并发处理集
	class Concurrents
	{
	private:
		Concurrents();
		virtual ~Concurrents();
	public:
		static Concurrents* getInstance();
	public:
		void addConcurrent(Concurrent* io);
		void removeConcurrent(Concurrent* io);
	private:
	};
}