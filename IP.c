#include <stdio.h>
#include <stdlib.h>
#define MAX_TOKENS 4
#include <string.h>

void class(char *addresse);
void condition(char *addresse);

int main()
{
	char addresse[50];
	char addresse2[50];
	strcpy(addresse,getenv("QUERY_STRING"));
	sscanf(addresse,"ip=%s",addresse2);
	printf("Content-Type: text/html\n\n");
	printf("<html>\n");
	printf("	<head>\n");
	printf("		<title><b><FONT size =2>addresse IP</FONT></b></title>\n");
	printf("	</head>\n");
	printf("	<body>\n");
	
	condition(addresse2);
	class(addresse2);
	
	printf("	</body>\n");
	printf("</html>\n");
	return 0;
}
void condition(char *addresse2)
{
	int nombre_point=0;
	int len =0;
	len=strlen(addresse2);
	int i=0;
	for(i=0; i<len; i++)
	{
		if(addresse2[i]=='.')
		{
			nombre_point++;
		}
	}
	
	if(nombre_point !=3 )
	{
		printf("		ceci n'est pas un addresse IP V4");
		exit (3);
	}
}

void class(char *addresse2)
{
	int tabaddresse[4];
	int j=0;
	int i=0;
	char *tokens[MAX_TOKENS];
	const char delimiter[] = ".";
	char *token = strtok(addresse2, delimiter); 
	while (token != NULL && j < MAX_TOKENS)
	{
        tokens[j] = token;
        j++;
        token = strtok(NULL, delimiter);
    }
    
    for(i=0 ; i<4 ; i++)
    {
		tabaddresse[i]=atoi(tokens[i]);
	}
    
	for(i=0 ; i<4 ; i++)
	{
		if(tabaddresse[i]<0)
		{
			printf("adresse IP non valide\n");
			printf("%d inférieur à 0",tabaddresse[i]);
			exit (1);
		}
		if(tabaddresse[i]>255)
		{
			printf("adresse IP non valide\n");
			printf("%d supérieur à 8-bit",tabaddresse[i]);
			exit (2);
		}
	}
	if(tabaddresse[0]>=0 && tabaddresse[0]<=127)
	{
		printf("l'addresse IP est de classe A");
	}
	
	if(tabaddresse[0]>=128 && tabaddresse[0]<=191)
	{
		printf("l'addresse IP est de classe B");
	}
	
	if(tabaddresse[0]>=192 && tabaddresse[0]<=223)
	{
		printf("l'addresse IP est de classe C");
	}
	
	if(tabaddresse[0]>=224 && tabaddresse[0]<=239)
	{
		printf("l'addresse IP est de classe D");
	}
	if(tabaddresse[0]>=240 && tabaddresse[0]<=255)
	{
		printf("l'addresse IP est de classe E");
	}
}
