#pragma once

#include <string>
#include <queue>
#include <functional>
#include "Thread/Mutex.h"
#include "Framework/Object.h"

namespace sys
{
	// ��������
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

		// ��ȡ���ݻص�
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

		// ��ȡ����
		typedef std::function<void(ReadData* data)> ReadFunc;
		// д�뺯��
		typedef std::function<void(WriteData* data)> WriteFunc;
		
	public:
		Concurrent();
		virtual ~Concurrent();
	public:
		// ��ȡ����
		bool read(char* data, int offset, int size, ReadDataCallback callback);
		// д������
		bool write(const char* data, int size);
		// ��������
		void finish();
		// ���ö�ȡ����
		void setReadFunc(ReadFunc func);
		// ����д�뺯��
		void setWriteFunc(WriteFunc func);
		// �Ƿ����ö�ȡ����
		bool isSetReadFunc();
		// �Ƿ�����д�뺯��
		bool isSetWriteFunc();
	private:
		void init();
	protected:
		Mutex _mutex; 
	private:
		// ��ȡ����
		ReadFunc _readFunc;
		// д�����
		WriteFunc _writeFunc;
		// �¼�����
		std::queue<Data*> _eventQueue;
		// �Ƿ�����������
		bool _bRunning;
	};
}