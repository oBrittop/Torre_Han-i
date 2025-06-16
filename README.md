
<h1 align="center"> Projeto final de Estrutura de Dados</h1>
<<<<<<< refactor/featdesenharjogo
_Grupo 5_ = { 
    ["Gustavo Brito"], 
    ["Isaac Ramos"], 
    ["Isaquiel Nathan"], 
    ["Gustavo Barbosa"], 
    ["Rodrigo Castro Dantas"] 
    }
=======
_Grupo 5_ = {
["Gustavo Brito"],
["Isaac Ramos"],
["Isaquiel Nathan"],
["Gustavo Barbosa"],
["Rodrigo Castro Dantas"]
}
>>>>>>> main


<h2 align="center"> Jogo Torre de Hanoi</h2>

__Optamos por fazer uma__




---

## 🏗️ Estrutura e Arquitetura do Projeto

__Criamos funçoes por partes, eu GB fui fazendo oque achava que era as funçoes principais, com a idea de aplicar componentização em todo o codigo__

Para garantir um código mais limpo, organizado e reutilizável, optamos por adotar uma estrutura modular separando a nossa "biblioteca" da lógica principal do jogo.

Esta abordagem consiste em dois tipos de arquivos principais:

### 1. O Arquivo de Cabeçalho (`hanoi.h`)

Este arquivo funciona como a **interface pública** do nosso módulo. É aqui que definimos os "contratos" que outras partes do nosso código podem usar.

Ele contém:
* **Definições das Estruturas**: `struct Disco` e `struct Estaca`.
* **Constantes e Macros**: Como `#define ALTURA_TORRE 5`.
* **Protótipos das Funções**: A assinatura de todas as funções que manipulam o jogo, como:
    ```c
    void empilhar(Disco **pilha, int tamanho);
    int desempilhar(Disco **pilha);
    void desenharJogo(Estaca estacas[]);
    ```

> ✨ **Pense no `.h` como o menu de um restaurante**: ele te diz o que você pode pedir (as funções), mas não como os pratos são preparados na cozinha.

### 2. O Arquivo de Implementação (`hanoi.c`)

Este arquivo contém a **lógica interna** e o "recheio" das funções declaradas no arquivo `.h`.

* É aqui que o código que **executa** as tarefas de empilhar, desempilhar e desenhar o jogo reside.
* Ele "inclui" o seu próprio arquivo de cabeçalho (`#include "hanoi.h"`) para garantir que a implementação está de acordo com os protótipos definidos.

### Vantagens desta Abordagem

* **Organização**: Separa claramente a interface da implementação, tornando o projeto mais fácil de navegar.
* **Abstração**: O `main.c` não precisa saber *como* a função `desenharJogo` funciona, apenas que ela existe e como chamá-la.
* **Reutilização**: Se quiséssemos criar outro jogo que usa pilhas, poderíamos facilmente reutilizar nossos arquivos `torre_hanoi.h` e `torre_hanoi.c`.
* **Manutenção**: Facilita a correção de bugs, pois o código está contido em módulos lógicos.

### Como Compilar o Projeto

Com essa estrutura, o comando para compilar o projeto une os arquivos de implementação:
```bash
gcc main.c torre_hanoi.c -o jogo_torre_de_hanoi


