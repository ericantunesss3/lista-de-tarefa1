#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

//Eric Antunes"
// Segunda parte do projeto da lista de tarefas
// main final do codigo

int main() {


    ListaDeTarefas lt; //criamos a lista de tarefas lt que servirá para
    int cod;
    char arquivo[] = "salvo.txt";
    int prioridadeDesejada;
    char statusDesejada[20];


    cod = carregarLista(&lt, arquivo);// carrega o arquivo ao abrir o codigo
    if(cod == 1){
        lt.qtd = 0;
    }

    int opcao;
    do{ //Lista com as interações que o usuario pode fazer com o programa
        printMenu();
        printf(">>> ");
        scanf("%d", &opcao);

        if(opcao == 1){
            criarTarefa(&lt);
        }
        else if(opcao == 2){
            DeletarTarefa(&lt);
        }
        else if(opcao == 3){
            ListarTarefa(lt);
        }
        else if(opcao == 4){
            EditarTarefas(&lt);
        }
        else if(opcao == 5){
            printf("Digite a prioridade que deseja filtrar (0 a 10): ");
            scanf("%d", &prioridadeDesejada);
            FiltrarPrioridade(lt, prioridadeDesejada);
        } 
        else if (opcao == 6){
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Digite o status desejado (em andamento, finalizada, nao iniciado\n-> ");
            fgets(statusDesejada,20,stdin);
            statusDesejada[strcspn(statusDesejada,"\n")] = '\0';
            Filtrarstatus(lt, statusDesejada);
        }
        else if (opcao == 7){
            FiltrarPrioridadeCategoria(lt);
        }

    }while(opcao != 8); // permite que o usuário saia do programa

    //Logica que salva todas as funções feitas dentro do arquivo
    cod = salvarLista(&lt, "salvo.txt");
    if(cod != 0){
        printf("Erro ao salvar as tarefas");
    }
    return 0;
}