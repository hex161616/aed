#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *nomes = NULL;

void adicionar() {
    char buffer[100];
    printf("Digite o nome para adicionar: ");
    scanf("%s", buffer);

    size_t len_atual = (nomes == NULL) ? 0 : strlen(nomes);
    size_t len_novo = strlen(buffer);

    nomes = realloc(nomes, len_atual + len_novo + 2);
    if (!nomes) {
        printf("Erro de memória!\n");
        exit(1);
    }

    if (len_atual == 0) {
        nomes[0] = '\0';
    }

    strcat(nomes, buffer);
    strcat(nomes, "\n");

    printf("Nome adicionado!\n");
}

void remover() {
    if (!nomes || strlen(nomes) == 0) {
        printf("Nenhum nome para remover.\n");
        return;
    }

    char buffer[100];
    printf("Nome para remover: ");
    scanf("%s", buffer);

    char *pos = strstr(nomes, buffer);
    if (!pos) {
        printf("Nome não encontrado.\n");
        return;
    }

    size_t len_rem = strlen(buffer);
    char *fim = pos + len_rem;
    if (*fim == '\n') fim++;

    memmove(pos, fim, strlen(fim) + 1);

    nomes = realloc(nomes, strlen(nomes) + 1);
    printf("Nome removido!\n");
}

void listar() {
    printf("Lista de nomes:\n%s", nomes);
}

void sair() {
    free(nomes);
    exit(0);
}

int main() {
    int opcao;
    do {
        printf("1) Adicionar nome\n");
        printf("2) Remover nome\n");
        printf("3) Listar\n");
        printf("4) Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            adicionar();
            break;
        case 2:
            remover();
            break;
        case 3:
            listar();
            break;
        case 4:
            sair();
            break;
        default:
            printf("Valor invalido!\n");
        }
    } while (opcao != 4);
    
    return 0;
}