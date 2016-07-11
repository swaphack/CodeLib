#pragma once

#include "Arithmetical/import.h"
#include "IO/import.h"
#include "Memory/import.h"
#include "Control/import.h"

namespace idea
{
	// ����
	class Brain
	{
	public:
		Brain();
		virtual ~Brain();
	public:
		// �����豸
		Input* getInput();
		// ����豸
		Output* getOutput();
		// ������
		Arithmetical* getArithmetical();
		// �洢
		Memory* getMemory();

		void update();
	protected:
		// ������
		Control* _control;
		// ������
		Arithmetical* _arithmetical;
		// �����豸
		Input* _input;
		// ����豸
		Output* _output;
		// �洢
		Memory* _memory;
	};
}