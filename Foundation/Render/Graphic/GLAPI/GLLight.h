#pragma once

#include "mathlib.h"
#include "macros.h"
namespace render
{
	/**
	*	π‚‘¥
	*/
	class GLLight
	{
	public:
		static void getLight(LightName name, LightParameter mode, float* value);


		static void setLightModel(LightModel type, float value);
		static void setLightModel(LightModelParameter type, const float* value);
		/**
			The params parameter contains four floating-point values that specify the ambient RGBA intensity of the entire scene. 
			Integer values are mapped linearly such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0.
			Floating-point values are mapped directly.
			Neither integer nor floating-point values are clamped. 
			The default ambient scene intensity is (0.2, 0.2, 0.2, 1.0).
		*/
		static void setLightModelAmbient(const float* value);
		/**
			The params parameter is a single floating-point value that specifies how specular reflection angles are computed. 
			If param is 0 (or 0.0), specular reflection angles take the view direction to be parallel to and in the direction of the -z axis,regardless of the location of the vertex in eye coordinates. 
			Otherwise, specular reflections are computed from the origin of the eye coordinate system. 
			The default is 0.
		*/
		static void setLightModelLocalViewer(const float* value);
		/**
			The params parameter is a single floating-point value that specifies whether one-sided or two-sided lighting calculations are done for polygons. 
			It has no effect on the lighting calculations for points, lines, or bitmaps. 
			If param is 0 (or 0.0), one-sided lighting is specified, and only the front material parameters are used in the lighting equation. 

			Otherwise, two-sided lighting is specified.
			In this case, vertices of back-facing polygons are lighted using the back material parameters, and have their normals reversed before the lighting equation is evaluated. 
			Vertices of front-facing polygons are always lighted using the front material parameters, with no change to their normals. 
			The default is 0.
		*/
		static void setLightModelTwoSide(const float* value);
	public:
		static void setLight(LightName  name, LightParameter type, const float* value);

		static void setLightAmbient(LightName  name, const float* value);
		static void setLightAmbient(LightName  name, const math::Vector4& value);
		static void setLightDiffuse(LightName  name, const float* value);
		static void setLightDiffuse(LightName  name, const math::Vector4& value);
		static void setLightSpecular(LightName  name, const float* value);
		static void setLightSpecular(LightName  name, const math::Vector4& value);
		static void setLightPosition(LightName  name, const float* value);
		static void setLightPosition(LightName  name, const math::Vector4& value);
		static void setLightSpotDirection(LightName  name, const float* value);
		static void setLightSpotDirection(LightName  name, const math::Vector3& value);
		static void setLightSpotExponent(LightName  name, float value);
		static void setLightSpotCutOff(LightName  name, float value);
	public:
		static void setLightConstantAttenuation(LightName  name, float value);
		static void setLightLinearAttenuation(LightName  name, float value);
		static void setLightQuadraticAttenuation(LightName  name, float value);
	};
}