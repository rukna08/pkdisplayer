@echo off

pushd ..

mkdir Debug

pushd Debug

cl -Zi ../src/pkdisplayer.c User32.lib Gdi32.lib Kernel32.lib

popd

popd