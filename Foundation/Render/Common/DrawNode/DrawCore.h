#pragma once

#include "mathlib.h"
#include <string>
#include <map>

namespace render
{

	class Node;
	class Camera;

	class DrawNode;
	class MultiDrawNode;
	class ShaderProgram;
	class Texture;
	struct DrawParameter;

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
		*	渲染节点
		*/
		void render(DrawNode* node);
		/**
		*	渲染节点
		*/
		void render(MultiDrawNode* node);
		/**
		*	渲染
		*/
		void render(DrawParameter* parameter);
	public:
		/**
		*	使用代码设置材质
		*/
		void beginApply(DrawParameter* parameter);
		/**
		*	使用代码
		*/
		void endApply(DrawParameter* parameter);
	public:
		/**
		*	使用shader设置材质
		*/
		void beginApplyWithShader(DrawParameter* parameter);
		/**
		*	使用shader
		*/
		void endApplyWithShader(DrawParameter* parameter);
	public:
		// 开始更新着色器uniform值
		void startUpdateShaderUniformValue(const DrawParameter* parameter);
		// 结束更新着色器attrib值
		void startUpdateShaderVertexValue(const DrawParameter* parameter);
		// 结束更新着色器uniform值
		void endUpdateShaderUniformValue(const DrawParameter* parameter);
		// 结束更新着色器attrib值
		void endUpdateShaderVertexValue(const DrawParameter* parameter);
	protected:
		// 更新环境
		void updateEnvUniformVallue(const DrawParameter* parameter);
		// 更新矩阵
		void updateMatrixUniformValue(const DrawParameter* parameter);
		// 更新材质
		void updateMaterialUniformValue(const DrawParameter* parameter);
		// 更新纹理
		void updateTexturesUnifromValue(const DrawParameter* parameter);

		void releaseMaterialUniformValue(const DrawParameter* parameter);
		void releaseTextureUniformValue(const DrawParameter* parameter);
	protected:
		// 应用光照着色器
		void applyLightShader(const DrawParameter* parameter);
		// 更新单色光源，距离最近
		void updateNearestLightUniformValue(const DrawParameter* parameter);
		// 更新所有光源
		void updateAllLightsUniformValue(const DrawParameter* parameter);
	protected:
		// 自定义类型
		void updateSelfDefinedUniformValue(const DrawParameter* parameter);
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
	public:
		/**
		*	重置绘制调用次数
		*/
		void beginRecordDrawCall();
		/**
		*	增加绘制调用次数
		*/
		void increaseDrawCall();
		/**
		*	增加未绘制调用次数
		*/
		void increaseUnDrawCall();
		/**
		*	重置绘制调用次数
		*/
		void endRecordDrawCall();
		/**
		*	获取绘制调用次数
		*/
		int getDrawCallCount();
		/**
		*	获取未绘制调用次数
		*/
		int getUnDrawCallCount();
	public:
		/**
		*	添加绘制参数
		*/
		void addDrawParameter(DrawParameter* parameter);
		/**
		*	移除所有绘制参数
		*/
		void removeAllDrawParameters();
	public:
		/**
		*	合批
		*/
		void batch();
		/**
		*	绘制合批
		*/
		void drawBatch();
		/**
		*	取消合批
		*/
		void unbatch();
	protected:
		/**
		*	是否同一个对象
		*/
		bool isSameObject(DrawParameter* a, DrawParameter* b);
		/**
		*	是否同一个材质
		*/
		bool isSameMaterial(DrawParameter* a, DrawParameter* b);
	private:
		/**
		*	临时矩阵
		*/
		math::Matrix4x4 _tempMatrix;
		/**
		*	绘制调用次数
		*/
		int _drawCallCount = 0;
		/**
		*	未绘制调用次数
		*/
		int _undrawCallCount = 0;
		/**
		*	一次完整绘制调用次数
		*/
		int _oneDrawCallCount = 0;
		/**
		*	一次完整未绘制调用次数
		*/
		int _oneUnDrawCallCount = 0;

	private:
		struct BatchDrawParameter
		{
			DrawParameter* root = nullptr;
			std::vector<DrawParameter*> parameters;
			BatchDrawParameter(DrawParameter* node)
			{
				root = node;
				parameters.push_back(node);
			}
		};
		// 合批处理
		std::vector<BatchDrawParameter> _batchDrawParameters;
		// 合图处理
		std::vector<BatchDrawParameter> _packDrawParameters;
	};

#define G_DRAWCORE sys::Instance<render::DrawCore>::getInstance()
}
