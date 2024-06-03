#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PONTOS_PARA_GANHAR 5

sem_t semaforo_jogador1;
sem_t semaforo_jogador2;

int pontos_jogador1 = 0;
int pontos_jogador2 = 0;

void* jogador1(void* arg) {
    while (1) {
        sem_wait(&semaforo_jogador1); // Espera pelo sinal para jogar

        if (pontos_jogador1 >= PONTOS_PARA_GANHAR || pontos_jogador2 >= PONTOS_PARA_GANHAR) {
            sem_post(&semaforo_jogador2); // Garante que a outra thread seja desbloqueada
            break;
        }

        int marcou_ponto;
        printf("Jogador 1: O jogador 1 marcou ponto? (1 para sim, 0 para não): ");
        scanf("%d", &marcou_ponto);
        
        if (marcou_ponto) {
            pontos_jogador1++;
            printf("Jogador 1: Ping! Pontos: %d\n", pontos_jogador1);
        }

        sleep(1); // Simula o tempo de resposta
        sem_post(&semaforo_jogador2); // Sinaliza o jogador 2
    }
    pthread_exit(NULL);
}

void* jogador2(void* arg) {
    while (1) {
        sem_wait(&semaforo_jogador2); // Espera pelo sinal para jogar

        if (pontos_jogador1 >= PONTOS_PARA_GANHAR || pontos_jogador2 >= PONTOS_PARA_GANHAR) {
            sem_post(&semaforo_jogador1); // Garante que a outra thread seja desbloqueada
            break;
        }

        int marcou_ponto;
        printf("Jogador 2: O jogador 2 marcou ponto? (1 para sim, 0 para não): ");
        scanf("%d", &marcou_ponto);

        if (marcou_ponto) {
            pontos_jogador2++;
            printf("Jogador 2: Pong! Pontos: %d\n", pontos_jogador2);
        }

        sleep(1); // Simula o tempo de resposta
        sem_post(&semaforo_jogador1); // Sinaliza o jogador 1
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_jogador1, thread_jogador2;

    // Inicializa os semáforos
    sem_init(&semaforo_jogador1, 0, 1); // Jogador 1 começa com o semáforo disponível
    sem_init(&semaforo_jogador2, 0, 0); // Jogador 2 começa com o semáforo não disponível

    // Cria as threads
    pthread_create(&thread_jogador1, NULL, jogador1, NULL);
    pthread_create(&thread_jogador2, NULL, jogador2, NULL);

    // Espera as threads terminarem
    pthread_join(thread_jogador1, NULL);
    pthread_join(thread_jogador2, NULL);

    // Declara o vencedor
    if (pontos_jogador1 >= PONTOS_PARA_GANHAR) {
        printf("Jogador 1 é o campeão com %d pontos!\n", pontos_jogador1);
    } else if (pontos_jogador2 >= PONTOS_PARA_GANHAR) {
        printf("Jogador 2 é o campeão com %d pontos!\n", pontos_jogador2);
    }

    // Destroi os semáforos
    sem_destroy(&semaforo_jogador1);
    sem_destroy(&semaforo_jogador2);

    return 0;
}