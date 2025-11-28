#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===== CORES ANSI ===== */
#define RESET   "\033[0m"
#define VERMELHO "\033[31m"
#define VERDE    "\033[32m"
#define AMARELO  "\033[33m"
#define AZUL     "\033[34m"

/* TAMANHOS */
#define FILA_TAM 5
#define PILHA_TAM 3

/* ESTRUTURA DA PEÇA */
typedef struct {
    char nome;
    int id;
} Peca;

/* FILA */
Peca fila[FILA_TAM];
int inicio = 0, fim = 0, totalFila = 0;

/* PILHA */
Peca pilha[PILHA_TAM];
int topo = -1;

/* CONTADOR GLOBAL */
int contadorID = 0;

/* ================== FUNÇÃO GERADORA ================== */
Peca gerarPeca() {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = contadorID++;
    return p;
}

/* ================== FILA ================== */
void enqueue() {
    fila[fim] = gerarPeca();
    fim = (fim + 1) % FILA_TAM;
    totalFila++;
}

void dequeue() {
    if (totalFila > 0) {
        inicio = (inicio + 1) % FILA_TAM;
        totalFila--;
    }
}

/* ================== PILHA ================== */
void push(Peca p) {
    if (topo < PILHA_TAM - 1) {
        pilha[++topo] = p;
        printf(VERDE "Peça reservada!\n" RESET);
    } else {
        printf(VERMELHO "Pilha cheia!\n" RESET);
    }
}

void pop() {
    if (topo >= 0) {
        printf(AMARELO "Peça da pilha usada.\n" RESET);
        topo--;
    }
    else printf(VERMELHO "Pilha vazia!\n" RESET);
}

/* ================== EXIBIÇÃO ================== */
void mostrarFila() {
    int i, pos = inicio;
    printf(AZUL "\nFila: " RESET);
    for (i = 0; i < totalFila; i++) {
        printf("[%c " AMARELO "%d" RESET "] ", fila[pos].nome, fila[pos].id);
        pos = (pos + 1) % FILA_TAM;
    }
}

void mostrarPilha() {
    printf(AZUL "\nPilha (Topo -> base): " RESET);
    for (int i = topo; i >= 0; i--) {
        printf("[%c " AMARELO "%d" RESET "] ", pilha[i].nome, pilha[i].id);
    }
}

/* ================== TROCAS ================== */
void trocaSimples() {
    if (topo >= 0 && totalFila > 0) {
        Peca temp = fila[inicio];
        fila[inicio] = pilha[topo];
        pilha[topo] = temp;
        printf(VERDE "Troca simples realizada.\n" RESET);
    } else {
        printf(VERMELHO "Troca não permitida.\n" RESET);
    }
}

void trocaMultipla() {
    if (topo >= 2 && totalFila >= 3) {
        for (int i = 0; i < 3; i++) {
            int pos = (inicio + i) % FILA_TAM;
            Peca temp = fila[pos];
            fila[pos] = pilha[topo - i];
            pilha[topo - i] = temp;
        }
        printf(VERDE "Troca múltipla realizada.\n" RESET);
    } else {
        printf(VERMELHO "Troca múltipla impossível.\n" RESET);
    }
}

/* ================== NÍVEL NOVATO ================== */
void nivelNovato() {
    int op;
    do {
        mostrarFila();
        printf(AZUL "\n\n=== NÍVEL NOVATO ===" RESET);
        printf("\n1 - Jogar peça");
        printf("\n2 - Inserir peça");
        printf("\n0 - Voltar\n");
        scanf("%d", &op);

        if (op == 1) {
            dequeue();
            printf(AMARELO "Peça jogada!\n" RESET);
        }
        else if (op == 2 && totalFila < FILA_TAM) {
            enqueue();
            printf(VERDE "Peça inserida!\n" RESET);
        }

    } while (op != 0);
}

/* ================== NÍVEL AVENTUREIRO ================== */
void nivelAventureiro() {
    int op;
    do {
        mostrarFila();
        mostrarPilha();
        printf(AZUL "\n\n=== NÍVEL AVENTUREIRO ===" RESET);
        printf("\n1 - Jogar peça");
        printf("\n2 - Reservar peça");
        printf("\n3 - Usar peça da pilha");
        printf("\n0 - Voltar\n");
        scanf("%d", &op);

        if (op == 1) {
            dequeue();
            enqueue();
            printf(AMARELO "Peça jogada!\n" RESET);
        }
        else if (op == 2 && topo < PILHA_TAM - 1) {
            push(fila[inicio]);
            dequeue();
            enqueue();
        }
        else if (op == 3) pop();

    } while (op != 0);
}

/* ================== NÍVEL MESTRE ================== */
void nivelMestre() {
    int op;
    do {
        mostrarFila();
        mostrarPilha();
        printf(AZUL "\n\n=== NÍVEL MESTRE ===" RESET);
        printf("\n1 - Jogar peça");
        printf("\n2 - Reservar peça");
        printf("\n3 - Usar peça reservada");
        printf("\n4 - Troca simples");
        printf("\n5 - Troca múltipla");
        printf("\n0 - Voltar\n");
        scanf("%d", &op);

        if (op == 1) {
            dequeue();
            enqueue();
            printf(AMARELO "Peça jogada!\n" RESET);
        }
        else if (op == 2 && topo < PILHA_TAM - 1) {
            push(fila[inicio]);
            dequeue();
            enqueue();
        }
        else if (op == 3) pop();
        else if (op == 4) trocaSimples();
        else if (op == 5) trocaMultipla();

    } while (op != 0);
}

/* ================== MAIN ================== */
int main() {
    srand(time(NULL));

    for (int i = 0; i < FILA_TAM; i++) enqueue();

    int nivel;
    do {
        printf(AZUL "\n=== TETRIS STACK ===" RESET);
        printf("\n1 - Nível Novato");
        printf("\n2 - Nível Aventureiro");
        printf("\n3 - Nível Mestre");
        printf("\n0 - Sair\n");
        scanf("%d", &nivel);

        if (nivel == 1) nivelNovato();
        else if (nivel == 2) nivelAventureiro();
        else if (nivel == 3) nivelMestre();

    } while (nivel != 0);

    printf(VERDE "\nPrograma encerrado!\n" RESET);
    return 0;
}