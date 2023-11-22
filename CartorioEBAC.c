#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca das strings
#include <dirent.h>


int registro(){ //função para cadastrar
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //copia os valores das strings

    FILE *file; //cria o arquivo 
    file=fopen(arquivo, "w"); //cria o arquivo para escrita
    fprintf(file, cpf); //escreve no arquivo a variável
    fclose(file); //fecha o arquivo

    file=fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file=fopen(arquivo,"a");
    fprintf(file, nome);
    fclose(file);

    file=fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file=fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file=fopen(arquivo, "a"); //atualiza o arquivo
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file=fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("cls");
    printf("Usuário Cadastrado com sucesso\n");
    system("pause");

}

int consulta(){ //função para consultar 

    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf); //%s para string

    FILE *file;
    file=fopen(cpf, "r"); //para ler o arquivo

    if(file == NULL){
        printf("CPF não econtrado\n");
    }

    while (fgets(conteudo, 200, file) != NULL) //enquanto tiver conteudo no arquivo, guardar na variável conteudo
    {
        printf("Essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    
    
    system("pause");
    
}

int deleta(){ //função para deletar 
   char cpf[40];
   printf("Digite o CPF a ser deletado: ");
   scanf("%s", cpf);
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");

   if (file == NULL)
   {
        printf("CPF não encontrado\n");
        system("pause");
   }
      
}

int main(){
int opcao=0;
int x=1;
int menu=0;
int y=1;
    for(x=1;x=1;){

        setlocale(LC_ALL, "Portuguese");

        printf("Cartório da EBAC \n\n");
        printf("Escolha a opção desejada:\n\n");
        printf("\t 1- Registrar nomes:\n");
        printf("\t 2- Consultar nomes:\n");
        printf("\t 3- Deletar nomes:\n\n");
        
        //printf("Esse software pertence a José Rodrigo");
        printf("Digite a opção: ");


        scanf("%d", &opcao);
        system("cls"); //limpa a tela

        switch(opcao){ //onde chama as funções 
            case 1:
            registro();
            system("cls");
            for (y=1;y=1;){
                printf("Deseja voltar ao menu?\n 1-Sim \n 2-Não\n\n");
                scanf("%d", &menu);
                if (menu == 1)
                    {
                        break;
                    }
                if (menu == 2)
                {
                    registro();
                } 
            }
            break;

            case 2:
            consulta();
            system("cls");
            for (y=1;y=1;){
                printf("Deseja voltar ao menu?\n 1-Sim \n 2-Não\n\n");
                scanf("%d", &menu);
                if (menu == 1)
                    {
                        break;
                    }
                if (menu == 2)
                {
                    consulta();
                } 
            }
            break;



            case 3:
            deleta();
            system("cls");
            for (y=1;y=1;){
                printf("Deseja voltar ao menu?\n 1-Sim \n 2-Não\n\n");
                scanf("%d", &menu);
                if (menu == 1)
                    {
                        break;
                    }
                if (menu == 2)
                {
                    deleta();
                } 
            }
            break;

            break;

            case 4:
            default:
            printf("Opção Inválida\n");
            system("pause");
            break;
        }
    }   
}