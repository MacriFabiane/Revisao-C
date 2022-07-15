/*) Ler uma string e copiar o valor decimal do código ASCII de cada elemento da string para um vetor. Mostrar 
o vetor. Ordenar o vetor. Mostrar o vetor ordenado. Percorrer o vetor ordenado contando, sem repetição, os 
números pares e os números ímpares e mostrar a soma total desses valores. Criar um vetor chamado vPares 
e um vetor chamado vImpares e copiar, sem repetição, os elementos pares e ímpares para os respectivos 
vetores. Mostrar os dois vetores. Criar uma matriz chamada mPares e uma matriz chamada mImpares, sendo 
que mPares deverá conter na primeira coluna todos os elementos pares do vetor e na segunda coluna a 
quantidade de ocorrências de cada elemento par no vetor e na matriz mImpares fazer o mesmo com os 
elementos ímpares. Mostrar as duas matrizes.*/
#include<stdio.h>
void ordenarVetor (int tam, int vet[]);
void mostrarVetor (int tam, int vet[]);
int ocorrencia (int tam, int vet[], int elemento);

int main (void)
{
	char ch;
	
	do
	{
		char string[100];
		int vetor[100],tam, i, cont;
		
		printf ("Insira uma string: ");
		setbuf (stdin, NULL);
		gets(string);
		
		//cria vet da string ascii
		while (string[i]!='\0')
		{
			vetor[i]=(int)string[i];
			i++;
		}
		tam=i;
		
		printf ("\n===VETOR===\n");
		mostrarVetor(tam, vetor);
		ordenarVetor(tam, vetor);
		
		printf("\n===VETOR ORDENADO===\n");
		mostrarVetor(tam, vetor);
		
		int I, P, k, j;
		
		P=0;
		I=0;
		for (i=0; i<tam; i++)//contar pares e impares sem repetição
	    {
			if (i==0||vetor[i]!=vetor[i-1])
			{
				if (vetor[i]%2==0)
				{
					P++;
				}
				if (vetor[i]%2==1)
				{
					I++;
				}
			}
        }
		printf("\nNumero de pares (sem repeticao): %d\n", P );
		printf("Numero de impares (sem repeticao): %d\n", I );
		
		int vetPares[P], vetImpar[I];
		
		k=0;
		j=0;
		
		for (i=0; i<tam; i++)//cria os vetores de pares e impares sem repetição
	    {
			if (i==0||vetor[i]!=vetor[i-1])
			{
				if (vetor[i]%2==0)
				{
					vetPares[k]=vetor[i];
					k++;
				}
				if (vetor[i]%2!=0)
				{
					vetImpar[j]=vetor[i];
					j++;
				}
			}
	 	    
        }
		printf ("\n===VETOR PAR===\n");
		mostrarVetor(P, vetPares);
		
		printf ("\n===VETOR IMPAR===\n");
		mostrarVetor(I, vetImpar);
		
		int matrizPar[P][2], matrizImpar[I][2], l;
		
		printf ("\n===MATRIZ DE IMPARES===\n");
		printf("Impares\t\tOcorrencias\n");
		
	     l=0;
	    for(l=0; l<I; l++)
	    {
	    	matrizImpar[l][0]=vetImpar[l];
	    	matrizImpar[l][1]=ocorrencia(tam, vetor, vetImpar[l]);
	    	
	    	printf("%d\t\t %d\n", matrizImpar[l][0], matrizImpar[l][1] );
	    	
		}
		printf ("\n===MATRIZ DE PARES===\n");
		printf("Pares\t\tOcorrencias\n");
	     
	    for(l=0; l<P; l++)
	    {
	    	matrizPar[l][0]=vetPares[l];
	    	matrizPar[l][1]=ocorrencia(tam, vetor, vetPares[l]);
	    	
	    	printf("%d\t\t %d\n", matrizPar[l][0], matrizPar[l][1] );
		}
		
		
		printf ("\nDeseja repetir o programa? ");
		setbuf(stdin, NULL);
		scanf("%c", & ch);
		 
	}while (ch=='S'||ch=='s');
	return 0;
}
void mostrarVetor (int tam, int vet[])
{
	int i;
	
	for (i=0; i<tam; i++)
	{
		printf ("%d\t", vet[i]);
	}
}
void ordenarVetor (int tam, int vet[])
{
	int i, aux, j;
	
	for (j=tam-1; j>0; j--)
	{
		for(i=0; i<j; i++)
		{
			if (vet[i]>vet[i+1])
			{
				aux=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=aux;
			}
		}
	}
}
int ocorrencia (int tam, int vet[], int elemento)
{
	int i, cont=0;
	
	for (i=0; i<tam; i++)
	{
		if(vet[i]==elemento)
		{
			cont++;
		}
	}
	return (cont);
}
   
