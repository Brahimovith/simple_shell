#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
 #include <sys/wait.h>
 #include <string.h>
 extern char **environ;

char *lire_ligne(void);
char** token(char* ligne);
char *_strdupl(char *str);
void vidercom(char **com);
int executer(char **com,char  **argv, int i);
int positif(char *str);
int stoe(char *str);
char *_getenv(char *variable);
char *_getpath(char *commande);
char* _itoa(int i);
void revstring(char *buf, int i);
void printenv(char **c,int *s);
void exit_shell(char **c,char **argv,int *s,int i);
void built(char **c,char **argv,int *s,int i);
int builtinn(char * c);
void _printenv(char **envp);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void erreur(char* nom,char * comd,int i);

#endif

