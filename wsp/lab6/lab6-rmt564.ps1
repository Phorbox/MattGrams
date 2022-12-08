# Matthew Henderson rmt564 
# part 1
$randFile = "randomNumbers.txt"
if(Test-Path -Path $randFile){
    Remove-Item $randFile
}
New-Item $randFile

for ($i = 0; $i -lt 20; $i++) {
    $newRand = Get-Random -maximum 100
    Add-Content $randFile  $newRand
}

# part 2
$accountsFile = "Accounts.txt"
if(Test-Path -Path $accountsFile){
    Remove-Item $accountsFile
}
New-Item $accountsFile

foreach($line in Get-Content $randFile) {
    $outLine = "FirstName$line,LastName$line"
    Add-Content $accountsFile $outLine

}

# part 3
$accountsCsv = "Accounts.csv"
if(Test-Path -Path $accountsCsv){
    Remove-Item $accountsCsv
}
New-Item $accountsCsv

foreach($line in Get-Content $accountsFile) {
    Add-Content $accountsCsv $line

}

# part 4
$evens = "evens"
if(Test-Path -Path $evens){
    Remove-Item $evens -Recurse
}
New-Item $evens -ItemType Directory

$odds = "odds"
if(Test-Path -Path $odds){
    Remove-Item $odds -Recurse
}
New-Item $odds -ItemType Directory

foreach($line in Get-Content $accountsCsv) {
    $accountNumber = $line.Split(',')[-1] -replace '[^0-9]' , ''
    switch ($accountNumber % 2) {
        0 { $outputFile = "$evens\Account$accountNumber.txt" }
        1 { $outputFile = "$odds\Account$accountNumber.txt" }
        Default {break}
    }
    Add-Content $outputFile $line

}