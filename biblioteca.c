//biblioteca.c final do codigo
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void printMenu(){ // usada para printar o menu toda vez que acontece alguma ação no programa
    printf("\nGerenciador de Tarefas\n");
    printf("Escolha a funcao:\n 1 Adicionar nova tarefa\n 2 Deletar tarefa\n 3 Listar tarefas\n 4 Editar tarefa\n 5 filtrar tarefas por prioridade\n 7 filtrar tarefas por prioridade e categoria\n 8 sair\n");
}


int criarTarefa(ListaDeTarefas *lt) {

    if (lt->qtd < 100) { // se a lista tiver menos que 100 tarefas, é possivel configurar uma
        printf("Digite a descricao: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].descricao);

        printf("Digite a prioridade (0 a 10):");
        scanf(" %d", &lt->tarefas[lt->qtd].prioridade);

        printf("Digite a categoria:");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria);

        printf("Digite o status da tarefa: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].status);

        printf("Tarefa adicionada com sucesso!\n");
    }
    else{
        printf("Sua lista de tarefas esta cheia!");
    }
    lt->qtd++;// estrutura que pula pra proxima linha do arquivo para que o usuario nao salve as novas tarefas em cima das outras
    return 0;
}

int DeletarTarefa(ListaDeTarefas *lt){
    int tarefaEscolhida;
    printf("Qual tarefa voce deseja deletar? (0 a 99)"); // informa a tarefa a ser deletada
    scanf("%d", &tarefaEscolhida);

    for (int i = tarefaEscolhida; i < 100; i++){
        lt->tarefas[i] = lt->tarefas[i + 1];
    }

    lt->qtd--;// ao deletar uma tarefa, as posições das restante devem "descer" para uma posição abaixo da que estava
    return 0;
}


int ListarTarefa(ListaDeTarefas lt){
        for (int i = 0; i < lt.qtd; i++){ //apenas aparece as tarefas já estabelecidas
            printf("Tarefa %d\n", i);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("status: %s\n", lt.tarefas[i].status);
            printf("\n");
        }
    return 0;
}

int salvarLista(ListaDeTarefas *lt, char nome[]){ // "escreve" em uma arquivo a lista de tarefas em binário para salvá-la
    FILE *f = fopen(nome, "wb");
    if(f == NULL){
        return 1;
    }else {
        fwrite(lt, sizeof(ListaDeTarefas), 1, f);
        fclose(f);
    }
    return 0;
}
int carregarLista(ListaDeTarefas *lt, char nome[]){ // "lê" as informações em binário para que sejam usadas no programa toda vez que for iniciado
    FILE *f = fopen(nome, "rb");
    if (f == NULL){
        return 1;
    }
    else{
        fread(lt, sizeof(ListaDeTarefas),1, f);
        fclose(f);
    }
    return 0;
}

int  EditarTarefas(ListaDeTarefas *lt){
    int TarefaEscolida;
    printf("informe a tarefa que deseja editar (0 a 99):");
    scanf("%d", &TarefaEscolida);

    if(TarefaEscolida >= 0 && TarefaEscolida < lt->qtd) {
        // Dados que serão editados
        printf("editar a descrição (atual: %s): ",lt->tarefas[TarefaEscolida].descricao);
        scanf(" %[^\n]", lt->tarefas[TarefaEscolida].descricao);

        printf("Editar a prioridade (atual: %d): ", lt->tarefas[TarefaEscolida].prioridade);
        scanf(" %d", &lt->tarefas[TarefaEscolida].prioridade);

        printf("Editar a categoria (atual: %s): ", lt->tarefas[TarefaEscolida].categoria);
        scanf(" %[^\n]", lt->tarefas[TarefaEscolida].categoria);

        printf("Editar o status (atual: %s): ", lt->tarefas[TarefaEscolida].status);
        scanf(" %[^\n]", lt->tarefas[TarefaEscolida].status);

        printf("Tarefa editada com sucesso!\n");
    } else {
        printf("Tarefa com o índice %d não encontrada.\n", TarefaEscolida);
    }
    return 0;
}

void FiltrarPrioridade(ListaDeTarefas lt, int prioridadeDesejada) {
    int encontrouTarefa = 0; // Variável para rastrear se alguma tarefa com a prioridade desejada foi encontrada

    printf("Tarefas com prioridade %d:\n", prioridadeDesejada);

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridadeDesejada) {
            printf("Tarefa %d\n", i);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Status: %s\n", lt.tarefas[i].status);
            printf("\n");
            encontrouTarefa = 1; // Marca que pelo menos uma tarefa foi encontrada
        }
    }

    if (!encontrouTarefa) {
        printf("Nenhuma tarefa com prioridade %d encontrada.\n", prioridadeDesejada);
    }
}

void Filtrarstatus(ListaDeTarefas lt, char *statusDesejada) {
    int encontrouTarefa = 0; // Variável para rastrear se alguma tarefa com a prioridade desejada foi encontrada

    printf("Tarefas com status %s:\n", statusDesejada);
    

    for (int i = 0; i < lt.qtd; i++) {
        if  (strcmp(lt.tarefas[i].status, statusDesejada) == 0) {
            printf("Tarefa %d\n", i);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Status: %s\n", lt.tarefas[i].status);
            printf("\n");
            encontrouTarefa = 1; // Marca que pelo menos uma tarefa foi encontrada
        }
    }

    if (!encontrouTarefa) {
        printf("Nenhuma tarefa com status %s encontrada.\n", statusDesejada);
    }
}

int FiltrarPrioridadeCategoria(ListaDeTarefas lt){ 
     int prioridade;
     char categoria[50];
   

    printf("Categorias: ");

    char categorias_colocadas[100][50];
    int num_categorias_colocadas = 0;

    //função de printar as categorias existentes
    for (int i = 0; i < lt.qtd; i++) {
        int categoria_repetida = 0;
        for (int j = 0; j < num_categorias_colocadas; j++) {
            if (strcmp(lt.tarefas[i].categoria, categorias_colocadas[j]) == 0) {
                categoria_repetida = 1;
                break;
            }
        }

        if (!categoria_repetida) {
            printf("%s, ", lt.tarefas[i].categoria);
            strcpy(categorias_colocadas[num_categorias_colocadas], lt.tarefas[i].categoria);
            num_categorias_colocadas++;
        }
    }

    printf("\nEscolha a categoria: ");
    scanf(" %[^\n]", categoria);

    printf("Escolha a prioridade (0 a 10)");
    scanf("%d", &prioridade);

    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0){ // logica de comparação da prioridade e categoria
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %s\n", lt.tarefas[i].status);
            printf("\n");

            verificar = 1;
        }
    }
    if (!verificar){
        printf("Não existe essa tarefa\n");
    }
    return 0;
}