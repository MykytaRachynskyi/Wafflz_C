@echo off

mkdir ..\build
pushd ..\build
cl /clr ..\code\win32_wafflz.cpp user32.lib
popd
