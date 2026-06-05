#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char usuario[50];
    char senha[50];
} Conta;

int total = 0;

Conta conta[MAX];

void cadastrar() {

    printf("\nUsuario: ");
    scanf(" %[^\n]", conta[total].usuario);

    printf("\nSenha: ");
    scanf(" %[^\n]", conta[total].senha);
    
    total++;
    printf("\nConta cadastrada com sucesso!\n");
}

void login() {

    char usuario[50];
    char senha[50];
    int encontrado = 0;
    int i;
    
    printf("\nUsuario: ");
    scanf(" %[^\n]", usuario);

    printf("\nSenha: ");
    scanf(" %[^\n]", senha);
    
    for (i = 0; i < total; i++) {
        if (strcmp(usuario, conta[i].usuario) == 0 && strcmp(senha, conta[i].senha) == 0) {
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado) {
        printf("\nLogin realizado com sucesso!\n");
    } else {
        printf("\nUsuario ou senha incorreta!\n");
    }
}

int main() {

    int opcao;

    do {
    	
    	printf("\n\nEscolha uma opcao:\n");
        printf("\n1 - Cadastrar\n2 - Login\n0 - Sair\n\n");
        scanf("%d", &opcao);


        switch(opcao) {

            case 1:
                cadastrar();
                break;

            case 2:
                login();
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while(opcao != 0);

    return 0;
}
