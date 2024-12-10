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
#define MAX_ASSENTO 20
//contador universal
int contP=0,contT=0,contVoo=0, contAss=0;

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
//CRUD TRIPULAÇÃO

//CREAT
void PreencheTripulacao(struct Tripulacao tripulantes[MAX_TRIPULANTE]){
    printf("cod tripulante: ");
    scanf("%i", &tripulantes[contT].cod_tripulante);
    fflush(stdin);

    printf("Nome: ");
    scanf(" %[^\n]", &tripulantes[contT].nomeTripulante);
    fflush(stdin);

    printf("Telefone: ");
    scanf(" %[^\n]", &tripulantes[contT].TelTripulante);
    fflush(stdin);

    printf("Cargo(piloto/copiloto/comissario): ");
    scanf(" %[^\n]", &tripulantes[contT].cargo);
    fflush(stdin);

    contT++;
}
//READ
void ImprimeTripulacao(struct Tripulacao tripulantes[MAX_TRIPULANTE]){
        if(contT==0){
        printf("Nao ha voo");
        return;
    }

    for(int i=0;i<contT;i++){
        printf("\nCódigo de tripulante: %i\n",tripulantes[i].cod_tripulante);
        printf("Nome do tripulante: %s\n",tripulantes[i].nomeTripulante);
        printf("Telefone do tripulante: %s\n",tripulantes[i].TelTripulante);
        printf("Cargo: %s\n", tripulantes[i].cargo);
    }
}

//UPDATE
void UpdateTripulacao(struct Tripulacao tripulantes[MAX_TRIPULANTE]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite o codigo do voo: ");
    scanf("%i",&cod);

    for(int i=0;i<contT;i++){
        if(tripulantes[i].cod_tripulante==cod){
            verifica=true;
            val_i=i;
            i=contT;
        }
    }

    if(verifica == true){
        printf("Nome: ");
        scanf(" %[^\n]", &tripulantes[contT].nomeTripulante);
        fflush(stdin);

        printf("Telefone: ");
        scanf(" %[^\n]", &tripulantes[contT].TelTripulante);
        fflush(stdin);

        printf("Cargo(piloto/copiloto/comissario): ");
        scanf(" %[^\n]", &tripulantes[contT].cargo);
        fflush(stdin);
    }
}

//DELETE
void DeleteTripulacao(struct Tripulacao tripulantes[MAX_TRIPULANTE]){
        int cod, val_i;
    bool verifica=false;
    printf("Digite codigo de tripulante que sera deletado: ");
    scanf("%i", &cod);

    for(int i=0;i<contT;i++){
        if(tripulantes[i].cod_tripulante==cod){
            verifica=true;
            val_i=i;
        }
    }
    if(verifica==true){

        for(int i=val_i-1;i<MAX_TRIPULANTE-1;i++){
            tripulantes[i] = tripulantes[i++];
        }
        contT-1;
    }
}
//FIM CRUD TRIPULAÇÃO

//CRUD VOO

//CREAT
void PreencheVoo(struct Voo voo[MAX_VOO]){
    if(contVoo < MAX_VOO){
        printf("cod voo: ");
        scanf("%i",&voo[contVoo].cod_voo);
        fflush(stdin);

        printf("data dd/mm/aaaa: ");
        scanf("%d/%d/%d",&voo[contVoo].DataVoo.dia,&voo[contVoo].DataVoo.mes,&voo[contVoo].DataVoo.ano);
        fflush(stdin);

        printf("Hora hh:mm : ");
        scanf("%d:%d",&voo[contVoo].HoraVoo.hora,&voo[contVoo].HoraVoo.minuto);
        fflush(stdin);

        printf("Origem do voo: ");
        scanf(" %[^\n]", &voo[contVoo].origem);
        fflush(stdin);

        printf("Destino do voo: ");
        scanf(" %[^\n]", &voo[contVoo].destino);
        fflush(stdin);

        printf("Codigo do avião: ");
        scanf("%i", voo[contVoo].cod_aviao);
        fflush(stdin);

        printf("Codigo do piloto: ");
        scanf("%i", voo[contVoo].cod_piloto);
        fflush(stdin);

        printf("Codigo do copiloto: ");
        scanf("%i", voo[contVoo].cod_copiloto);
        fflush(stdin);

        printf("Codigo do/a comissario/a de bordo: ");
        scanf("%i", voo[contVoo].cod_comissaria);
        fflush(stdin);

        printf("STATUS(ativo/inativo): ");
        scanf(" %[^\n]", voo[contVoo].status);
        fflush(stdin);

        printf("Tarifa: ");
        scanf("%.2f", voo[contVoo].tarifa);
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
        printf("\nCódigo do avião: %i",voo[i].cod_aviao);
        printf("\nCódigo do piloto: %i", voo[i].cod_piloto);
        printf("\nCódigo do copiloto: %i", voo[i].cod_copiloto);
        printf("\nCódigo do/a comissario/a de bordo: %i", voo[i].cod_comissaria);
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

        printf("data dd/mm/aaaa: ");
        scanf("%d/%d/%d",&voo[contVoo].DataVoo.dia,&voo[contVoo].DataVoo.mes,&voo[contVoo].DataVoo.ano);
        fflush(stdin);

        printf("Hora hh:mm : ");
        scanf("%d:%d",&voo[contVoo].HoraVoo.hora,&voo[contVoo].HoraVoo.minuto);
        fflush(stdin);

        printf("Origem do voo: ");
        scanf(" %[^\n]", &voo[contVoo].origem);
        fflush(stdin);

        printf("Destino do voo: ");
        scanf(" %[^\n]", &voo[contVoo].destino);
        fflush(stdin);

        printf("Codigo do avião: ");
        scanf("%i", voo[contVoo].cod_aviao);
        fflush(stdin);

        printf("Codigo do piloto: ");
        scanf("%i", voo[contVoo].cod_piloto);
        fflush(stdin);

        printf("Codigo do copiloto: ");
        scanf("%i", voo[contVoo].cod_copiloto);
        fflush(stdin);

        printf("Codigo do/a comissario/a de bordo: ");
        scanf("%i", voo[contVoo].cod_comissaria);
        fflush(stdin);

        printf("STATUS(ativo/inativo): ");
        scanf(" %[^\n]", voo[contVoo].status);
        fflush(stdin);

        printf("Tarifa: ");
        scanf("%.2f", voo[contVoo].tarifa);
        fflush(stdin);



    }

}

//DELETE
void DeleteVoo(struct Voo voo[MAX_VOO]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite codigo de VOO que sera deletado: ");
    scanf("%i", &cod);

    for(int i=0;i<contT;i++){
        if(voo[i].cod_voo==cod){
            verifica=true;
            val_i=i;
        }
    }
    if(verifica == true){
        for(int i=val_i-1;i<MAX_VOO-1;i++){
            voo[i] = voo[i++];
        }
        contVoo-1;

    }
}
//FIM CRUD VOO

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
        printf("já não ah assentos");

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

//INICIO CRUD ASSENTO

//CREAT
void PreencheAssento(struct Assento assento[MAX_ASSENTO]){
    printf("Numero do assento: ");
    scanf("%i", &assento[contAss].num_assento);
    fflush(stdin);

    printf("codigo do voo: ");
    scanf("%i", &assento[contAss].CodVoo.cod_voo);
    fflush(stdin);

    printf("Status da cadeira: ");
    scanf(" [^\n]", &assento[contAss].Status_assento);
    fflush(stdin);

    contAss++;
}

//READ
void ImprimeAssento(struct Assento assento[MAX_ASSENTO]){
    if(contAss=0){
        printf("Assento não cadastrado");
        return;
    }
    printf("código do voo: %i\n",assento[contAss].CodVoo.cod_voo);
    printf("Número do assento: %i\n",assento[contAss].num_assento);
    printf("STATUS: %s\n",assento[contAss].Status_assento);
}

//UPDATE
void UpdateAssento(struct Assento assento[MAX_ASSENTO]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite codigo de passageiro: ");
    scanf("%i", &cod);

    for(int i=0;i<contP;i++){
        if(assento[i].CodVoo.cod_voo==cod){
            verifica=true;
            val_i=i;
            i=contAss;
        }
    }
    if(verifica == true){
        printf("Status da cadeira: ");
        scanf(" [^\n]", &assento[contAss].Status_assento);
        fflush(stdin);

        printf("Numero do assento: ");
        scanf("%i", &assento[contAss].num_assento);
        fflush(stdin);
    }

}

//DELETE
void DeleteAssento(struct Assento assento[MAX_ASSENTO]){
    int cod, val_i;
    bool verifica=false;
    printf("Digite código de VOO que será deletado: ");
    scanf("%i", &cod);

    for(int i=0;i<contAss;i++){
        if(assento[i].CodVoo.cod_voo==cod){
            verifica=true;
            val_i=i;
        }
    }
    if(verifica==true){

        for(int i=val_i-1;i<MAX_ASSENTO-1;i++){
            assento[i] = assento[i++];
        }
        contAss-1;


    }
}
//FIM CRUD ASSENTO



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
    setlocale(LC_ALL, "Portuguese");

    FILE *backupPass;

    FILE *v;
    FILE *pass;
    FILE *assent;
    FILE *res;
    int caso,subcaso_passageiro,subcaso_tripulacao,subclasse_voo,subclasse_Assento;

    struct Tripulacao tripulantes[MAX_TRIPULANTE];
    struct Passageiro passageiros[MAX_PASSAGEIROS];
    struct Voo voo[MAX_VOO];
    struct Assento assento[MAX_ASSENTO];
    struct Reserva reserva;
    printf("----MENU----\n");
    printf("1-Passageiro\n2-Tripulação\n3-Voo\n4-Assento\n5-Reserva\n");
    printf("---- ---- ----");
    scanf("%i",&caso);
    switch (caso){
    case 1:
        printf("\n---- PASSAGEIRO ----\n");
        printf("1-Preencher\n2-Atualizar\n3-Deletar passageiro\n4-Imprimir informações");
        printf("\n---- ---- ----\n");
        scanf("%i",&subcaso_passageiro);
        switch(subcaso_passageiro){
        case 1:
            PreenchePassageiro(passageiros);
            break;

        case 2:
            UpdatePassageiro(passageiros);
            break;

        case 3:
            DeletePassageiro(passageiros);
            break;

        case 4:
            ImprimePassageiro(passageiros);
            break;
        }
    case 2:
        printf("\n---- TRIPULAÇÃO ----\n");
        printf("1-Preencher\n2-Atualizar\n3-Deletar passageiro\n4-Imprimir informações");
        printf("\n---- ---- ----\n");
        scanf("%i",&subcaso_tripulacao);
        switch(subcaso_tripulacao){
        case 1:
            PreencheTripulacao(tripulantes);
            break;
        case 2:
            UpdateTripulacao(tripulantes);
            break;
        case 3:
            DeleteTripulacao(tripulantes);
            break;
        case 4:
            ImprimeTripulacao(tripulantes);
            break;
        }
    case 3:
        printf("\n---- VOO ----\n");
        printf("1-Preencher\n2-Atualizar\n3-Deletar passageiro\n4-Imprimir informações");
        printf("\n---- ---- ----\n");
        scanf("%i",subclasse_voo);
        switch (subclasse_voo){
        case 1:
            PreencheVoo(voo);
            break;
        case 2:
            UpdateVoo(voo);
            break;
        case 3:
            DeleteVoo(voo);
            break;
        case 4:
            ImprimeVoo(voo);
        }
    case 4:
        printf("\n---- ASSENTO ----\n");
        printf("1-Preencher\n2-Atualizar\n3-Deletar passageiro\n4-Imprimir informações");
        printf("\n---- ---- ----\n");
        scanf("%i",&subclasse_Assento);
        switch(subclasse_Assento){
        case 1:
            PreencheAssento(assento);
            break;
        case 2:
            UpdateAssento(assento);
            break;
        case 3:
            DeleteAssento(assento);
            break;
        case 4:
            ImprimeAssento(assento);

        }

    }
    //PreencheVoo(voo);
    //PreenchePassageiro(passageiros);
    //ImprimePassageiro(passageiros);
    //UpdatePassageiro(passageiros);
    //DeletePassageiro(passageiros);
    //ImprimePassageiro(passageiros);

    //PreencheTripulacao(tripulantes);
    //ImprimeTripulacao(tripulantes);
    //UpdateTripulacao(tripulantes);
    //DeleteVoo(voo);

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
