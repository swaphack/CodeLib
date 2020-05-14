#pragma once

#include <cstdint>
#include <functional>
#include <queue>
#include <string>

#include "Thread/Mutex.h"
#include "Framework/Object.h"

namespace sys
{
	// ��������
	// ʹ��finish���������ͷŵ�ǰ��
	class Concurrent : public Object
	{
	protected:


		enum class EventType
		{
			READ,
			WRITE,
			FINISH,
		};

		struct Data
		{
			EventType type;
			Data(EventType type)
			{
				this->type = type;
			}
		};

		// ��ȡ���ݻص�
		typedef std::function<void(const char* data, int32_t size)> ReadDataCallback;

		struct ReadData : public Data
		{
			char* data;
			int32_t offset;
			int32_t size;
			ReadDataCallback callback;

			ReadData(char* data, int32_t offset, int32_t size, ReadDataCallback callback)
				:Data(EventType::READ)
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
			int32_t size;

			WriteData(const char* data, int32_t size)
				:Data(EventType::WRITE)
			{
				this->data = data;
				this->size = size;
			}
		};

		struct FinishData : public Data
		{
			FinishData()
				:Data(EventType::FINISH)
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
		bool read(char* data, int32_t offset, int32_t size, ReadDataCallback callback);
		// д������
		bool write(const char* data, int32_t size);
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