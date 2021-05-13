ifeq ($(UNIX_BASED), true)
	ifeq ($(OS), Linux)
		override LDLIBS += -lprocps
	else ifeq ($(OS), FreeBSD)
		override LDLIBS += -lprocstat -lutil -lc
	endif
endif
SOURCES += Universal_System/Extensions/CrossProcess/crossprocess.cpp
SOURCES += Universal_System/Extensions/CrossProcess/enigma.cpp
