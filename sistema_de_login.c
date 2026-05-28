#include <stdio.h>
#include <string.h>

typedef struct {
    char usuario[50];
    char senha[50];
} Conta;

Conta conta;

void cadastrar() {

    printf("\nUsuario: ");
    scanf(" %[^\n]", conta.usuario);

    printf("\nSenha: ");
    scanf(" %[^\n]", conta.senha);

    printf("\nConta cadastrada com sucesso!\n");
}

void login() {

    char usuario[50];
    char senha[50];

    printf("\nUsuario: ");
    scanf(" %[^\n]", usuario);

    printf("\nSenha: ");
    scanf(" %[^\n]", senha);

    if (strcmp(usuario, conta.usuario) == 0 &&
        strcmp(senha, conta.senha) == 0) {

        printf("\nLogin realizado com sucesso!\n");

    } else {

        printf("\nUsuario ou senha incorretos!\n");
    }
}

int main() {

    int opcao;

    do {

        printf("\n1 - Cadastrar");
        printf("\n2 - Login");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma opcao: ");
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
