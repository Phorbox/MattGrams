#!/bin/bash

looper=0
while [ $looper -eq 0 ]; do
    read -p "Enter one of the following actions or press CTRL-D to exit.
    C - create a new photo item
    R - read an existing photo item
    U - update an existing photo item
    D - delete an existing photo item
    Q - quit
    " execution



    case "$execution" in
        [Cc]reate|[Cc]) ./create.bash;;
        [Rr]ead|[Rr]) ./read.bash;;
        [Uu]pdate|[Uu]) ./update.bash;;
        [Dd]elete|[Dd]) ./delete.bash;;
        [Qq]uit|[Qq])   looper=1
                        exit 0;;
        *)  echo "ERROR: invalid option: '$execution'\n";;
    esac
done
exit 0
