AM_CFLAGS =\
	-Wall\
	-O4\
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@ \
	-I$(top_srcdir)/librawstudio/ \
	-I$(top_srcdir)/

lib_LTLIBRARIES = output_jpegfile.la

libdir = @RAWSTUDIO_PLUGINS_LIBS_DIR@

output_jpegfile_la_LIBADD = @PACKAGE_LIBS@ @LIBJPEG@
output_jpegfile_la_LDFLAGS = -module -avoid-version
output_jpegfile_la_SOURCES = output-jpegfile.c
