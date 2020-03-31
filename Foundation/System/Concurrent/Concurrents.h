#pragma once

#include <set>

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
		void addConcurrent(Concurrent* task);
		void removeConcurrent(Concurrent* task);
		void removeAllConcurrents();
	private:
		std::set<Concurrent*> _set;
	};
}