#!/bin/bash
cd $HOME
if git clone https://github.com/Fgib/fg_header.git
then make 
    make clean
    echo "coping fg_header to /bin/fg_header"
    sudo cp $HOME/fg_header/src/header_maker $HOME/fg_header/src/unknown_printer_for_the_yeet /bin
    echo "installation done"
else
    echo "Error: could not clone repository"
fi