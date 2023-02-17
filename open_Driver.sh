#!/bin/bash

echo "How many tabs you wants to open?"
read ret

#pswd "1234"

for ((idx =0; idx < $ret; ++idx))
do 
	gnome-terminal --tab --title='Driver' --command="sudo bash"
done

clear

