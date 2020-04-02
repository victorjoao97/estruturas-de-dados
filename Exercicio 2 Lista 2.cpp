#include <stdio.h>
#include <string.h>

struct Aluno
{
	char nome[50];
	float nota1, nota2, nota3, nota4;
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

void ler(int *_int, float *_float)
{
	if(_int != 0)
	{
		scanf("%d", _int);
	}else if(_float != 0)
	{
		scanf("%f", _float);
	}
}

float calcMedia(struct Aluno aluno)
{
	return (aluno.nota1 + aluno.nota2 + aluno.nota3 + aluno.nota4) / 4;
}

void verResultado(struct Aluno aluno)
{
	printf("%s", calcMedia(aluno) <= 5 ? "Reprovado" : "Aprovado");
}

void lerNotas(struct Aluno *alunos)
{
	digite("a nota 1: ");
	ler(0, &alunos->nota1);
	digite("a nota 2: ");
	ler(0, &alunos->nota2);
	digite("a nota 3: ");
	ler(0, &alunos->nota3);
	digite("a nota 4: ");
	ler(0, &alunos->nota4);
}

int main()
{
	int opcao, contador = 0;
	struct Aluno alunos[20];
	
	do{
		printf("\n\nDigite uma opcao\n\n1 - Cadastrar alunos\n2 - Media de determinado aluno\n3 - Visualizacao de aprovados e reprovados\n4 - Sair\n\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				if(contador < 20){
					puts("Cadastrar aluno\n");
					digite("o nome do aluno");
					lerString(alunos[contador].nome);
					lerNotas(&alunos[contador]);
					printf("\nAluno cadastrado com sucesso\n");
					contador++;
				}else{
					printf("Voce ja cadastrou o total de alunos");
				}
				break;
			case 2:
				char nome[50];
				digite("o nome de um aluno");
				lerString(nome);
				
				for (int i = 0; i < contador; i++){
					if(strcmp(alunos[i].nome, nome) == 0){
						printf("---Media de um aluno----");
						printf("\nNome do aluno: %s", alunos[i].nome);
						printf("\nMedia: %.2f", calcMedia(alunos[i]));
					}
				}
				break;
			case 3:
				printf("----Mostrando todos os alunos---");
				for (int i = 0; i < contador; i++){
					printf("\nNome do aluno: %s", alunos[i].nome);
					printf("\nMedia: %.2f\n", calcMedia(alunos[i]));
					verResultado(alunos[i]);
				}
				break;
			case 4:
				puts("\n------Saindo do Sistema-----");
				break;
			default:
				puts("\nOpcao invalida\n");
				break;
		}
	}while(opcao != 4);
	
	getchar();
	return 0;
}