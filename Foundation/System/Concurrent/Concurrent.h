#pragma once

#include "Base/Types.h"
#include "Thread/Mutex.h"
#include "Framework/Object.h"

namespace sys
{
	// ��������
	// ʹ��finish���������ͷŵ�ǰ��
	class Concurrent : public sys::Object
	{
	protected:
		struct Data
		{
			int32 type;
			Data(int32 type)
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
		typedef std::function<void(const char* data, int32 size)> ReadDataCallback;

		struct ReadData : public Data
		{
			char* data;
			int32 offset;
			int32 size;
			ReadDataCallback callback;

			ReadData(char* data, int32 offset, int32 size, ReadDataCallback callback)
				:Data((int32)EET_READ)
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
			int32 size;

			WriteData(const char* data, int32 size)
				:Data((int32)EET_WRITE)
			{
				this->data = data;
				this->size = size;
			}
		};

		struct FinishData : public Data
		{
			FinishData()
				:Data((int32)EET_FINISH)
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
		bool read(char* data, int32 offset, int32 size, ReadDataCallback callback);
		// д������
		bool write(const char* data, int32 size);
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
	};
}