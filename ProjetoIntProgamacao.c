#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    int nota;
}aluno;

int CadastrarAluno (aluno p[],int tamanhoVetor, int quantidade)
{    
    aluno alunoCadastrado;

    printf("\n<<<<<<<Cadastro de aluno>>>>>>>\n");
    
    printf("\nDigite o seu nome: ");
    scanf("%s", alunoCadastrado.nome);

    printf("\nDigite a sua nota: ");
    scanf("%d", &alunoCadastrado.nota);

    if (alunoCadastrado.nota < 0 || alunoCadastrado.nota > 10)
    {
        while (alunoCadastrado.nota < 0 || alunoCadastrado.nota > 10)
        {
            printf("Por favor, digite a sua verdadeira nota. Tente novamente: \n");
            scanf("%d", &alunoCadastrado.nota);
        }
    }
    p[quantidade] = alunoCadastrado;

    return 1;
}

void ExibirAluno(aluno p[], int quantidade)
{
    printf("\n<<<<<<<Exibir aluno>>>>>>>\n");

    printf("\n+++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nAlunos: %d\nAluno: %s\n Nota: %d \n", (i+1), p[i].nome, p[i].nota);
        printf("\n====================================\n");
    }
    printf("\n++++++++++++++++++++++++++++++++++++\n");
}

void AlterarAluno (aluno p[], int quantidade)
{
    printf("\n<<<<<<<Alterar aluno>>>>>>>\n");

    if(quantidade == 0)
    {
        printf("Voce nao cadastrou nenhum aluno.\n");
    }
    else
    {
        ExibirAluno(p, quantidade);
        
        int numeroID;

        printf("\nDigite o numero da posicao em que o aluno que voce deseja trocar esta: ");
        scanf("%d", &numeroID);

        getchar();

        numeroID--;

        if(numeroID >=0 && numeroID < quantidade)
        {
            aluno novoAluno;

            printf("\nDigite o nome do novo aluno: ");
            scanf("%99[^\n]", novoAluno.nome);

            printf("\nDigite a nota do novo aluno: ");
            scanf("%d", &novoAluno.nota);

            getchar();

            if (novoAluno.nota > 10 || novoAluno.nota < 0)
            {
                while (novoAluno.nota > 10 || novoAluno.nota < 0)
                {
                    printf("\nNota invalida. Por favor digite novamente: ");
                    scanf("%d", &novoAluno.nota);
                }
                
            }

            p[numeroID] = novoAluno;
            
        }

        else
        {
            printf("Numero da posicao invalida.\n");
        }
    }
}

int deletarAluno (aluno p[], int quantidade)
{
    printf("\n<<<<<<<Deletar aluno>>>>>>>\n");

    if (quantidade == 0)
    {
        printf("Voce nao tem alunos cadastrados.\n");
        
        return 2;
    }
    
    int numeroID;

    printf("\nDigite a posicao em que o aluno esta na orgem de cadastro: ");
    scanf("%d", &numeroID);
    
    getchar();

    numeroID--;

    if (numeroID >= 0 && numeroID < quantidade)
    {
        if (numeroID == (quantidade - 1))
        {
            printf("Aluno deletado\n");

            return -1;
        }
        
        int i, j;

        for (i = numeroID; i < quantidade; i++)
        {
            if (i == (quantidade - 1))
            {
                j = i;
            }
            
            else
            {
                j = i + 1;
            }

            aluno temporaria = p[i];
            p[i] = p[j];
            p[j] = temporaria;
        }
     
    }

    else
    {
        printf("Opcao invalida.\n");
        return 3;
    }

    printf("Pessoa deletada com sucesso!\n");
    return 4;

}

int main (){

	int escolha;
    aluno alunos[50];
    int tamanhoVetorPessoa = sizeof(alunos) / sizeof (aluno);
    int qtdAlunos = 0;


    printf("\n==== Menu ====\n");
    printf("1. Adicionar nome do aluno e sua nota\n");
    printf("2. Exibir nome e nota do aluno\n");
    printf("3. Atualizar nome e nota do aluno\n");
    printf("4. Excluir nome e nota do aluno\n");
    printf("0. Sair\n");
    printf("==============\n");

    printf("Escolha uma opcao: ");
	scanf("%d", &escolha);

    if (escolha == 0)
    {
        printf("Sistema encerrado.");
    }
    
    while (escolha != 0)
    {

    
        switch (escolha)
        {
            case 1:
                getchar();
                qtdAlunos += CadastrarAluno(alunos, tamanhoVetorPessoa, qtdAlunos);
                printf("\n\tPessoas Cadastradas = %d\n", qtdAlunos);                
            
            break;

            case 2:

                ExibirAluno(alunos, qtdAlunos);

            break;

            case 3:

                AlterarAluno(alunos, qtdAlunos);
            break;

            case 4:
             qtdAlunos += deletarAluno(alunos, qtdAlunos);
                break;

            default:

                printf("Opcao invalida\n");
            break;
        }

        printf("\nEscolha uma opcao: ");
	    scanf("%d", &escolha);

        if (escolha == 0)
        {
            printf("Sistema encerrado.");
        }        
    }
	
    return 0;
}