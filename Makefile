VERSION=2.2.3
ApplicationRoot := $(shell pwd)/ssrcArmNeon
LibrariesRoot := $(ApplicationRoot)/libraries
BaseLibraryName = baselibrary
BaselibraryRoot := $(ApplicationRoot)/$(BaseLibraryName)
WrapperRoot := $(ApplicationRoot)/wrapper

ModuleName := $(notdir $(ApplicationRoot))

GccVersion = $(shell expr `$(CC) -dumpversion | cut -f1`)
GccInclude = $(SDKTARGETSYSROOT)/usr/include/ \
	     $(SDKTARGETSYSROOT)/usr/include/c++/$(GccVersion)/ \
	     $(SDKTARGETSYSROOT)/usr/include/c++/$(GccVersion)/aarch64-poky-linux/

IncludeDirectories   := $(ApplicationRoot)/include $(LibrariesRoot)/include $(BaselibraryRoot)/include $(WrapperRoot)
ObjectLibDirectory   := object_libcross
ExecutableLibDirectory  := exec_libcross
DependLibDirectory      := depend_libcross

ObjectDirectory   := object_linuxcross
ExecutableDirectory  := exec_linuxcross
DependDirectory      := depend_linuxcross

IncludePaths := $(addprefix -I, $(IncludeDirectories))

ModuleCppSourceFilesWithPath := $(wildcard $(ApplicationRoot)/source/*.cpp)
ModuleCppSourceFiles := $(patsubst $(ApplicationRoot)/source/%.cpp,%.cpp,$(ModuleCppSourceFilesWithPath))
ModuleCppObjectFiles := $(patsubst %.cpp,$(ObjectDirectory)/%.o,$(ModuleCppSourceFiles))
ModuleCppDependFiles := $(patsubst %.cpp,$(DependDirectory)/%.dep,$(ModuleCppSourceFiles))

BaselibraryCppSourceFilesWithPath := $(wildcard $(BaselibraryRoot)/source/*.cpp)
BaselibraryCppSourceFiles := $(patsubst $(BaselibraryRoot)/source/%.cpp,%.cpp,$(BaselibraryCppSourceFilesWithPath))
BaselibraryCppObjectFiles := $(patsubst %.cpp,$(ObjectLibDirectory)/%.o,$(BaselibraryCppSourceFiles))
BaselibraryCppDependFiles := $(patsubst %.cpp,$(DependLibDirectory)/%.dep,$(BaselibraryCppSourceFiles))
BaselibraryCppLIBSOFiles := $(patsubst %.cpp,$(ExecutableLibDirectory)/lib%.so,$(BaselibraryCppSourceFiles))

LibraryCppSourceFilesWithPath := $(wildcard $(LibrariesRoot)/source/*.cpp)
LibraryCppSourceFiles := $(patsubst $(LibrariesRoot)/source/%.cpp,%.cpp,$(LibraryCppSourceFilesWithPath))
LibraryCppObjectFiles := $(patsubst %.cpp,$(ObjectLibDirectory)/%.o,$(LibraryCppSourceFiles))
LibraryCppDependFiles := $(patsubst %.cpp,$(DependLibDirectory)/%.dep,$(LibraryCppSourceFiles))
LibraryCppLIBSOFiles := $(patsubst %.cpp,$(ExecutableLibDirectory)/lib%.so,$(LibraryCppSourceFiles))

WrapperCppSourceFilesWithPath := $(wildcard $(WrapperRoot)/*.cpp)
WrapperCppSourceFiles := $(patsubst $(WrapperRoot)/%.cpp,%.cpp,$(WrapperCppSourceFilesWithPath))
WrapperCppObjectFiles := $(patsubst %.cpp,$(ObjectLibDirectory)/%.o,$(WrapperCppSourceFiles))
WrapperCppDependFiles := $(patsubst %.cpp,$(DependLibDirectory)/%.dep,$(WrapperCppSourceFiles))

CLANGCC ?= clang
CLANGCXX ?= clang++
MAKE = make
AR := ar
RM := rm -f
LD := ld
DEP:= $(CLANGCXX)

CrossCompileSettings = -march=armv8-a -target aarch64-linux-gnu --sysroot=$(SDKTARGETSYSROOT) -Wno-unused-command-line-argument

ifeq ($(strip $(TARGET_SYS)),)
TARGET_SYS_AUTO := $(shell $(firstword $(CC)) -dumpmachine 2>/dev/null)
ifneq ($(strip $(TARGET_SYS_AUTO)),)
TARGET_SYS := $(TARGET_SYS_AUTO)
endif
endif

CrossCompileSettings = -march=armv8-a -Wno-unused-command-line-argument

ifneq ($(strip $(SDKTARGETSYSROOT)),)
CrossCompileSettings += --sysroot=$(SDKTARGETSYSROOT)
endif

ifeq ($(MAKECMDGOALS),linuxcross)
    export DepAndCCCommonFlags := -DUSE_ARM_INLINE $(CrossCompileSettings) --target=$(TARGET_SYS)
endif
ifeq ($(MAKECMDGOALS),libcross)
    export DepAndCCCommonFlags := -DUSE_ARM_INLINE $(CrossCompileSettings) --target=$(TARGET_SYS)
endif

DEPENDENCY := $(DepAndCCCommonFlags) -MM -MT
CppFlags := -c $(DepAndCCCommonFlags) -g3 -std=gnu++17 -fno-rtti -fno-exceptions -fPIC
CFlags   := -c $(DepAndCCCommonFlags) -g3 -std=c99 -fPIC

ArFlags ?= -ruc
LdExecFlags := -fPIC

ExecutableObjects = $(ModuleCppObjectFiles) $(ModuleCcObjectFiles) $(ModuleCppObjectInterpolatorFiles) $(ModuleCppObjectFilterFiles)
Libraries := -lstdc++ -lc -l$(ModuleName)
LdObjectFlags := -r


LibraryPath := -L $(ExecutableLibDirectory)


.SECONDARY: $(ModuleCppDependFiles) $(ModuleCDependFiles) $(ModuleCppObjectFiles) $(ModuleCObjectFiles) $(BaselibraryCppObjectFiles) $(BaselibraryCppDependFiles) $(LibraryCppObjectFiles) $(LibraryCppDependFiles) \
	    $(WrapperCppObjectFiles) $(WrapperCppDependFiles)

.PRECIOUS : %.o %.dep %.a %.so

default:
	@echo target
	@echo linuxcross - Cross compile application on linux
	@echo libcross - Cross compile library on linux

linuxcross: ObjectDirectories $(ExecutableLibDirectory)/lib$(ModuleName).so $(ExecutableDirectory)/$(ModuleName)

libcross: ObjectDirectories $(ExecutableLibDirectory)/lib$(ModuleName).so


$(ObjectDirectory)/%.o : $(ApplicationRoot)/source/%.cpp
	$(CLANGCXX) $(CppFlags) $< $(IncludePaths) -o $@
$(ObjectLibDirectory)/%.o : $(BaselibraryRoot)/source/%.cpp
	$(CLANGCXX) $(CppFlags) $< $(IncludePaths) -o $@
$(ObjectLibDirectory)/%.o : $(LibrariesRoot)/source/%.cpp
	$(CLANGCXX) $(CppFlags) $< $(IncludePaths) -o $@
$(ObjectLibDirectory)/%.o : $(WrapperRoot)/%.cpp
	$(CLANGCXX) $(CppFlags) $< $(IncludePaths) -o $@

$(DependDirectory)/%.dep : $(ApplicationRoot)/source/%.cpp
	$(DEP) $< $(IncludePaths) $(DEPENDENCY) $(DependDirectory)/$(*F).dep > $(DependDirectory)/$(*F).dep
$(DependLibDirectory)/%.dep :  $(BaselibraryRoot)/source/%.cpp
	$(DEP) $< $(IncludePaths) $(DEPENDENCY) $(DependLibDirectory)/$(*F).dep > $(DependLibDirectory)/$(*F).dep
$(DependLibDirectory)/%.dep : $(LibrariesRoot)/source/%.cpp
	$(DEP) $< $(IncludePaths) $(DEPENDENCY) $(DependLibDirectory)/$(*F).dep > $(DependLibDirectory)/$(*F).dep
$(DependLibDirectory)/%.dep : $(WrapperRoot)/%.cpp
	$(DEP) $< $(IncludePaths) $(DEPENDENCY) $(DependLibDirectory)/$(*F).dep > $(DependLibDirectory)/$(*F).dep

$(ExecutableLibDirectory)/lib$(ModuleName).so : $(BaselibraryCppObjectFiles) $(LibraryCppObjectFiles) $(WrapperCppObjectFiles) | ObjectDirectories
	$(CXX) $(BaselibraryCppObjectFiles) $(LibraryCppObjectFiles) $(WrapperCppObjectFiles) -o $(ExecutableLibDirectory)/lib$(ModuleName).so.$(VERSION) -shared -Wl,-soname,lib$(ModuleName).so.$(VERSION)
	ln -srf $(ExecutableLibDirectory)/lib$(ModuleName).so.$(VERSION) $(ExecutableLibDirectory)/lib$(ModuleName).so
$(ExecutableDirectory)/$(ModuleName): $(ExecutableLibDirectory)/lib$(ModuleName).so $(ModuleCppObjectFiles) | ObjectDirectories
	$(CXX) $(LdExecFlags) $(ModuleCppObjectFiles) $(ModuleCObjectFiles) $(LibraryPath) $(Libraries) -o $@

ObjectDirectories:
	@mkdir -p $(ObjectDirectory)
	@mkdir -p $(DependDirectory)
	@mkdir -p $(ExecutableDirectory)
	@mkdir -p $(ObjectLibDirectory)
	@mkdir -p $(DependLibDirectory)
	@mkdir -p $(ExecutableLibDirectory)

clean:
	rm -rf depend_*
	rm -rf object_*
	rm -rf exec_*
