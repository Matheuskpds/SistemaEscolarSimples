#include "lista_alunos.h"

typedef struct{
    char nome_professor[TAMNOMES];
    char senha_professor[TAMPASSWORD];
}CProfessor;

void set_nome_professor(CProfessor* pProfessor, char* nome);
char* get_nome_professor(CProfessor* pProfessor);

void set_senha_professor(CProfessor* pProfessor, char* senha);
char* get_senha_professor(CProfessor* pProfessor);

//Função para verificar o nome de usuario e senha digitados pelo usuario:
int verifica_professor(CProfessor* pProfessor, char* nome_professor, char* senha_professor);