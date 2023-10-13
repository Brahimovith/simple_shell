#include "shell.h"
char *_getenv(char *va)
{
    char *env,*cop, *cle, *valeur;
    int j;
    for(j = 0;environ[j]; j++)
    {
       cop = strdup(environ[j]);
       cle = strtok(cop, "=");
       if(strcmp(cle,va) == 0)
       {
          valeur = strtok(NULL, "\n");
          env = strdup(valeur);
          free(cop);
          return (env);
          
       }
    
    free(cop),cop= NULL;
    
    }
    
    return NULL;
}

int builtinn(char * c)
{
  char *b[] ={"exit","env","setenv","cd",NULL};
  int i;
  for(i=0;b[i];i++)
  {
  
    if(_strcmp(c,b[i])==0){return 1;}
    
  }
  return 0; 
}

void built(char **c,char **argv,int *s,int i)
{
  if(_strcmp(c[0],"exit")==0)
  {
    exit_shell(c,argv,s,i);
  }
  else if (_strcmp(c[0],"env")==0)
  {
    printenv(c,s);
  }
}

void exit_shell(char **c,char **argv,int *s,int i)
{
  char m[]=" exit: Illegal number: ";
  int e = (*s);
  i = i + '0';
  if(c[1])
  {
     if(positif(c[1]))
     {
        e = stoe(c[1]);
     }
     else
     {
        write(STDERR_FILENO, argv[0], _strlen(argv[0]));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, &i,1);
        write(STDERR_FILENO, m, _strlen(m));
        write(STDERR_FILENO, c[1], _strlen(c[1]));
        write(STDERR_FILENO, "\n", 1);
        vidercom(c);
        return;
     }
  
  }
  vidercom(c);
  exit(e);
}

void printenv(char **c,int *s)
{
  int i;
  for(i=0;environ[i];i++)
  {
  
     write(STDOUT_FILENO,environ[i],_strlen(environ[i]));
     write(STDOUT_FILENO,"\n",1);
  }
  vidercom(c);
  (*s) = 0;
}
