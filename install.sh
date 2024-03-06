#!/bin/bash

if [ ! -d ./lib ]; then
    mkdir -p lib
fi

gcc -Wall -shared -fPIC -o lib/libclr.so src/colourmods.c src/display.c -Iinclude

if [ ! -d /usr/include/libclr ]; then
    sudo mkdir -p /usr/include/libclr/
fi

sudo cp ./include/* /usr/include/libclr/

sudo mv ./lib/libclr.so /usr/lib/
