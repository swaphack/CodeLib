#pragma once

#include "../macros.h"
#include "../Arithmetical/import.h"
#include "../Memory/import.h"

namespace idea
{
	// 控制
	class Control : public IWorker
	{
	public:
		Control();
		virtual ~Control();
	public:
		// 设置逻辑运算单元
		void setArithmetical(Arithmetical* arithmetical);
		// 设置内存管理单元
		void setMemory(Memory* memory);
		// 处理事件
		virtual Result* run(Event* e);
	protected:
		Arithmetical* getArithmetical();
		Memory* getMemory();
	private:
		// 逻辑运算单元
		Arithmetical* _arithmetical;
		// 内存管理单元
		Memory* _memory;
		// ai模块
		AI* _ai;
	};
}