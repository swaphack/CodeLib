#pragma once

#include "Identity.h"

namespace game
{
	// �������
	class IResult
	{
	public:
		virtual ~IResult();
	public:
		// ���ӷ���
		virtual int getHostScore() const = 0;
		// �Ͷӷ���
		virtual int getVisiterScore() const = 0;
	};
}