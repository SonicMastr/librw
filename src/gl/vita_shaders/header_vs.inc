const char *header_vert_src =
"uniform float4  u_fogData;\n"


"#define u_fogStart (u_fogData.x)\n"
"#define u_fogEnd (u_fogData.y)\n"
"#define u_fogRange (u_fogData.z)\n"
"#define u_fogDisable (u_fogData.w)\n"

"uniform float4x4 u_proj;\n"
"uniform float4x4 u_view;\n"

"#define MAX_LIGHTS 8\n"

"uniform float4x4 u_world;\n"
"uniform float4 u_ambLight;\n"
"uniform float4 u_lightParams[MAX_LIGHTS];\n"
"uniform float4 u_lightPosition[MAX_LIGHTS];\n"
"uniform float4 u_lightDirection[MAX_LIGHTS];\n"
"uniform float4 u_lightColor[MAX_LIGHTS];\n"

"uniform float4 u_matColor;\n"
"uniform float4 u_surfProps;	// amb, spec, diff, extra\n"

"#define surfAmbient (u_surfProps.x)\n"
"#define surfSpecular (u_surfProps.y)\n"
"#define surfDiffuse (u_surfProps.z)\n"

"float3 DoDynamicLight(float3 V, float3 N)\n"
"{\n"
"	float3 color = float3(0.0, 0.0, 0.0);\n"
"	for(int i = 0; i < MAX_LIGHTS; i++){\n"
"		if(u_lightParams[i].x == 0.0)\n"
"			break;\n"
"		if(u_lightParams[i].x == 1.0){\n"
"			// direct\n"
"			float l = max(0.0, dot(N, -u_lightDirection[i].xyz));\n"
"			color += l*u_lightColor[i].rgb;\n"
"		}\n"
"	}\n"
"	return color;\n"
"}\n"

"float DoFog(float w)\n"
"{\n"
"	return clamp((w - u_fogEnd)*u_fogRange, u_fogDisable, 1.0);\n"
"}\n";
