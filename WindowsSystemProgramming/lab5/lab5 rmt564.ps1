## Matthew Henderson rmt564
## Lab 5 - PowerShell Operators	

## Work:	                    # Answer:
'PowerShell' -eq 'PowerShell';  #TRUE
'PowerShell' -eq 'powershell';  #TRUE
'PowerShell' -ceq 'powershell'; #FALSE
write-host " ";

## Work:    # Answer:	    
5 -gt 5;    #FALSE
5 -ge 5;    #TRUE
5 -lt 10;   #TRUE
write-host " ";

## Work:	                     # Answer:
'PowerShell' -like '*shell';     #TRUE
'PowerShell' -match '^*.shell%'; #FALSE
write-host " ";

## Work:	
$numbers = 1..10;           # Answer:
$numbers -contains 15;      #FALSE
$numbers -contains 10;      #TRUE
$numbers -notcontains 15;   #TRUE
15 -in $numbers;            #FALSE
10 -in $numbers;            #TRUE
write-host " ";

## Work:                                                 # Answer:
'PowerShell' -replace 'Shell';                           #Power
'SQL Saturday - Baton Rouge' -replace 'saturday', 'Sat'; #SQL Sat - Baton Rouge
'SQL Saturday - Baton Rouge'.Replace('Saturday', 'Sat'); #SQL Sat - Baton Rouge
write-host " ";

## Work:	
## Arithmetic Examples:	
$a = 10;
$b = 20;
$c = 25;
$d = 25;
## Find: # Answer:	
$a + $b; #30
$a - $b; #-10
$a * $b; #200
$b / $a; #2
$b % $a; #0
write-host " ";

## Find:	
$a = 10;
$b = 20;        # Answer:
$c = $a + $b;   #30
write-host $c;
$c += $a;       #40
write-host $c;
$c -= $a;       #30
write-host $c;
write-host " ";

## If Statements	
$x = 10;
If ($x -le 20) {	                  # Answer:
    Write-host("X was less than 20"); #X was less than 20
}


## If..else..statements	
## Work:	
## Set $x=20, modify the above if statement to print out if X is less than 20 or more than 20.	
## If…elseif…elseif statements
$x = 20;
If ($x -le 20) {
    Write-host("X($x) was less than 20");
}
else {
    Write-host("X($x) was more than 20");
}


## Work:	
## Set $x=30, write an if elseif statement to print out if X is equal to 10 or 20 or 30 or none of these.
$x = 10;
If ($x -eq 30) {
    Write-host("X($x) was equal to 30");
}
elseif ($x -eq 20) {
    Write-host("X($x) was equal to 20");
}
elseif ($x -eq 10) {
    Write-host("X($x) was equal to 10");
}
else {
    Write-host("X($x) was equal to nothing")
}


## Nested if statement	
## Work:	
## Set x=30, y=20, write a nested if statement to print out a message that x was equal to 30 and y was equal to 20.
$x = 30;
$y = 20;
If ($x -eq 30) {
    if ($y -eq 20) {
        Write-host("X($x) was equal to 30 and y($y) was equal to 20");
    }
    
}
else {
    Write-host("X($x) was equal to nothing");
}
write-host " ";

## Switch Statement	
switch (3) {	
    1 { "One" }
    2 { "Two" }	
    3 { "Three" }	
    4 { "Four" }	
    3 { "Three Again" }	
}	  
# Answer:                                                                              
#"Three", "Three Again"
write-host " ";

## Work:	
## Re-write the if…elseif..elseif.. from above into a switch statement.	
$x = 10;
switch ($x) { 
    { $x -eq 30 } {
        Write-host("X($x) was equal to 30");
    } 
    { $x -eq 20 } {
        Write-host("X($x) was equal to 20");
    } 
    { $x -eq 10 } {
        Write-host("X($x) was equal to 10");
    }
    Default {
        Write-host("X($x) was equal to nothing");
    }

}
write-host " ";

## Working with Arrays:	
$a = 5, 6, 7, 8, 9;
# Answer: 
# Print out numbers greater than 7:	

Write-Output "Numbers greater than 7"; 
$a -gt 7;
# Answer: 
#Numbers greater than 7
#8
#9
write-host " ";

## Work:	
## List all numbers greater than or equal to 7	
Write-Output "Numbers greater than or equal to 7";                                  
$a -ge 7; 
# Answer:
#Numbers greater than or equal to 7
#7
#8
#9
write-host " ";

# List all numbers smaller than 7
Write-Output "Numbers smaller than 7"; 
$a -lt 7; 
# Answer:
#Numbers smaller than 7
#5
#6
write-host " ";

# List all numbers smaller than or equal to 7
Write-Output "Numbers smaller or equal to than 7";                                  
$a -le 7; 
# Answer:
#Numbers smaller or equal to than 7
#5
#6
#7
write-host " ";

# Set an array with numbers 1 thru 10. Write a script to show only EVEN numbers.
$oneTen = 1..10;
Write-Output "even numbers 1-10"; 
foreach ($thing in $oneTen) {
    if ($thing % 2 -eq 0) {
        Write-Output $thing;
    }
} 
# Answer:                                                                                 
#even numbers 1-10
#2
#4
#6
#8
#10
write-host " ";

## Write a PowerShell script that reads in the following array and does the following:	
## Array to sort: 87,44,65,2,3,67,33,9,54,37,23,55,61,48,66,32,4,8,90,20	
## 1) Create two arrays, one with only even elements and one with only odd elements	
$unsorted = 87, 44, 65, 2, 3, 67, 33, 9, 54, 37, 23, 55, 61, 48, 66, 32, 4, 8, 90, 20;

$evens = @();
$odds = @();

# get evens and odds
foreach ($each in $unsorted) {
    switch ($each % 2) {
        0 { $evens += $each }
        1 { $odds += $each }
        Default { Write-host "Thats odd, is this even a number?" }
    }
}
Write-host "evens: $evens";
Write-host "odds:  $odds";
write-host " ";

## 2) Sorts each new even/odd array into descending (from largest to smallest)
# sort evens 
for ($j = 0; $j -lt $evens.Count; $j++) {
    $largest = $j;
    for ($i = $j; $i -lt $evens.Count; $i++) {
        if ($evens[$i] -gt $evens[$largest]) {
            $largest = $i;
        }
    }
    $temp = $evens[$j]
    $evens[$j] = $evens[$largest]
    $evens[$largest] = $temp
}
# sort odds
for ($j = 0; $j -lt $odds.Count; $j++) {
    $largest = $j;
    for ($i = $j; $i -lt $odds.Count; $i++) {
        if ($odds[$i] -gt $odds[$largest]) {
            $largest = $i;
            
        }
    }
    $temp = $odds[$j];
    $odds[$j] = $odds[$largest];
    $odds[$largest] = $temp;
}
Write-host "Sorted evens:  $evens";
Write-host "Sorted odds:  $odds";
write-host " ";
# You must turn in your source code as well as your output.	


