@echo off

pushd ..

mkdir Release

pushd Release

cl ../src/pkdisplayer.c User32.lib Gdi32.lib Kernel32.lib

popd

popd