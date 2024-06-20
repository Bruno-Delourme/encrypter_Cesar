#include <stdio.h>
#include <string.h>

// Fonction pour chiffrer une chaine avec le chiffrement Cesar
void caesarEncrypt(char* text, int shift) {
    int i;
    char ch;

    // Parcourir chaque caractere de la chaine
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Verifie si le caractere est une lettre minuscule
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
            text[i] = ch;
        }
        // Verifie si le caractere est une lettre majuscule
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int shift;

    // Demande a l'utilisateur d'entrer une chaine
    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Supprimer le saut de ligne

    // Demande a l'utilisateur d'entrer le decalage
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Chiffre la chaine
    caesarEncrypt(text, shift);

    // Affiche le resultat chiffre
    printf("Encrypted text: %s\n", text);

    return 0;
}
