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
	$(MAKE) -f makefile.generic.gcc.mk SUB_BUILD_PATH=amigaos/m68k MUICPP_PATH=../../AmigaOS.MUI.cpp.wrapper \
	GITHUB_PATH=../../../GitHub CPPC=m68k-amigaos-g++ CC=m68k-amigaos-gcc STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump \
	MORE_LFLAGS=-lamiga,-lmui AMIGAOS_68K_BUILD=1 all

out/amigaos/m68k:
	$(dir_guard)

out/morphos/ppc:
	$(dir_guard)

clean.obj:
	rm -f -R obj/*

clean: clean.obj
	rm -f -R out/*
