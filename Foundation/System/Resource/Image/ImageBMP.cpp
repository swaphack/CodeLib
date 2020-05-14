#include "ImageBMP.h"

using namespace sys;
#if _WIN32
#include <windows.h>
#else

// 文件头结构体
typedef struct tagBITMAPFILEHEADER {
	unsigned short bfType;      // 19778，必须是BM字符串，对应的十六进制为0x4d42,十进制为19778，否则不是bmp格式文件
	unsigned int bfSize;        // 文件大小
	unsigned short bfReserved1; // 保留，必须设置为0
	unsigned short bfReserved2; // 保留，必须设置为0
	unsigned int bfOffBits;     // 从文件头到像素数据的偏移
} BITMAPFILEHEADER;

//图像信息头结构体
typedef struct tagBITMAPINFOHEADER {
	unsigned int biSize;        // 此结构体的大小
	int biWidth;                // 图像的宽
	int biHeight;               // 图像的高
	unsigned short biPlanes;    // 表示bmp图片的平面属，显然显示器只有一个平面，所以恒等于1
	unsigned short biBitCount;  // 一像素所占的位数，一般为24
	unsigned int biCompression; // 说明图象数据压缩的类型，0为不压缩。
	unsigned int biSizeImage;   // 像素数据所占大小, 这个值应该等于上面文件头结构中bfSize-bfOffBits
	int biXPelsPerMeter;        // 说明水平分辨率，用象素/米表示。一般为0
	int biYPelsPerMeter;        // 说明垂直分辨率，用象素/米表示。一般为0
	unsigned int biClrUsed;     // 说明位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）。 
	unsigned int biClrImportant;// 说明对图象显示有重要影响的颜色索引的数目，如果是0，表示都重要。
} BITMAPINFOHEADER;

#endif

//24位图像素信息结构体
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

	//从文件里读取信息
	fread(&fileHeader, sizeof(fileHeader), 1, fp);
	fread(&infoHeader, sizeof(infoHeader), 1, fp);

	//解析头信息
	if (fileHeader.bfType != 19778){
		fclose(fp);
		return false;
	}

	int bit_depth = infoHeader.biBitCount;
	int nUnitSize = bit_depth / 8;

	//计算补齐量(这里用更容易理解的除法和求余，效果和位运算相同)
	int offset = (bit_depth / 8 * infoHeader.biWidth) % 4;
	if (offset != 0){
		offset = 4 - offset;
	}

	//动态创建一块内存以存储像素信息
	int nPerLineSize = nUnitSize * (infoHeader.biWidth + offset);
	int nTotalSize = nPerLineSize * infoHeader.biHeight;
	uint8_t* texels = (uint8_t*)malloc(nTotalSize);

	fread(texels, 1, nTotalSize, fp);

	fclose(fp);

	this->setTextureInfo(nUnitSize);
	this->setPixels(texels, infoHeader.biWidth, infoHeader.biHeight, nUnitSize);

	//释放内存
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

