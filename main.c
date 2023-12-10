#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isAnlamli(char word[]);
void decrypt(char *message, int key);

int main() {
    char fileName[100];
    int key;

    printf("Dosya adini girin: ");
    scanf("%s", fileName);

    printf("Kaydirma miktarini girin: ");
    scanf("%d", &key);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Dosya acilmadi.\n");
        return 1;
    }

    char message[100];
    fgets(message, sizeof(message), file);
    fclose(file);

    decrypt(message, key);
    printf("Cozulmus mesaj: %s\n", message);

    return 0;
}

bool isAnlamli(char word[]) {
    int i = 0;
    while (word[i] != '\0') {
        if (!isalpha(word[i])) {
            return false;
        }
        i++;
    }
    return true;
}

/*isalpha fonksiyonu verilen karakterin bir harf olup olmadýðýný kontrol eder*/
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            } else if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            }
        }
        i++;
    }
}
