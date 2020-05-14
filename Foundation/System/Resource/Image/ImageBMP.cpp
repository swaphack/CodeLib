#include "ImageBMP.h"

using namespace sys;
#if _WIN32
#include <windows.h>
#else

// �ļ�ͷ�ṹ��
typedef struct tagBITMAPFILEHEADER {
	unsigned short bfType;      // 19778��������BM�ַ�������Ӧ��ʮ������Ϊ0x4d42,ʮ����Ϊ19778��������bmp��ʽ�ļ�
	unsigned int bfSize;        // �ļ���С
	unsigned short bfReserved1; // ��������������Ϊ0
	unsigned short bfReserved2; // ��������������Ϊ0
	unsigned int bfOffBits;     // ���ļ�ͷ���������ݵ�ƫ��
} BITMAPFILEHEADER;

//ͼ����Ϣͷ�ṹ��
typedef struct tagBITMAPINFOHEADER {
	unsigned int biSize;        // �˽ṹ��Ĵ�С
	int biWidth;                // ͼ��Ŀ�
	int biHeight;               // ͼ��ĸ�
	unsigned short biPlanes;    // ��ʾbmpͼƬ��ƽ��������Ȼ��ʾ��ֻ��һ��ƽ�棬���Ժ����1
	unsigned short biBitCount;  // һ������ռ��λ����һ��Ϊ24
	unsigned int biCompression; // ˵��ͼ������ѹ�������ͣ�0Ϊ��ѹ����
	unsigned int biSizeImage;   // ����������ռ��С, ���ֵӦ�õ��������ļ�ͷ�ṹ��bfSize-bfOffBits
	int biXPelsPerMeter;        // ˵��ˮƽ�ֱ��ʣ�������/�ױ�ʾ��һ��Ϊ0
	int biYPelsPerMeter;        // ˵����ֱ�ֱ��ʣ�������/�ױ�ʾ��һ��Ϊ0
	unsigned int biClrUsed;     // ˵��λͼʵ��ʹ�õĲ�ɫ���е���ɫ����������Ϊ0�Ļ�����˵��ʹ�����е�ɫ����� 
	unsigned int biClrImportant;// ˵����ͼ����ʾ����ҪӰ�����ɫ��������Ŀ�������0����ʾ����Ҫ��
} BITMAPINFOHEADER;

#endif

//24λͼ������Ϣ�ṹ��
typedef struct _PixelInfo {
	unsigned char b;
	unsigned char g;
	unsigned char r;
} PixelInfo;


ImageBMP::ImageBMP()
{

}

ImageBMP::~ImageBMP()
{

}

bool ImageBMP::load(const std::string& fullpath)
{
	if (fullpath.empty())
	{
		return false;
	}

	FILE* fp;
	fp = fopen(fullpath.c_str(), "rb");
	if (fp == NULL){
		return false;
	}

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	//���ļ����ȡ��Ϣ
	fread(&fileHeader, sizeof(fileHeader), 1, fp);
	fread(&infoHeader, sizeof(infoHeader), 1, fp);

	//����ͷ��Ϣ
	if (fileHeader.bfType != 19778){
		fclose(fp);
		return false;
	}

	int bit_depth = infoHeader.biBitCount;
	int nUnitSize = bit_depth / 8;

	//���㲹����(�����ø��������ĳ��������࣬Ч����λ������ͬ)
	int offset = (bit_depth / 8 * infoHeader.biWidth) % 4;
	if (offset != 0){
		offset = 4 - offset;
	}

	//��̬����һ���ڴ��Դ洢������Ϣ
	int nPerLineSize = nUnitSize * (infoHeader.biWidth + offset);
	int nTotalSize = nPerLineSize * infoHeader.biHeight;
	uint8_t* texels = (uint8_t*)malloc(nTotalSize);

	fread(texels, 1, nTotalSize, fp);

	fclose(fp);

	this->setTextureInfo(nUnitSize);
	this->setPixels(texels, infoHeader.biWidth, infoHeader.biHeight, nUnitSize);

	//�ͷ��ڴ�
	free(texels);

	return true;
}

void ImageBMP::setTextureInfo(int pixel_depth)
{
	switch (pixel_depth)
	{
	case 3:
		setDataFormat(ImageDataFormat::BGR);
		break;
	case 4:
		setDataFormat(ImageDataFormat::BGRA);
		break;
	default:
		break;
	}
}

