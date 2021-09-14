#!/bin/bash

blankCheck () {
    if [[ ! -z $1 ]]; then 
        blankCondition=0
    else
        blankCondition=1
    fi
}

#Format 1 is the number to check, 2 is the lower bound inclusive, 3 is the upperbound inclusive
rangeCheck () {
    if [[ $1 -gt $3 ]]; then
        rangeCondition=1
    elif [[ $1 -lt $2 ]]; then
        rangeCondition=1
    else
        rangeCondition=0
    fi
}

numberCheck () {
    if [[ $1 -gt 0 ]]; then 
        numberCondition=0
    else
        numberCondition=1
    fi
}

clearChecks () {
    blankCondition=0
    rangeCondition=0
    numberCondition=0
    allCondition=1
}

sumChecks () {
    let allCondition=$blankCondition+$rangeCondition+$numberCondition
}

printError () {
    if [[ allCondition -gt 0 ]]; then
        echo "$1 must be $2."
    fi
}

idInput () {
    while [[ $allCondition -ne 0 ]]; do
        read -p "Photo: " IDNumber
        blankCheck "$IDNumber"
        rangeCheck "$IDNumber" 1 99999
        numberCheck "$IDNumber"
        sumChecks
        printError "Photo" "a number between 1 and 99999"
    done
    clearChecks
}

printInfo () {
    echo "$1: $2"
}

readOldVars () {
 read photo
 read year_old month_old day_old
 read location_old
 read names_old
}

###########################################
#End of Functions
###########################################

clearChecks
idInput
filename="p$IDNumber.photo"

FILE=data/$filename
if [ -f "$FILE" ]; then 
    readOldVars < "$FILE"
    printInfo "File" "$photo"
    printInfo "Date" "$month_old/$day_old/$year_old"
    printInfo "Location" "$location_old"
    printInfo "Names" "$names_old"
    echo ""
else
   echo "ERROR: photo $FILE not found" 
    exit 0
fi    
