#include <stdio.h>
#include <string.h>
#define dimStringhe 30

int retDistanza(int n,char citta[][dimStringhe],int distanze[][n],char citta1[],char citta2[]);
void trovaDistanzeMaggiori(int n,char citta[][dimStringhe],int distanze[][n],int k);

int main()
{
	int n;
	printf("Inserire il numero di citta': ");
	scanf("%d",&n);
	printf("\n");

	char citta[n][dimStringhe];
	int scelta;
	int distanze[n][n];
	int i,j;

	char citta1[dimStringhe],citta2[dimStringhe];
	int k;

	for(i=0;i<n;i++)
	{
		printf("Inserire la citta' n.%d: ",i+1);
		scanf("%s",citta[i]);
	}

	printf("\n");

	for(i=0;i<n;i++)
	{
		distanze[i][i]=0;
		for(j=i+1;j<n;j++)
		{
			printf("Inserire la distanza %s-%s: ",citta[i],citta[j]);
			scanf("%d",&distanze[i][j]);
			distanze[j][i]=distanze[i][j];
		}
	}
	printf("\n");
	do
	{
		printf("Selezionare un'opzione: ");
		printf("\n");
		printf("1.Distanza tra due citta'\n");
		printf("2.Citta' piu' distanti di ... km\n");
		printf("3.Esci\n");
		scanf("%d",&scelta);
		printf("\n");
		switch(scelta)
		{
			case 1:
				printf("Inserire la prima citta': ");
				scanf("%s",citta1);
				printf("Inserire la seconda citta': ");
				scanf("%s",citta2);
				if(retDistanza(n,citta,distanze,citta1,citta2)==-1)
				{
					printf("\nAttenzione! Una delle due citta' non e' presente!\n\n");
				}
				else
				{
					printf("\nLa distanza tra le due citta' e': %d\n\n",retDistanza(n,citta,distanze,citta1,citta2));
				}
				break;
			case 2:
				printf("Inserire il valore di confronto: ");
				scanf("%d",&k);
				printf("\n");
				trovaDistanzeMaggiori(n,citta,distanze,k);
				break;
			case 3:
				break;
			default:
				printf("\nValore non riconosciuto, riprovare!\n\n");
				break;
		}


	}
	while(scelta!=3);




}

int retDistanza(int n,char citta[][30],int distanze[][n],char citta1[],char citta2[])
{
	int i,j;
	int trovato=0;
	int distanza;
	i=0;
	while(i<n && !trovato)
	{
		if(strcmp(citta[i],citta1)==0)
		{
			trovato=1;
		}
		i++;
	}
	if(trovato)
	{
		trovato=0;
		i--;
		j=0;
		while(j<n && !trovato)
		{
			if(strcmp(citta[j],citta2)==0)
			{
				trovato=1;
			}
			j++;
		}
		if(trovato)
		{
			j--;
			distanza = distanze[i][j];
		}
		else
		{
			distanza=-1;
		}
	}
	else
	{
		distanza=-1;
	}

	return distanza;


}

void trovaDistanzeMaggiori(int n,char citta[][dimStringhe],int distanze[][n],int k)
{
	int contaCitta=1;
	printf("Elenco di citta' la cui distanza e' maggiore di %d:\n",k);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(distanze[i][j]>k)
			{
				printf("%d)%s-%s\n",contaCitta,citta[i],citta[j]);
				contaCitta++;
			}
		}
	}
	printf("\n");
}