#include "notas.h"

typedef struct{
    char nome_aluno[TAMNOMES];
    char senha_aluno[TAMPASSWORD];
    int idade_aluno;
    CNotas pNotas;
}CAluno;

void set_nome_aluno(CAluno* pAluno, char* nome);
char* get_nome_aluno(CAluno* pAluno);

void set_senha_aluno(CAluno* pAluno, char* senha);
char* get_senha_aluno(CAluno* pAluno);

void set_idade_aluno(CAluno* pAluno, int idade);
int get_idade_aluno(CAluno* pAluno);

void set_nota_calculo(CAluno* pAluno, int nota);
void set_nota_fisica(CAluno* pAluno, int nota);
void set_nota_estatistica(CAluno* pAluno, int nota);