#
#  CPU-A
#
#  (c) 2024 TDolphin
#
#  generic makefile for gcc
#
#  for Linux (host) x86_64 (64-bit)
#
# cross compilation setup from -> https://github.com/bebbo/amiga-gcc
#
#  	  requires: AmigaOS MUI C++ wrapper classes (https://github.com/tdolphin-org/AmigaOS.MUI.cpp.wrapper)
#

# replace , => space
MORE_CPP_FLAGS_X = $(shell echo $(MORE_CPP_FLAGS) | tr ',' ' ')
MORE_LFLAGS_X = $(shell echo $(MORE_LFLAGS) | tr ',' ' ')

# trace/debug flags
DEBUG_FLAGS =

CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS_X) -std=c++17 -Isrc -I${MUICPP_PATH}/wrappers/src -I${MUICPP_PATH}/components/src -O1
LFLAGS = -L${MUICPP_PATH}/wrappers/lib/$(SUB_BUILD_PATH) -lMUIcpp $(MORE_LFLAGS_X) -lstdc++ -noixemul

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

include makefile.gen.version.mk

MUI_COMPONENTS_PATH = ${MUICPP_PATH}/components
MUI_COMPONENTS_MODULES = Components/Core Components/MCC Components/MCC/Core
MUI_COMPONENTS_SRC_DIRS = $(addprefix $(MUI_COMPONENTS_PATH)/src/,$(MUI_COMPONENTS_MODULES))
MUI_COMPONENTS_SRCS = $(foreach sdir,$(MUI_COMPONENTS_SRC_DIRS),$(wildcard $(sdir)/*.cpp))

MODULES_COMPONENTS = Components Components/Core Components/Tabs Components/MCC
MODULES = $(MODULES_COMPONENTS) FileResources TextResources DataInfo AOS/Identify

SRC_DIRS = src $(addprefix src/,$(MODULES))
SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))\
	$(patsubst $(MUI_COMPONENTS_PATH)/src/%.cpp,$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o,$(MUI_COMPONENTS_SRCS))

HEADERS = src/ProgDefines.hpp

all: src/Version.cpp src/Version.hpp $(BINPATH)/$(APP_FILE_NAME)

$(BINPATH)/$(APP_FILE_NAME): $(OBJS)
	@echo "## Linking ..."
	$(CPPC) $^ $(LFLAGS) -o $@_nonstripped
	@echo "## Stripping ..."
	$(STRIP) --remove-section=.comment $@_nonstripped -o $@
	$(OBJDUMP) --syms --reloc --disassemble-all $@_nonstripped > $@_disassembled
	@echo "## Finished :)"

obj/$(SUB_BUILD_PATH)/%.o: src/%.cpp src/%.hpp $(HEADERS)
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o: $(MUI_COMPONENTS_PATH)/src/%.cpp $(MUI_COMPONENTS_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -f $(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/*.o
	rm -f obj/$(SUB_BUILD_PATH)/*.o
	rm -f -R out/$(SUB_BUILD_PATH)/*

rebuild : clean all
