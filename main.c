#include <stdio.h>
#include <string.h>

// Fonction pour chiffrer une chaine avec le chiffrement Cesar
void caesarEncrypt(char* text, int shift)
        {
    int i;
    char ch;

    // Parcourir chaque caractere de la chaine
    for (i = 0; text[i] != '\0'; ++i)
        {
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

// Fonction pour dechiffrer une chaine avec le chiffrement Cesar
void caesarDecrypt(char* text, int shift)
        {
    int i;
    char ch;

    // Parcourir chaque caractere de la chaine
    for (i = 0; text[i] != '\0'; ++i)
        {
        ch = text[i];

        // Verifie si le caractere est une lettre minuscule
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
            text[i] = ch;
        }
        // Verifie si le caractere est une lettre majuscule
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
            text[i] = ch;
        }
    }
}

int main() {
    char text[100];
    int shift;
    char choice;

    // Demande a l'utilisateur de choisir entre chiffrer ou dechiffrer
    printf("Do you want to (e)ncrypt or (d)ecrypt? ");
    scanf(" %c", &choice); // L'espace avant %c est important pour consommer tout espace residuel

    // Demande a l'utilisateur d'entrer une chaine
    printf("Enter a string: ");
    getchar(); // Pour consommer le saut de ligne résiduel après la saisie du choix
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Supprime le saut de ligne

    // Demande a l'utilisateur d'entrer le decalage
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Chiffre ou dechiffre la chaine en fonction du choix de l'utilisateur
    if (choice == 'e')
    {
        caesarEncrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 'd') {
        caesarDecrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
