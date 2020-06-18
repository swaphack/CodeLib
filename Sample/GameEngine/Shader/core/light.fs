struct Light 
{
	vec3 position;

	vec4 ambient;
	vec4 diffuse;
	vec4 specular;

	vec3 direction;
	float exponent;
	float cutoff;

	float constant;
	float linear;
	float quadratic;
};

