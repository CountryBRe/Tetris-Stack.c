🎮 Tetris Stack — Estruturas de Dados em C

Este projeto implementa o jogo Tetris Stack em linguagem C, utilizando estruturas de dados para simular o sistema de peças futuras e peças reservadas do jogo.

Durante a execução, o jogador interage com uma fila circular de peças e uma pilha de reserva, podendo jogar, guardar, usar e trocar peças conforme o nível escolhido.

🧠 Estruturas de dados utilizadas

Fila circular → peças futuras (FIFO)
Pilha linear → peças reservadas (LIFO)
Structs → representação das peças
Arrays estáticos
Funções e modularização
Condicionais e estruturas de repetição

---

🎮 Funcionalidades por nível
✅ Nível Novato

Controle apenas da fila de peças.

Jogar peça (remove da fila).

Inserir nova peça.

Visualizar a fila atual.

---

✅ Nível Aventureiro

Adição da pilha de reserva.

Reservar peça da fila.

Usar peça reservada.

A fila permanece sempre cheia.

---

✅ Nível Mestre

Troca entre fila e pilha.

Troca simples (uma peça).

Troca múltipla (três peças).

Jogabilidade mais estratégica.

---

🎨 Sistema de cores (ANSI)

O programa utiliza cores no terminal para melhorar a visualização:

| Cor      | Significado         |
|----------|-------------------|
| 🟢 Verde  | Mensagens de sucesso |
| 🔴 Vermelho | Erros e Bloqueios |
| 🟡 Amarelo | Avisos e ações |
| 🔵 Azul   | Títulos e menus |

---

⚙️ Compilação e Execução
Compilar:
gcc TetrisStack.c -o TetrisStack

Executar:
./TetrisStack

---

🧩 Exemplo de saída
=== TETRIS STACK ===

|----------|-------------------|
| Fila: [T 2] [O 3] [L 4] [I 5] [O 6] |
| Pilha: [T 9] [I 8] |

| 1 - Jogar peça |
| 2 - Reservar peça | 
| 3 - Usar reserva |
| 4 - Trocar peça |
| 5 - Troca múltipla |
| 0 - Sair |

---

👨‍💻 Autor: Rodrigo Gomes
Disciplina: Estruturas de Dados
Professor: Nathan de Freitas
Faculdade: Estácio de Sá

---
⚙️ Compilação e Execução
Compilar:
gcc TetrisStack.c -o TetrisStack

Executar:
./TetrisStack
