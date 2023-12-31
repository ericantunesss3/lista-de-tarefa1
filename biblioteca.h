//
// Created by unifjtakeda on 15/09/2023.
//biblioteca.h final

#ifndef UNTITLED3_BIBLIOTECA_H
#define UNTITLED3_BIBLIOTECA_H

typedef struct  { // struct que mostra onde vai ser salvo cada tipo de conteudo
    char descricao[300];
    char categoria[100];
    int prioridade;
    char status[15];
}Tarefa;

typedef struct{ // struct que armazenará cada tarefa
    Tarefa tarefas[100];
    int qtd;
}ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int DeletarTarefa(ListaDeTarefas *lt);
int ListarTarefa(ListaDeTarefas lt);
int EditarTarefas(ListaDeTarefas *lt);
void FiltrarPrioridade(ListaDeTarefas lt, int prioridadeDesejada);
void Filtrarstatus(ListaDeTarefas lt, char *statusDesejada);
int FiltrarPrioridadeCategoria(ListaDeTarefas lt);


void printMenu();
int salvarLista(ListaDeTarefas *lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);

#endif //UNTITLED3_BIBLIOTECA_H