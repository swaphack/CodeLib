#pragma once

#include "macros.h"

struct AVFormatContext;

namespace render
{
	// ��ƵͼƬ֡
	class VideoFrameImage : public ImageDetail
	{
	public:
		VideoFrameImage();
		virtual ~VideoFrameImage();
	public:
		void init(int format, int internalFormat, uint8_t* pixels, uint32_t width, uint32_t height);
	protected:
	private:
	};

	// ��ƵƬ��
	class VideoAudioClip : public AudioDetail
	{
	public:
		VideoAudioClip();
		virtual ~VideoAudioClip();
	public:
		void init(uint8_t* data, int frameSize);
		void init(uint8_t* data, int frameSize, int channels, int64_t channelLayout, int format, int frequency, int samples);
	};

	// ffmpeg ����
	class MediaFFmpeg : public MediaDetail, public IMediaLoader
	{
	public:
		MediaFFmpeg();
		virtual ~MediaFFmpeg();
	public:
		// ������Ƶ
		virtual void load(const MediaDefine& mediaDefine);
		// ��ȡ��һ֡��Ƶ
		virtual ImageDetail* getNextPicture();
		// ��ȡ��һ֡��ƵͼƬ
		virtual AudioDetail* getNextAudio();
		// ��ȡ��һ֡����
		virtual std::string getNextTitle();
		// �Զ���ת����һ֡
		virtual void autoNextFrame();
		// ������Ƶ֡λ��
		virtual void setVideoFrame(mf_s frame);
	protected:
		// ����ffm
		void loadFFM(const MediaDefine& mediaDefine);
		// ��ʼ��
		void initFFmpeg(const std::string& path);
		// ж��ffm
		void disposeFFM();
		// ��ȡ�ļ��в�ͬ��Դ���ڵ�λ��
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
		// ��Ƶ
		VideoAudioClip _audio;
		// �ı�
		std::string _text;
		/// ��ʽ������
		AVFormatContext* _formatContext;
		// �Ƿ��ʼ��ffm
		static bool s_bInitFFmpeg;
	};
}