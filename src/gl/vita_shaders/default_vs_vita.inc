const char *default_vert_src =
"void main(\n"
"	float3 in_pos,\n"
"	float3 in_normal,\n"
"	float4 in_color,\n"
"	float2 in_tex0,\n"
"	out float4 gl_Position : POSITION,\n"
"	out float4 v_color : COLOR,\n"
"	out float2 v_tex0 : TEXCOORD0,\n"
"	out float v_fog : FOG\n"
") {\n"
"	float4 V = mul(u_world, float4(in_pos, 1.0));\n"
"	gl_Position = mul(mul(u_proj, u_view), V);\n"
"	float3 N = mul(float3x3(u_world), in_normal);\n"

"	v_tex0 = in_tex0;\n"

"	v_color = in_color;\n"
"	v_color.rgb += u_ambLight.rgb*surfAmbient;\n"
"	v_color.rgb += DoDynamicLight(V.xyz, N)*surfDiffuse;\n"
"	v_color = clamp(v_color, 0.0, 1.0);\n"
"	v_color *= u_matColor;\n"

"	v_fog = DoFog(gl_Position.w);\n"
"}\n";
