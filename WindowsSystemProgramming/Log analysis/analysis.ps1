# Matthew Henderson rmt564
 
# This regex parses out each field
# it uses $Matches.key to grab the named groups
$theBeautifulYetGrossRegex = '(?<ip>^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - (?<user>.*?) \[(?<day>\d{2})\/(?<month>[A-Z][a-z]{2})\/(?<Year>\d{4}):(?<Time>\d{2}:\d{2}:\d{2}) (?<Timezone>[+-]\d{4})\] "(?<URI>.*)" (?<respnse>\d{3}) (?<Other>\d{1,10}) "(?<URL>.*)" "(?<metadata>.*)"'
$logFile = "access.log";

# reset days folder
Write-Output "Reseting Days"
$days = "days"
if (Test-Path -Path $days) {
    Remove-Item $days -Recurse
}

# reset ips folder
Write-Output "Reseting ips"
$ips = "ips"
if (Test-Path -Path $ips) {
    Remove-Item $ips -Recurse
}

## This commented out code is to store non-matches from theBeautifulYetGrossRegex
# Write-Output "Reseting Failed"
# $failedPath = "failed.log"
# if ((Test-Path -Path $failedPath)) {
#     Remove-Item -Path $failedPath
# }
# New-Item $failedPath | Out-Null

$culprits = @{}
$counter = 0
$failed = 0

Write-Output "Now Reading"
foreach ($line in Get-Content $logFile) {
    If ($line -Match $theBeautifulYetGrossRegex) {
        # parses matches
        $ip = $Matches.ip
        $user = $Matches.user
        $day = $Matches.day       
        $month = $Matches.month        
        $Year = $Matches.Year     
        $Time = $Matches.Time
        $Timezone = $Matches.Timezone
        $URI = $Matches.URI
        $respnse = $Matches.respnse
        $other = $Matches.Other
        $URL = $Matches.URL
        $metadata = $Matches.metadata
        
        # preps and sends days folder target
        $daysDirectory = "$days\\$Year\\$month\\$day"
        $daysPath = "$daysDirectory\\$ip"
        $content = "$user`t$Time`t$Timezone`t$URI`t$respnse`t$other`t$URL`t$metadata"

        if (!(Test-Path -Path $daysDirectory)) {
            New-Item $daysDirectory -ItemType Directory | Out-Null
        }
        if (!(Test-Path -Path $daysPath)) {
            New-Item $daysPath | Out-Null
        }
        Add-Content -path $daysPath -Value $content

        # preps and sends ips folder target
        $ipsDirectory = "$ips\\$ip"
        $ipsPath = "$ipsDirectory\\$day-$month-$Year"
        if (!(Test-Path -Path $ipsDirectory)) {
            New-Item $ipsDirectory -ItemType Directory | Out-Null
        }
        if (!(Test-Path -Path $ipsPath)) {
            New-Item $ipsPath | Out-Null
        }
        Add-Content -path $ipsPath -Value $content
        
        #adds line info to culprit map, or increments count if already there
        if ($culprits[$ip]) {
            $culprits[$ip] += 1
        }
        else {
            $culprits[$ip] = 1
        }
    }
    ## more code for finding failed matches
    # else {
    #     Add-Content -path $failedPath -Value "$line"
    #     $failed += 1
    # }

    # progress tracking
    $counter += 1
    if (($counter % 5000 ) -eq 0) {
        # Write-Output "Line: $counter`tFailed: $failed"
        Write-Output "Line: $counter"
    }
}

Write-Output "Read:`t$counter Lines"
Write-Output "Failed:`t$failed Lines"
Write-Output "Sorting Culprits"
$sortedCulprits = @{}
$max = 0

# transpose culprits map to an array map for determining sort
foreach ($ipCulprit in $culprits.keys) {
    $sortedIndex = $culprits[$ipCulprit]
    $temp = $sortedCulprits[$sortedIndex]
    #if row is initialized add to map
    if ($temp) {
        $sortedCulprits[$sortedIndex]+=($ipCulprit)
    }
    #if not, initialize with current culprit
    else {
        $temp = @($ipCulprit)
        $sortedCulprits[$sortedIndex] = $temp
    }
    #get max for iterating through sorted map
    if ($sortedIndex -gt $max) {
        $max = $sortedIndex
    }   
}

#prep culprits and write sorted map
Write-Output "Writing Culprits"
$culpritsPath = "Culprits.txt"
if ((Test-Path -Path $culpritsPath)) {
    Remove-Item -Path $culpritsPath
}
New-Item $culpritsPath | Out-Null
foreach ($key in $max..1) {
    foreach ($each in $sortedCulprits[$key]) {
        Add-Content -path $culpritsPath -Value "$key`t$each"
    }
    
}
