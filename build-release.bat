@echo off

mkdir Release

pushd Release

cl ../pkdisplayer.c User32.lib Gdi32.lib Kernel32.lib

popd