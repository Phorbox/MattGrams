



public static void mostCommonNames(Scanner input) {
        
         
        while (input.hasNextLine()){
          String alpha = input.nextLine();
          Scanner lineScan = new Scanner(alpha);
            
            int counter =  1;  
            String duplo = "";
            String nameA = "";
            
            
            while (lineScan.hasNext()) {
               
               String nameB = lineScan.next(); 
               
               if(nameA.contains(nameB)){
                  counter++;
               }else if(counter > 1){
            
                  duplo = duplo + nameA + "*" + counter + " ";
                  counter = 1;
                  nameA = nameB;
               }else{
                  nameA = nameB;
               }
               
               
            }
              if(counter > 1){
              
              duplo = duplo + nameA + "*" + counter + " ";   
              }
               System.out.print(duplo);
              System.out.println();
        
         }
        
        }