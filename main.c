#include "Headers/professor.h"

void menu_principal();
void aluno(CLista* pLista, int posicao_aluno);
void professor(CProfessor* pProfessor, CLista* pLista);


int main(){
    
    menu_principal();
    
    return 0;

}


void menu_principal(){
    int loop_principal = 1;
    int loop = 1;
    int who;

    int aux = 0; //variavel auxiliadora para verificar se ja houve um cadastro de professor. Se tiver, sera
    //pedido ao usuario (professor) para digitar o nome e senha para continuar e fazer um novo cadastro

    char nome_usuario[TAMNOMES];
    char senha_usuario[TAMPASSWORD];
    char verifica_senha[TAMPASSWORD];
    int idade_usuario;
    CAluno pAluno;
    CLista pLista;
    CProfessor pProfessor;
    int resp;


    while( loop_principal ){
        loop = 1;
        printf("\n");
        printf("-=-=-=-=-= SISTEMA ESCOLAR -=-=-=-=-=\n");
        printf("[1] Sign-In\n");
        printf("[2] Sign-Up (cadastro)\n");
        //printf("[3] Mostrar Lista de Alunos\n");
        printf("[3] Encerrar\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        scanf("%d", &resp);

        if(resp == 1){
            //loop = 1;
            while(loop){

                printf("\n");
                printf("-=-=-=-=-= SIGN_IN -=-=-=-=-=\n");
                printf("[1] Aluno\n");
                printf("[2] Professor\n");
                printf("[3] Sair\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                scanf("%d", &who);

                if(who == 1){

                    printf("Nome de Usuario: \n");
                    scanf("%s", nome_usuario);
                    printf("Senha: \n");
                    scanf("%s", senha_usuario);

                    if(Verifica_Aluno(&pLista, nome_usuario, senha_usuario) == 0){
                        //printf("ok!\n");
                        //printf("%d\n",Posicao_Aluno(&pLista, nome_usuario, senha_usuario));
                        aluno(&pLista, Posicao_Aluno(&pLista, nome_usuario, senha_usuario));
                    }else{
                        printf("Nao foi encontrado um aluno com o nome/senha digitados\n");
                    }

                }else if(who== 2){

                    printf("Nome de Usuario: \n");
                    scanf("%s", nome_usuario);
                    printf("Senha: \n");
                    scanf("%s", senha_usuario);

                    if(verifica_professor(&pProfessor, nome_usuario, senha_usuario)==0){
                        //printf("ok!\n");
                        professor(&pProfessor, &pLista);
                    }else{
                        printf("Nao existe um professor com nome/senha digitados!\n");
                    }

                }else if(who == 3){
                    loop = 0;
                    break;
                }

            }

        }else if(resp == 2){
            //loop = 1;
            while(loop){
                if(pLista.pPrimeiro != 1){
                    FL_Vazia(&pLista);
                    //printf("entrou\n");
                }
                printf("\n");
                printf("-=-=-=-=-= SIGN_UP -=-=-=-=-=\n");
                printf("[1] Aluno\n");
                printf("[2] Professor\n");
                printf("[3] Sair\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                scanf("%d", &who);

                if(who == 1){
                    printf("Nome de Usuario: \n");
                    scanf("%s", nome_usuario);
                    printf("Idade: \n");
                    scanf("%d", &idade_usuario);
                    printf("Senha: \n");
                    scanf("%s", senha_usuario);
                    printf("Confirme a senha: \n");
                    scanf("%s", verifica_senha);

                    if(strlen(nome_usuario)>10){
                        printf("Nome muito grande! Maximo de 10 letras\n");
                        break;
                    }

                    if(strcmp(senha_usuario, verifica_senha) == 0){
                        if(Verifica_Lista(&pLista) == 1){
                            printf("O total de alunos ja foi completado\n");
                        }else{
                            if(Verifica_Aluno(&pLista, nome_usuario, senha_usuario)==0){
                                printf("ja existe um aluno com o mesmo nome e senha cadastrado\n");
                                break;
                            }else if(Verifica_Aluno(&pLista, nome_usuario, senha_usuario)==1){
                                set_nome_aluno(&pAluno, nome_usuario);
                                set_senha_aluno(&pAluno, senha_usuario);
                                set_idade_aluno(&pAluno, idade_usuario);
                                Adicionar_Aluno_Lista(&pLista, pAluno);


                                printf("Cadastro Concluido com Sucesso!\n");
                            }

                        }
                    }else{
                        printf("As senhas estao diferentes!\n");
                    }

                }else if(who == 2){
                    if(aux == 0){
                        printf("Nome de Usuario: \n");
                        scanf("%s", nome_usuario);
                        printf("Senha: \n");
                        scanf("%s", senha_usuario);
                        printf("Confirme a senha: \n");
                        scanf("%s", verifica_senha);

                        if(strlen(nome_usuario)>10){
                            printf("Nome muito grande! Maximo de 10 letras\n");
                            break;
                        }

                        if(strcmp(senha_usuario, verifica_senha) == 0){
                            set_nome_professor(&pProfessor, nome_usuario);
                            set_senha_professor(&pProfessor, senha_usuario);
                            printf("Cadastro Concluido com Sucesso!\n");
                            aux++;
                        }else{
                            printf("As senhas estao diferentes!\n");
                        }
                    }else{
                        printf("-=-=-=-=-= Novo Cadastro de Professor (adm) -=-=-=-=-=\n");
                        printf("Por favor, digite seu nome e senha para continuar\n");
                        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                        printf("\n");
                        printf("Nome de Usuario: \n");
                        scanf("%s", nome_usuario);
                        printf("Senha: \n");
                        scanf("%s", senha_usuario);

                        if(verifica_professor(&pProfessor, nome_usuario, senha_usuario)==0){

                            printf("Novo Nome de Usuario: \n");
                            scanf("%s", nome_usuario);
                            printf("Nova Senha: \n");
                            scanf("%s", senha_usuario);
                            printf("Confirme a Senha: \n");
                            scanf("%s", verifica_senha);

                            if(strlen(nome_usuario)>10){
                                printf("Nome muito grande! Maximo de 10 letras\n");
                                break;
                            }

                            if(strcmp(senha_usuario, verifica_senha) == 0){
                                set_nome_professor(&pProfessor, nome_usuario);
                                set_senha_professor(&pProfessor, senha_usuario);
                                printf("Cadastro Concluido com Sucesso!\n");
                                aux++;
                            }else{
                                printf("As senhas estao diferentes!\n");
                            }

                        }else{
                            printf("Nome/senha invalido\n");
                        }

                    }
                }else{
                    loop = 0;
                    break;
                }

            }
        }else if(resp == 3){
            printf("Programa Encerrado!\n");
            loop_principal = 0;
            break;
        }else
            printf("Opcao Invalida!\n");

    }
}

void professor(CProfessor* pProfessor, CLista* pLista){
    int loop_principal = 1;
    int resp;
    int resp_materia;
    int posicao_aluno;
    char nome_usuario[TAMNOMES];

    //Variavel para a nota:
    int nota;


    while(loop_principal){
        printf("\n");
        printf("-=-=-=-=-= PROFESSOR -=-=-=-=-=\n");
        printf("[1] Alterar Notas dos Alunos\n");
        printf("[2] Mostrar Lista de Alunos\n");
        printf("[3] Sair\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        scanf("%d", &resp);

        if(resp == 1){
            printf("Digite o nome do aluno:\n");
            scanf("%s", nome_usuario);
            posicao_aluno = Posicao_Aluno_Professor(pLista, nome_usuario);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Selecione a materia para adicionar/alterar a nota:\n");
            printf("[1] Calculo\n");
            printf("[2] Fisica\n");
            printf("[3] Estatistica\n");
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            scanf("%d", &resp_materia);
            printf("Digite a nova nota: \n");
            scanf("%d", &nota);

            if(resp_materia == 1){
                //pLista->lista[posicao_aluno].pNotas.calculo = nota;
                set_calculo(&pLista->lista[posicao_aluno].pNotas, nota);
            }else if(resp_materia == 2){
                //pLista->lista[posicao_aluno].pNotas.fisica = nota;
                set_fisica(&pLista->lista[posicao_aluno].pNotas, nota);
            }else if(resp_materia == 3){
                //pLista->lista[posicao_aluno].pNotas.estatistica = nota;
                set_estatistica(&pLista->lista[posicao_aluno].pNotas, nota);
            }else{
                printf("opcao invalida!\n");
            }

        }
        else if(resp == 2){
            Imprime_Lista(*pLista);
            //Imprime_Lista(*pLista);
        }

        else{
            loop_principal = 0;
            break;
        }

    }

}

void aluno(CLista* pLista, int posicao_aluno){
    int loop_principal = 1;
    int resp;

    while(loop_principal){
        printf("\n");
        printf("-=-=-=-=-= ALUNO -=-=-=-=-=\n");
        printf("[1] Verificar seus Dados\n");
        printf("[2] Ver Notas\n");
        printf("[3] Sair\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        scanf("%d", &resp);

        if(resp == 1){
            printf("Nome: %s\n", pLista->lista[posicao_aluno].nome_aluno);
            printf("Idade: %d\n", pLista->lista[posicao_aluno].idade_aluno);
            printf("Senha: %s\n", pLista->lista[posicao_aluno].senha_aluno);
        }
        else if(resp == 2){
            printf("Calculo: %d\n", pLista->lista[posicao_aluno].pNotas.calculo);
            printf("Fisica: %d\n", pLista->lista[posicao_aluno].pNotas.fisica);
            printf("Estatistica: %d\n", pLista->lista[posicao_aluno].pNotas.estatistica);
        }
        else{
            loop_principal = 0;
            break;
        }
    }
}



