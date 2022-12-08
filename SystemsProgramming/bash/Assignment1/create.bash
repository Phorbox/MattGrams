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


pathInput () {
    while [[ $allCondition -ne 0 ]]; do
        read -p "Photo Name: " filePlace
        blankCheck "$filePlace"
        sumChecks
        printError "Photo Name" "the filepath to the photo"
    done
    clearChecks
}

yearInput () {
    while [[ $allCondition -ne 0 ]]; do 
        read -p "Year: " year
        blankCheck "$year"
        numberCheck "$year"
        sumChecks
        printError "Year" "a number greater than 0"
    done
    clearChecks
}

monthInput () {
    while [[ $allCondition -ne 0 ]]; do
         read -p "Month: " month
         blankCheck "$month"
         rangeCheck "$month" 1 12
         numberCheck "$month"
         sumChecks 
         printError "Month" "a number between 1 and 12"
    done
    clearChecks
}

dayInput () {
    while [[ $allCondition -ne 0 ]]; do
         read -p "Day: " day
         blankCheck "$day"
         numberCheck "$day"
         daysInMonth
         rangeCheck "$day" 1 "$lastDay"
         sumChecks
         printError "Day" "a number between 1 and $lastDay"
    done
    clearChecks
}

locationInput () {
    while [[ $allCondition -ne 0 ]]; do
        read -p "Location: " location
        blankCheck "$location"
        sumChecks
        printError "Location" "the location of the photo int the world"
    done
    clearChecks
}

peopleInput () {
    read -p "Names: " people
}

daysInMonth () {
    case "$month" in
    1|3|5|7|8|10|12)    lastDay=31;;
    4|6|9|11)           lastDay=30;;
    2)                  lastDay=29;;
    *)  echo "Error returning days in month"
        return 0;;
esac
}

###########################################
#End of Functions
###########################################

clearChecks
idInput
pathInput
yearInput
monthInput
dayInput
locationInput
peopleInput

#check if data file exists, if not create it.
FILE=/data
if [[ ! -d "$FILE" ]]; then 
    mkdir -p data
    echo "Creating data directory"
fi
fileName="p"$IDNumber".photo"

#check if date is within range
date="$day / $month / $year"

#update Log
doot=$(date "+[%Y-%m-%d %H:%M:%S]")
echo "$doot CREATED: "$IDNumber" - $filePlace - $date - $location - $people" >> ./data/queries.log

FILE="./data/$fileName"
echo "$FILE"
echo "$filePlace" > "$FILE"
echo "$year $month $day" >> "$FILE"
echo "$location" >> "$FILE"
echo "$people" >> "$FILE"
echo ""
echo "Created data/$fileName"
echo ""


