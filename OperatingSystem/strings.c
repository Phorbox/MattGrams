// matthew Henderson rmt564

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isVowel(char thing)
{
   return (thing == 'a' ||
           thing == 'e' ||
           thing == 'i' ||
           thing == 'o' ||
           thing == 'u');
}

int isConsanant(char thing)
{
   return (thing >= 'a' &&
           thing <= 'z');
}

int isQuit(char *thing)
{
   char temp[5];
   temp[4] = '\0';
   for (int i = 0; i < 4; i++)
   {
      temp[i] = thing[i];
   }
   return !strcmp(temp, "quit");
}

void allLower(char *thing)
{
   int i = 0;
   while (thing[i] != '\0')
   {
      thing[i] = tolower(thing[i]);
      i++;
   }
}

int isEnd(char thing)
{
   return (thing != '\0' && thing != '\n');
}
int isNotBlank(char *thing)
{
   return (thing != NULL) && strcmp(thing, "\n");
}

int main()
{
   int vowels, consonant, digit, space;
   char line[80];
   char *token;
   while (1)
   {

      vowels = consonant = digit = space = 0;
      printf("Please enter a sentence:  ");

      fgets(line, sizeof(line), stdin);
      allLower(line);
      if (isQuit(line))
      {
         printf("Exiting");
         exit(0);
      }
      token = strtok(line, " ");
      if (isNotBlank(token))
      {
         space++;
      }

      while (token != NULL)
      {
         int i = 0;
         while (isEnd(token[i]))
         {
            if (isVowel(token[i]))
            {
               ++vowels;
            }
            else if (isConsanant(token[i]))
            {
               ++consonant;
            }
            i++;
         }
         token = strtok(NULL, " ");
         if (isNotBlank(token))
         {
            space++;
         }
      }

      printf("Number of vowels found: %d", vowels);
      printf("\nNumber of consonants found: %d", consonant);
      printf("\nNumber of words:  %d\n\n", space);
   }
   return 0;
}
