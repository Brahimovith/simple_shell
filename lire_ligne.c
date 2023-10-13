#include "shell.h"
/**
* read_line - take line from user
*
* Return: string
*/

char *lire_ligne(void)
{
   char *l = NULL;
   size_t len = 0;
   ssize_t m;
   
   if(isatty(STDIN_FILENO) == 1)
   {
     write(STDOUT_FILENO, "$ ",2);
   }
   m = getline(&l, &len, stdin);
   if(m == -1)
   {
     free(l), l= NULL;
     return (NULL);
   }
   l[strlen(l) - 1] = '\0';
   return (l);
   
}

