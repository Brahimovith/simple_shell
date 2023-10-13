#include "shell.h"
char *_getpath(char *commande)
{
char *lien, *tcom, *dossier;
int i;
struct stat s;
for(i = 0;commande[i];i++)
{
   if(commande[i] == '/')
   {
       if(stat(commande,&s) == 0)
       {
       return (_strdupl(commande));
       }
       else 
       {
        return NULL;
       }
   }

}
lien = _getenv("PATH");
if(lien == NULL)
{
return NULL;
}
dossier = strtok(lien, ":");
while(dossier)
 {
 tcom = malloc(_strlen(dossier)+_strlen(commande)+2);
 if(tcom)
 {
  _strcpy(tcom,dossier);
  _strcat(tcom,"/");
  _strcat(tcom,commande);
  if(stat(tcom,&s) == 0)
  {
    free(lien), lien = NULL;
    return tcom;
  }
  free(tcom), tcom =NULL;
  dossier = strtok(NULL,":");
 }  
 }
 
 free(lien), lien = NULL;
 return NULL;    
}
