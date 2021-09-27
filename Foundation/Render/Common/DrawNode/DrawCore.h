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
	*	���Ʋ���
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
	*	���ƺ���
	*/
	class DrawCore
	{
	public:
		DrawCore();
		virtual ~DrawCore();
	public:
		/**
		*	ʹ�ô������ò���
		*/
		void beginApply(const DrawCoreParameter& parameter);
		/**
		*	ʹ�ô���
		*/
		void endApply(const DrawCoreParameter& parameter);
	public:
		/**
		*	ʹ��shader���ò���
		*/
		void beginApplyWithShader(const DrawCoreParameter& parameter);
		/**
		*	ʹ��shader
		*/
		void endApplyWithShader(const DrawCoreParameter& parameter);
	public:
		// ��ʼ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(const DrawCoreParameter& parameter);
		// ����������ɫ��attribֵ
		void startUpdateShaderVertexValue(const DrawCoreParameter& parameter);
		// ����������ɫ��uniformֵ
		void endUpdateShaderUniformValue(const DrawCoreParameter& parameter);
		// ����������ɫ��attribֵ
		void endUpdateShaderVertexValue(const DrawCoreParameter& parameter);
	protected:
		// ���»���
		void updateEnvUniformVallue(const DrawCoreParameter& parameter);
		// ���¾���
		void updateMatrixUniformValue(const DrawCoreParameter& parameter);
		// ���²���
		void updateMaterialUniformValue(const DrawCoreParameter& parameter);
		// ��������
		void updateTexturesUnifromValue(const DrawCoreParameter& parameter);

		void releaseMaterialUniformValue(const DrawCoreParameter& parameter);
		void releaseTextureUniformValue(const DrawCoreParameter& parameter);
	protected:
		// Ӧ�ù�����ɫ��
		void applyLightShader(const DrawCoreParameter& parameter);
		// ���µ�ɫ��Դ���������
		void updateNearestLightUniformValue(const DrawCoreParameter& parameter);
		// �������й�Դ
		void updateAllLightsUniformValue(const DrawCoreParameter& parameter);
	protected:
		// �Զ�������
		void updateSelfDefinedUniformValue(const DrawCoreParameter& parameter);
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
	private:
		/**
		*	��ʱ����
		*/
		math::Matrix4x4 _tempMatrix;
	};

#define G_DRAWCORE sys::Instance<render::DrawCore>::getInstance()
}
