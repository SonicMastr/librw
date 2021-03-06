const char *im3d_vert_src =
"void main(\n"
"	float3 in_pos,\n"
"	float4 in_color,\n"
"	float2 in_tex0,\n"
"	uniform float4 u_fogData,\n"
"	uniform float4x4 u_proj,\n"
"	uniform float4x4 u_world,\n"
"	uniform float4x4 u_view,\n"
"	out float4 gl_Position : POSITION,\n"
"	out float4 v_color : COLOR0,\n"
"	out float2 v_tex0 : TEXCOORD0,\n"
"	out float v_fog : FOG\n"
")\n"
"{\n"
"	float4 V = mul(float4(in_pos, 1.0), u_world);\n"
"	gl_Position = mul(mul(V, u_view), u_proj);\n"
"	v_color = in_color;\n"
"	v_tex0 = in_tex0;\n"
"	v_fog = DoFog(gl_Position.w, u_fogData);\n"
"}\n";
