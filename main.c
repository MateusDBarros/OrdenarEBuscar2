#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados dos alunos
struct Aluno {
    char alunoNome[25];
    int alunoPrioridade;
};

// Declaração das funções
int ordenar(struct Aluno alunos[], int *numAlunos);
int busca(struct Aluno alunos[], int alvo, int inicio, int fim);
void inserirAluno(struct Aluno alunos[], int *numAlunos);
int exibirLista(struct Aluno alunos[], int *numAlunos);
void exibirMenu(void);

int main(void) {
    struct Aluno alunos[100];  // Array para armazenar até 100 alunos
    int numAlunos = 0;  // Contador de alunos
    int escolha;  // Variável para armazenar a escolha do usuário
    int alvo;  // Variável para armazenar a prioridade a ser buscada
    
    // Loop do menu principal
    do {
        printf("\n");
        exibirMenu();  // Exibe o menu para o usuário
        printf("Seleciona uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirAluno(alunos, &numAlunos);  // Chama a função para inserir um novo aluno
                break;
            case 2:
                exibirLista(alunos, &numAlunos);  // Chama a função para exibir a lista de alunos
                break;
            case 3:
                printf("Insira o ID do aluno: ");
                scanf("%d", &alvo);
                int indice = busca(alunos, alvo, 0, numAlunos - 1);  // Chama a função de busca
                if (indice != -1) {
                    printf("| %-20s | %-10s |\n", "Nome", "Prioridades");
                    printf("|----------------------|-------------|\n");
                    printf("| %-20s | %-5d |\n", alunos[indice].alunoNome, alunos[indice].alunoPrioridade);
                    printf("|----------------------|-------|\n");
                } else {
                    printf("Aluno nao encontrado!\n");
                }
                break;
            case 4:
                return 0;  // Termina o programa
            default:
                printf("Escolha invalida!\n");
                break;
        }
    } while (escolha != 4);

    return 0;  // Retorno da função main
}

// Função para ordenar a lista de alunos por prioridade usando Bubble Sort
int ordenar(struct Aluno alunos[], int *numAlunos) {
    struct Aluno temp;
    for (int i = 0; i < *numAlunos - 1; i++) {
        for (int j = 0; j < *numAlunos - 1 - i; j++) {
            if (alunos[j].alunoPrioridade > alunos[j + 1].alunoPrioridade) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    return 0;  // Ordenação realizada com sucesso
}

// Função para buscar um aluno por prioridade usando busca binária
int busca(struct Aluno alunos[], int alvo, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;

    if (inicio > fim) return -1;  // Condição de parada da busca
    if (alvo == alunos[meio].alunoPrioridade) return meio;  // Aluno encontrado

    if (alvo < alunos[meio].alunoPrioridade)
        return busca(alunos, alvo, inicio, meio - 1);  // Buscar na metade inferior
    else
        return busca(alunos, alvo, meio + 1, fim);  // Buscar na metade superior
}

// Função para inserir um novo aluno na lista
void inserirAluno(struct Aluno alunos[], int *numAlunos) {   
    printf("Entre o nome do novo aluno: ");
    scanf("%s", alunos[*numAlunos].alunoNome);
    printf("Qual a prioridade de %s? ", alunos[*numAlunos].alunoNome);
    scanf("%d", &alunos[*numAlunos].alunoPrioridade);
    printf("Aluno cadastrado com sucesso!\n");
    (*numAlunos)++;
    ordenar(alunos, numAlunos);  // Ordena a lista após a inserção
}

// Função para exibir a lista de alunos
int exibirLista(struct Aluno alunos[], int *numAlunos) {
    printf("| %-20s | %-10s |\n", "Nome", "Prioridades");
    printf("|----------------------|-------------|\n");
    for (int i = 0; i < *numAlunos; i++) {
        printf("| %-20s | %-5d |\n", alunos[i].alunoNome, alunos[i].alunoPrioridade);
        printf("|----------------------|-------|\n");
    }
    return 0;
}

// Função para exibir o menu principal
void exibirMenu(void) {
    printf("\n\t---Menu Principal---\t\n");
    printf("1. Adicionar Aluno\n");
    printf("2. Exibir Lista de Alunos\n");
    printf("3. Buscar Aluno\n");
    printf("4. Sair\n");
}
