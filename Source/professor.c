#include "../Headers/professor.h"

void set_nome_professor(CProfessor* pProfessor, char* nome){
    strcpy(pProfessor->nome_professor, nome);
}
char* get_nome_professor(CProfessor* pProfessor){
    return pProfessor->nome_professor;
}

void set_senha_professor(CProfessor* pProfessor, char* senha){
    strcpy(pProfessor->senha_professor, senha);
}
char* get_senha_professor(CProfessor* pProfessor){
    return pProfessor->senha_professor;
}

int verifica_professor(CProfessor* pProfessor, char* nome_professor, char* senha_professor){
    if(strcmp(pProfessor->nome_professor, nome_professor) == 0){
        if(strcmp(pProfessor->senha_professor, senha_professor) == 0){
            return 0;
        }
    }
    return 1;
}