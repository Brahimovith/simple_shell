
#include "shell.h"
int executer(char **com,char **argv, int i)
{
   pid_t enfant;
   char *cc;
   int s;
   cc= _getpath(com[0]);
   if(cc == NULL)
   {
     erreur(argv[0],com[0],i);  
     vidercom(com);
     return(127);
   }
   enfant = fork();
   if(enfant == 0)
   {
      if(execve(cc, com, environ) == -1)
      {
        free(cc),cc= NULL;
        vidercom(com);
       
      }
   
   
   }
   else
   {
      waitpid(enfant,&s,0);
      vidercom(com);
      free(cc),cc= NULL;
      
      
   
   }
   return (WEXITSTATUS(s));

}
