O propósito do código é implementar a Cifra de Hill como um exemplo prático de criptografia simétrica para o projeto integrador do curso de Cibersegurança da PUC-Campinas. 

O programa é uma implementação da Cifra de Hill que adiciona interatividade ao solicitar ao usuário uma matriz-chave 2x2, usada para a criptografia. 
Ele segue o princípio da álgebra linear para transformar pares de caracteres do texto em números, aplicar operações matriciais e reconvertê-los em letras criptografadas.

----------------

Definições e Constantes

- MODULO é definido como 26 para restringir operações ao alfabeto inglês (A-Z).
----------------

----------------
- multiplicarMatriz:

Função multiplicarMatriz
Essa função realiza o núcleo matemático da Cifra de Hill:

Entrada:
matriz[2][2]: a matriz-chave de 2x2 fornecida pelo usuário.
vetor[2]: o par de caracteres do texto convertido em números (A=0, B=1, ..., Z=25).

Processo:
Multiplica cada linha da matriz pelo vetor correspondente.
Aplica a operação módulo 26 para garantir que o resultado seja válido dentro do alfabeto inglês.

Saída:
resultado[2]: vetor resultante, que contém os valores numéricos dos caracteres criptografados.


----------------
- cifraHill:

Função cifraHill
Realiza a criptografia do texto:

Entrada:
texto: string de entrada.
matriz[2][2]: a matriz-chave.

Processo:
Ajuste do texto:
Se o número de caracteres não for par, adiciona o caractere X no final.

Processamento em pares:
Divide o texto em blocos de 2 caracteres.
Converte cada caractere em valor numérico ('A' = 0, ..., 'Z' = 25).
Passa o par de valores para a função multiplicarMatriz.

Conversão:
Converte os valores numéricos retornados em caracteres e substitui os originais no texto.

Saída:
Atualiza o texto com os caracteres criptografados.


----------------
- lerMatriz:

Função lerMatriz
Permite ao usuário especificar a matriz-chave:

Entrada: Valores digitados pelo usuário.

Processo:
Solicita e lê os elementos de uma matriz 2x2, exibindo mensagens interativas.

Saída: Atualiza a matriz global usada na criptografia.


----------------
- Função main 

Leitura da matriz: Chama lerMatriz para permitir que o usuário insira a chave.

Leitura do texto:
Usa fgets para capturar o texto.
Remove espaços, converte para maiúsculas e elimina caracteres não alfabéticos.

Criptografia: Chama cifraHill para processar o texto.

Saída: Exibe o texto criptografado na tela.
