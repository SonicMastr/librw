librw-Vita
=====

librw Vita port using the NX port as a base

This library is supposed to be a re-implementation of RenderWare graphics,
or a good part of it anyway.

It is intended to be cross-platform in two senses eventually:
support rendering on different platforms similar to RW;
supporting all file formats for all platforms at all times and provide
way to convert to all other platforms.

File formats are already supported rather well, although rasters
as used by TXD files still need some work, especially for PS2.

As for rendering, D3D9 and OpenGL 3 work somewhat well but both still need
work. Rendering some things on the PS2 is working as a test only.

# Building (to come)

The Simple Process
------------------
Install [DolceSDK](https://github.com/dolcesdk/doc)

```make -j4```

Dolce Support for required libraries coming soon
