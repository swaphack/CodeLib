#pragma once

namespace sys
{
	/**
	*	��Ե
	*/
	struct Margin
	{
	public:
		// �������
		float left = 0;
		// �ұ�����
		float right = 0;
		// ��������
		float top = 0;
		// �ײ�����
		float bottom = 0;
	public:
		Margin();
		Margin(float left, float right, float bottom, float top);
		Margin(const Margin& margin);
		Margin& operator=(const Margin& margin);
	};
}