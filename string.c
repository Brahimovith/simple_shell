#include "shell.h"
/**
 * erreur - print erreur
 * @n: p
 * @comd: p
 * @i: p
 * Return: int
 */
void erreur(char* nom,char * comd,int i)
{
    char l;
    char m[] = ": not found\n";
    
    l = i + '0';
    
    write(STDERR_FILENO, nom, _strlen(nom));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, &l, 1);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, comd, _strlen(comd));
    write(STDERR_FILENO, m, _strlen(m));
    

}
int positif(char *str)
{

int i;
if(str == NULL)
{ 
  return 0;
}
for(i = 0;str[i];i++)
{
   if(str[i] < '0' || str[i] > '9')
   {
     return 0;
   }
} 
  return 1;
}

int stoe(char *str)
{
int i,n=0;

for(i=0;str[i];i++)
{
  n *= 10;
  n *= (str[i] - '0');
}
return n;
}

char* _itoa(int i)
{
    char buf[30];
    int n = 0;

    if(i == 0)
    {
        buf[n++] = '0';
    }
    else
    {
        while(i > 0)
        {
            buf[n++] = (i % 10) + '0';
            n /= 10;
        }
    }
    buf[n] = '\0';
    revstring(buf, n);
    return (_strdupl(buf));
    
}

void revstring(char *buf, int i)
{
    char m;
    int s = 0;
    int e = i-1;

    while(s < e)
    {
        m = buf[s];
        buf[s] = buf[e];
        buf[e] = m;
        s++;
        e--;
    }

}


/**
 * _strlen - length
 * @s: p
 *
 * Return: int
 */
int _strlen(char *s)
{
	int q;
	int i;

	q = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		q++;
	}
	return (q);
}

/**
* _strcpy - copying the array
* @dest: first input
* @src: second input
*
* Return: char *
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}


/**
 * _strcat - cat
 * @dest: 1
 * @src: 2
 *
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int x;

	for (i = 0; *(dest + i) != '\0'; i++)
	{
	}
	for (x = 0; *(src + x) != '\0'; x++)
	{
		*(dest + i + x) = *(src + x);
	}
	*(dest + i + x) = '\0';
	return (dest);
}

/**
* _strcmp - copmare two str
* @s1: first input
* @s2: secend input
*
* Return: int
*/
int _strcmp(char *s1, char *s2)
{
	int x;
	int i;

	x = 0;
	for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			x = (int)*(s1 + i) - (int)*(s2 + i);
			break;
		}
	}
	return (x);
}

/**
* vidercom - a
* @com: tableau de string
*
* Return: void
*/
void vidercom(char **com)
{
    int i;
    if(com == NULL)
    {
        return;
    }
    for(i = 0; com[i]; i++)
    {
        free(com[i]);
        com[i] = NULL;
    }
    free(com), com = NULL;
}

/**
* _strdup - array
* @str: string
*
* Return: char
*/
char *_strdupl(char *str)
{
	int l,i;
	char *c;
	if(str == NULL)
	{
	   return(NULL);
	}
	l = _strlen(str);
	c = (char*)malloc((l+1)*sizeof(char));
	if(c == NULL)
	{
	return NULL;
	}
	for(i = 0; i <= l; i++)
	{
	c[i] = str[i];
	}
	return c;
}
