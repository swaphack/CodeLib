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
		*	��ȡһ��id
		*/
		static int getID();
		// ����ID����
		static void reset();
	private:
		static int s_nID;
	};
}