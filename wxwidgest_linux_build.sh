#!/bin/sh

sudo apt update -y
sudo apt upgrade -y

sudo apt install build-essential gdb wget mc

wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.tar.bz2
tar xf wxWidgets-3.2.4.tar.bz2

cd wxWidgets-3.2.4

mkdir buildgtk
cd buildgtk
../configure --with-gtk --disable-shared  --enable-unicode
make -j$(nproc --all)
sudo make install
sudo ldconfig
cd ..
cd ..

rm wxWidgets-3.2.4.tar.bz2