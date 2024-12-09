#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <locale.h>


#define MAX_PASSAGEIROS 20
#define MAX_TRIPULANTE 20
#define MAX_VOO 20
//contador universal
int contP=0,contT=0,contVoo=0;

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Hora{
    int hora;
    int minuto;
};

struct Tripulacao{
    int cod_tripulante;
    char nomeTripulante[100];
    char TelTripulante[100];
    char cargo[100];
};//informacoes da tripulacao

struct Voo{
    int cod_voo;
    struct Data DataVoo;
    struct Hora HoraVoo;
    char origem[100];
    char destino[100];
    int cod_aviao;
    int cod_piloto;
    int cod_copiloto;
    int cod_comissaria;
    char status[15];
    float tarifa;

};//pegar informações do VOO

struct Passageiro{
    int cod;
    char nome[100];
    char endereco[100];
    char tel[10];
    int fidelidade;
    int PontoFid;
};//pegar informaçoes do passageiro

struct Assento{
    int num_assento;
    struct Voo CodVoo;
    char Status_assento[100];
};

struct Reserva{
    struct Voo CodVoo;
    struct Assento AssentoReservado;
    struct Passageiro CodPassageiro;
};

void PreencheTripulacao(struct Tripulacao tripulantes[MAX_TRIPULANTE]){
    printf("cod tripulante: ");
    scanf("%i", tripulantes[contT].cod_tripulante);
    fflush(stdin);

    printf("Nome: ");
    scanf(" %[^\n]", tripulantes[contT].nomeTripulante);
    fflush(stdin);

    printf("Telefone: ");
    scanf(" %[^\n]", tripulantes[contT].TelTripulante);
    fflush(stdin);

    printf("Cargo(piloto/copiloto/comissario): ");
    scanf(" %[^\n]", tripulantes[contT].cargo);
    fflush(stdin);

    contT++;
}
//CRUD VOO

//CREAT
void PreencheVoo(struct Voo voo){
    if(contVoo < MAX_VOO){
        printf("cod voo: ");
        scanf("%i",&voo.cod_voo);
        fflush(stdin);

        printf("data dd/mm/aaaa: ");
        scanf("%d/%d/%d",&voo.DataVoo.dia,&voo.DataVoo.mes,&voo.DataVoo.ano);
        fflush(stdin);

        printf("Hora hh:mm : ");
        scanf("%d:%d",&voo.HoraVoo.hora,&voo.HoraVoo.minuto);
        fflush(stdin);

        printf("Origem do voo: ");
        scanf(" %[^\n]", &voo.origem);
        fflush(stdin);

        printf("Destino do voo: ");
        scanf(" %[^\n]", &voo.destino);
        fflush(stdin);

        printf("Codigo do avião: ");
        scanf("%i", voo.cod_aviao);
        fflush(stdin);

        printf("Codigo do piloto: ");
        scanf("%i", voo.cod_piloto);
        fflush(stdin);

        printf("Codigo do copiloto: ");
        scanf("%i", voo.cod_copiloto);
        fflush(stdin);

        printf("Codigo do/a comissario/a de bordo: ");
        scanf("%i", voo.cod_comissaria);
        fflush(stdin);

        printf("STATUS(ativo/inativo): ");
        scanf(" %[^\n]", voo.status);
        fflush(stdin);

        printf("Tarifa: ");
        scanf("%.2f", voo.tarifa);
        fflush(stdin);



    }
    else
        printf("ja tem um voo cadastrado");

        contVoo++;
}
//READ
void ImprimeVoo(struct Voo voo[MAX_VOO]){
        if(contVoo==0){
        printf("Nao ha voo");
        return;
    }
     for(int i=0;i<contVoo;i++){
        printf("codigo de voo: %i", voo[i].cod_voo);
        printf("\nData: %d/%d/%d ", voo[i].DataVoo.dia,voo[i].DataVoo.mes,voo[i].DataVoo.ano);
        printf("\nHora: %d:%d", voo[i].HoraVoo.hora,voo[i].HoraVoo.minuto);
        printf("\nOrigem do voo: %s", voo[i].origem);
        printf("\nDestino do voo: %s", voo[i].destino);
        printf("\nCodigo do avião: %i",voo[i].cod_aviao);
        printf("\nCodigo do piloto: %i", voo[i].cod_piloto);
        printf("\nCodigo do copiloto: %i", voo[i].cod_copiloto);
        printf("\nCodigo do/a comissario/a de bordo: %i", voo[i].cod_comissaria);
        printf("STATUS SELECIONADO: %s", voo[i].status);
        printf("Tarifa: R$%i", voo[i].tarifa);
     }
}

//UPDATE
void UpdateVoo(struct Voo voo[MAX_VOO]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite o codigo do voo: ");
    scanf("%i",&cod);

    for(int i=0;i<contVoo;i++){
        if(voo[i].cod_voo==cod){
            verifica=true;
            val_i=i;
            i=contVoo;
        }
    }
    if(verifica==true){

    }

}



//CRUD PASSAGEIRO

//CRIACAO
void PreenchePassageiro(struct Passageiro passageiros[MAX_PASSAGEIROS]){



   if (contP < MAX_PASSAGEIROS){

        printf("\ncod passageiro: ");
        scanf("%i",&passageiros[contP].cod);
        fflush(stdin);

        printf("Nome do passageiro: ");
        scanf(" %[^\n]", &passageiros[contP].nome);
        fflush(stdin);

        printf("Endereço: ");
        scanf(" %[^\n]", &passageiros[contP].endereco);
        fflush(stdin);

        printf("Telefone: ");
        scanf(" %[^\n]", &passageiros[contP].tel);
        fflush(stdin);

        printf("Faz parte do  programa de fidelidade?\nDigite '0' para NAO e '1' para SIM: ");
        scanf("%i", &passageiros[contP].fidelidade);
        fflush(stdin);
        if (passageiros[contP].fidelidade==1){
            passageiros[contP].PontoFid+=10;
        }

    /*
        printf("\ncódigo pessoa: %i", passageiros[contP].cod);
        printf("\nNome: %s", passageiros[contP].nome);
        printf("\nEndereço: %s", passageiros[contP].endereco);
        printf("\nTelefone: %s",passageiros[contP].tel);
        printf("\nPontos acumulados: %i\n", passageiros[contP].PontoFid);
    */
        contP++;
    }
    else
        printf("ja nao ah assentos");

}

//READ
void ImprimePassageiro(struct Passageiro passageiros[MAX_PASSAGEIROS]){
    if(contP==0){
        printf("Nao ha passageiros");
        return;
    }
    for(int i=0;i<contP;i++){
        printf("\ncódigo pessoa: %i", passageiros[i].cod);
        printf("\nNome: %s", passageiros[i].nome);
        printf("\nEndereço: %s", passageiros[i].endereco);
        printf("\nTelefone: %s\n",passageiros[i].tel);
        printf("\nPontos acumulados: %i\n", passageiros[i].PontoFid);
    }
}
//UPDATE
void UpdatePassageiro(struct Passageiro passageiros[MAX_PASSAGEIROS]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite codigo de passageiro: ");
    scanf("%i", &cod);

    for(int i=0;i<contP;i++){
        if(passageiros[i].cod==cod){
            verifica=true;
            val_i=i;
            i=contP;
        }
    }
    if(verifica==true){
        printf("Nome do passageiro: ");
        scanf(" %[^\n]", &passageiros[val_i].nome);
        fflush(stdin);

        printf("Endereço: ");
        scanf(" %[^\n]", &passageiros[val_i].endereco);
        fflush(stdin);

        printf("Telefone: ");
        scanf(" %[^\n]", &passageiros[val_i].tel);
        fflush(stdin);
    }
}
//DELETE
void DeletePassageiro(struct Passageiro passageiros[MAX_PASSAGEIROS]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite codigo de passageiro que sera deletado: ");
    scanf("%i", &cod);

    for(int i=0;i<contP;i++){
        if(passageiros[i].cod==cod){
            verifica=true;
            val_i=i;
        }
    }
    if(verifica==true){

        for(int i=val_i-1;i<MAX_PASSAGEIROS-1;i++){
            passageiros[i] = passageiros[i++];
        }
        contP-1;

        /*
        passageiros[0]=passageiros[1];
        contP-1;
        */
    }
}
//FIM DE CRUD PASSAGEIRO

void PreencheAssento(struct Assento assento){
    printf("Numero do assento: ");
    scanf("%i", &assento.num_assento);
    fflush(stdin);

    printf("codigo do voo: ");
    scanf("%i", &assento.CodVoo.cod_voo);
    fflush(stdin);

    printf("Status da cadeira: ");
    scanf(" [^\n]", &assento.Status_assento);
    fflush(stdin);
}
//inicio backup
void pegaDados(const char nomearquivo,struct Passageiro passageiros,int total){
    FILE *arq;
    arq = fopen(nomearquivo,"wb");
    if(arq == (NULL))
    {
        printf("Erro ao abrir o arquivo %s", nomearquivo);
    }
    //salva total de elementos
    fwrite(&total,sizeof(int),1,arq);
    //salva dados
    //fwrite(passageiros,sizeof(Passageiro),total,arq);
    fclose(nomearquivo);
}

void bkup(struct Passageiro passageiros){

    pegaDados("passageiro.bin",passageiros,contP);
}
//fim backup


int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    FILE *backupPass;

    FILE *v;
    FILE *pass;
    FILE *assent;
    FILE *res;

    struct Tripulacao tripulantes[MAX_TRIPULANTE];
    struct Passageiro passageiros[MAX_PASSAGEIROS];
    struct Voo voo;
    struct Assento assento;
    struct Reserva reserva;


    //PreencheVoo(voo);
    //PreenchePassageiro(passageiros);
   // ImprimePassageiro(passageiros);
    //UpdatePassageiro(passageiros);
    //DeletePassageiro(passageiros);
    //ImprimePassageiro(passageiros);
    //PreencheTripulacao(tripulantes);


}


//arquivo passageiro
/*
pass = *fopen("passageiro.txt", "a");
if(!pass){
    printf("ERRO AO ABRIR ARQUIVO DESEJADO");
    exit(0);
}
    for(int i=0;i<contP;i++){
    fprintf(pass, %i %s %s %s %i,passageiros[i].cod,passageiros[i].nome,passageiros[i].endereco,passageiro[i].tel,passageiros[i].PontoFid);
    }
*/

