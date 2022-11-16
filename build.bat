@echo off

mkdir Debug

pushd Debug

cl -Zi ../pkdisplayer.c User32.lib Gdi32.lib Kernel32.lib

popd