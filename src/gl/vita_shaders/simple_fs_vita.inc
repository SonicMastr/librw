const char *simple_frag_src =
"void main(\n"
"	float4 v_color : COLOR,\n"
"	float2 v_tex0 : TEXCOORD0,\n"
"	float v_fog : FOG,\n"
"	uniform sampler2D tex0\n"
") {\n"
"	float4 color;\n"
"	color = v_color*tex2D(tex0, float2(v_tex0.x, 1.0-v_tex0.y));\n"
"	color.rgb = lerp(u_fogColor.rgb, color.rgb, v_fog);\n"
"	DoAlphaTest(color.a);\n"
"	v_color = color;\n"
"}\n";
