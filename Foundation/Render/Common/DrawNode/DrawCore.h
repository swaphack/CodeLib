#pragma once

#include "mathlib.h"
#include <string>
#include <map>
#include "Graphic/GLAPI/macros.h"

namespace sys
{
	class MeshDetail;
}

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
	*	���ƺ���
	*/
	class DrawCore
	{
	public:
		enum class DrawType
		{
			// Ĭ��
			Default,
			// ����
			Batch,
			// ��ͼ
			Pack,
		};
	public:
		DrawCore();
		virtual ~DrawCore();
	public:
		/**
		*	��Ⱦ��ʽ
		*/
		void setDrawType(DrawType type);
		/**
		*	��Ⱦ��ʽ
		*/
		DrawType getDrawType() const;
		/**
		*	��Ⱦ��ʽ
		*/
		void setDebugDrawMode(DrawMode mode);
		/**
		*	��Ⱦ��ʽ
		*/
		DrawMode getDebugDrawMode() const;
	public:
		/**
		*	��Ⱦ�ڵ�
		*/
		void render(DrawNode* node);
		/**
		*	��Ⱦ�ڵ�
		*/
		void render(MultiDrawNode* node);
		/**
		*	��Ⱦ
		*/
		void render(DrawParameter* parameter);
	public:
		/**
		*	ʹ�ô������ò���
		*/
		void beginApply(DrawParameter* parameter);
		/**
		*	ʹ�ô���
		*/
		void endApply(DrawParameter* parameter);
	public:
		/**
		*	ʹ��shader���ò���
		*/
		void beginApplyWithShader(DrawParameter* parameter);
		/**
		*	ʹ��shader
		*/
		void endApplyWithShader(DrawParameter* parameter);
	public:
		// ��ʼ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(const DrawParameter* parameter);
		// ����������ɫ��attribֵ
		void startUpdateShaderVertexValue(const DrawParameter* parameter);
		// ����������ɫ��uniformֵ
		void endUpdateShaderUniformValue(const DrawParameter* parameter);
		// ����������ɫ��attribֵ
		void endUpdateShaderVertexValue(const DrawParameter* parameter);
	protected:
		// ���»���
		void updateEnvUniformVallue(const DrawParameter* parameter);
		// ���¾���
		void updateMatrixUniformValue(const DrawParameter* parameter);
		// ���²���
		void updateMaterialUniformValue(const DrawParameter* parameter);
		// ��������
		void updateTexturesUnifromValue(const DrawParameter* parameter);

		void releaseMaterialUniformValue(const DrawParameter* parameter);
		void releaseTextureUniformValue(const DrawParameter* parameter);
	protected:
		// Ӧ�ù�����ɫ��
		void applyLightShader(const DrawParameter* parameter);
		// ���µ�ɫ��Դ���������
		void updateNearestLightUniformValue(const DrawParameter* parameter);
		// �������й�Դ
		void updateAllLightsUniformValue(const DrawParameter* parameter);
	protected:
		// �Զ�������
		void updateSelfDefinedUniformValue(const DrawParameter* parameter);
	protected:
		/**
		*	ʹ�û���������
		*/
		void drawWithBufferObject(const DrawParameter* parameter);
		/**
		*	ʹ�ÿͻ������ݻ���
		*/
		void drawWithClientArray(const DrawParameter* parameter);
	public:
		/**
		*	������ʱ����
		*/
		void setTempMatrix(const math::Matrix4x4& matrix);
		/**
		*	������ʱ����
		*/
		void resetTempMatrix();
	public:
		/**
		*	��ȡ�������
		*/
		math::Matrix4x4 getWorldMatrix(const Node* node);
		/**
		*	��ȡ����ͷ
		*/
		Camera* getCamera(const Node* node);
	public:
		/**
		*	���û��Ƶ��ô���
		*/
		void beginRecordDrawCall();
		/**
		*	���ӻ��Ƶ��ô���
		*/
		void increaseDrawCall();
		/**
		*	����δ���Ƶ��ô���
		*/
		void increaseUnDrawCall();
		/**
		*	���û��Ƶ��ô���
		*/
		void endRecordDrawCall();
		/**
		*	��ȡ���Ƶ��ô���
		*/
		int getDrawCallCount();
		/**
		*	��ȡδ���Ƶ��ô���
		*/
		int getUnDrawCallCount();
	public:
		/**
		*	��ӻ��Ʋ���
		*/
		void addDrawParameter(DrawParameter* parameter);
		/**
		*	�Ƴ����Ʋ���
		*/
		void removeDrawParameter(DrawParameter* parameter);
		/**
		*	�Ƴ����л��Ʋ���
		*/
		void removeAllDrawParameters();
	protected:
		/**
		*	����������Ʋ���
		*/
		void addBatchDrawParameter(DrawParameter* parameter);
		/**
		*	��Ӵ�����Ʋ���
		*/
		void addPackDrawParameter(DrawParameter* parameter);
	public:
		/**
		*	����
		*/
		void processDraw();
		/**
		*	ȡ������
		*/
		void unbatch();
	protected:
		/**
		*	����
		*/
		void processBatchDraw();
		/**
		*	���
		*/
		void processPackDraw();
	protected:
		/**
		*	�Ƿ�ͬһ������
		*/
		bool isSameObject(DrawParameter* a, DrawParameter* b);
		/**
		*	�Ƿ�ͬһ������
		*/
		bool isSameMaterial(DrawParameter* a, DrawParameter* b);
		/**
		*	�����Ƿ���ͬ
		*/
		bool isSameTexture(DrawParameter* a, DrawParameter* b);
	private:
		/**
		*	��ʱ����
		*/
		math::Matrix4x4 _tempMatrix;
		/**
		*	���Ƶ��ô���
		*/
		int _drawCallCount = 0;
		/**
		*	δ���Ƶ��ô���
		*/
		int _undrawCallCount = 0;
		/**
		*	һ���������Ƶ��ô���
		*/
		int _oneDrawCallCount = 0;
		/**
		*	һ������δ���Ƶ��ô���
		*/
		int _oneUnDrawCallCount = 0;
	private:
		struct BatchDrawParameter
		{
		public:
			// �ӽڵ�
			std::vector<DrawParameter*> children;
			// ���ڵ�
			DrawParameter* root = nullptr;
			// ��ʱ
			sys::MeshDetail* tempMeshDtail = nullptr;
			// ���»���
			bool redraw = true;
		public:
			BatchDrawParameter(DrawParameter* parameter);
			// �Ƿ����
			bool contains(DrawParameter* parameter);
			// �Ƴ�
			void remove(DrawParameter* parameter);
			// ���
			void add(DrawParameter* parameter);
			// �������
			bool packMeshes(sys::MeshDetail* meshDetail);
		};
		// ��������
		std::vector<BatchDrawParameter*> _batchDrawParameters;
		// ��ͼ����
		std::vector<BatchDrawParameter*> _packDrawParameters;
		// �����»��ƵĲ���
		std::set<BatchDrawParameter*> _redrawParameters;
		// ���Ʒ�ʽ
		DrawType _drawType = DrawType::Batch;
		// ���Ի��Ʒ�ʽ
		DrawMode _debugDrawMode = DrawMode::NONE;
	};

#define G_DRAWCORE sys::Instance<render::DrawCore>::getInstance()
}
