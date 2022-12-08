#!/bin/bash

fileEnding=".photo"

#user input
userinput() {
    read -p "$1: " $2
}

userinput "Photo: " IDNumber
userinput "PhotoName: " filePlace
userinput "Year: " year
userinput "Month: " month
userinput "Day: " day
userinput "Location: " location
userinput "Names: " people

#print user info
fileName="p$IDNumber$fileEnding"
date="$day / $month / $year"

echo "Photo: $IDNumber $fileName"
echo "File $filePlace"
echo "Date: $date"
echo "Location: $location"
echo "Names: $people"

#check for the file
#check if date is within range
#check if data file exists, if not create it.
#update Log