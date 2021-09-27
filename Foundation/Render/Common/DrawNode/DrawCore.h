#pragma once

#include "mathlib.h"
#include <string>
#include <map>

namespace render
{

	class Node;
	class Camera;
	class DrawTextureCache;
	class Mesh;
	class ShaderProgram;
	class Material;

	/**
	*	绘制参数
	*/
	struct DrawCoreParameter
	{
		Node* node = nullptr;
		ShaderProgram* program = nullptr;
		Mesh* mesh = nullptr;
		Material* material = nullptr;
		DrawTextureCache* textureCache = nullptr;
	};

	/**
	*	绘制核心
	*/
	class DrawCore
	{
	public:
		DrawCore();
		virtual ~DrawCore();
	public:
		/**
		*	使用代码设置材质
		*/
		void beginApply(const DrawCoreParameter& parameter);
		/**
		*	使用代码
		*/
		void endApply(const DrawCoreParameter& parameter);
	public:
		/**
		*	使用shader设置材质
		*/
		void beginApplyWithShader(const DrawCoreParameter& parameter);
		/**
		*	使用shader
		*/
		void endApplyWithShader(const DrawCoreParameter& parameter);
	public:
		// 开始更新着色器uniform值
		void startUpdateShaderUniformValue(const DrawCoreParameter& parameter);
		// 结束更新着色器attrib值
		void startUpdateShaderVertexValue(const DrawCoreParameter& parameter);
		// 结束更新着色器uniform值
		void endUpdateShaderUniformValue(const DrawCoreParameter& parameter);
		// 结束更新着色器attrib值
		void endUpdateShaderVertexValue(const DrawCoreParameter& parameter);
	protected:
		// 更新环境
		void updateEnvUniformVallue(const DrawCoreParameter& parameter);
		// 更新矩阵
		void updateMatrixUniformValue(const DrawCoreParameter& parameter);
		// 更新材质
		void updateMaterialUniformValue(const DrawCoreParameter& parameter);
		// 更新纹理
		void updateTexturesUnifromValue(const DrawCoreParameter& parameter);

		void releaseMaterialUniformValue(const DrawCoreParameter& parameter);
		void releaseTextureUniformValue(const DrawCoreParameter& parameter);
	protected:
		// 应用光照着色器
		void applyLightShader(const DrawCoreParameter& parameter);
		// 更新单色光源，距离最近
		void updateNearestLightUniformValue(const DrawCoreParameter& parameter);
		// 更新所有光源
		void updateAllLightsUniformValue(const DrawCoreParameter& parameter);
	protected:
		// 自定义类型
		void updateSelfDefinedUniformValue(const DrawCoreParameter& parameter);
	public:
		/**
		*	设置临时矩阵
		*/
		void setTempMatrix(const math::Matrix4x4& matrix);
		/**
		*	重置临时矩阵
		*/
		void resetTempMatrix();
	public:
		/**
		*	获取世界矩阵
		*/
		math::Matrix4x4 getWorldMatrix(const Node* node);
		/**
		*	获取摄像头
		*/
		Camera* getCamera(const Node* node);
	private:
		/**
		*	临时矩阵
		*/
		math::Matrix4x4 _tempMatrix;
	};

#define G_DRAWCORE sys::Instance<render::DrawCore>::getInstance()
}
