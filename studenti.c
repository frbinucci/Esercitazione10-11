#include <stdio.h>
/*Definizione di una struttura "s_studente", rappresentante uno
studente universitario.

int matriocola=>Campo intero rappresenentante la matricola dello studente.
char cognome[30]=>Campo stringa contenente il cognome dello studente.
char nome[30]=>Campo stringa contenente il nome dello studente.*/
struct s_studente{
	int matricola;
	char cognome[30];
	char nome[30];
};
/*Definizione di una struttura "s_esame", rappresentante un esame
universitario.

int matricola=>Campo intero rappresentante la matricola dello studente che ha sostenuto l'esame.
char materia[30]=>Campo stringa rappresentante la materia d'esame.
int voto=>Campo intero rappresentante il voto d'esame.
int lode=>Campo booleano che rappresenta la presenza/assenza di lode.
*/
struct s_esame{
	int matricola;
	char materia[30];
	int voto;
	int lode;
};
//Definizione degli alias per le strutture definite.
typedef struct s_studente studente;
typedef struct s_esame esame;
/*--DEFINIZIONE DEI PROTOTIPI DELLE FUNZIONI NECESSARIE--*/
/*Prototipo della funzione "calcolaVisualizzaMedia()",che consente di calcolare e visualizzare la media degli esami
di uno studente indicato in input.

studente studenti[]=>Array di record rappresentante gli studenti memorizzati.
esame esami[]=>Array di record rappresentante gli esami memorizzati.
int sizeStudenti=>Parametro intero rappresentante la dimensione dell'array "studenti[]".
int sizeEsami=>Parametro intero rappresentante la dimensione dell'array "esami[]".
int mat=>Parametro intero rappresentante la matricola dello studente.
*/
void calcolaVisualizzaMedia(studente studenti[],esame esami[],int sizeStudenti,int sizeEsami,int mat);
/*Protitipo della funzione "matricolaEsistente()", la quale consente di verificare se un dato
studente è già memorizzato nell'array. La funzione restituisce due valori:

1=>Lo studente è già presente nell'array.
0=>Lo studente non è presente nell'array.

studente studenti[]=>Array di record rappresentante gli studenti memorizzati.
int size=>Parametro intero contenente la dimensione dell'array.
int mat=>Parametro intero contenente la matricola dello studente da ricercare.
*/
int matricolaEsistente(studente studenti[],int size,int mat);
//Funzione "main()".
int main()
{
	int dimStudenti;
	int dimEsami;
	printf("Inserire il numero di studenti: ");
	scanf("%d",&dimStudenti);
	printf("Inserire il numero di esami: ");
	scanf("%d",&dimEsami);
	printf("\n");

	studente studenti[dimStudenti];
	esame esami[dimEsami];
	int matricola;
	char continua;

	printf("****INSERIMENTO DATI STUDENTI****");
	printf("\n\n");

	for(int i=0;i<dimStudenti;i++)
	{
		do
		{
			printf("Inserire matricola studente: ");
			scanf("%d",&matricola);
			if(matricolaEsistente(studenti,dimStudenti,matricola))
			{
				printf("\nAttenzione! La matricola inserita esiste gia', riprovare!\n\n");
			}
		}
		while(matricolaEsistente(studenti,dimStudenti,matricola));
		studenti[i].matricola=matricola;
		printf("Inserire cognome studente: ");
		scanf("%29s",studenti[i].cognome);
		printf("Inserire nome studente: ");
		scanf("%29s",studenti[i].nome);
		printf("\n");
	}

	printf("\n");
	printf("****INSERIMENTO DATI ESAMI****");
	printf("\n\n");

	for(int i=0;i<dimEsami;i++)
	{
		do
		{
			printf("Inserire matricola studente: ");
			scanf("%d",&matricola);
			if(!matricolaEsistente(studenti,dimStudenti,matricola))
			{
				printf("\nAttenzione! Matricola non presente, riprovare!\n\n");
			}
		}
		while(!matricolaEsistente(studenti,dimStudenti,matricola));
		esami[i].matricola=matricola;
		printf("Inserire materia esame: ");
		scanf("%29s",esami[i].materia);
		printf("Inserire il voto d'esame: ");
		scanf("%d",&esami[i].voto);
		if(esami[i].voto==30)
		{
			printf("Lode? (0-1): ");
			scanf("%d",&esami[i].lode);
		}
		else
		{
			esami[i].lode=0;
		}
		printf("\n");
	}

	printf("\n");
	printf("****RICERCA INFORMAZIONI****");
	printf("\n\n");


	do
	{
		printf("\nInserire la matricola da ricercare: ");
		scanf("%d",&matricola);
		printf("\n");
		calcolaVisualizzaMedia(studenti,esami,dimStudenti,dimEsami,matricola);
		printf("\n\nContinuare? (s/n): ");
		scanf(" %c",&continua);
	}
	while(continua=='s');

	printf("\n\n");



}
/*Definizione della funzione "calcolaVisualizzaMedia()", necessaria a calcolare e visualizzare la media dei voti
di uno studente, data la sua matricola.*/
void calcolaVisualizzaMedia(studente studenti[],esame esami[],int sizeStudenti,int sizeEsami,int mat)
{
	double media=0;
	int esamiSostenuti=0;
	int trovato=0;
	int i=0;
	//Ricerca della matricola all'interno dell'array "studenti[]".
	while(i<sizeStudenti && !trovato)
	{
		if(studenti[i].matricola==mat)
		{
			trovato=1;
		}
		i++;
	}
	//Se la matricola è stata trovata, lo studente esiste, e verranno stampati i dati corrisponenti.
	if(trovato)
	{
		printf("%s %s media: ",studenti[i-1].cognome,studenti[i-1].nome);
		//Calcolo della media dello studente.
		i=0;
		while(i<sizeEsami)
		{
			if(esami[i].matricola==mat)
			{
				media+=esami[i].voto;
				esamiSostenuti++;
			}
			i++;
		}
		if(esamiSostenuti!=0)
		{
			media/=esamiSostenuti;
		}
		//Stampa della media.
		printf("%g",media);

	}
	else
	{
		//Se la matricola non viene trovata viene generato un opportuno messaggio di errore.
		printf("Attenzione! Matricola non trovata!");
	}

}
//Definizione della funzione "matricolaEsistente()".
int matricolaEsistente(studente studenti[],int size,int mat)
{
	int trovato=0;
	int i=0;
	/*Ricerca della matricola nell'array "studenti[]", passato come parametro
	alla funzione.*/
	while(i<size && !trovato)
	{
		if(studenti[i].matricola==mat)
		{
			trovato=1;
		}
		i++;
	}

	return trovato;

}
