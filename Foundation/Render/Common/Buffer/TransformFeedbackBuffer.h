#pragma once

#include "NoNamedBuffer.h"

namespace render
{
	class TransformFeedbackBuffer : public NoNamedBuffer
	{
	public:
		TransformFeedbackBuffer();
		virtual ~TransformFeedbackBuffer();
	public:
		void setBufferSize(int size);
	};
}
