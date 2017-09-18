#pragma once

#include "macros.h"

struct AVFormatContext;

namespace render
{
	// ��ƵͼƬ֡
	class VideoFrameImage : public Image
	{
	public:
		VideoFrameImage();
		virtual ~VideoFrameImage();
	public:
		void init(int format, int internalFormat, uchar* pixels, uint width, uint height);
	protected:
	private:
	};

	// ffmpeg ����
	class FFmpeg : public Media, public IMediaLoader
	{
	public:
		FFmpeg();
		virtual ~FFmpeg();
	public:
		// ������Ƶ
		virtual void load(const MediaDefine& mediaDefine);
		// ��ȡ��һ֡��Ƶ
		virtual Image* getNextPicture();
		// �Զ���ת����һ֡
		virtual void autoNextFrame();
		// ������Ƶ֡λ��
		virtual void setVideoFrame(mf_s frame);
	protected:
		// ����ffm
		void loadFFM(const MediaDefine& mediaDefine);
		// ��ʼ��
		void initFFmpeg(const char* path);
		// ж��ffm
		void disposeFFM();

		void getStreamIndex(int type, int& streamIndex);
	private:
		// ��Ƶ��λ��
		int _videoStream;
		// ��Ƶ��λ��
		int _audioStream;
		// ������λ��
		int _subTitleStream;
		// ͼƬ
		VideoFrameImage _image;
		// �ı�
		std::string _text;
		AVFormatContext* _formatContext;
		// �Ƿ��ʼ��ffm
		static bool s_bInitFFmpeg;
	};
}