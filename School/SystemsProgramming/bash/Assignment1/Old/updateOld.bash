#!/bin/bash

#$1 is a string describing the variable $2 is destination for the variable
userinput () { 
    read -p "$1: " $2
    
}

#Format 1 is the number to check, 2 is the lower bound inclusive, 3 is the upperbound inclusive
userInputCondition () {
    
    if [[ 1 -gt $3 ]]; then
        return 0
    elif [[ $1 -lt $2 ]]; then
        return 0
    else; then
        return 1
    fi
}

#Format: 1 is the name of the variable, 2 is the number to check, 3 is the lower bound inclusive, 4 is the upperbound inclusive
checkNumber () {
    if [[ $# -ne 4 ]]; then
        echo "Error checking $1 variable"
        return 0
    fi
    while userInputCondition $2 $3 $4 ; do
        userinput "$1 number must be in the range of $3 and $4: " $2
    done
}


#assumes leap year is always possible
checkDate () {
    checkNumber Month month 1 12
    daysInMonth
    checkNumber Day day 1 $daysOfMonth
}

daysInMonth () {
    case "$month" in
    1|3|5|7|8|10|12) daysOfMonth=31;;
    4|6|9|11) daysOfMonth=30;;
    2) daysOfMonth=29;;
    *)  echo "Error returning days in month"
        return 0;;
esac
}

readOldVars () {
 read photo   
 read year_old month_old day_old
 read location_old
 read names_old
}

askUpdate () {
    userinput $1 $2
    if [ -z "$2" ]; then 
        "$2" = "$2_old"
        echo "Using old $1"
    fi
}


read -p "Photo" IDNumber
checkNumber Photo IDNumber 1 99999
filename="p$IDNumber.photo"

FILE=data/$filename
if [ -f "$FILE" ]; then 
    readOldVars < "$FILE" 

else
   echo "ERROR: photo $FILE not found" 
    exit 0
fi    

askUpdate "Year" year
askUpdate "Month" month
askUpdate "Day" day
askUpdate "Location" location
askUpdate "Names" people

#update Log
doot=$(date "+[%Y-%m-%d %H:%M:%S]")
echo "$doot CREATED: $IDNumber - $filePlace - $date - $location - $people" >> ./data/queries.log

echo "$filePlace" > "$FILE"
echo "$year $month $day" >> "$FILE"
echo "$location" >> "$FILE"
echo "$people" >> "$FILE"
echo ""
echo "Updated data/$fileName"
echo ""
