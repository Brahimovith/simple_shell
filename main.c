#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
* main - entry point
*
* @argc: first paramter
* @argv: second paramter
* @envp: therrd
* Return: 0 if success
*/

int main(int argc, char *argv[])
{
    char *ligne = NULL;
    char **com = NULL;
    int s = 0, i = 0;
    (void) argc;

    while(1)
    {
        ligne = lire_ligne();
        if(ligne == NULL)
        {
          if(isatty(STDIN_FILENO))
          {
             write(STDOUT_FILENO,"\n",1);
          }
          return (s);
        }
        i++;
        com = token(ligne);
        
        if(com == NULL)
        {
          continue;
        }
        
        if(builtinn(com[0]))
        {
          built(com,argv,&s,i);
        }
        else
        {
          s = executer(com, argv, i);
        }  

     
        
    }
    
}
