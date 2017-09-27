#pragma once

#include <string>
#include <queue>
#include <functional>
#include "Thread/Mutex.h"
#include "Framework/Object.h"

namespace sys
{
	// 并发处理
	class Concurrent : public sys::Object
	{
	protected:
		struct Data
		{
			int type;
			Data(int type)
			{
				this->type = type;
			}
		};

		enum EventType
		{
			EET_READ,
			EET_WRITE,
			EET_FINISH,
		};

		// 读取数据回调
		typedef std::function<void(const char* data, int size)> ReadDataCallback;

		struct ReadData : public Data
		{
			char* data;
			int offset;
			int size;
			ReadDataCallback callback;

			ReadData(char* data, int offset, int size, ReadDataCallback callback)
				:Data((int)EET_READ)
			{
				this->data = data;
				this->offset = offset;
				this->size = size;
				this->callback = callback;
			}
		};

		struct WriteData : public Data
		{
			const char* data;
			int size;

			WriteData(const char* data, int size)
				:Data((int)EET_WRITE)
			{
				this->data = data;
				this->size = size;
			}
		};

		struct FinishData : public Data
		{
			FinishData()
				:Data((int)EET_FINISH)
			{}
		};

		// 读取函数
		typedef std::function<void(ReadData* data)> ReadFunc;
		// 写入函数
		typedef std::function<void(WriteData* data)> WriteFunc;
		
	public:
		Concurrent();
		virtual ~Concurrent();
	public:
		// 读取数据
		bool read(char* data, int offset, int size, ReadDataCallback callback);
		// 写入数据
		bool write(const char* data, int size);
		// 结束操作
		void finish();
		// 设置读取函数
		void setReadFunc(ReadFunc func);
		// 设置写入函数
		void setWriteFunc(WriteFunc func);
		// 是否设置读取函数
		bool isSetReadFunc();
		// 是否设置写入函数
		bool isSetWriteFunc();
	private:
		void init();
	protected:
		Mutex _mutex; 
	private:
		// 读取解析
		ReadFunc _readFunc;
		// 写入解析
		WriteFunc _writeFunc;
		// 事件队列
		std::queue<Data*> _eventQueue;
		// 是否正在运行中
		bool _bRunning;
	};
}