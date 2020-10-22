const char *matfx_env_vert_src =
"void main(\n"
"	uniform float4x4 u_texMatrix,\n"
"	float3 in_pos,\n"
"	float3 in_normal,\n"
"	float4 in_color,\n"
"	float2 in_tex0,\n"
"	float4 v_color : COLOR,\n"
"	out float4 gl_Position : POSITION,\n"
"	out float2 v_tex0 : TEXCOORD0,\n"
"	out float2 v_tex1 : TEXCOORD1,\n"
"	out float v_fog : FOG\n"
")\n"
"{\n"
"	float4 V = mul(u_world, float4(in_pos, 1.0));\n"
"	gl_Position = mul(u_proj,mul(u_view, V));\n"
"	float3 N = mul(float3x3(u_world), in_normal);\n"

"	v_tex0 = in_tex0;\n"
"	v_tex1 = mul(u_texMatrix, float4(N, 1.0)).xy;\n"

"	v_color = in_color;\n"
"	v_color.rgb += u_ambLight.rgb*surfAmbient;\n"
"	v_color.rgb += DoDynamicLight(V.xyz, N)*surfDiffuse;\n"
"	v_color = clamp(v_color, 0.0, 1.0);\n"
"	v_color *= u_matColor;\n"

"	v_fog = DoFog(gl_Position.w);\n"
"}\n";
const char *matfx_env_frag_src =
"void main(\n"
"	float4 v_color : COLOR,\n"
"	float2 v_tex0 : TEXCOORD0,\n"
"	float2 v_tex1 : TEXCOORD1,\n"
"	float v_fog : FOG,\n"
"	uniform sampler2D tex0,\n"
"	uniform sampler2D tex1,\n"
"	uniform float2 u_fxparams,\n"
"	uniform float4 u_colorClamp\n"
")\n"
"{\n"
"	float4 color;\n"

"	float4 pass1 = v_color;\n"
"	float4 envColor = max(pass1, u_colorClamp);\n"
"	pass1 *= tex2D(tex0, float2(v_tex0.x, 1.0-v_tex0.y));\n"

"	float4 pass2 = envColor*u_fxparams.x*tex2D(tex1, float2(v_tex1.x, 1.0-v_tex1.y));\n"

"	pass1.rgb = lerp(u_fogColor.rgb, pass1.rgb, v_fog);\n"
"	pass2.rgb = lerp(float3(0.0, 0.0, 0.0), pass2.rgb, v_fog);\n"

"	float fba = max(pass1.a, u_fxparams.y);\n"
"	color.rgb = pass1.rgb*pass1.a + pass2.rgb*fba;\n"
"	color.a = pass1.a;\n"

"	DoAlphaTest(color.a);\n"

"	v_color = color;\n"
"}\n";
