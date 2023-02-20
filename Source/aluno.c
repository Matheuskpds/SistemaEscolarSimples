#include "../Headers/aluno.h"

void set_nome_aluno(CAluno* pAluno, char* nome){
    strcpy(pAluno->nome_aluno, nome);
}
char* get_nome_aluno(CAluno* pAluno){
    return pAluno->nome_aluno;
}

void set_senha_aluno(CAluno* pAluno, char* senha){
    strcpy(pAluno->senha_aluno, senha);
}
char* get_senha_aluno(CAluno* pAluno){
    return pAluno->senha_aluno;
}

void set_idade_aluno(CAluno* pAluno, int idade){
    pAluno->idade_aluno = idade;
}
int get_idade_aluno(CAluno* pAluno){
    return pAluno->idade_aluno;
}


void set_nota_calculo(CAluno* pAluno, int nota){
    pAluno->pNotas.calculo = nota;
}
void set_nota_fisica(CAluno* pAluno, int nota){
    pAluno->pNotas.fisica = nota;
}
void set_nota_estatistica(CAluno* pAluno, int nota){
    pAluno->pNotas.estatistica = nota;
}