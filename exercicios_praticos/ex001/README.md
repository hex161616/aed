# TRABALHO - Exercício Pratico - Lemonade Change

Gabriel Lima Nascimento - 23100451

## Descrição do Exercício dado em Aula

Dado um array bills representando as notas que cada cliente usa para pagar um suco de limão de $5, determine se é possível dar troco corretamente a todos.
Cada suco custa $5, e você pode receber notas de $5, $10 ou $20.
Você começa sem dinheiro.
Retorne true se conseguir dar o troco a todos, senão false.

## Casos que foram testados

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
Dos três primeiros clientes, recebemos três notas de 5 em sequência.
Do quarto cliente, recebemos uma nota de 10 e devolvemos uma de 5.
Do quinto cliente, devolvemos uma nota de 10 e uma de 5.
Como todos os clientes receberam o troco certo, o resultado é true.

Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
Dos dois primeiros clientes, recebemos duas notas de 5.
Dos dois seguintes, recebemos uma nota de 10 e devolvemos uma de 5.
Pro último cliente, não conseguimos dar o troco de 15, porque só temos duas notas de 10.
Como nem todos receberam o troco certo, o resultado é false.

## Condições 

- Está funcionando com letras repetidas. 
- Código funcionando no leetcode.