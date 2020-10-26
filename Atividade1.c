#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro {
    char marca[10];
    char modelo[10];
    int ano_fabricacao;
    char placa[7];
    int valor;

};

int contador = 0, contador_1 = 0 ;
struct carro arr_carro[11];


void organiza_db_por_ano(struct carro *arr_carro);




void main() {
    int escolha, carro_id = 0;
     //vale ressaltar que os carros vão de 0 a 9, deixei um vetor em branco devido as trocas necessárias para organização da DB
    while (escolha != 5) {
        printf("Digite 0 para acrescentar um novo carro ao banco de dados.\n");
        printf("Digite 1 para listar todos os carros.\n");
        printf("Digite 2 para listar os carros por ano de fabricacao.\n");
        printf("Digite 3 para listar os carros por modelo. \n");
        printf("Digite 5 para sair.\n");
        scanf("%d", &escolha);
        printf("escolha = %d \n", escolha);



        if (escolha == 0) { //Cadastro.
            printf("Digite o ano de fabricacao. \n");
            scanf("%d", &arr_carro[carro_id].ano_fabricacao);
            printf("Digite a marca do carro. \n");
            scanf("%s", &arr_carro[carro_id].marca);
            printf("Digite o modelo do carro. \n");
            scanf("%s", &arr_carro[carro_id].modelo);
            printf("Digite agora a placa do carro, sem hifen.");
            scanf("%s", &arr_carro[carro_id].placa);
            printf("Digite agora o valor do carro.");
            scanf("%d", &arr_carro[carro_id].valor);
            carro_id++;
            organiza_db_por_ano(arr_carro); //essa função está definida no final do programa, ela quem organiza os carros por ano.
        } //Fim Impressão


        if (escolha == 1) { //Impressão.
            int contador_1 = 0;
                for (contador_1 = 0; contador_1 < 10; contador_1++) {
                    if (arr_carro[contador_1].ano_fabricacao != 0){
                        //imprimir(arr_carro[contador_1]);
                        {
                            printf("\n Ano de fabricacao: %d", arr_carro[contador_1].ano_fabricacao);
                            printf("\n Marca: %s", arr_carro[contador_1].marca);
                            printf("\n Modelo: %s", arr_carro[contador_1].modelo);
                            printf("\n Placa: %s", arr_carro[contador_1].placa);
                            printf("\n Valor: R$ %d", arr_carro[contador_1].valor);
                            printf("\n ===================================== \n");
                        }
                    }
                }
        } //Fim Impressão.

          if (escolha == 2) { //Impressão por ano.
            int contador_1 = 0;
            int ano_escolhido = 0;
            printf("Digite um ano para a pesquisa... \n");
            scanf("%d", &ano_escolhido);
            printf("\n");
                for (contador_1 = 0; contador_1 < 10; contador_1++) { //for para checar todos os carros por ano.
                    if (arr_carro[contador_1].ano_fabricacao == ano_escolhido){ //condicional...
                        printf("\n Ano de fabricacao: %d", arr_carro[contador_1].ano_fabricacao);
                        printf("\n Marca: %s", arr_carro[contador_1].marca);
                        printf("\n Modelo: %s", arr_carro[contador_1].modelo);
                        printf("\n Placa: %s", arr_carro[contador_1].placa);
                        printf("\n Valor: R$ %d", arr_carro[contador_1].valor);
                        printf("\n ===================================== \n");
                        }
                }
        } //Fim Impressão por ano.


            if (escolha == 3) { //Impressão por modelo.
            int contador_1 = 0;
            char modelo_escolhido[10];
            printf("Digite um modelo para a pesquisa... \n");
            scanf("%s", &modelo_escolhido);
            printf("\n");
                for (contador_1 = 0; contador_1 < 10; contador_1++) { //for para checar todos os carros...
                    if ( !strcmp(arr_carro[contador_1].modelo,modelo_escolhido) )//condicional...
                        {
                        printf("\n Ano de fabricacao: %d", arr_carro[contador_1].ano_fabricacao);
                        printf("\n Marca: %s", arr_carro[contador_1].marca);
                        printf("\n Modelo: %s", arr_carro[contador_1].modelo);
                        printf("\n Placa: %s", arr_carro[contador_1].placa);
                        printf("\n Valor: R$ %d", arr_carro[contador_1].valor);
                        printf("\n ===================================== \n");
                        }
                }
        } //Fim Impressão por modelo.





        } //Fim do while de loop.

return 0;
}

// void imprimir(struct carro arr_carro)


 void organiza_db_por_ano(struct carro *arr_carro) {
    contador = 0;
    printf("\n carro0 = %d, carro1 = %d",arr_carro[contador].ano_fabricacao, arr_carro[contador +1].ano_fabricacao );
    for (contador = 0; contador < 11; contador++) {
        if (arr_carro[contador].ano_fabricacao > arr_carro[contador +1].ano_fabricacao){

            arr_carro[10].ano_fabricacao = arr_carro[contador].ano_fabricacao;
            arr_carro[10].valor = arr_carro[contador].valor;
            strcpy( arr_carro[10].marca, arr_carro[contador].marca);
            strcpy( arr_carro[10].modelo, arr_carro[contador].modelo);
            strcpy( arr_carro[10].placa, arr_carro[contador].placa);

            arr_carro[contador].ano_fabricacao = arr_carro[contador+1].ano_fabricacao;
            arr_carro[contador].valor = arr_carro[contador+1].valor;
            strcpy( arr_carro[contador].marca, arr_carro[contador+1].marca);
            strcpy( arr_carro[contador].modelo, arr_carro[contador+1].modelo);
            strcpy( arr_carro[contador].placa, arr_carro[contador+1].placa);

            arr_carro[contador+1].ano_fabricacao = arr_carro[10].ano_fabricacao;
            arr_carro[contador+1].valor = arr_carro[10].valor;
            strcpy( arr_carro[contador+1].marca, arr_carro[10].marca);
            strcpy( arr_carro[contador+1].modelo, arr_carro[10].modelo);
            strcpy( arr_carro[contador+1].placa, arr_carro[10].placa);
        }
    }
    contador = 0;
}

