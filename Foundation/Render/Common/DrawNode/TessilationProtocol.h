#pragma once

namespace render
{
	class TessilationProtocol
	{
	public:
		TessilationProtocol();
		virtual ~TessilationProtocol();
	public:
		/**
		*	设置是否启动细分着色器
		*/
		void setEnableTessilation(bool bEnable);
		/**
		*	是否启动细分着色器
		*/
		bool isTessilationEnable() const;
	public:
		/**
		*	设置细分顶点数
		*/
		void setTessVerticeCount(int value);
		/**
		*	细分顶点数
		*/
		int getTessVerticeCount() const;
		/**
		*	设置细分外部等级
		*/
		void setTessOuterLevel(float value[4]);
		/**
		*	细分外部等级
		*/
		const float* getTessOuterLevel() const;
		/**
		*	设置细分内部等级
		*/
		void setTessInnerLevel(float value[2]);
		/**
		*	细分内部等级
		*/
		const float* getTessInnerLevel() const;
	protected:
		/**
		*	更新细分
		*/
		void updateTessilation();
	protected:
		// 是否启动细分
		bool _bTessilationEnable = false;
		// 细分顶点数, 默认三角形
		int _tessVerticeCount = 3;
		// 细分外部等级
		float _tessOuterLevel[4];
		// 细分内部等级
		float _tessInnerLevel[2];
	};
}
