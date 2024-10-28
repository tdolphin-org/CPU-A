#
# Makefile for CPU-A project
#
# (c) 2024 TDolphin
#

SUB_PROJECTS = app
APP_DRAWER_NAME = CPU-A

OUT_PATH = out
OUT_APP_PATH = $(OUT_PATH)/$(APP_DRAWER_NAME)

include app/appversion.txt

all:
	@echo "make aos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make clean.obj - remove all obj files"
	@echo "make clean - remove all obj files and executable files"

aos_m68k: sub_projects_aos_m68k build_aos_m68k

sub_projects_aos_m68k:
	@echo "------------------------------------------------"
	@date
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) amigaos_m68k -C $$dir; \
	done
	@date
	@echo "------------------------------------------------"

build_aos_m68k:
	mkdir -p $(OUT_APP_PATH)
	@for dir in $(SUB_PROJECTS); do \
		echo "copy ... " $$dir/out/amigaos/m68k/"*" $(OUT_APP_PATH); \
		cp -R $$dir/out/amigaos/m68k/* $(OUT_APP_PATH); \
	done
	mkdir -p $(OUT_APP_PATH)/images
	cp -r data/images/* $(OUT_APP_PATH)/images

clean.obj:
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean.obj -C $$dir; \
	done

clean: clean.obj
	rm -f -R $(OUT_PATH)/*
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean -C $$dir; \
	done

rebuild_aos_m68k: clean aos_m68k build_aos_m68k
