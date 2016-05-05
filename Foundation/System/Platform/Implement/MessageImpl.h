#pragma once

namespace sys
{
	class MessageImpl
	{
	public:
		virtual ~MessageImpl() = 0;
	public:
		virtual void setBody(void* msg) = 0;
		virtual void* getBody() = 0;
	protected:
	private:
	};
}