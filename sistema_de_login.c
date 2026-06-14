#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char usuario[50];
    char senha[50];
} Conta;

int total = 0;

Conta conta[MAX];

int lerInteiro() {
    int valor;
    while (scanf("%d", &valor) != 1) {
        printf("\nEntrada invalida, insira um numero: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return valor;
}

void cadastrar() {
	
	if (total >= MAX) {
    printf("\nLimite de contas atingido!\n");
    return;
    }
	
    char usuario[50];
    char senha[50];
    int i;
    
    printf("\nUsuario: ");
    scanf(" %[^\n]", usuario);
    
    for (i = 0; i < total; i++) {
        if (strcmp(usuario, conta[i].usuario) == 0) {
            printf("\nUsuario ja cadastrado!\n");
            return;
        }
    }
    
    printf("\nSenha: ");
    scanf(" %[^\n]", senha);
    
    strcpy(conta[total].usuario, usuario);
    strcpy(conta[total].senha, senha);
    
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

void excluir() {
    char usuario[50];
    char senha[50];
    int encontrado = -1;
    int i;

    printf("\nInsira o Usuario e a Senha correta:\n");
    printf("\nUsuario: ");
    scanf(" %[^\n]", usuario);
    printf("\nSenha: ");
    scanf(" %[^\n]", senha);

    for (i = 0; i < total; i++) {
        if (strcmp(usuario, conta[i].usuario) == 0 && strcmp(senha, conta[i].senha) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nUsuario ou senha incorreta!\n");
        return;
    }

    for (i = encontrado; i < total - 1; i++) {
        conta[i] = conta[i + 1];
    }
    total--;

    printf("\nConta excluida com sucesso!\n");
}

void alterarSenha() {
	
    char usuario[50];
    char senha[50];
    char novaSenha[50];
    int encontrado = -1;
    int i;

    printf("\nInsira o Usuario e a Senha atual:\n");
    printf("\nUsuario: ");
    scanf(" %[^\n]", usuario);
    printf("\nSenha atual: ");
    scanf(" %[^\n]", senha);

    for (i = 0; i < total; i++) {
        if (strcmp(usuario, conta[i].usuario) == 0 && strcmp(senha, conta[i].senha) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nUsuario ou senha incorreta!\n");
        return;
    }

    do {
        printf("\nNova senha: ");
        scanf(" %[^\n]", novaSenha);

        if (strcmp(novaSenha, conta[encontrado].senha) == 0) {
            printf("\nSenhas iguais! Tente novamente:\n");
        }
    } while (strcmp(novaSenha, conta[encontrado].senha) == 0);

    strcpy(conta[encontrado].senha, novaSenha);
    printf("\nSenha alterada com sucesso!\n");
}

int main() {

    int opcao;

    do {
    	
    	printf("\n\nEscolha uma opcao:\n");
        printf("\n1 - Cadastrar\n2 - Login\n3 - Excluir conta\n4 - Alterar senha\n0 - Sair\n\n");
        opcao = lerInteiro();


        switch(opcao) {

            case 1:
                cadastrar();
                break;

            case 2:
                login();
                break;
                
            case 3:
            	excluir();
            	break;
            	
            case 4:
            	alterarSenha();
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
