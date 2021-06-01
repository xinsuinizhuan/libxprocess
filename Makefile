override CXXFLAGS += -DXPROCESS_GUIWINDOW_IMPL
override CFLAGS += -DXPROCESS_GUIWINDOW_IMPL
ifeq ($(UNIX_BASED), true)
	ifeq ($(OS), Darwin)
		override LDLIBS += -framework CoreFoundation  -framework CoreGraphics
	else ifeq ($(OS), Linux)
		override CXXFLAGS += `pkg-config x11 --cflags`
		override CFLAGS += `pkg-config x11 --cflags`
		override LDLIBS += -lprocps `pkg-config x11 --libs`
	else ifeq ($(OS), FreeBSD)
		override CXXFLAGS += `pkg-config x11 --cflags`
		override CFLAGS += `pkg-config x11 --cflags`
		override LDLIBS += -lprocstat -lutil -lc `pkg-config x11 --clibs`
	endif
else
	CROSSPROCESS := $(shell "/c/msys64/msys2_shell.cmd" -defterm -mingw32 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess32.exe -std=c++17 -static-libgcc -static-libstdc++ -static -lShlwapi -m32")
	CROSSPROCESS += $(shell "/c/msys64/msys2_shell.cmd" -defterm -mingw64 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess64.exe -std=c++17 -static-libgcc -static-libstdc++ -static -lShlwapi -m64")
	CROSSPROCESS += $(shell cd Universal_System/Extensions/xProcess/;xxd -i crossprocess32 > crossprocess32.h)
	CROSSPROCESS += $(shell cd Universal_System/Extensions/xProcess/;xxd -i crossprocess64 > crossprocess64.h)
	CROSSPROCESS += $(shell rm -f "Universal_System/Extensions/xProcess/crossprocess32.exe" "Universal_System/Extensions/xProcess/crossprocess64.exe")
	override CXXFLAGS += -DXPROCESS_WIN32EXE_INCLUDES
	override CFLAGS += -DXPROCESS_WIN32EXE_INCLUDES
	override LDLIBS += -lShlwapi
endif
SOURCES += Universal_System/Extensions/xProcess/crossprocess.cpp
SOURCES += Universal_System/Extensions/xProcess/enigma.cpp
