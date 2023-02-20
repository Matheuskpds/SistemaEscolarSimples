#include "aluno.h"

typedef int apontador;

typedef struct CLista{
    CAluno lista[MAXALUNOS];
    apontador pPrimeiro, pUltimo;
}CLista;

//Função para criar a lista de alunos:
void FL_Vazia(CLista* pLista);

//Função que verifica se a lista está cheia:
int Verifica_Lista(CLista* pLista);

//Função para adicionar um aluno na lista (máximo de 30 alunos):
void Adicionar_Aluno_Lista(CLista* pLista, CAluno pAluno);

//Função para verificar se existe um aluno com o nome e senha digitados pelo usuário:
int Verifica_Aluno(CLista* pLista, char* nome_aluno, char* senha_aluno);

//Função para encontrar a posição de um aluno no vetor:
int Posicao_Aluno(CLista* pLista, char* nome_aluno, char* senha_aluno);
int Posicao_Aluno_Professor(CLista* pLista, char* nome_aluno);


//Mostra na tela todos os elementos da lista:
void Imprime_Lista(CLista PLista);