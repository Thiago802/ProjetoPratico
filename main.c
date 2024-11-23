#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <locale.h>

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

void PreencheTripulacao(struct Tripulacao tripulacao){
    printf("cod tripulante: ");
    scanf("%i", tripulacao.cod_tripulante);
    fflush(stdin);

    printf("Nome: ");
    scanf(" %[^\n]", tripulacao.nomeTripulante);
    fflush(stdin);

    printf("Telefone: ");
    scanf(" %[^\n]", tripulacao.TelTripulante);
    fflush(stdin);

    printf("Cargo(piloto/copiloto/comissario): ");
    scanf(" %[^\n]", tripulacao.cargo);
    fflush(stdin);
}

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


    printf("codigo de voo: %i", voo.cod_voo);
    printf("\nData: %d/%d/%d ", voo.DataVoo.dia,voo.DataVoo.mes,voo.DataVoo.ano);
    printf("\nHora: %d:%d", voo.HoraVoo.hora,voo.HoraVoo.minuto);
    printf("\nOrigem do voo: %s", voo.origem);
    printf("\nDestino do voo: %s", voo.destino);
    printf("\nCodigo do avião: %i",voo.cod_aviao);
    printf("\nCodigo do piloto: %i", voo.cod_piloto);
    printf("\nCodigo do copiloto: %i", voo.cod_copiloto);
    printf("\nCodigo do/a comissario/a de bordo: %i", voo.cod_comissaria);
    printf("STATUS SELECIONADO: %s", voo.status);
    printf("Tarifa: R$%i", voo.tarifa);

}

void PreenchePassageiro(struct Passageiro passageiro){

    printf("\ncod passageiro: ");
    scanf("%i",&passageiro.cod);
    fflush(stdin);

    printf("Nome do passageiro: ");
    scanf(" %[^\n]", &passageiro.nome);
    fflush(stdin);

    printf("Endereço: ");
    scanf(" %[^\n]", &passageiro.endereco);
    fflush(stdin);

    printf("Telefone: ");
    scanf(" %[^\n]", &passageiro.tel);
    fflush(stdin);

    printf("Faz parte do  programa de fidelidade?\nDigite '0' para NÃO e '1' para SIM: ");
    scanf("%i", &passageiro.fidelidade);
    fflush(stdin);

    printf("\ncódigo pessoa: %i", passageiro.cod);
    printf("\nNome: %s", passageiro.nome);
    printf("\nEndereço: %s", passageiro.endereco);
    printf("\nTelefone: %s",passageiro.tel);
    //printf("Pontos acumulados: %i", passageiro.PontoFid);

}

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


int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    struct Tripulacao tripulacao;
    struct Voo voo;
    struct Passageiro passageiro ;
    struct Assento assento;
    struct Reserva reserva;

    //PreencheVoo(voo);
    //PreenchePassageiro(passageiro);
    PreencheTripulacao(tripulacao);

}
