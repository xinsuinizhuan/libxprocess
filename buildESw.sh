#!/bin/sh
cd "${0%/*}"

if [ $(uname) = "Linux" ]; then
  g++ gamemaker.cpp crossprocess.cpp -o libxprocess.so -shared -std=c++17 -static-libgcc -static-libstdc++ -lprocps -lpthread -DXPROCESS_GUIWINDOW_IMPL `pkg-config x11 --cflags --libs` -fPIC;
elif [ $(uname) = "FreeBSD" ]; then
  clang++ gamemaker.cpp crossprocess.cpp -o libxprocess.so -shared -std=c++17 -I/usr/local/include -L/usr/local/lib -lprocstat -lutil -lc -lpthread -DXPROCESS_GUIWINDOW_IMPL `pkg-config x11 --cflags --libs` -fPIC;
fi
