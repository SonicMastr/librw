all: header_vs.inc header_fs.inc im2d_vita.inc im3d_vita.inc default_vs_vita.inc simple_fs_vita.inc matfx_vita.inc skin_vita.inc

header_vs.inc: header.vert.cg
	(echo 'const char *header_vert_src =';\
	 sed 's/..*/"&\\n"/' header.vert.cg;\
	 echo ';') >header_vs.inc

header_fs.inc: header.frag.cg
	(echo 'const char *header_frag_src =';\
	 sed 's/..*/"&\\n"/' header.frag.cg;\
	 echo ';') >header_fs.inc

im2d_vita.inc: im2d.vert.cg
	(echo 'const char *im2d_vert_src =';\
	 sed 's/..*/"&\\n"/' im2d.vert.cg;\
	 echo ';') >im2d_vita.inc

im3d_vita.inc: im3d.vert.cg
	(echo 'const char *im3d_vert_src =';\
	 sed 's/..*/"&\\n"/' im3d.vert.cg;\
	 echo ';') >im3d_vita.inc

default_vs_vita.inc: default.vert.cg
	(echo 'const char *default_vert_src =';\
	 sed 's/..*/"&\\n"/' default.vert.cg;\
	 echo ';') >default_vs_vita.inc

simple_fs_vita.inc: simple.frag.cg
	(echo 'const char *simple_frag_src =';\
	 sed 's/..*/"&\\n"/' simple.frag.cg;\
	 echo ';') >simple_fs_vita.inc

matfx_vita.inc: matfx_env.frag.cg matfx_env.vert.cg
	(echo 'const char *matfx_env_vert_src =';\
	 sed 's/..*/"&\\n"/' matfx_env.vert.cg;\
	 echo ';';\
	 echo 'const char *matfx_env_frag_src =';\
	 sed 's/..*/"&\\n"/' matfx_env.frag.cg;\
	 echo ';') >matfx_vita.inc

skin_vita.inc: skin.vert.cg
	(echo 'const char *skin_vert_src =';\
	 sed 's/..*/"&\\n"/' skin.vert.cg;\
	 echo ';') >skin_vita.inc

