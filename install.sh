#!/bin/bash
make 
make clean
echo "coping fg_header to /bin/fg_header"
sudo cp $HOME/fg_header/src/header_maker $HOME/fg_header/src/unknown_printer_for_the_yeet /bin
echo "installation done"