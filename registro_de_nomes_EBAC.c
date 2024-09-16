#include <stdio.h> //biblioteca para inter��o com o usuario
#include <stdlib.h> //biblioteca para aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca da string

int registro()// fun��o para gegistrar um novo aluno
{
	// inicia as variaveis ultilizadas nesta fun��o
	char arquivo[11];
	char cpf[11];
	char nome[15];
	char sobrenome[15];
	char cargo[40];
	int loop = 1;
	
	while(loop==1)
	{
	
		system("cls");
		setlocale(LC_ALL, "portuguese"); // definindo a linguagem do texto a ser mostrado(portugu�s)
	
		printf("\t<<<<<Cadastro>>>>>\n\n\n");// titulo da tela
	
		printf("Digite o CPF: ");
		scanf("%s", cpf);// espera a entrada do cpf a ser inserido
	
		strcpy(arquivo, cpf);//copia o cpf para o arquivo, ou seja o cpf sera o localizador ddeste arquivo	
	
		FILE *file;//cria um arquivo
		file = fopen(arquivo, "r");// tenta abrir um arquivo com o cpf inserido
	
		if(file == NULL)// verifica se o cpf ja foi registrado
		{
			fclose(file);//fecha o arquivo anterior para n�o existir a possibilidade de erro
			file = fopen(arquivo, "w");//cria um arquivo com o cpf dado
			fprintf(file,cpf);//salva a variavel cpf no arquivo.
			fclose(file);//fecha o arquivo.
		
			file = fopen(arquivo, "a");
			fprintf(file,",");//adiciona uma seapara��o entre as informa��es
			fclose(file);
	
			printf("\n\nDigite o Primeiro nome: ");
			scanf("%s", nome); //espera o nome
			file = fopen(arquivo, "a");
			fprintf(file, nome);//adiciona o nome ao arquivo
			fclose(file);
		
			file = fopen(arquivo, "a");
			fprintf(file, ",");
			fclose(file);
	
			printf("\n\nDigite o sobrenome: ");
			scanf("%s", sobrenome); //espera o sobrenome
			file = fopen(arquivo, "a");
			fprintf(file, sobrenome);//adiciona o sobrenome 
			fclose(file);
	
			file = fopen(arquivo, "a");
			fprintf(file, ",");
			fclose(file);
	
			printf("\n\nDigite o cargo: ");
			scanf("%s", cargo);//espera o cargo deste nome
			file = fopen(arquivo, "a");
			fprintf(file, cargo);//adiciona o cargo ao arquivo
			fclose(file);
			printf("CPF cadastrado com sucesso!\n\n");//mostra caso o cpf ja tenha cadastro para n�o ocorrer duplicatas
			system("pause");//deixa a aplica��o em pausa para leitura das mensagens
		}
		else
		{
			fclose(file);
			printf("CPF j� foi cadastrado!\n\n");//mostra caso o cpf ja tenha cadastro para n�o ocorrer duplicatas
			system("pause");//deixa a aplica��o em pausa para leitura das mensagens
		}
		system("cls");
		loop = decisao();	
	}
}

int decisao()
{
	char escolha;//variavel que armazena a escolha do ususario
	int loop = 1;//variavel que mantem o loop caso a esccolha do usuario seja invalida
	
	setlocale(LC_ALL, "portuguese");

	while(loop==1)//inicio do loop
	{
		
		printf("deseja voltar ao menu? y/n\n");
		scanf(" %c", &escolha);// aguarda a decis�o do usuario
		
		switch(escolha)//manuseia a escolha
		{
			case 'y':
				return 0; //caso ele escolha y ou neste caso voltar ao menu ela retornara 0 para encerar o loop da fun��o que esta fun��o dara suporte 
			break;
			
			case 'n':
				return 1; //e aqui ele retornara 1 que mantera o loop intacto
			break;
			
			default:
				system("cls");
				printf("escolha invalida digite y para sim ou n para n�o\n");//mensagem caso a escolha seja invalida
		}
	}
}

int consulta()//fun��o para consultar as informa��es de um cpf
{
	//cria as variaveis usadas
	char cpf[11];
	char conteudo[200];
	char *token;//ponteiro para a fun��o strtok()
	int loop = 1;
	
	while(loop == 1)
	{
		system("cls");
		setlocale(LC_ALL, "portuguese");// define a lingua
	
		printf("\t<<<<Consultar informa��es.>>>>\n\n\n");//titulo
		printf("Digite o CPF: ");
		scanf("%s", cpf);//espera o cpf a ser consultado
	
		printf("\n\n\n");
		
		FILE *file;
		file = fopen(cpf, "r");// tenta abrir o arquivo deste cpf
	
		if(file == NULL)
		{
			printf("CPF n�o foi encontrado.\n\n");// caso n�o encontre este arquivo
		}
		else
		{
			printf("Informa��es: \n\n");
		
			while(fgets(conteudo, 200, file) != NULL ){// coloca todas as informa��es do arquivo na string conteudo
			}
			token = strtok(conteudo, ",");//separa a string pela <,> que foi o que usamos no registro para separar informa��es
			printf("\tCPF: ");
			printf("%s\n", token);//mostra a primeira informa��o
			token = strtok(NULL, ","); // usando NULL aqui o ponteiro token passa a conter a proxima informa��o nesse caso o nome
			printf("\tNome: ");
			printf("%s", token);
			token = strtok(NULL, ",");// segue a mesma logica do anterior
			printf(" %s\n", token);
			token = strtok(NULL, ",");// segue a mesma logica do anterior
			printf("\tCargo: ");
			printf("%s\n\n", token);
		}
		
		fclose(file);
		system("pause");
		loop = decisao();
	}
}

int deletar() //fun��o para deletar
{
	char cpf[11];
	char confirmar;
	int loop = 1;
	
	while(loop == 1)
	{
		system("cls");
		setlocale(LC_ALL, "portuguese");// define a lingua
	
		printf("\t<<<<Deletar cadastro.>>>>\n\n\n");//titulo
	
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", cpf);// espera o cpf a ser deletado
	
		FILE *file;
		file = fopen(cpf, "r"); //tenta abrir o arquivo deste cpf
		fclose(file);
	
		if(file == NULL)// verifica se o arquivo existe ou n�o
		{
			printf("\n\nCPF n�o encontrado!\n\n");//mensagem caso n�o encontre o cpf
			system("pause");

		}
		else
		{
			printf("\n\nTem certeza que quer deletar o CPF %s?", cpf);// pede a confirma��o para deletar o cpf
			scanf(" %c", &confirmar);
		
			if(confirmar == 'y')
			{
				remove(cpf);// remove o cpf 
				printf("\n\nCPF deletado com sucesso!\n");
				system("pause");
			
			}
			else
			{
				printf("\n\nExclus�o cancelada!\n");//mensagem se a exclus�o for cancelada
				system("pause");
			}		
		}
		system("cls");
		loop = decisao();
	}
	
	
}

int main()
{
	int escolha = 0;
	char sair[3];
	int loop = 1;
	char senhadigitada[10] = "a";
	int comparacao = 1;
	
	printf("########  Registro de Nomes EBAC  ########\n\n");
	
	printf("acesso do adiministrador\n");
	printf("Digite a senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	
	if(comparacao == 0)
	{
		for(loop =1;loop=1;)
		{
		
			system("cls");//limpa a tela
		
			setlocale(LC_ALL, "portuguese");
	
			printf("########  Registro de Nomes EBAC  ########\n\n");//titulo da aplica��o
		
			//tela de menu
			printf("Digite o n�mero da op��o desejada:\n\n");
	
			printf("\tDigite 1 para cadastrar novo Nome.\n\n\tDigite 2 para consultar os dados. \n\n\tDigite 3 para excluir um cadastro.\n\n\tDigite 4 para sair do sistema.\n\n\n\n");//op��es a serem escolhidas
	
			printf("Op��o: ");
			scanf("%d", &escolha);//esperando o usuario escolher a op��o
		
			system("cls");//limpa a tela
	
			switch(escolha)//inicio da escolha
			{
		
				case 1:
					registro();//chamda de fun��o registro
				break;
			
				case 2:
					consulta();//chamada de fun��o consulta
				break;
			
				case 3:
					deletar();//chamada de fun��o deletar
				break;
			
				case 4:
					printf("Obrigado por usar este sistema!!");
					return 0;
				break;
			
				default:
					printf("\tOp��o n�o esta disponivel no menu.\n\n\n");//fim da escolha
					system("pause");
				break;
			}
		}
	}
	else
	{
		printf("senha errada.");
	}
	
	
	

}
