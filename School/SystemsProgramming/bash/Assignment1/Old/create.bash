#!/bin/bash

#$1 is a string describing the variable $2 is destination for the variable
userinput () { 
    condition=1
    while [[ $condition -ne 0 ]]; do
    
        read -p "$1: " $2
        
        echo $2
        if [[ ! -z $2 ]]; then 
            condition=0
        else
            echo "$1 cannot be blank, please enter a value."
        fi
    done
}



isNumber () {
    if [[ $2 -gt 0 ]]; then 
        condition=0
    fi
}

yearInput () {
    condition=1
    while [[ $condition -ne 0 ]]; do
         read -p "$1: " $2
         isNumber $2
    done
}

#Format 1 is the number to check, 2 is the lower bound inclusive, 3 is the upperbound inclusive
userRangeCondition () {
    
    if [[ $1 -gt $3 ]]; then
        condition=1
    elif [[ $1 -lt $2 ]]; then
        condition=1
    else
        condition=0
    fi
}

#Format: 1 is the name of the variable, 2 is the number to check, 3 is the lower bound inclusive, 4 is the upperbound inclusive
checkNumber () {
    userRangeCondition $2 $3 $4
    while [[ $condition -ne 0 ]]; do
        userinput "$1 number must be in the range of $3 and $4: " $2
        userRangeCondition $2 $3 $4
    done
}


daysInMonth () {
    newCondition=$month
    case $newCondition in
    1|3|5|7|8|10|12) daysOfMonth=31;;
    4|6|9|11) daysOfMonth=30;;
    2) daysOfMonth=29;;
    *)  echo "Error returning days in month"
        return 0;;
esac
}


userinput "Photo" IDNumber
checkNumber "Photo" IDNumber 1 99999

userinput "PhotoName" filePlace

yearInput "Year: " year
userinput "Month: " month
checkNumber "Month" "month" 1 12

daysInMonth
userinput "Day" day
checkNumber "Day" day 1 "$daysOfMonth"

userinput "Location" location
userinput "Names" people


#check if data file exists, if not create it.
FILE=/data
echo "$FILE"
if [[ ! -d "$FILE" ]]; then 
    mkdir -p data
    echo "Creating data directory"
fi
fileName="p$IDNumber.photo"

#check if date is within range
date="$day / $month / $year"

#update Log
doot=$(date "+[%Y-%m-%d %H:%M:%S]")
echo "$doot CREATED: $IDNumber - $filePlace - $date - $location - $people" >> ./data/queries.log

FILE="./data/$fileName"
echo "$FILE"
echo "$filePlace" > "$FILE"
echo "$year $month $day" >> "$FILE"
echo "$location" >> "$FILE"
echo "$people" >> "$FILE"
echo ""
echo "Created data/$fileName"
echo ""


