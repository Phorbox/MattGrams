#!/bin/bash

read -p "Enter an input filename:" filename

counter=0
checker=0
big=0

while read line; do
    let counter=$counter+1
    let checker=$counter%3
    if [[ checker -eq 0 ]]; then
        let big=$big+1
        echo "$line"
    fi
done < "$filename"

if [[ $big -gt 10 ]]; then
    echo "Big"
else
    echo "Small" 
fi

exit 0

for step in File Date Location Names; do
        read line < "$FILE"

        case "$step" in
            File)       read line < "$FILE"
                        echo "$step: $line"
                        ;;
            Date)       read line lineM lineD < "$FILE"
                        echo "$step: $lineM/$lineD/$line"
                        ;;
            Location)   read line < "$FILE" 
                        echo "$step: $line"
                        ;;
            Names)      read line < "$FILE"
                        echo "$step: $line"
                        ;;
            *)  ;;
        esac
    done 