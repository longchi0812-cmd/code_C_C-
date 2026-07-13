#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int secretNumber, guess, attempts = 0;
    srand(time(0)); // Kh?i t?o s? ng?u nhiên
    secretNumber = rand() % 100 + 1; // S? bí m?t t? 1 d?n 100
    
    printf("Chào m?ng b?n d?n v?i trò choi doán s?!\n");
    printf("Tôi dã ch?n m?t s? t? 1 d?n 100, hãy th? doán nó.\n");
    
    do {
        printf("Nh?p s? b?n doán: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < secretNumber) {
            printf("S? b?n doán nh? hon s? bí m?t. Hãy th? l?i!\n");
        } else if (guess > secretNumber) {
            printf("S? b?n doán l?n hon s? bí m?t. Hãy th? l?i!\n");
        } else {
            printf("Chúc m?ng! B?n dã doán dúng s? bí m?t là %d trong %d l?n th?!\n", secretNumber, attempts);
        }
    } while (guess != secretNumber);
}

int main() {
    char choice;
    do {
        playGame();
        printf("B?n có mu?n choi l?i không? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("C?m on b?n dã choi trò choi!\n");
    return 0;
}

