#pragma once


namespace render
{
	/**
	*	顶点数据类型
	*/
	enum class VertexDataType
	{
		// 位置
		POSITION,
		// 颜色
		COLOR,
		// 纹理坐标
		UV,
		// 法线
		NORMAL,
		// 切线
		TANGENT,
		// 二重切线
		BITANGENT,
		// 模型矩阵
		MODEL_MATRIX = 10,

		MAX,
	};
	/**
	*	环境
	*/
	enum class EnvUniformType
	{
		// 摄像机位置
		VIEW_POSITION,
		// 伽马值
		GAMMA,
		// 光源数量
		LIGHT_COUNT,
		// 点大小
		POINT_SIZE,
	};
	/**
	*	矩阵
	*/
	enum class MatrixUniformType
	{
		// 投影矩阵
		PROJECT_MATRIX,
		// 视图矩阵
		VIEW_MATRIX,
		// 模型矩阵
		MODEL_MATRIX,
		// 法线矩阵
		NORMAL_MATRIX,
	};
	/**
	*	纹理
	*/
	enum class TextureUniformType
	{
		// 纹理
		TEXTURE0,
		// 纹理
		TEXTURE1,
		// 纹理
		TEXTURE2,
		// 纹理
		TEXTURE3,
		// 纹理
		TEXTURE4,
		// 纹理
		TEXTURE5,
		// 纹理
		TEXTURE6,
		// 纹理
		TEXTURE7,
		// 纹理
		TEXTURE8,
		// 纹理
		TEXTURE9,
		// 纹理
		TEXTURE10,
		// 纹理
		TEXTURE11,
		// 纹理
		TEXTURE12,
		// 纹理
		TEXTURE13,
		// 纹理
		TEXTURE14,
		// 纹理
		TEXTURE15,
		// 纹理
		TEXTURE16,
		// 纹理
		TEXTURE17,
		// 纹理
		TEXTURE18,
		// 纹理
		TEXTURE19,
		// 纹理
		TEXTURE20,
		// 纹理
		TEXTURE21,
		// 纹理
		TEXTURE22,
		// 纹理
		TEXTURE23,
		// 纹理
		TEXTURE24,
		// 纹理
		TEXTURE25,
		// 纹理
		TEXTURE26,
		// 纹理
		TEXTURE27,
		// 纹理
		TEXTURE28,
		// 纹理
		TEXTURE29,
		// 纹理
		TEXTURE30,
		// 纹理
		TEXTURE31,
	};
	/**
	*	材质
	*/
	enum class MaterialUniformType
	{
		// 发射颜色
		MATERIAL_EMISSION,
		// 材质环境颜色参数
		MATERIAL_COLOR_AMBIENT,
		// 材质漫射颜色参数
		MATERIAL_COLOR_DIFFUSE,
		// 材质高光颜色参数
		MATERIAL_COLOR_SPECULAR,
		// 材质环境参数
		MATERIAL_TEXTURE,
		// 透明度参数
		MATERIAL_TEXTURE_ALPHA,
		// bump参数
		MATERIAL_TEXTURE_BUMP,
		// 材质漫射参数
		MATERIAL_TEXTURE_DIFFUSE,
		// 材质高光参数
		MATERIAL_TEXTURE_SPECULAR,
		// 材质法线参数
		MATERIAL_TEXTURE_NORMAL,
		// 材质阴影参数
		MATERIAL_TEXTURE_SHADOW,
		// 材质亮度参数
		MATERIAL_SHININESS,
		// 材质亮度增强参数
		MATERIAL_STRENGTH,
	};
	/**
	*	单光源
	*/
	enum class SingleLightUniformType
	{
		// 启用光源
		LIGHT_ENABLED,
		// 是否本地光源
		LIGHT_LOCAL,
		// 是否锥形光源
		LIGHT_SPOT,
		// 光源位置
		LIGHT_POSITION,
		// 光源方向
		LIGHT_DIRECTION,
		// 光源颜色参数
		LIGHT_COLOR,
		// 光源漫反射
		LIGHT_AMBIENT,
		// 光源半向量
		LIGHT_HALF_VECTOR,
		// 光源衰减常量系数
		LIGHT_CONSTANT_ATTENUATION,
		// 光源衰减线性系数
		LIGHT_LINEAR_ATTENUATION,
		// 光源衰减二次系数
		LIGHT_QUADRATIC_ATTENUATION,
		// 锥形光角度
		LIGHT_SPOT_EXPONENT,
		// 锥形光显示最大值
		LIGHT_SPOT_COST_CUTOFF,
		// 光照矩阵
		LIGHT_SPACE_MATRIX,
	};
	/**
	*	多光源
	*/
	enum class MultiLightsUniformType
	{
		// 启用多光源
		MULTI_LIGHT_ENABLED,
		// 是否本地光源
		MULTI_LIGHT_LOCAL,
		// 是否锥形光源
		MULTI_LIGHT_SPOT,
		// 光源位置
		MULTI_LIGHT_POSITION,
		// 光源方向
		MULTI_LIGHT_DIRECTION,
		// 光源颜色参数
		MULTI_LIGHT_COLOR,
		// 光源漫反射
		MULTI_LIGHT_AMBIENT,
		// 光源半向量
		MULTI_LIGHT_HALF_VECTOR,
		// 光源衰减常量系数
		MULTI_LIGHT_CONSTANT_ATTENUATION,
		// 光源衰减线性系数
		MULTI_LIGHT_LINEAR_ATTENUATION,
		// 光源衰减二次系数
		MULTI_LIGHT_QUADRATIC_ATTENUATION,
		// 锥形光角度
		MULTI_LIGHT_SPOT_EXPONENT,
		// 锥形光显示最大值
		MULTI_LIGHT_SPOT_COST_CUTOFF,
		// 光照矩阵
		MULTI_LIGHT_SPACE_MATRIX,
	};
}