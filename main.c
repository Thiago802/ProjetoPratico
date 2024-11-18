#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Hora{
    int hora;
    int minuto;
};

struct Voo{
    int cod_voo;
    struct Data DataVoo;
    struct Hora HoraVoo;
    char origem[100];
};

struct Passageiro{
    int cod;
    char nome[100];
    char endereco[100];
    char tel[10];
    int fidelidade;
    int PontoFid;
};//pegar informaçoes do passageiro

void PreencheVoo(struct Voo voo){

    printf("cod voo: ");
    scanf("%i",&voo.cod_voo);
    fflush(stdin);
    printf("data dd/mm/aaaa: ");
    scanf("%d/%d/%d",&voo.DataVoo.dia,&voo.DataVoo.mes,&voo.DataVoo.ano);
    fflush(stdin);
    printf("Hora hh:mm : ");
    scanf("%d:%d",&voo.HoraVoo.hora,&voo.HoraVoo.minuto);
    fflush(stdin);



    printf("cod: %i",voo.cod_voo);
    printf("\nData: %d/%d/%d ",voo.DataVoo.dia,voo.DataVoo.mes,voo.DataVoo.ano);
    printf("\nHora: %d:%d",voo.HoraVoo.hora,voo.HoraVoo.minuto);
}


int main()
{
    struct Voo voo;
    struct Passageiro passageiro ;

    PreencheVoo(voo);

    /*
    printf("cod:\n");
    scanf("%i",&passageiro.cod);
    fflush(stdin);

    printf("nome:\n");
    //gets(passageiro.nome);
    scanf(" %[^\n]" , &passageiro.nome);
    fflush(stdin);

    printf("endereco:\n");
    //gets(passageiro.endereco)
    scanf(" %[^\n]" , &passageiro.endereco);
    fflush(stdin);

    printf("tel:\n");
    //gets(passageiro.tel);
    scanf(" %[^\n]" , &passageiro.tel);
    fflush(stdin);

    printf("fidelidade:\n");
    scanf("%i",&passageiro.fidelidade);
    fflush(stdin);

    printf("\nNome: %s",passageiro.nome);
    printf("\nCod: %i",passageiro.cod);
    */
}
