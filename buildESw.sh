#!/bin/sh
cd "${0%/*}"

if [ $(uname) = "Linux" ]; then
  g++ gamemaker.cpp crossprocess.cpp -o libxproc.so -shared -std=c++17 -static-libgcc -static-libstdc++ -lprocps -lpthread -DXPROCESS_GUIWINDOW_IMPL `pkg-config x11 --cflags --libs`;
elif [ $(uname) = "FreeBSD" ]; then
  clang++ gamemaker.cpp crossprocess.cpp -o libxproc.so -shared -std=c++17 -lprocstat -lutil -lc -lpthread -DXPROCESS_GUIWINDOW_IMPL `pkg-config x11 --cflags --libs`;
fi