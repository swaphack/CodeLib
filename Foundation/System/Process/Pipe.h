#pragma once

#include <string>

namespace sys
{
	/**
	*	¹ÜµÀ
	*/
	class Pipe
	{
	public:
		Pipe(const std::string& name);
		~Pipe();
	public:
		void listen();
		void write();
		void read();
	private:
		std::string m_strName;
	};
}