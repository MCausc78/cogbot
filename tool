#!/bin/bash

shopt -s globstar

cd src/cpp
FILES="$(eval echo **/**.cpp)"
cd ../asm

ASMFILES="$(eval echo **/**.asm)"
cd ../..

execc() {
	echo "$1"
	eval "$1"
}

execc "rm -rf bin/ obj/"
execc "mkdir -p bin/ obj/ src/ include/"

CXX=clang++
CXXFLAGS="-Wall -Werror -std=c++20 -stdlib=libstdc++ -c -Iinclude"
LD=clang++
LDFLAGS="-ldpp -lfmt -lcurl -lpqxx -lyaml-cpp -lpq"

AS=nasm
ASFLAGS=-felf64

for f in $FILES
do
	DIR="$(dirname obj/$f.o)"
	if [ ! -d $DIR ]; then
		mkdir -p "$DIR"
	fi
	execc "$CXX $CXXFLAGS -o obj/$f.o src/cpp/$f"
done

for f in $ASMFILES
do
	DIR="$(dirname obj/$f.o)"
	if [ ! -d $DIR ]; then
		mkdir -p "$DIR"
	fi
	execc "$AS $ASFLAGS -o obj/$f.o src/asm/$f"
done

execc "$LD -o bin/main obj/**/**.o $LDFLAGS"
