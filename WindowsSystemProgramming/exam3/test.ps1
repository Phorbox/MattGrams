New-Item -name "Lines.txt"
$currentLine = 1
foreach ($counter in 1..100) {
    if($counter % 2 -eq 1){
        Add-Content "Lines.txt" -Value $currentLine
        $currentLine+=1
    }
}
