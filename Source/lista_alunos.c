#include "../Headers/lista_alunos.h"

//Função para criar a lista de alunos:
void FL_Vazia(CLista* pLista){
    pLista->pPrimeiro = 1;
    pLista->pUltimo = pLista->pPrimeiro;
}

//Função que verifica se a lista está cheia:
int Verifica_Lista(CLista* pLista){
    if(pLista->pUltimo == MAXALUNOS){
        return 1;
    }
    return 0;
}

//Função para adicionar um aluno na lista (máximo de 30 alunos):
void Adicionar_Aluno_Lista(CLista* pLista, CAluno pAluno){
    pLista->lista[pLista->pUltimo-1] = pAluno;
    pLista->pUltimo++;
}

//Funções para verificar se existe um aluno ou professor com o nome e senha digitados pelo usuário:
int Verifica_Aluno(CLista* pLista, char* nome_aluno, char* senha_aluno){
    int aux;
    int cont=0;



    for(aux=pLista->pPrimeiro-1; aux<=pLista->pUltimo-2; aux++){
        if(strcmp(pLista->lista[aux].nome_aluno, nome_aluno) == 0){
            cont++;
            if(strcmp(pLista->lista[aux].senha_aluno, senha_aluno) == 0){
                cont++;
                break;
            }
        }
    }
    if(cont==0)
        return 1;
    else
        return 0;
}

int Posicao_Aluno(CLista* pLista, char* nome_aluno, char* senha_aluno){
    int aux;
    
    for(aux=pLista->pPrimeiro-1; aux<=pLista->pUltimo-2; aux++){
        if(strcmp(pLista->lista[aux].nome_aluno, nome_aluno) == 0){
            if(strcmp(pLista->lista[aux].senha_aluno, senha_aluno) == 0){
                return aux;
                break;
            }
        }
    }
}

int Posicao_Aluno_Professor(CLista* pLista, char* nome_aluno){
    int aux;
    
    for(aux=pLista->pPrimeiro-1; aux<=pLista->pUltimo-2; aux++){
        if(strcmp(pLista->lista[aux].nome_aluno, nome_aluno) == 0){
            return aux;
            break;
        }
    }
}

void Imprime_Lista(CLista pLista){
    int aux;
    printf("\n");
    for(aux=pLista.pPrimeiro-1; aux<=pLista.pUltimo-2; aux++){
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Nome: %s\n", pLista.lista[aux].nome_aluno);
        printf("Idade: %d\n", pLista.lista[aux].idade_aluno);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
    printf("\n");
}