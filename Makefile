ifeq ($(UNIX_BASED), true)
	ifeq ($(OS), Linux)
		override LDLIBS += -lprocps
	else ifeq ($(OS), FreeBSD)
		override LDLIBS += -lprocstat -lutil -lc
	endif
else
	CROSSPROCESS := $(shell "/c/msys64/msys2_shell.cmd" -defterm -mingw32 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess32.exe -std=c++17 -static-libgcc -static-libstdc++ -static -m32")
	CROSSPROCESS += $(shell "/c/msys64/msys2_shell.cmd" -defterm -mingw64 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess64.exe -std=c++17 -static-libgcc -static-libstdc++ -static -m64")
	CROSSPROCESS += $(shell cd Universal_System/Extensions/xProcess/;xxd -i crossprocess32 > crossprocess32.h)
	CROSSPROCESS += $(shell cd Universal_System/Extensions/xProcess/;xxd -i crossprocess64 > crossprocess64.h)
	CROSSPROCESS += $(shell rm -f "Universal_System/Extensions/xProcess/crossprocess32.exe" "Universal_System/Extensions/xProcess/crossprocess64.exe")
	override CXXFLAGS += -DEXE_INCLUDES
	override CFLAGS += -DEXE_INCLUDES
endif
SOURCES += Universal_System/Extensions/xProcess/crossprocess.cpp
SOURCES += Universal_System/Extensions/xProcess/enigma.cpp
