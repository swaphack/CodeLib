#pragma once

namespace render
{
	class Node;
	class ShaderProgram;

	// 光照接口
	class LightProtocol
	{
	public:
		LightProtocol();
		virtual ~LightProtocol();
	public:
		// 支持光源
		void setSupportLight(bool support);
		// 支持光源
		bool isSupportedLight();
		// 支持多光源
		void setSupportMultiLight(bool support);
		// 支持多光源
		bool isSupportedMultiLight();

		// 显示阴影
		void setCastShadow(bool show);
		// 显示阴影
		bool isCastShadow();
		// 接受阴影
		void setRecieveShadow(bool recieve);
		// 接受阴影
		bool isRecieveShadow();
	protected:
		// 支持多光源
		bool _bSupportMultiLight = false;
		// 支持多光源
		bool _bSupportLight = false;

		// 显示阴影
		bool _bCastShadow = false;
		// 接受阴影
		bool _bRecieveShadow = false;
	};
}