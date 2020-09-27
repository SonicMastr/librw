
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
CFLAGS  = -g -Wl,-q -O3 -ffast-math -mtune=cortex-a9 -mfpu=neon -ftree-vectorize -DVITA -DDEBUG -DRW_GL3 -DRW_GLES2 -DLIBRW_SDL2
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
	cp rw.h $(DOLCESDK)/$(PREFIX)/include/