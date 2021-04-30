BEGIN{
    n = length("news.cais.net:");
    for(i = 0; i < 2*n; i++){
        printf(" ");
    }
    printf("Incoming News Feed Summary\n");
    printf("\n");
    for(i = 0; i < n; i++){
        printf(" ");
    }
    printf("\t");
    printf("Accepted\t Rejected\t Cancelled\n");
    temp = 0;
    replacer = 0;
    
    for (i = 0; i <= 2; i++){
        tempArr[i] = "";
    }

    for (i = 1; i <= 6; i++){
        oldest[i] = 0;
        current[i] = 0;
        youngest[i] = 999;
    }

    #1 accepted, 2 rejected, 3 cancelled
    for (i = 1; i <= 3; i++){
        swrinde[i] = 0;
        cais[i] = 0;
        question[i] = 0;
    }
}
{
   # printf("%s %d %d %d %d %d",$1,);
    #make array for current date
    # mm dd hh mm ss lll
    # 1  2  3  4  5  6
    #turn month to number for array   
    switch ($1) {
        case "Jan"  : 
            current[1] = 1;
            break
        case "Feb"  : 
            current[1] = 2;
            break
        case "Mar"  : 
            current[1] = 3;
            break
        case "Apr"  : 
            current[1] = 4;
            break
        case "May"  : 
            current[1] = 5;
            break
        case "Jun"  : 
            current[1] = 6;
            break
        case "Jul"  : 
            current[1] = 7;
            break
         case "Aug"  : 
            current[1] = 8;
            break
         case "Sep"  : 
            current[1] = 9;
            break
        case "Oct"  : 
            current[1] = 10;
            break
         case "Nov"  : 
            current[1] = 11;
            break
         case "Dec"  : 
            current[1] = 12;
            break
        default :
            break
    }
    
    #add day to array
    current[2] = $2;
    
    #parse time into 3,4
    split($3, tempArr, ":")
    for (i = 1; i <= 2; i++){
        current[i+2] = tempArr[i];
    }

    #parse time into 5,6
    split(tempArr[3], tempArr, ".")
    for (i = 1; i <= 2; i++){
        current[i+4] = tempArr[i];
    }

    #if high replace oldest
    replacer = 0;
    for (i = 1; i < 7; i++){
        if(replacer == 1 || current[i] > oldest[i]){
            oldest[i] = current[i];
            replacer = 1;
        }else if(current[i] == oldest[i]){

        }
        else {
            i += 7;
        }
    }

    #if low replace youngest
    replacer = 0;
    for (i = 1; i < 7; i++){
        if(replacer == 1 || current[i] < youngest[i]){
            youngest[i] = current[i];
            replacer = 1
        }else if(current[i] == youngest[i]){

        }
        else {
            i += 7;
        }
    }

    temp = 0;
    #if + or j add to accepted 1
    
    if(match($4,"+")||match($4,"j")){
        temp = 1;

    #if c add to cancelled 3
    } else if(match($4,"c")){
        temp = 3;

    #if - add to rejected 2
    } else if(match($4,"-")){
        temp = 2;
    }

    #increment appropriate feed
    if (match($5,"swrinde")){
        swrinde[temp]++;
        if (temp == 3){
            swrinde[1]++;
        }
    }
    if (match($5,"news.cais.net")){
        cais[temp]++;
        if (temp == 3){
            cais[1]++;
        }

    }
    if (match($5,"?")){
        question[temp]++;
        if (temp == 3){
            question[1]++;
        }

    }

}

END{
    switch (youngest[1]) {
        case 1  : 
            youngest[7] = "Jan";
            break
        case 2  : 
            youngest[7] = "Feb";
            break
        case 3  : 
            youngest[7] = "Mar";
            break
        case 4  : 
            youngest[7] = "Apr";
            break
        case 5  : 
            youngest[7] = "May";
            break
        case 6  : 
            youngest[7] = "Jun";
            break
        case 7  : 
            youngest[7] = "Jul";
            break
        case 8  : 
            youngest[7] = "Aug";
            break
        case 9  : 
            youngest[7] = "Sep";
            break
        case 10  : 
            youngest[7] = "Oct";
            break
        case 11  : 
            youngest[7] = "Nov";
            break
        case 12  : 
            youngest[7] = "Dec";
            break
        default :
            break
    }

    switch (oldest[1]) {
        case 1  : 
            oldest[7] = "Jan";
            break
        case 2  : 
            oldest[7] = "Feb";
            break
        case 3  : 
            oldest[7] = "Mar";
            break
        case 4  : 
            oldest[7] = "Apr";
            break
        case 5  : 
            oldest[7] = "May";
            break
        case 6  : 
            oldest[7] = "Jun";
            break
        case 7  : 
            oldest[7] = "Jul";
            break
        case 8  : 
            oldest[7] = "Aug";
            break
        case 9  : 
            oldest[7] = "Sep";
            break
        case 10  : 
            oldest[7] = "Oct";
            break
        case 11  : 
            oldest[7] = "Nov";
            break
        case 12  : 
            oldest[7] = "Dec";
            break
        default :
            break
    }


    #print swrinde
    printf("swrinde:")
    for(i = 0; i < n-length("swrinde:"); i++){
        printf(" ");
    }
    printf("\t");
    printf("%-8d\t %-8d\t %-8d \n",swrinde[1], swrinde[2], swrinde[3]);

    #print cais
    printf("news.cais.net:")
    printf("\t");
    printf("%-8d\t %-8d\t %-8d \n", cais[1], cais[2], cais[3]);
    #print ?
    printf("?:")
    for(i = 0; i < n-length("?:"); i++){
        printf(" ");
    }
    printf("\t");
    printf("%-8d\t %-8d\t %-8d\n",question[1], question[2], question[3]);
    printf("Start Time = ");
    printf("%s ", youngest[7]);
    printf("%02d ", youngest[2]);
    printf("%02d:", youngest[3]);
    printf("%02d:", youngest[4]);
    printf("%02d.", youngest[5]);
    printf("%03d", youngest[6]);
    printf("\t"); 
    printf("\tEnd Time = ");
    printf("%s ", oldest[7]);
    printf("%02d ", oldest[2]);
    printf("%02d:", oldest[3]);
    printf("%02d:", oldest[4]);
    printf("%02d.", oldest[5]);
    printf("%03d", oldest[6]);
    printf("\n");
    
}