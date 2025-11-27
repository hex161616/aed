TRABALHO – Agenda pBuffer

Gabriel Lima Nascimento - 23100451

Descrição do Trabalho

A ideia central é trabalhar apenas com um único bloco de memória (void *pBuffer). Todo o controle e organização deverão ser feitos manualmente, simulando o papel do Sistema Operacional no gerenciamento da memória.

Regras

1 — O programa inteiro não pode declarar variáveis comuns; apenas ponteiros são permitidos, sempre apontando para regiões dentro do pBuffer.

1.1 — Isso também vale para parâmetros de função: somente ponteiros.

1.2 — Exemplos proibidos: int c;, char a;, int v[10];, void funcao(int x).

2 — O uso de struct não é permitido em nenhuma parte do código.