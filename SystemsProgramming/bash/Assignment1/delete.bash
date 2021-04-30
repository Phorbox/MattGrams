#!/bin/bash

#$1 is a string describing the variable $2 is destination for the variable
userinput () { 
    read -p "$1: " $2
    
}
checkNumber () {
    if [[ $# -ne 4 ]]; then
        echo "Error checking $1 variable"
        return 0
    fi
    while userInputCondition $2 $3 $4 ; do
        userinput "$1 number must be in the range of $3 and $4: " $2
    done
}
#Format 1 is the number to check, 2 is the lower bound inclusive, 3 is the upperbound inclusive
userInputCondition () {
    
    if [[ $# -ne 3 ]]; then
        return 0
    elif [[ 1 -gt $3 ]]; then
        return 0
    elif [[ $1 -lt $2 ]]; then
        return 0
    else
        return 1
    fi
}

userinput "Photo" IDNumber
checkNumber Photo IDNumber 1 99999
filename="p$IDNumber.photo"

FILE=data/$filename
if [ -f "$FILE" ]; then 
    rm "$FILE"
    echo "$FILE was successfully deleted."
else
   echo "ERROR: photo $FILE not found" 
    exit 0
fi  

doot=$(date "+[%Y-%m-%d %H:%M:%S]")
echo "$doot DELETED: $IDNumber" >> ./data/queries.log