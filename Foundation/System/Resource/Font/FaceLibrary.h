#pragma once
#include "Memory/MemoryData.h"
#include <string>
#include "TextDefine.h"

namespace sys
{
	// ÿ���ַ��洢������
	struct FT_CHAR_DATA
	{
	public:
		// ʵ����ʾ��������
		int width = 0;
		int height = 0;

		// ʵ�ʱ�׼���-����,���
		int advX = 0;
		int advY = 0;

		// ����ԭ��(0,0)������λͼ��������ص�ˮƽ����.�����������ص���ʽ��ʾ�� 
		int deltaX = 0;
		int deltaY = 0;

		// �ַ�bit����
		MemoryData data;
	public:
		FT_CHAR_DATA();
		~FT_CHAR_DATA();
	};

	class LabelStream;

	/**
	*	���棨�̶���С�������
	*/ 
	class FaceLibrary
	{
	public:
		FaceLibrary();
		~FaceLibrary();
	public:
		// ��ʼ��FTģ��
		bool init(void* lib, const std::string& filepath, int size);
	public:
		void setBorder(bool border);
		bool isBorder() const;
	public:
		// �����ı�
		bool load(const TextDefine& textDefine, LabelStream* stream);
	protected:
		// ��ȡ�ַ�����
		FT_CHAR_DATA* getCharData(uint64_t ch);
		// �����ַ�����
		FT_CHAR_DATA* loadChar(uint64_t ch, int fontSize);
		// �Ƿ�FTģ��
		void dispose();
	private:
		// ������д������
		void writeStream(uint64_t ch, LabelStream* stream, const phy::Color3B& color);
	private:
		void* _face = nullptr;
		int	_fontSize = 0;
		bool _border = false;
		std::map<uint64_t, FT_CHAR_DATA> _datas;
	};
}