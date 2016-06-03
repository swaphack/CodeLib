#pragma once

#include "../AI/ai.h"
#include "Arithmetical.h"
#include "Input.h"
#include "Output.h"
#include "Memory.h"

namespace idea
{
	// ����
	class Control : public IWorker
	{
	public:
		Control();
		~Control();
	public:
		void setInput(Input* input);
		void setOutput(Output* output);
		void setArithmetical(Arithmetical* arithmetical);
		void setMemory(Memory* memory);

		virtual Result* run(Event* e);
	protected:
		Input* getInput();
		Output* getOutput();
		Arithmetical* getArithmetical();
		Memory* getMemory();
	private:
		Arithmetical* _arithmetical;
		Input* _input;
		Output* _output;
		Memory* _memory;
	};
}