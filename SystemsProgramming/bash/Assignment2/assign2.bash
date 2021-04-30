#!/bin/bash

for var in "$@"
do
    sed -i -f assign2.sed $var 
done