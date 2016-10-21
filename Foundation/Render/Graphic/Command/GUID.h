#pragma once

namespace render
{
	class GUID
	{
	private:
		GUID();
		~GUID();
	public:
		static int getID();
		static void resetID();
	private:
		static int s_nID;
	};
}