#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int menu1(void);
int menu2(void);


int main() {
    int option1,option2;
    do{
        option1 = menu1();
        switch(option1){
            case 0:
                getch();
                break;
            case 1: 
                do{
                    option2 = menu2();
                    switch(option2){
                        case 0:
                            getch();
                            break;
                         case 1:            
                            getch();
                            break;
                        case 2:
                            getch();
                            break;
                        default:
                            break;                   
                    }
                }while(option2>0);           
                break;
            case 2:
                getch();
                break;
            case 3:
                getch();
                break;
            default:
                break;                   
        }
    }while(option1>0);
}

int menu1(void)
{
	int opt;
    system("cls"); //Limpa tela....	
	printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Cadastro do material\n");
	printf("2. Compra de material reciclado\n");
    printf("3. Histórico de compras\n");
    printf("Opcao: "); scanf("%d", &opt);        	
	return opt;
}

int menu2(void)
{
	int opt;
    system("cls"); //Limpa tela....	
	printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Cadastrar novo produto\n");
	printf("2. Materiais cadastrados\n");
    printf("Opcao: "); scanf("%d", &opt);        	
	return opt;
}
