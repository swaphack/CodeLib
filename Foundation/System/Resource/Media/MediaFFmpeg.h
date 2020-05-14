#pragma once

#include "IMediaLoader.h"
#include "../Image/ImageDetail.h"
#include "MediaDetail.h"
#include "AudioDetail.h"

struct AVFormatContext;

namespace sys
{
	// ��ƵͼƬ֡
	class VideoFrameImage : public ImageDetail
	{
	public:
		VideoFrameImage();
		virtual ~VideoFrameImage();
	public:
		void init(ImageDataFormat format, uint8_t* pixels, uint32_t width, uint32_t height, int nUnitSize);
	protected:
	private:
	};

	// ��ƵƬ��
	class VideoAudioClip : public AudioDetail
	{
	public:
		VideoAudioClip();
		VideoAudioClip(const VideoAudioClip& detail);
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
		virtual bool load(const std::string& filepath);
		// ��ȡ��һ֡��Ƶ
		virtual ImageDetail* getNextPicture();
		// ��ȡ��һ֡��ƵͼƬ
		virtual AudioDetail* getNextAudio();
		// ��ȡ��һ֡����
		virtual std::string getNextTitle();
		// �Զ���ת����һ֡
		virtual void autoNextFrame();
		// ������Ƶ֡λ��
		virtual void setVideoFrame(float frame);
	protected:
		// ����ffm
		void loadFFM(const std::string& filepath);
		// �ӱ��ؼ���
		bool loadFromLocalFile(const std::string& fullpath);
		// ������������
		bool loadFromRemoteUrl(const std::string& path);
		// ж��ffm
		void disposeFormatContext();
		// ��ȡ�ļ��в�ͬ��Դ���ڵ�λ��
		void getStreamIndex(int type, int& streamIndex);
	private:
		// ��Ƶ��λ��
		int _videoStream = -1;
		// ��Ƶ��λ��
		int _audioStream = -1;
		// ������λ��
		int _subTitleStream = -1;
		// ͼƬ
		VideoFrameImage _image;
		// ��Ƶ
		VideoAudioClip _audio;
		// �ı�
		std::string _text;
		/// ��ʽ������
		AVFormatContext* _formatContext = nullptr;
		// �Ƿ��ʼ��ffm
		static bool s_bInitFFmpeg;
	};
}