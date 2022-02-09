#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include <string.h>


struct nodo {
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;
struct nodo *fondo=NULL;


void insertarL(int x)
{
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    nuevo->sig=NULL;
    if (vacia())
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else
    {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}


void imprimir()
{
    struct nodo *reco=raiz;
    printf("La ip es:.\n");
    while (reco!=NULL)
    {
        printf("%i.",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int extraer()
{
    if (raiz != NULL)
    {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
    }
    else
    {
        return -1;
    }
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

int main()
{
	printf("\n1)IP a Binario\n\n2)MAC a BINARIO\n\nIngresa Opcion:\n");
	int m=0;
	scanf("%i",&m);
	menu(m);
    return 0;
}

void decabin (int n) {
    if (n) {
        decabin(n / 2);
        printf("%d", n % 2);
    }
}

void menu(int m){
	system("cls");
	int n[4], numeroD[6];
	char str[1];
	  switch (m) {
    case 1:
		printf("Programa que transforma IP's a Binario'\n");
		int i=0;
		printf("Ingresa la ip:\n.");
		for(i;i<4;i++){
			scanf("%d",&n[i]);
			if(n[i]<255 && n[i]>=0){
				insertarL(n[i]);
			}else{
				printf("\nIP invalida\n");
				return 0;
			}	
			if(i<3){
				printf(".");	
			}
			
		}
   		imprimir();
   		printf("En binario es:\n");
   		i = 0;
   		for(i;i<4;i++){
   			decabin(extraer());
   			if(i<3){
				printf(".");	
			}
  		 }
    liberar();
    getch();
    system("cls");
    main();

      break;
    case 2:
    	liberar();
    	system("cls");
    	printf("Programa que transforma MAC's a Binario'\n");
    	printf("Ingresa en MAYUSCULAS'\n");
		i=0;
		printf("Ingresa la MAC:\n::");
		for(i;i<6;i++){
			scanf("%s",str);
			numeroD[i]= Translate16To10(str);
			if(numeroD[i]<=255 && numeroD[i]>=0){
			insertarL(numeroD[i]);
			}else{
				printf("\nMAC invalida\n");
				return 0;
			}	
			if(i<5){
				printf("::");	
			}
  		}
		
		printf("En binario es:\n");
   		i = 0;
   		for(i;i<6;i++){
   			decabin(extraer());
   			if(i<5){
				printf("::");	
			}
			}
		liberar();
		getch();
    	system("cls");
 		main();
    	
      break;
    default:
    	system("cls");
		printf("Ninguna accion cerrando programa....\n");
		return 0;
	      break;
  }


}


int Translate16To10(char s[])
{
	int p = 0,i;
	int  n = 1;
	int ans=0;
	for ( i = strlen(s) - 1; i >= 0; i--)
	{
		if (s[i] >= 'A'&&s[i] <= 'F')
			p = s[i] - 'A' + 10;
		else
			p = s[i] - '0';
		ans += p * n;
		n *= 16;
	}
	return ans;
}

