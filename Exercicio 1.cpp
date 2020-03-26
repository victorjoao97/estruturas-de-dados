#include <stdio.h>
#include <string.h>
	
struct Conta
{
	int numConta;
	char nomeCliente[30];
	float saldo;
};

int main()
{
	int op, contador = 0;
	
	float menorSaldo = 9999999.9;
	int posMenorSaldo = 0;
	
	struct Conta contas[15];
	
	do
	{
		printf("\n\nDigite uma opcao\n\n1 - Cadastrar contas\n2 - Visualizar toda as contas\n3 - Visualizar a conta de determinado cliente\n4 - Mostrar a conta com o menor saldo\n5 - Sair\n\n");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				if(contador < 3){
					for (int i = 0; i < 3; i++){
						int numConta;
						printf("\nDigite o numero da conta: ");
						scanf("%d", &numConta);
						
						bool existeConta = false;
						for(int j = 0; j < 3; j++){
							if(numConta == contas[j].numConta){
								printf("\nJa existe uma conta com este numero\n");
								i--;
								existeConta = true;
								break;
							}
						}
						if(existeConta){
							continue;
						}else{
							contas[i].numConta = numConta;
							fflush(stdin);
							printf("\nDigite o nome do cliente: ");
							gets(contas[i].nomeCliente);
							printf("\nDigite o saldo do cliente: ");
							scanf("%f", &contas[i].saldo);
							contador++;
						}
					}
					printf("\nConta cadastrada com sucesso");
				}else{
					printf("Voce ja cadastrou o total de contas");
				}
				break;
			case 2:
				for (int i = 0; i < 3; i++){
					printf("\n\nDados da conta");
					printf("\nNumero da conta: %d", contas[i].numConta);
					printf("\nNome do cliente: %s", contas[i].nomeCliente);
					printf("\nSaldo do cliente: %.2f", contas[i].saldo);
				}
				
				break;
			case 3:
				char nomeCliente[30];
				printf("\nDigite o nome de um cliente: ");
				fflush(stdin);
				gets(nomeCliente);
				
				for (int i = 0; i < 3; i++){
					if(strcmp(contas[i].nomeCliente, nomeCliente) == 0){
						printf("Dados da conta");
						printf("\nNumero da conta: %d", contas[i].numConta);
						printf("\nNome do cliente: %s", contas[i].nomeCliente);
						printf("\nSaldo do cliente: %.2f", contas[i].saldo);
					}
				}
				break;
			case 4:
				for (int i = 0; i < 3; i++){
					if(contas[i].saldo < menorSaldo){
						menorSaldo = contas[i].saldo;
						posMenorSaldo = i;
					}
				}
				printf("\n\n A conta com menor saldo: \nNumero da conta: %d\nNome: %s\nSaldo: %.2f\n", contas[posMenorSaldo].numConta, contas[posMenorSaldo].nomeCliente, contas[posMenorSaldo].saldo);
				break;
			default:
				break;
		}
	}while(op != 5);
	
	getchar();
	return 0;
}