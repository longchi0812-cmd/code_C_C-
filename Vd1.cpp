#include <stdio.h>
#include <string.h>
#include <ctype.h>

void showCurrent(char word[], int guessed[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i])
            printf("%c ", word[i]);
        else
            printf("_ ");
    }
    printf("\n");
}

int main() {
    char word[] = "laptrinh";
    int guessed[100] = {0};  // dánh d?u ký t? dã doán dúng
    int length = strlen(word);
    int tries = 7; // s? l?n doán sai t?i da

    printf("?? Chao mung den voi game Doan Tu Bi An!\n");
    printf("?? Tu khoa co %d chu cai. Ban co %d lan doan sai.\n", length, tries);

    while (tries > 0) {
        printf("\nHien tai: ");
        showCurrent(word, guessed);

        printf("Nhap 1 ky tu: ");
        char c;
        scanf(" %c", &c);
        c = tolower(c);  // chuy?n v? ch? thu?ng d? d? so

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == c && !guessed[i]) {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (!found) {
            tries--;
            printf("? Sai roi! Con %d lan thu.\n", tries);
        } else {
            printf("? Dung roi!\n");
        }

        // ki?m tra th?ng
        int win = 1;
        for (int i = 0; i < length; i++) {
            if (!guessed[i]) {
                win = 0;
                break;
            }
        }

        if (win) {
            printf("\n?? Ban da doan dung tu: %s\n", word);
            break;
        }
    }

    if (tries == 0) {
        printf("\n?? Het luot! Tu dung la: %s\n", word);
    }

    return 0;
}


