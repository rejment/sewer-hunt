@echo off

pushd ..\build
cl /nologo ..\src\main_win32.cpp user32.lib Gdi32.lib
popd
