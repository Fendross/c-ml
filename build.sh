#!/bin/sh

set -xe

mkdir -p build/
clang -Wall -Wextra -o build/twice twice.c -lm