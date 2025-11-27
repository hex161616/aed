#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    /*
    ======================
    Aloca memória em bloco
    ======================
    */

    void *pBuffer = malloc(
        sizeof(int) +
        100 +
        100 +  
        sizeof(int) +
        sizeof(int) +    //cabeça atual
        sizeof(int)      //prox a ser usada
    );

    /*
    ===============================
    Verifica se alocou corretamente
    ===============================
    */

    if (!pBuffer) return 1;

    /*
    ==========================================================
    Aponta para o inicio da lista e calcula para o prox inicio
    ==========================================================
    */

    *(int *)((char *)pBuffer + sizeof(int) + 100 + 100 + sizeof(int)) = 0;
    *(int *)((char *)pBuffer + sizeof(int) + 100 + 100 + sizeof(int) + sizeof(int)) = 
        sizeof(int) + 100 + 100 + sizeof(int) + sizeof(int) + sizeof(int);

    while (1) {
        int *pOpcao = (int *)pBuffer;
        char *pNome = (char *)pBuffer + sizeof(int);
        char *pEmail = pNome + 100;
        int *pIdade = (int *)(pEmail + 100);
        int *pHead = (int *)(pIdade + 1);
        int *pProxOffset = pHead + 1;

        printf ("\n1-Adicionar\n2-Remover\n3-Buscar\n4-Listar\n5-Sair\nEscolha: ");
        scanf ("%d", pOpcao);
        getchar ();

        /*
        =============
        Opção 5-Sair
        ============
        */

        if (*pOpcao == 5)
            break;

        /*
        =================
        Opção 1-Adicionar
        =================
        */
        
        if (*pOpcao == 1) {
            printf ("Nome: ");
            fgets (pNome, 100, stdin);
            pNome[strcspn (pNome, "\n")] = 0;

            printf ("Idade: ");
            scanf ("%d", pIdade);
            getchar ();

            printf ("Email: ");
            fgets (pEmail, 100, stdin);
            pEmail[strcspn (pEmail, "\n")] = 0;

            size_t lenNome = strlen(pNome) + 1;
            size_t lenEmail = strlen(pEmail) + 1;

            int offAtual = *pProxOffset;

            size_t tamNo = sizeof(int) + sizeof(int) + lenNome + lenEmail;

            void *pNovoBuffer = realloc(pBuffer, offAtual + tamNo);
            if (!pNovoBuffer) {
                printf ("Erro memória\n");
                free (pBuffer);
                return 1;
            }
            pBuffer = pNovoBuffer;

            /*
            ============================================
            Recalcula o para onde os ponteiros apontarão
            ============================================
            */

            pOpcao = (int *)pBuffer;
            pNome = (char *)pBuffer + sizeof(int);
            pEmail = pNome + 100;
            pIdade = (int *)(pEmail + 100);
            pHead = (int *)(pIdade + 1);
            pProxOffset = pHead + 1;

            char *pNo = (char *)pBuffer + offAtual;

            *(int *)pNo = *pHead;       // Preenche nó: próximo nó = head atual, idade, nome, email
            *(int *)(pNo + sizeof(int)) = *pIdade;
            memcpy (pNo + 2 * sizeof(int), pNome, lenNome);
            memcpy (pNo + 2 * sizeof(int) + lenNome, pEmail, lenEmail);

            /*
            ==========================================
            Atualiza a cabeça para o prox espaço livre
            ==========================================
            */

            *pHead = offAtual;
            *pProxOffset = offAtual + tamNo;

            /*
            =================
            Opção 2-Remover
            =================
            */

        } else if (*pOpcao == 2) {
            printf ("Nome para remover: ");
            fgets (pNome, 100, stdin);
            pNome[strcspn (pNome, "\n")] = 0;

            int *pPrevOffset = pProxOffset + 1;
            int *pCurOffset = pPrevOffset + 1;

            *pPrevOffset = 0;   //Inicializa pra percorrer 
            *pCurOffset = *pHead; //Inicializando no começo

            while (*pCurOffset != 0) {  //Percorrendo a lista ligada
            char *pNo = (char *)pBuffer + *pCurOffset;
            int proxNo = *(int *)pNo;
            char *pNomeNo = pNo + 2 * sizeof(int);
                if (strcmp(pNomeNo, pNome) == 0) {
                    if (*pPrevOffset == 0) {
                        *pHead = proxNo;
                    } else {
                        *(int *)((char *)pBuffer + *pPrevOffset) = proxNo;
                    }
                printf("Removido: %s\n", pNomeNo);
                break;
                }

        *pPrevOffset = *pCurOffset;
        *pCurOffset = proxNo;
        }

        if (*pCurOffset == 0) {
            printf("Pessoa nao encontrada\n");
        }

        /*
        ==============
        Opção 3-Buscar 
        ==============
        */
        
        } else if (*pOpcao == 3) {
            printf ("Nome para buscar: ");
            fgets (pNome, 100, stdin);
            pNome[strcspn (pNome, "\n")] = 0;


            int *pCurOffset = pHead;

            while (*pCurOffset != 0) {
                char *pNo = (char *)pBuffer + *pCurOffset;
                int *pProxNo = (int *)pNo;
                int *pIdadeNo = (int *)(pNo + sizeof(int));
                char *pNomeNo = (char *)(pNo + 2 * sizeof(int));
                char *pEmailNo = pNomeNo + strlen(pNomeNo) + 1;
 
                if (strcmp(pNomeNo, pNome) == 0) {
                    printf("Encontrado: %s, %d anos, email: %s\n", pNomeNo, *pIdadeNo, pEmailNo);
                    break;
                }

                pCurOffset = pProxNo;
            }

            if (*pCurOffset == 0)
            printf("Pessoa não encontrada\n");

        /*
        ==============
        Opção 4-Listar
        ==============
        */   

        } else if (*pOpcao == 4) {
            
            int *pCurOffset = pHead;

            while (*pCurOffset != 0) {
                char *pNo = (char *)pBuffer + *pCurOffset;
                int *pProxNo = (int *)pNo;
                int *pIdadeNo = (int *)(pNo + sizeof(int));
                char *pNomeNo = pNo + 2 * sizeof(int);
                char *pEmailNo = pNomeNo + strlen(pNomeNo) + 1;

                printf ("\nNome: %s\nIdade: %d\nEmail: %s\n", pNomeNo, *pIdadeNo, pEmailNo);
                pCurOffset = pProxNo;
            }

        /*
        ======================================
        Caso o usúario digite um num diferente
        ======================================
        */

        } else {
            printf ("Opcao invalida\n");
        }
    }
    
    /*
    =========================================
    Libera a memória para encerrar o programa
    =========================================
    */

    free (pBuffer);
    return 0;
}