DEFAULT_INCLUDES = -I$(top_builddir)/lib -I$(top_srcdir)/lib

if BUILD_WITH_MSVC
noinst_LIBRARIES = commonrender.lst
else
noinst_LTLIBRARIES = libcommonrender.la
endif

RegularSources = \
	CvrTextureObject.cpp CvrTextureObject.h \
	CvrRGBATexture.cpp CvrRGBATexture.h \
	CvrPaletteTexture.cpp CvrPaletteTexture.h \
	Cvr2DPaletteTexture.cpp Cvr2DPaletteTexture.h \
	Cvr3DPaletteTexture.cpp Cvr3DPaletteTexture.h \
	Cvr3DPaletteGradientTexture.cpp Cvr3DPaletteGradientTexture.h \
	Cvr2DRGBATexture.cpp Cvr2DRGBATexture.h \
	Cvr3DRGBATexture.cpp Cvr3DRGBATexture.h

libcommonrender_la_SOURCES = $(RegularSources)

commonrender_lst_SOURCES = $(RegularSources)

commonrender.lst: $(commonrender_lst_OBJECTS)
	@echo "Linking $@..."; \
	rm -f $@; \
	for i in $(commonrender_lst_OBJECTS); do echo $$i >>$@; done
