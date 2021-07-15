ifeq ($(UNIX_BASED), true)
	ifeq ($(OS), Darwin)
		override LDLIBS += -framework CoreFoundation -framework CoreGraphics -framework Cocoa
		override CXXFLAGS += -ObjC++
		override CFLAGS += -ObjC++
	else ifeq ($(OS), Linux)
		override LDLIBS += -lprocps
	else ifeq ($(OS), FreeBSD)
		override LDLIBS += -lprocstat -lutil -lc
	else ifeq ($(OS), DragonFly)
		override LDLIBS += -lkvm -lutil -lc
	endif
else
	CROSSPROCESS := $(shell FILE=Universal_System/Extensions/xProcess/crossprocess32.h;if test -f "$FILE"; then echo $FILE exists;else "$(dirname $MSYSTEM_PREFIX)/msys2_shell.cmd" -defterm -mingw32 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess32.exe -std=c++17 -static-libgcc -static-libstdc++ -static -lShlwapi -m32";fi)
	CROSSPROCESS += $(shell FILE=Universal_System/Extensions/xProcess/crossprocess64.h;if test -f "$FILE"; then echo $FILE exists;else "$(dirname $MSYSTEM_PREFIX)/msys2_shell.cmd" -defterm -mingw64 -no-start -here -lc "g++ Universal_System/Extensions/xProcess/crossprocess.cpp -o Universal_System/Extensions/xProcess/crossprocess64.exe -std=c++17 -static-libgcc -static-libstdc++ -static -lShlwapi -m64";fi)
	CROSSPROCESS += $(shell FILE=Universal_System/Extensions/xProcess/crossprocess32.h;if test -f "$FILE"; then echo $FILE exists;else cd Universal_System/Extensions/xProcess/;xxd -i crossprocess32 > crossprocess32.h;fi)
	CROSSPROCESS += $(shell FILE=Universal_System/Extensions/xProcess/crossprocess64.h;if test -f "$FILE"; then echo $FILE exists;else cd Universal_System/Extensions/xProcess/;xxd -i crossprocess64 > crossprocess64.h;fi)
	CROSSPROCESS += $(shell rm -f "Universal_System/Extensions/xProcess/crossprocess32.exe" "Universal_System/Extensions/xProcess/crossprocess64.exe")
	override CXXFLAGS += -DXPROCESS_WIN32EXE_INCLUDES
	override CFLAGS += -DXPROCESS_WIN32EXE_INCLUDES
	override LDLIBS += -lShlwapi
endif
SOURCES += Universal_System/Extensions/xProcess/crossprocess.cpp
SOURCES += Universal_System/Extensions/xProcess/enigma.cpp
