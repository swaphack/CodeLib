#pragma once

namespace ue
{
	class Config
	{
	public:
		virtual ~Config() {}
	public:
		virtual void Dispose() = 0;
	};
}
