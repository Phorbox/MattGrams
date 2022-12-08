// matthew Henderson rmt564

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

enum opcode
{
   quit,
   cd,
   showpid,
   other
};

char **str_split(char *string, const char delimiter)
{
   char **result = 0;
   size_t count = 0;

   char *tmp = string;
   char *last_comma = 0;
   char delim[2];
   delim[0] = delimiter;
   delim[1] = 0;
   while (*tmp)
   {
      if (delimiter == *tmp)
      {
         count++;
         last_comma = tmp;
      }
      tmp++;
   }
   count += last_comma < (string + strlen(string) - 1);
   count++;

   result = malloc(sizeof(char *) * count);

   if (result)
   {
      size_t idx = 0;
      char *token = strtok(string, delim);

      while (token)
      {
         assert(idx < count);
         *(result + idx++) = strdup(token);
         token = strtok(0, delim);
      }
      assert(idx == count - 1);
      *(result + idx) = 0;
   }

   return result;
}

// int isCommand(char* possible){
//    return (strcmp(possible,"") ||
//    strcmp(possible,"") ||
//    strcmp(possible,"") ||
//    strcmp(possible,"") ||
//    strcmp(possible,"") ||
//    );
// }

int isQuit(char *thing)
{
   char temp[5];
   temp[4] = '\0';
   for (int i = 0; i < 4; i++)
   {
      temp[i] = thing[i];
   }

   return !(strcmp(temp, "quit") || strcmp(temp, "exit"));
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

int getCase(char *splitLine)
{
   printf("CASE:\t%s\n", splitLine);
   if (isQuit(splitLine))
   {
      return quit;
   }
   if (strcmp(splitLine, "cd") == 0)
   {
      return cd;
   }
   return other;
}

void lsh_loop()
{
   char line[80];
   char **splitLine;

   char *token;
   int caser;
   while (1)
   {

      printf("prompt$  ");

      fgets(line, sizeof(line), stdin);
      allLower(line);
      splitLine = str_split(line, ' ');
      caser = getCase(splitLine[0]);
      printf("CASER:\t%d\n", caser);

      switch (caser)
      {
      case quit:
         printf("Exiting\n");
         exit(0);
         break;
      case cd:
         printf("cd\t");
         printf("%s\n", splitLine[1]);
         break;
      case showpid:
         printf("showpid\t");
         printf("%s\n", splitLine[1]);
         break;
      case other:
         printf("other\t");
         printf("%s\n", splitLine[1]);
         break;
      default:
         break;
      }

      memset(line, '\0', 80);
      free(splitLine);
   }
}

int main(int argc, char **argv)
{
   // Load config files, if any.

   // Run command loop.
   lsh_loop();

   // Perform any shutdown/cleanup.

   return 0;
}