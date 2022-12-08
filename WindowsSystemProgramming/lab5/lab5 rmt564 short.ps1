## Matthew Henderson rmt564
## Lab 5 - PowerShell Operators	

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


