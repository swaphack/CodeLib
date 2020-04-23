#include "macros.h"

namespace render
{
	class GLVertexArrays
	{
	public: // ¶¥µãÊý×é
		static void genVertexArrays(int size, uint32_t* ary);
		static uint32_t genVertexArray();

		static void bindVertexArrays(uint32_t ary);

		static void deleteVertexArrays(int size, const uint32_t* ary);
		static void deleteVertexArray(uint32_t ary);

		static bool isVertexArrays(uint32_t ary);
	};
}