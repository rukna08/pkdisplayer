@echo off

mkdir build

pushd build

cl -Zi ../pkdisplayer.c User32.lib Gdi32.lib Kernel32.lib

popd