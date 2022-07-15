//Questao 1
#include<stdio.h>
int main (void)
{
    int limIn, limSup, i, ant=1, atu=1, prox, cont, contPar;
    char ch;

    do{

    do
    {
        printf ("Informe um valor meior que 0 para o limite inferior do intervalo: ");
        scanf ("%d", & limIn);
    }while (limIn<=0);

    do
    {
        printf ("Informe um valor meior que o limite inferior para o limite superior do intervalo: ");
        scanf ("%d", & limSup);
    }while (limSup<limIn);

    for (i=limIn; i<=limSup; i++)
    {
        ant=1;
        atu=1;
        contPar=0;
        cont=0;
        printf ("%d ==> %d  %d ", i, ant, atu);
        do
        {
            prox=ant+atu;
            printf (" %d ", prox);
            cont++;
            ant=atu;
            atu=prox;

            if (prox%2==0)
            {
                contPar++;
            }

        }while (cont<i-1);
        printf ("==> %d pares\n", contPar);

    }
        printf ("Deseja continuar o programa (S/s)?");
        setbuf (stdin,NULL);
        scanf ("%c", &ch);

    }while (ch == 'S' || ch =='s');
    return 0;
}
