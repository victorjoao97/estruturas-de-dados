#include <stdio.h>
#include <string.h>

struct Funcionario
{
	char nome[50];
	int numDep, horasTrab;
	float salHora;
};

void digite(const char texto[])
{
	printf("Digite %s: ", texto);
}

void lerString(char *variavel)
{
	fflush(stdin);
	gets(variavel);
}

void ler(int *_int, float *_float, char tipo)
{
	switch(tipo)
	{
	case 'd':
		scanf("%d", _int);
		break;
	case 'f':
		scanf("%f", _float);
		break;
	default:
		break;
	}
}

float calcSalBruto(struct Funcionario func){
	return func.salHora * func.horasTrab + (108.0 * func.numDep);
}

float calcINSS(struct Funcionario func){
	float salBruto = calcSalBruto(func);
	return salBruto < 1500 ? salBruto * 0.1 : 100;
}

float calcIR(struct Funcionario func){
	float salInss = calcSalBruto(func) - calcINSS(func);
	if(salInss <= 950)
	{
		return 0;
	}else if(salInss <= 2500)
	{
		return salInss * 0.1;
	}else{
		return salInss * 0.2;
	}
}

float calcLiq(struct Funcionario func){
	return calcSalBruto(func) - calcINSS(func) - calcIR(func);
}

int main()
{
	int continuar = 1;
	printf("------Calculo de Salario de Funcionarios-----\n");
	do{
		struct Funcionario func;
		digite("o nome");
		lerString(func.nome);
		digite("o valor do salario por hora");
		ler(0, &func.salHora,'f');
		digite("o numero de dependentes");
		ler(&func.numDep, 0,'d');
		digite("as horas trabalhadas");
		ler(&func.horasTrab, 0, 'd');
		
		printf("Dados do funcionario: %s", func.nome);
		printf("\nSalario Bruto: %.2f", calcSalBruto(func));
		printf("\nDesconto INSS: %.2f", calcINSS(func));
		printf("\nDesconto IR: %.2f", calcIR(func));
		printf("\nSalario Liquido: %.2f", calcLiq(func));
		
		puts("\n\nDeseja continuar? 1 [s] - 0 [n]: ");
		ler(&continuar, 0, 'd');
	} while(continuar != 0);
	printf("-------Encerrando programa-------");
	return 0;
}