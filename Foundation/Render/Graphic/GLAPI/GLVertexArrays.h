#include "macros.h"

namespace render
{
	class GLVertexArrays
	{
	public: // ��������
		static void genVertexArrays(int size, uint32_t* arys);
		static uint32_t genVertexArray();

		static void createVertexArrays(int size, uint32_t* arys);
		static uint32_t createVertexArray();

		static void bindVertexArray(uint32_t ary);

		static void deleteVertexArrays(int size, const uint32_t* arys);
		static void deleteVertexArray(uint32_t ary);

		static bool isVertexArray(uint32_t ary);
	};
}