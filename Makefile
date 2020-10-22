
TARGET          := librw
SOURCES         := src src/d3d src/gl src/lodepng src/ps2

CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
ASMFILES := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.S))
CPPFILES :=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
OBJS     := $(CFILES:.c=.o) $(ASMFILES:.S=.o) $(CPPFILES:.cpp=.o)

PREFIX  = arm-dolce-eabi
CC      = $(PREFIX)-gcc
CXX		= $(PREFIX)-g++
AR      = $(PREFIX)-gcc-ar
CFLAGS  = -g -Wl,-q -O3 -ffast-math -mtune=cortex-a9 -mfpu=neon -ftree-vectorize -DVITA -DDEBUG -DRW_GL3 -DRW_GLES2 -DGLFW_INCLUDE_ES2
CXXFLAGS = $(CFLAGS)
ASFLAGS = $(CFLAGS)

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	$(AR) -rc $@ $^
	
clean:
	@rm -rf $(TARGET).a $(OBJS)
	
install: $(TARGET).a
	@mkdir -p $(DOLCESDK)/$(PREFIX)/lib/
	cp $(TARGET).a $(DOLCESDK)/$(PREFIX)/lib/
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/
	cp *.h $(DOLCESDK)/$(PREFIX)/include/
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/src
	cp src/*.h $(DOLCESDK)/$(PREFIX)/include/src/
	cp src/base.err $(DOLCESDK)/$(PREFIX)/include/src/
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/src/d3d
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/src/gl
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/src/lodepng
	@mkdir -p $(DOLCESDK)/$(PREFIX)/include/src/ps2
	cp src/d3d/*.h $(DOLCESDK)/$(PREFIX)/include/src/d3d/
	cp src/gl/*.h $(DOLCESDK)/$(PREFIX)/include/src/gl/
	cp src/lodepng/lodepng.h $(DOLCESDK)/$(PREFIX)/include/src/lodepng/
	cp src/ps2/*.h $(DOLCESDK)/$(PREFIX)/include/src/ps2/