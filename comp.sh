#!/bin/bash

clear
sudo apt install libgtk-4-dev -y

gcc -o app app.c $(pkg-config --cflags gtk4) $(pkg-config --libs gtk4)

echo "Compiling Successed.!"
