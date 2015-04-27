lib_LTLIBRARIES = libyoutube-dl-embedder.la

libyoutube_dl_embedder_la_SOURCES = youtube-dl-embedder.c
libyoutube_dl_embedder_includedir = $(includedir)/youtube-dl-embedder
libyoutube_dl_embedder_include_HEADERS = youtube-dl-embedder.h
libyoutube_dl_embedder_la_CFLAGS = $(PYTHON_CFLAGS)
libyoutube_dl_embedder_la_LDFLAGS = $(PYTHON_LIBS)

python_DATA=youtube_dl_url_resolver.py

CLEANFILES = youtube-dl-embedder.pc

EXTRA_DIST = youtube-dl-embedder.pc.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = youtube-dl-embedder.pc
