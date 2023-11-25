#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <locale.h>
#include<ctype.h>
#include<string.h> 

typedef struct {	

	int codigo_item;
	char nome_item[30] ;
	char tipo_item[30] ;
	float preco_item;
	float quantidade_item;
	char nome_fornecedor[30];
	
} ITEM;

//----------- DECLARACAO DAS SUBROTINAS ---------------------
int menu1(void);
int menu2(void);
int menu3(void);
int cadastro_item(int n, ITEM f[100]);
void consuta_item(int n, ITEM f[100]);
void historico_compras(int m, ITEM f[100]);
void menu_compra_materiais(int n, ITEM f[100]);
int compra_materiais(int n, ITEM f[100], int m, ITEM hf[100]);
void consulta_estoque(int n, ITEM f[100]);
//-----------------------------------------------------------


//----------- ROTINA CADASTRO DE ITENS ----------------------
int cadastro_item(int n, ITEM f[100])
{
	int i, val_codigo_item;
	bool val_codigo_item_nok = 0;	
	int val_tipo_item = 0;
	bool val_tipo_item_ok = 0;		
	char novo_item;
	
	do { 											//Recebe e valida confirmacao de novo item para ser cadastrado	
																		
		do { 										//Recebe e valida o codigo do item= 0 a 999			
			system("cls"); //Limpa tela....		
			printf("\n================================================================================================================ ");
			printf("\n==================================== CADASTRO DE MATERIAIS RECICLADOS ========================================== ");
			printf("\n================================================================================================================\n\n ");
	
			printf("A. Codigo do item: ");
			scanf("%d", &val_codigo_item);
			if ((val_codigo_item<=0) || (val_codigo_item>999)) {    
				printf("\n Código incorreto, digite novamente."); 
				getch();
				system ("cls");				
			} else { 	
				val_codigo_item_nok = false;	
				for (i=0; i<n; i++) {    				
					if (val_codigo_item == f[i].codigo_item) { 
						val_codigo_item_nok = true;			
					}
				}
				if (val_codigo_item_nok == true) { 
					printf("\n Código digitado já foi cadastrado, tente novamente..."); 
					getch();
					system ("cls");				
				} else {
					f[n].codigo_item = val_codigo_item;
				}		
			}

		} while ((val_codigo_item<=0) || (val_codigo_item>999) || (val_codigo_item_nok == true));
			
		do { 	                                   //Recebe valida o tipo do item
			system("cls"); //Limpa tela....		
			printf("\n================================================================================================================ ");
			printf("\n==================================== CADASTRO DE MATERIAIS RECICLADOS ========================================== ");
			printf("\n================================================================================================================\n\n ");
			
			printf("B. Tipo do item: \n\n");
			printf(" 1= Plástico \n");	
			printf(" 2= Papel \n");
			printf(" 3= Vidro \n");
			printf(" 4= Metal \n");	
			printf(" 5= Madeira \n");
			printf(" 6= Lixo orgânico \n");
			printf(" 7= Lixo não recicláveis \n");
			printf(" 8= Lixo Radioativo \n");
			printf(" 9= Lixo Hospitalar \n");
			printf(" 10= Pilhas e Baterias \n");
			scanf("%d", &val_tipo_item);		
					
			switch (val_tipo_item)
    		{
				case 1:
					strcpy (f[n].tipo_item, "Plastico");
					val_tipo_item_ok = true;
					break;
					
				case 2:
					strcpy (f[n].tipo_item, "Papel");
					val_tipo_item_ok = true;
					break;
					
				case 3:
					strcpy (f[n].tipo_item, "Vidro");
					val_tipo_item_ok = true;
					break;
					
				case 4:
					strcpy (f[n].tipo_item, "Metal");
					val_tipo_item_ok = true;
					break;
					
				case 5:
					strcpy (f[n].tipo_item, "Madeira");
					val_tipo_item_ok = true;
					break;
					
				case 6:
					strcpy (f[n].tipo_item, "Lixo Orgânico");	
					val_tipo_item_ok = true;
					break;
					
				case 7:
					strcpy (f[n].tipo_item, "Lixo Não Orgânico");	
					val_tipo_item_ok = true;
					break;
					
				case 8:
					strcpy (f[n].tipo_item, "Lixo Radioativo");
					val_tipo_item_ok = true;
					break;
					
				case 9:
					strcpy (f[n].tipo_item, "Lixo Hospitalar");	
					val_tipo_item_ok = true;
					break;
					
				case 10:
					strcpy (f[n].tipo_item, "Pilhas e Baterias");
					val_tipo_item_ok = true;
					break;
					
				default:
					val_tipo_item_ok = false;
					break;
			};
			if (val_tipo_item_ok == false) {
				printf("\n Tipo do item inválido, digite novamente."); 
				getch();
				system ("cls");				
			}		
		} while (val_tipo_item_ok == false);
		
		system("cls"); //Limpa tela....		
		printf("\n================================================================================================================ ");
		printf("\n==================================== CADASTRO DE MATERIAIS RECICLADOS ========================================== ");
		printf("\n================================================================================================================\n\n ");
		
		printf("C. Nome: "); 						//Recebe nome do item
		fflush(stdin);
		gets (f[n].nome_item);
			
		do { 										//Recebe e valida o preco do kg do item > 0
			system("cls"); //Limpa tela....		
			printf("\n================================================================================================================ ");
			printf("\n==================================== CADASTRO DE MATERIAIS RECICLADOS ========================================== ");
			printf("\n================================================================================================================\n\n ");
		
			printf("D. Valor do kg do item: ");
			scanf("%f", &f[n].preco_item);
			if (f[n].preco_item<=0) {
				printf("\n Valor não pode ser zerado, digite novamente.");
				getch();
				system ("cls");			
			}
		} while (f[n].preco_item<=0);
		
		do { 										//Recebe e valida a quantidade do item em kg >= 0
			system("cls"); //Limpa tela....		
			printf("\n================================================================================================================ ");
			printf("\n==================================== CADASTRO DE MATERIAIS RECICLADOS ========================================== ");
			printf("\n================================================================================================================\n\n ");
		
			printf("E. Quantidade em kg do item: ");
			scanf("%f",  &f[n].quantidade_item);
			if (f[n].quantidade_item < 0) {
				printf("\n Valor não pode ser zerado, digite novamente.");
				getch();
				system ("cls");			
			}
		} while (f[n].quantidade_item < 0);	
		
		n++;                                        //Incrementa para salvar o proximo item da lista
	
		do {										//Recebe e valida confirmacao de novo item para ser cadastrado
			system("cls"); //Limpa tela....	
			printf("\n\n Deseja cadastrar um novo item? "); 
			printf("\n S= Sim / N= Não \n"); 			
			novo_item = tolower(getche());
		
			if ((novo_item != 's') && (novo_item != 'n')) {
				system("cls"); //Limpa tela....
				printf("\n Dado inválido, digite novamente"); 	
				getch();
			}
		}  while ((novo_item !='s') && (novo_item !='n'));				
	} while (novo_item =='s');
	return n;
}


//----------- ROTINA CONSULTA DE MATERIAIS CADASTRADOS ----------------------
void consulta_item(int n, ITEM f[100])
{
	int i;
	system("cls"); //Limpa tela....	
	printf("\n================================================================================================================ ");
	printf("\n=================================== RELATORIO DE MATERIAIS CADASTRADOS ========================================= ");
	printf("\n================================================================================================================\n\n ");
	
	if (n==0) {										//Verifica se existe algum item cadastrado
		printf("******   Desculpe, não contém nenhum item cadastrado   ******");
		printf("\n\n================================================================================================================\n\n ");
		getch();
		system ("cls");	
	} else {
		printf("ITENS CADASTRADOS = %d \n",n);		
    	for(i=0; i<n ; i++)						    //Laco para impressao dos itens cadastrados
  		{	
  			printf("\n---------------------------------------------------------------------------------------------------------------- ");
	   		printf("\nITEM: %d   |   Codigo: %d   |   Nome: %s   |   Tipo: %s   |   Preco kg: R$%.2f reais   |   Quantidade: %.2f Kg ",i+1 ,f[i].codigo_item, f[i].nome_item, f[i].tipo_item, f[i].preco_item, f[i].quantidade_item);
	   		printf("\n---------------------------------------------------------------------------------------------------------------- ");
		}
		getch();
		system ("cls");
	}
}



//----------- ROTINA HISTÓRICO DE COMPRAS ----------------------
void historico_compras(int m, ITEM hf[100])
{
	int i;
	system("cls"); //Limpa tela....	
	printf("\n=================================================================================================================================================================");
	printf("\n==================================== RELATÓRIO DO HISTÓRICO DE COMPRAS ========================================================================================== ");
	printf("\n=================================================================================================================================================================\n\n ");
	
	if (m==0) {										//Verifica se existe alguma compra efetuada
		printf("******   Desculpe, não foi realizada nenhuma compra   ******");
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n ");
		getch();
		system ("cls");	
	} else {
		printf("ITENS COMPRADOS = %d \n",m);		
    	for(i=0; i<m ; i++)							//Laco para impressao das compras efetuadas
  		{	
  			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------- ");
	   		printf("\nITEM: %d   |   Codigo: %d   |   Nome: %s   |   Tipo: %s   |   Valor pago (kg): R$%.2f reais   |   Quantidade: %.2f Kg   |   Nome do fornecedor: %s ",i+1 ,hf[i].codigo_item, hf[i].nome_item, hf[i].tipo_item, hf[i].preco_item, hf[i].quantidade_item, hf[i].nome_fornecedor);
	   		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n ");
		}
		getch();
		system ("cls");
	}
}





//----------- ROTINA COMPRA DE MATERIAIS ----------------------
int compra_materiais(int n, ITEM f[100], int m, ITEM hf[100])
{
	int i, codigo, cont=0;
	float quantidade;
	char confirma_compra;
	
	system("cls"); //Limpa tela....	
	printf("\n================================================================================================================ ");
	printf("\n===================================== COMPRA DE MATERIAIS RECICLADOS =========================================== ");
	printf("\n================================================================================================================\n\n ");
	
	if (n==0) {										//Verifica se existe algum item cadastrado
		printf("******   Desculpe, não contém nenhum produto em estoque para venda   ******");
		printf("\n\n================================================================================================================\n\n ");
		getch();
		system ("cls");	
	} else {		
		printf("1. Digite o código do produto: ");
		scanf("%d", &codigo);	
    	for(i=0; i<n ; i++)	{	
  			if (codigo == f[i].codigo_item) {		                              //Verifica se o codigo digitado já foi cadastrado pelo sistema e imprime oas dados relacionados a ele
  				printf("\n---------------------------------------------------------------------------------------------------------------");
	   			printf("\nITEM: %d   |   Codigo: %d   |   Nome: %s   |   Tipo: %s   |   Preco kg: R$%.2f reais   |   Quantidade: %.2f Kg ",i+1 ,f[i].codigo_item, f[i].nome_item, f[i].tipo_item, f[i].preco_item, f[i].quantidade_item);
	   			printf("\n---------------------------------------------------------------------------------------------------------------\n\n ");
	   			cont++;
	   			
	   			do {								                              //Recebe e valida a quantidade informada para compra maior do que zero
	   				printf("2. Digite a quantidade desejada em (kg): ");
	   				scanf("%f", &quantidade);
	   				if (quantidade <= 0) {
	   					printf("\n Valor inválido, valor de compra não pode ser zero");
	   					getch();
						system ("cls");			   	
					}
				} while (quantidade <= 0);
				
				printf("\n 3. Nome do Fornecedor: ");                             //Recebe nome do fornecedor
				fflush(stdin);
				gets (f[i].nome_fornecedor);
				
				printf("\n O valor pago por %.2f kg do código %d é de %.2f reais", quantidade, f[i].codigo_item, f[i].preco_item * quantidade);
				
				do {								                             //Recebe e valida confirmacao de compra efetuada
					printf("\n\n Deseja confirmar a compra? "); 
					printf("\n S= Sim / N= Não \n"); 			
					confirma_compra = tolower(getche());
		
					if ((confirma_compra !='s') && (confirma_compra !='n')) {
						system("cls"); //Limpa tela....
						printf("\n Dado inválido, digite novamente"); 	
						getch();
					}
				}  while ((confirma_compra !='s') && (confirma_compra !='n'));
				
				if (confirma_compra =='s') {
					f[i].quantidade_item= (f[i].quantidade_item + quantidade);	// Atualiza quantidade de estoque do item
	
					hf[i] = f[i];                                               // Carrega os dados para o histórico de compras
					hf[i].quantidade_item = quantidade;                         // Carrega a quantidade atual da compra para o historico
					hf[i].preco_item = hf[i].preco_item * quantidade ;			// Calcula valor pago na compra para o historico
					
					m++;                                                        //Incrementa quantidade de itens comprados
				}							
			} else {
				
			printf("\n Produto desejado indisponível ");
			getch();
			system ("cls");
			
			}
		}				
	}
	return m;
}


//----------- ROTINA CONSULTA DE ESTOQUE ----------------------
void consulta_estoque(int n, ITEM f[100])
{
	int i, cont=0;
	
	system("cls"); //Limpa tela....	
	printf("\n================================================================================================================ ");
	printf("\n=========================================== CONSULTA DE ESTOQUE ================================================ ");
	printf("\n================================================================================================================\n\n ");

  																				//Laco para impressao das itens cadastrados
    for(i=0; i<n ; i++) {	
  		if (f[i].quantidade_item > 0) {
  			printf("\n---------------------------------------------------------------------------------------------------------------- ");
	   		printf("\nITEM: %d   |   Codigo: %d   |   Nome: %s   |  Tipo: %s   |   Preco kg: R$%.2f reais   |  Quantidade: %.2f Kg ",i+1 ,f[i].codigo_item, f[i].nome_item, f[i].tipo_item, f[i].preco_item, f[i].quantidade_item);
	   		printf("\n---------------------------------------------------------------------------------------------------------------- ");
	   		cont++;
		}
	}

	if (cont<=0) {																//Verifica se existem itens cadastradoa
		system("cls"); //Limpa tela....	
		printf("\n================================================================================================================ ");
		printf("\n============================================== CONSULTA DE ESTOQUE ============================================= ");
		printf("\n================================================================================================================\n\n ");
		
		printf("******   Desculpe, não contém nenhum produto em estoque para venda   ******");	
		printf("\n\n================================================================================================================\n\n ");				
	}
	getch();
}


//----------- ROTINA MENU PRINCIPAL ----------------------
int menu1(void)
{
	int opt;
    system("cls"); //Limpa tela....	
    printf("\n================================================================================================================ ");
	printf("\n================================================ MENU PRINCIPAL ================================================ ");
	printf("\n================================================================================================================\n\n ");
    printf("0. SAIR\n");
    printf(" 1. CADASTRO DE MATERIAIS\n");
	printf(" 2. COMPRA DE MATERIAIS RECICLADOS\n");
    printf(" 3. HISTÓRICO DE COMPRAS\n");
    printf(" Opcao: "); scanf("%d", &opt);        	
	return opt;
}

//----------- ROTINA MENU SECUNDARIO ----------------------
int menu2(void)
{
	int opt;
    system("cls"); //Limpa tela....	
    printf("\n================================================================================================================ ");
	printf("\n================================================ MENU CADASTRO =================================================");
	printf("\n================================================================================================================\n\n ");
    printf("0. VOLTAR\n");
    printf(" 1. CADASTRAR NOVO PRODUTO\n");
	printf(" 2. MATERIAIS CADASTRADOS\n");
    printf(" Opcao: "); scanf("%d", &opt);        	
	return opt;
}

//----------- ROTINA MENU COMPRAS DE MATERIAIS ----------------------
int menu3(void)
{
	int opt;
	system("cls"); //Limpa tela....	
    printf("\n================================================================================================================ ");
	printf("\n============================================= MENU COMPRA E ESTOQUE ============================================ ");
	printf("\n================================================================================================================\n\n ");
	printf("0. VOLTAR\n");
    printf(" 1. COMPRA DE MATERIAIS\n");
	printf(" 2. CONSULTA ESTOQUE DE MATERIAIS\n");
    printf(" Opcao: "); scanf("%d", &opt);        	
	return opt;				
}

int main() {
	
    int option1,option2,option3;
    int total_item=0, total_compras=0;
	ITEM fun[100]={0};
	ITEM hist_fun[100]={0};
	setlocale(LC_ALL, "Portuguese");
     
    do {
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
                            break;
                        case 1:            
                           	total_item = cadastro_item(total_item, fun);
                           	break;
                        case 2:
                            consulta_item(total_item, fun);
                            break;
                        default:
                            break;                   
                    }
                }while(option2>0);           
                break;
            case 2:
            	do{
                    option3 = menu3();
                    switch(option3){
                        case 0:
                            break;
                        case 1:            
                            total_compras = compra_materiais(total_item, fun, total_compras, hist_fun);
                           	break;
                        case 2:
                            consulta_estoque(total_item, fun);
                            break;
                        default:
                            break;                   
                    }
                }while(option3>0);  
                break;
            case 3:
            	historico_compras(total_compras, hist_fun);
                break;
            default:
                break;                   
        }
    } while(option1>0);
}
