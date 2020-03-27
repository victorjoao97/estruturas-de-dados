#include <stdio.h>

struct Funcionario
{
	int codigo;
	char nome[50];
	int anoAdmissao;
	char cargo[20];
	float salarioBase;
	int faltas;
};

void leituraDados(struct Funcionario *func)
{
	printf("\nDigite os dados do funcionario\n");
	printf("Digite o codigo: ");
	scanf("%d", &func->codigo);
	printf("Digite o nome: ");
	fflush(stdin);
	gets(func->nome);
	printf("Digite o ano de admissao: ");
	scanf("%d", &func->anoAdmissao);
	printf("Digite o cargo: ");
	fflush(stdin);
	gets(func->cargo);
	printf("Digite o salario-base: ");
	scanf("%f", &func->salarioBase);
	printf("Digite as faltas nesse ano: ");
	scanf("%d", &func->faltas);
	printf("\nFuncionario cadastrado com sucesso\n");
}

void verificarFuncionarios(struct Funcionario func[],int contador)
{
	int qtdFaltas = 0;
	float salarioMin = 0.0, salarioMax = 0.0;
	
	printf("\nFiltrar funcionarios por salario e quantidade de faltas\n");
	printf("Digite o salario minimo: ");
	scanf("%f", &salarioMin);
	printf("Digite o salario maximo: ");
	scanf("%f", &salarioMax);
	printf("Digite a quantidade de faltas: ");
	scanf("%d", &qtdFaltas);
	
	printf("\nFuncionarios com salario entre %.2f e %.2f, com mais de %d de faltas", salarioMin, salarioMax, qtdFaltas);
	
	for (int i = 0; i < contador; i++){
		if(func[i].salarioBase > salarioMin && func[i].salarioBase < salarioMax && func[i].faltas > qtdFaltas)
		{
			printf("\n\nDados do funcionario");
			printf("\nCodigo: %d", func[i].codigo);
			printf("\nNome: %s", func[i].nome);
			printf("\nAno de Admissao: %d", func[i].anoAdmissao);
			printf("\nCargo: %s", func[i].cargo);
			printf("\nSalario base: %.2f", func[i].salarioBase);
			printf("\nFaltas: %d", func[i].faltas);	
		}
	}
}

int main()
{
	int op, contador = 0;
	struct Funcionario func[999];
	
	do
	{
		printf("\n\nDigite uma opcao\n\n1 - Cadastrar funcionarios\n2 - Funcionarios com determinado salario, e quantidade de faltas\n3 - Sair\n\n");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				if(contador < 999){
					leituraDados(&func[contador]);
					contador++;
				}else{
					printf("\nLimite de funcionarios cadatrados\n");
				}
				break;
			case 2:
				verificarFuncionarios(func, contador);				
				break;
			case 3:
				printf("\nFechando programa");
				break;
			default:
				break;
		}
	}while(op != 3);
	
	getchar();
	return 0;
}