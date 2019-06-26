#include "Base/Types.h"

namespace sys
{
	class Pipe
	{
	public:
		Pipe(const char* name);
		~Pipe();
	public:
		void listen();
		void write();
		void read();
	private:
		std::string m_strName;
	};
}