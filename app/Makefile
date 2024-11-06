#
#  MakeFile for CPU-A
#
#  (c) 2024 TDolphin
#

include appversion.txt

export APP_DATE = `date +%d.%m.%Y`
export APP_FILE_NAME = CPU-A
export APP_BUILD_COMMIT_HASH = `git rev-parse HEAD`

dir_guard = mkdir -p $@

all:
	@echo "make amigaos_m68k"

amigaos_m68k: out/amigaos/m68k
	@echo "# Build App for AmigaOS m68k ---------------------------------------------------------------------"
	$(MAKE) -f makefile.generic.gcc.mk SUB_BUILD_PATH=amigaos/m68k \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	MUICPP_PATH=../../AmigaOS.MUI.cpp.wrapper \
	GITHUB_PATH=../../../GitHub \
	CPPC=m68k-amigaos-g++ CC=m68k-amigaos-gcc STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump \
	MORE_CPP_FLAGS=-std=c++17,-Os \
	MORE_LFLAGS=-lamiga,-noixemul \
	all

out/amigaos/m68k:
	$(dir_guard)

out/morphos/ppc:
	$(dir_guard)

clean.obj:
	rm -f -R ../../AmigaOS.cpp.wrapper/wrappers/obj/*
	rm -f -R ../../AmigaOS.MUI.cpp.wrapper/components/obj/*
	rm -f -R obj/*

clean: clean.obj
	rm -f -R out/*

rebuild : clean all
