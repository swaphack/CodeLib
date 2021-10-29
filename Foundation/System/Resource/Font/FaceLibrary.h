#pragma once
#include "Memory/MemoryData.h"
#include <string>
#include "TextDefine.h"
#include "Resource/Image/ImageDetail.h"

namespace sys
{
	class LabelStream;
	class ImageDetail;
	class FontCharDetail;

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
		// �����ַ�
		bool load(const TextDefine& textDefine, int& lineHeight, std::map<std::string, FontCharDetail*>& mapData);
		// ��ȡ�ַ�����
		const FontCharDetail* getCharData(uint64_t ch) const;
		// ��ȡ�ַ�����
		FontCharDetail* getCharData(uint64_t ch);
		// �ͷ�
		void dispose();
	protected:
		// �����ַ�����
		FontCharDetail* loadChar(uint64_t ch, int fontSize);
	private:
		// ������д������
		void writeStream(uint64_t ch, LabelStream* stream, const phy::Color3B& color);
	private:
		void* _face = nullptr;
		int	_fontSize = 0;
		bool _border = false;
		std::map<uint64_t, FontCharDetail*> _datas;
	};
}