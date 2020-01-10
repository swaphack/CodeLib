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
		float left;
		// �ұ�����
		float right;
		// ��������
		float top;
		// �ײ�����
		float bottom;
	public:
		Margin();
		Margin(float left, float right, float bottom, float top);
		Margin(const Margin& margin);
		Margin& operator=(const Margin& margin);
	};
}