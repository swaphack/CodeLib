#pragma once


namespace render
{
	/**
	*	������������
	*/
	enum class VertexDataType
	{
		POSITION,
		COLOR,
		UV,
		NORMAL,
		TANGENT,
		BITANGENT,
		UV1,
		UV2,
		UV3,
		UV4,
		BLEND_WEIGHT,
		BLEND_INDEX,
		MAX,
		UVS = UV,
	};

	/**
	*	ͳһ����
	*/
	enum class UniformType
	{
		// ͶӰ����
		PROJECT_MATRIX,
		// ��ͼ����
		VIEW_MATRIX,
		// ģ�;���
		MODEL_MATRIX,
		// ���߾���
		NORMAL_MATRIX,
		// m v p
		MVP_MATRIX,
		// m v
		MV_MATRIX,

		// ����
		TEXTURE0,
		// ����
		TEXTURE1,
		// ����
		TEXTURE2,
		// ����
		TEXTURE3,
		// ����
		TEXTURE4,
		// ����
		TEXTURE5,
		// ����
		TEXTURE6,
		// ����
		TEXTURE7,
		// ����
		TEXTURE8,
		// ����
		TEXTURE9,
		// ����
		TEXTURE10,
		// ����
		TEXTURE11,
		// ����
		TEXTURE12,
		// ����
		TEXTURE13,
		// ����
		TEXTURE14,
		// ����
		TEXTURE15,
		// ����
		TEXTURE16,
		// ����
		TEXTURE17,
		// ����
		TEXTURE18,
		// ����
		TEXTURE19,
		// ����
		TEXTURE20,
		// ����
		TEXTURE21,
		// ����
		TEXTURE22,
		// ����
		TEXTURE23,
		// ����
		TEXTURE24,
		// ����
		TEXTURE25,
		// ����
		TEXTURE26,
		// ����
		TEXTURE27,
		// ����
		TEXTURE28,
		// ����
		TEXTURE29,
		// ����
		TEXTURE30,
		// ����
		TEXTURE31,

		/**************������*****************/
		// ������ɫ
		MATERIAL_EMISSION,
		// ���ʻ�����ɫ����
		MATERIAL_COLOR_AMBIENT,
		// ����������ɫ����
		MATERIAL_COLOR_DIFFUSE,
		// ���ʸ߹���ɫ����
		MATERIAL_COLOR_SPECULAR,
		// ���ʻ�������
		MATERIAL_TEXTURE,
		// ͸���Ȳ���
		MATERIAL_TEXTURE_ALPHA,
		// bump����
		MATERIAL_TEXTURE_BUMP,
		// �����������
		MATERIAL_TEXTURE_DIFFUSE,
		// ���ʸ߹����
		MATERIAL_TEXTURE_SPECULAR,
		// ���ʷ��߲���
		MATERIAL_TEXTURE_NORMAL,
		// �������Ȳ���
		MATERIAL_SHININESS,
		// ����������ǿ����
		MATERIAL_STRENGTH,

		/**************����Դ*****************/
		// ���ù�Դ
		LIGHT_ENABLED,
		// �Ƿ񱾵ع�Դ
		LIGHT_LOCAL,
		// �Ƿ�׶�ι�Դ
		LIGHT_SPOT,
		// ��Դλ��
		LIGHT_POSITION,
		// ��Դ����
		LIGHT_DIRECTION,
		// ��Դ��ɫ����
		LIGHT_COLOR,
		// ��Դ������
		LIGHT_AMBIENT,
		// ��Դ������
		LIGHT_HALF_VECTOR,
		// ��Դ˥������ϵ��
		LIGHT_CONSTANT_ATTENUATION,
		// ��Դ˥������ϵ��
		LIGHT_LINEAR_ATTENUATION,
		// ��Դ˥������ϵ��
		LIGHT_QUADRATIC_ATTENUATION,
		// ׶�ι�Ƕ�
		LIGHT_SPOT_EXPONENT,
		// ׶�ι���ʾ���ֵ
		LIGHT_SPOT_COST_CUTOFF,

		/**************���Դ*****************/
		// ��Դ����
		MULTI_LIGHT_COUNT,
		// ���ö��Դ
		MULTI_LIGHT_ENABLED,
		// �Ƿ񱾵ع�Դ
		MULTI_LIGHT_LOCAL,
		// �Ƿ�׶�ι�Դ
		MULTI_LIGHT_SPOT,
		// ��Դλ��
		MULTI_LIGHT_POSITION,
		// ��Դ����
		MULTI_LIGHT_DIRECTION,
		// ��Դ��ɫ����
		MULTI_LIGHT_COLOR,
		// ��Դ������
		MULTI_LIGHT_AMBIENT,
		// ��Դ������
		MULTI_LIGHT_HALF_VECTOR,
		// ��Դ˥������ϵ��
		MULTI_LIGHT_CONSTANT_ATTENUATION,
		// ��Դ˥������ϵ��
		MULTI_LIGHT_LINEAR_ATTENUATION,
		// ��Դ˥������ϵ��
		MULTI_LIGHT_QUADRATIC_ATTENUATION,
		// ׶�ι�Ƕ�
		MULTI_LIGHT_SPOT_EXPONENT,
		// ׶�ι���ʾ���ֵ
		MULTI_LIGHT_SPOT_COST_CUTOFF,


		// �����λ��
		VIEW_POSITION,
		// ٤��ֵ
		GAMMA,
	};
}