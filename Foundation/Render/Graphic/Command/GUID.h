#pragma once

namespace render
{
	/**
	*	guid
	*/
	class GUID
	{
	private:
		GUID();
		~GUID();
	public:
		/**
		*	获取一个id
		*/
		static int getID();
		// 重置ID索引
		static void reset();
	private:
		static int s_nID;
	};
}