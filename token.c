#include "shell.h"
char** token(char* ligne)
{
 char *mot = NULL,*copie = NULL;
 const char *delim = " \n\t";
 char **com = NULL;
 int i = 0, j = 0;

 copie = strdup(ligne);

 mot = strtok(copie, delim);
 if(mot == NULL)
 {
   free(copie), copie = NULL;
   free(ligne), ligne = NULL;
   return (NULL);
 
 }
       
 while(mot)
 {
   i++;
    
   mot = strtok(NULL, delim);
 }
 free(copie),copie = NULL;
 com = malloc(sizeof(char *) * (i + 1));
 if(com == NULL)
 {
   free(ligne), ligne = NULL;
   return (NULL);
 }
  
 mot= strtok(ligne, delim);
 while(mot && j < i)
 {
    
    com[j] = strdup(mot);
    mot = strtok(NULL, delim);
    j++;
 }
 com[j] = NULL;
 free(ligne), ligne = NULL;
     
     
  return (com);
 
 
}
