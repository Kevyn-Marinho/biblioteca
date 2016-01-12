#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void linha(char nomeMetodo[50]){
	printf("\n\n******************** %s ********************\n\n", nomeMetodo);
}

                                             /* Consulente */

	typedef struct Consulente{
		int telC,cepC,regiC;
		char nomeC[50],rgC[10],ruaC[50],compC[50],cpfC[12];
		int nLivrosEmprestados;
		int status;
	}Consulente;

int regC=0, op=0, i=0, teste=0, valida=0, pesRegC=0;
Consulente bdconsulente[100];
int inativaC = 0;
int validaNLivros = 0;
char pesCpf[12];
char pesRegC1[10];
char aNome[50] = "";

int inConsulente(){
	linha("Cadastro de Consulente");

	struct Consulente consulente;

	fflush(stdin);
	printf("\nNome:");
	gets(consulente.nomeC);

	printf("\nRG: ");
	gets(consulente.rgC);
	int len=0;

	len = strlen(consulente.rgC);

	while(len>=10){
		printf("Numero de RG invalido, digite novamente: ");
		gets(consulente.rgC);
		len = strlen(consulente.rgC);
	}

	len = 0;

	for (i=0;i<100;i++){
		len = strcmp(bdconsulente[i].rgC, consulente.rgC);
		if(len == 0 )
			{
				printf("Numero de RG já cadastrado, digite novamente: ");
				gets(consulente.rgC);
			}
	}
	printf("\nCPF: ");
	scanf("%s",&consulente.cpfC);

	printf("\nTelefone: ");
	fflush(stdin);
	scanf("%d",&consulente.telC);

	fflush(stdin);
	printf("\nRua: ");
	gets(consulente.ruaC);

	printf("\nCEP: ");
	scanf("%d",&consulente.cepC);
	fflush(stdin);

	printf("\nComplemento: ");
	gets(consulente.compC);

	consulente.nLivrosEmprestados = 0;
	consulente.status = 1;

	bdconsulente[regC] = consulente;
	regC++;
	bdconsulente[regC-1].regiC = regC;

	printf("\nRegistro...: %d", bdconsulente[regC-1].regiC);
	printf("\nNome.......: %s", bdconsulente[regC-1].nomeC);
	printf("\nRG.........: %s", bdconsulente[regC-1].rgC);
	printf("\nCPF........: %s", bdconsulente[regC-1].cpfC);
	printf("\nTelefone...: %d", bdconsulente[regC-1].telC);
	printf("\nRua:.......: %s", bdconsulente[regC-1].ruaC);
	printf("\nCEP:.......: %d", bdconsulente[regC-1].cepC);
	printf("\nComplemento: %s", bdconsulente[regC-1].compC);

	printf("\n\nContinuar cadastrando? \n[1] - Sim\n[2] - Nao\nResp.:");
	scanf("%d",&op);
	if (op==1){
		return 1;
	} else {
		return 2;
	}
}

int pesConsulente (){
char pesNome [50], pesRG[10];
		while (op!=5)
		{
			linha("Pesquisa de Consulente");
			printf("[1] - Pesquisar por Nome\n");
			printf("[2] - Pesquisar por RG\n");
			printf("[3] - Pesquisar por CPF\n");
			printf("[4] - Pesquisar por RA\n");
			printf("[5] - Pesquisar Todos\n");
			printf("[6] - Sair \n");
			printf("\nResp.: ");
			scanf("%d",&op);
			fflush(stdin);
			switch(op)
			{
			case 1:
				printf("\n\nDigite NOME para pesquisa: ");
				gets(pesNome);
				teste=0;
				for (i=0; i<100; i++)
				{
					if (strcmp(bdconsulente[i].nomeC,pesNome)==0)
					{
						printf("\nRA.........: %d", bdconsulente[i].regiC);
						printf("\nNome.......: %s", bdconsulente[i].nomeC);
						printf("\nRG.........: %s", bdconsulente[i].rgC);
						printf("\nCPF........: %s", bdconsulente[i].cpfC);
						printf("\nTelefone...: %d", bdconsulente[i].telC);
						printf("\nRua:.......: %s", bdconsulente[i].ruaC);
						printf("\nCEP:.......: %d", bdconsulente[i].cepC);
						printf("\nComplemento: %s", bdconsulente[i].compC);

						printf("\n\n---------------------------------------");

					}else{
						teste++;
						if(teste==99)
							printf("\n\nConsulente nao encontrado.\n");
					}
				}
			break;

			case 2:
				fflush(stdin);
				printf("\n\nDigite RG para pesquisa: ");
				gets(pesRG);
				teste=0;
				for (i=0; i<100; i++)
				{
					if (strcmp(bdconsulente[i].rgC, pesRG)==0)
					{
						printf("\nRA.........: %d", bdconsulente[i].regiC);
						printf("\nNome.......: %s", bdconsulente[i].nomeC);
						printf("\nRG.........: %s", bdconsulente[i].rgC);
						printf("\nCPF........: %s", bdconsulente[i].cpfC);
						printf("\nTelefone...: %d", bdconsulente[i].telC);
						printf("\nRua:.......: %s", bdconsulente[i].ruaC);
						printf("\nCEP:.......: %d", bdconsulente[i].cepC);
						printf("\nComplemento: %s", bdconsulente[i].compC);

						printf("\n\n---------------------------------------");
						break;
					}else {
						teste++;
						if (teste==99){
							printf("\n\nNao encontrado.");
						}
					}
				}
			break;
			case 3:

				printf("Digite o CPF para pesquisa: \n");
				gets(pesCpf);
				for (i=0; i<100; i++)
				{
					if (strcmp(bdconsulente[i].cpfC,pesCpf)==0)
					{
						printf("\nRA.........: %d", bdconsulente[i].regiC);
						printf("\nNome.......: %s", bdconsulente[i].nomeC);
						printf("\nRG.........: %s", bdconsulente[i].rgC);
						printf("\nCPF........: %s", bdconsulente[i].cpfC);
						printf("\nTelefone...: %d", bdconsulente[i].telC);
						printf("\nRua:.......: %s", bdconsulente[i].ruaC);
						printf("\nCEP:.......: %d", bdconsulente[i].cepC);
						printf("\nComplemento: %s", bdconsulente[i].compC);

						printf("\n\n---------------------------------------");
						break;
					}
				}
			break;
			case 4:
				printf("Digite o RA para pesquisa: \n");
				fflush(stdin);
				teste=0;
				scanf("%d", &pesRegC);
				for (i=0; i<100; i++)
				{
					if (bdconsulente[i].regiC==pesRegC)
					{
						printf("\nRA.........: %d", bdconsulente[i].regiC);
						printf("\nNome.......: %s", bdconsulente[i].nomeC);
						printf("\nRG.........: %s", bdconsulente[i].rgC);
						printf("\nCPF........: %s", bdconsulente[i].cpfC);
						printf("\nTelefone...: %d", bdconsulente[i].telC);
						printf("\nRua:.......: %s", bdconsulente[i].ruaC);
						printf("\nCEP:.......: %d", bdconsulente[i].cepC);
						printf("\nComplemento: %s", bdconsulente[i].compC);

						printf("\n\n---------------------------------------");
						break;
					} else{
						teste++;
						if(teste==99){
							printf("Consulente nao encontrado.");
						}
					}
				}
			break;
			case 5:
				for(i=0;i<100;i++){
					if(strcmp(bdconsulente[i].nomeC,"")!=0){
						printf("\nRA.........: %d", bdconsulente[i].regiC);
						printf("\nNome.......: %s", bdconsulente[i].nomeC);
						printf("\nRG.........: %s", bdconsulente[i].rgC);
						printf("\nCPF........: %s", bdconsulente[i].cpfC);
						printf("\nTelefone...: %d", bdconsulente[i].telC);
						printf("\nRua:.......: %s", bdconsulente[i].ruaC);
						printf("\nCEP:.......: %d", bdconsulente[i].cepC);
						printf("\nComplemento: %s", bdconsulente[i].compC);

						printf("\n\n---------------------------------------");

					}
				}
				break;
			case 6:
			 valida = menuConsulente();
			 getch();
			break;
		}

		printf("\nDeseja continuar cadastrando   [1] - Sim | [2] - Não\n\nResp.:");
		scanf("%d",&op);

		if (op == 1 ){
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 1;
		} else {
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 2;
		}
		}

	}

int alterarConsulente(){
	linha("Alterar");
	printf("\n[1] - Nome\n[2] - RA\n[3] - RG\n");
	printf("\nResp.: ");
	scanf("%d", &op);
	teste=0;
	char nome[100];
	switch(op){
		case 1:
			fflush(stdin);
			printf("Digite o nome.: ");
			gets(nome);


			for(i=0;i<100;i++){
				if(strcmp(bdconsulente[i].nomeC, nome)==0){
					printf("RA.....: %d\n", bdconsulente[i].regiC);
					printf("Nome...: %s\n", bdconsulente[i].nomeC);
					printf("CPF....: %s\n", bdconsulente[i].cpfC);
					printf("RG.....: %s\n", bdconsulente[i].rgC);
					printf("Rua....: %s\n", bdconsulente[i].ruaC);
					printf("CEP....: %d\n", bdconsulente[i].cepC);
					printf("Comp...: %s\n", bdconsulente[i].compC);
					printf("Tel....: %d\n", bdconsulente[i].telC);

					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					op=0;
					scanf("%d",&op);


					if(op==1){

						printf("\n\nO que deseja alterar?\n");
						printf("[1] - Nome\n[2] - RG\n[3] - CPF\n[4] - Rua\n[5] - CEP\n[6] - Complemento\n[7] - Teleofne");
						printf("\n\nResp.:");
						scanf("%d", &op);
						fflush(stdin);
						switch(op){
						case 1:

							printf("Nome......: %s\n", bdconsulente[i].nomeC);
							printf("Novo nome.: ");
							scanf("%s", &bdconsulente[i].nomeC);
							break;
						case 3:
							printf("\nRG........: %s\n", bdconsulente[i].rgC);
							printf("Novo RG...:");
							scanf("%s", &bdconsulente[i].rgC);
							break;
						case 2:
							printf("\nCPF.......: %s\n", bdconsulente[i].cpfC);
							printf("Novo CPF..: ");
							scanf("%s", &bdconsulente[i].cpfC);
							break;
						case 4:
							printf("\nRua.......: %s\n", bdconsulente[i].ruaC);
							printf("Nova Rua..:");
							gets(bdconsulente[i].ruaC);
							break;
						case 5:
							printf("\nCEP.......: %d\n", bdconsulente[i].cepC);
							printf("Novo CEP..:");
							scanf("%d", &bdconsulente[i].cepC);
							fflush(stdin);
							break;
						case 6:
							printf("Comp...: %s\n", bdconsulente[i].compC);
							printf("Novo Comp...:");
							scanf("%s", &bdconsulente[i].compC);
							break;
						case 7:
							printf("Tel....: %d\n", bdconsulente[i].telC);
							printf("Novo tel.:");
							scanf("%d",&bdconsulente[i].telC);
							fflush(stdin);
						break;
						} return;
					}
				}  else {
					if(teste==99){
						printf("\n\nNao encontrado!\n");
						getch();
						alterarConsulente();
					}
				}

			}
			break;
		case 2:
			fflush(stdin);
			int ra=0;
			teste=0;
			printf("Digite o RA...: ");
			scanf("%d", &ra);
			for( i=0; i<100; i++){
				if(bdconsulente[i].regiC == ra){
					printf("RA.....: %d\n", bdconsulente[i].regiC);
					printf("Nome...: %s\n", bdconsulente[i].nomeC);
					printf("CPF....: %s\n", bdconsulente[i].cpfC);
					printf("RG.....: %s\n", bdconsulente[i].rgC);
					printf("Rua....: %s\n", bdconsulente[i].ruaC);
					printf("CEP....: %d\n", bdconsulente[i].cepC);
					printf("Comp...: %s\n", bdconsulente[i].compC);
					printf("Tel....: %d\n", bdconsulente[i].telC);

					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					scanf("%d\n", &op);

					if(op==1){

						printf("\n\nO que deseja alterar?\n ");
						printf("[1] - Nome\n[2] - RG\n[3] - CPF\n[4] - Rua\n[5] - CEP\n[6] - Complemento\n[7] - Teleofne");
						printf("\n\nResp.:");
						scanf("%d", &op);
						fflush(stdin);
						switch(op){
						case 1:

							printf("Nome......: %s\n", bdconsulente[i].nomeC);
							printf("Novo nome.: ");
							scanf("%s", &bdconsulente[i].nomeC);
							break;
						case 3:
							printf("\nRG........: %s\n", bdconsulente[i].rgC);
							printf("Novo RG...:");
							scanf("%s", &bdconsulente[i].rgC);
							break;
						case 2:
							printf("\nCPF.......: %s\n", bdconsulente[i].cpfC);
							printf("Novo CPF..: ");
							gets(bdconsulente[i].cpfC);
							break;
						case 4:
							printf("\nRua.......: %s\n", bdconsulente[i].ruaC);
							printf("Nova Rua..:");
							gets(bdconsulente[i].ruaC);
							break;
						case 5:
							printf("\nCEP.......: %d\n", bdconsulente[i].cepC);
							printf("Novo CEP..:");
							scanf("%d",&bdconsulente[i].cepC);
							fflush(stdin);
							break;
						case 6:
							printf("Comp...: %s\n", bdconsulente[i].compC);
							printf("Novo Comp...:");
							gets(bdconsulente[i].compC);
							break;
						case 7:
							printf("Tel....: %d\n", bdconsulente[i].telC);
							printf("Novo tel.:");
							scanf("%d",&bdconsulente[i].telC);
							fflush(stdin);
						break;
						} break;
					}
				}  else {
					if(teste==99){
						printf("\n\nNao encontrado!\n");
						getch();
						alterarConsulente();
					}
				}

			}
			break;
		case 3:
			fflush(stdin);
			char rg[10];
			printf("\nDigite o RG...: ");
			gets(rg);
			for( i=0; i<100; i++){
				if(strcmp(bdconsulente[i].rgC,rg) ==0 ){
					printf("RA.....: %d\n", bdconsulente[i].regiC);
					printf("Nome...: %s\n", bdconsulente[i].nomeC);
					printf("CPF....: %s\n", bdconsulente[i].cpfC);
					printf("RG.....: %s\n", bdconsulente[i].rgC);
					printf("Rua....: %s\n", bdconsulente[i].ruaC);
					printf("CEP....: %d\n", bdconsulente[i].cepC);
					printf("Comp...: %s\n", bdconsulente[i].compC);
					printf("Tel....: %d\n", bdconsulente[i].telC);

					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					fflush(stdin);

					scanf("%d\n", &op);
					printf("Pressione uma tecla para continuar....");

					if(op==1){
						printf("\n\nO que deseja alterar?\n ");
						printf("[1] - Nome\n[2] - RG\n[3] - CPF\n[4] - Rua\n[5] - CEP\n[6] - Complemento\n[7] - Teleofne");
						printf("\n\nResp.:");
						op=0;
						scanf("%d", &op);

						switch(op){
						case 1:

							printf("Nome......: %s\n", bdconsulente[i].nomeC);
							printf("Novo nome.: ");
							gets(bdconsulente[i].nomeC);
							break;

						case 3:
							printf("\nRG........: %s\n", bdconsulente[i].rgC);
							printf("Novo RG...:");
							gets(bdconsulente[i].rgC);
							break;
						case 2:
								printf("\nCPF.......: %s\n", bdconsulente[i].cpfC);
							printf("Novo CPF..: ");
							gets(bdconsulente[i].cpfC);
							break;
						case 4:
							printf("\nRua.......: %s\n", bdconsulente[i].ruaC);
							printf("Nova Rua..:");
							gets(bdconsulente[i].ruaC);
							break;
						case 5:
							printf("\nCEP.......: %d\n", bdconsulente[i].cepC);
							printf("Novo CEP..:");
							scanf("%d",&bdconsulente[i].cepC);
							fflush(stdin);
							break;
						case 6:
							printf("Comp...: %s\n", bdconsulente[i].compC);
							printf("Novo Comp...:");
							gets(bdconsulente[i].compC);
							break;
						case 7:
							printf("Tel....: %d\n", bdconsulente[i].telC);
							printf("Novo tel.:");
							scanf("%d",&bdconsulente[i].telC);
							fflush(stdin);
						break;
						}
					}
				}  else {
						printf("\n\nNao encontrado!\n");
							break;
							alterarConsulente();
						}

			}
			printf("\nOpcao Invalida!\n");
			break;
			default:
				printf("\nValor invalido.\n");
		}


		printf("\nDeseja continuar? [1] - Sim | [2] - Não\n\nResp.:");
		scanf("%d",&op);

		if (op == 1 ){
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 1;
		} else {
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 2;
		}
	}

int inativarConsulente(){
	linha("Inativar Consulente");

	printf("\n\nInforme o RA do Consulente a ser inativado.\nResp.: ");
	scanf("%d",&inativaC);

	for(i=0; i<100; i++){
		if (bdconsulente[i].regiC==inativaC)	{

			printf("\nRA.........: %d", bdconsulente[i].regiC);
			printf("\nNome.......: %s", bdconsulente[i].nomeC);
			printf("\nRG.........: %s", bdconsulente[i].rgC);
			printf("\nCPF........: %s", bdconsulente[i].cpfC);
			printf("\nTelefone...: %d", bdconsulente[i].telC);
			printf("\nRua:.......: %s", bdconsulente[i].ruaC);
			printf("\nCEP:.......: %d", bdconsulente[i].cepC);
			printf("\nComplemento: %s", bdconsulente[i].compC);

			printf("\n\n---------------------------------------");

			printf("Deseja mesmo inativar este consulente?       [1] - Sim | [2] - Nao");
			scanf("%d", &op);
			if (op==1){
				// 1 = inativo
				bdconsulente[i].status = 1;
				return 1;
			}else{
				inativarConsulente();
			}
		}
	}
}

int menuConsulente(){
	linha("Consulente");
	printf("\n\[1] - Incluir\n[2] - Pesquisar\n[3] - Alterar\n[4] - Voltar\nResp.:");
	scanf("%d",&teste);
	switch(teste){
		case 1:
			fflush(stdin);
			valida = 1;
			while(valida != 2){
				valida = inConsulente();
			}
			menuConsulente();
			break;
		case 2:
			fflush(stdin);
			valida = 1;
			while(valida != 2){
				valida = pesConsulente();
			}
			menuConsulente();
			break;
		case 3:
			fflush(stdin);
			valida = 1;
			while(valida != 2){
				valida = alterarConsulente();
			}
			break;
		case 4:
			fflush(stdin);
			valida = 1;
			return 2;
			break;
		default:
			printf("Opcao inválida.");
			menuConsulente();

	}
	return 1;
}

											/* Acervo */

typedef struct Livro{
		char nomel[100],autorl[100],editoral[100], isbnl[20];
		int regiL, statusL;
		int qt;
		int nLivrosDisponiveis, nLivrosEmprestados;
	}Livro;

struct Livro livro;
int regL=2, pesRegL=0;
Livro bdLivro[100];
int inativaL = 0;
char pesRegC1[10];

int inLivro(){

		linha("Cadastro de Livro");
		struct Livro livro;
		fflush(stdin);
		printf("\nNome do Livro:");
		gets(livro.nomel);
		printf("\nAutor do Livro: ");
		gets(livro.autorl);
		printf("\nEditora do Livro: ");
		gets(livro.editoral);
		printf("\nISBN:");
		gets(livro.isbnl);
		int len=0;
		len = strlen(livro.isbnl);

		if(len>=20){
			while(len>=20){
				printf("Numero de ISBN invalido, digite novamente: ");
				gets(livro.isbnl);
				len = strlen(livro.isbnl);
			}
		}

		for (i=0;i<100;i++){

			if (strcmp(bdLivro[i].isbnl, livro.isbnl) == 0){

				printf("Numero de ISBN já cadastrado, digite novamente: ");
				gets(livro.isbnl);

			}
		}

		printf("\nQuantidade de Livros: ");
		scanf("%d", &livro.nLivrosDisponiveis);

		fflush(stdin);

		livro.nLivrosEmprestados = 0;
		livro.statusL = 1;

		bdLivro[regL] = livro;
		regL++;
		bdLivro[regL-1].regiL = regL;


		printf("\n\n\nLivro cadastrado com sucesso! \n");
		printf("Nome......:  %5s\n",livro.nomel);
		printf("Autor.....:  %5s\n",livro.autorl);
		printf("Editora...:  %5s\n",livro.editoral);
		printf("ISBN......:  %5s\n",livro.isbnl);
		printf("Quantidade:  %5d\n",livro.nLivrosDisponiveis);
		fflush(stdin);

		printf("\nDeseja continuar cadastrando   [1] - Sim | [2] - Não\n\nResp.:");
		scanf("%d",&op);

		if (op == 1 ){
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 1;
		} else {
			if (op == 2){
			printf("\n\nPressione uma tecla para continuar...");
			getch();
			return 2;
		}else{
			printf("\n\nOpcao invalida");
			inLivro();		
		}

	}
}

int pesLivro (){
	char pesNomeL [100], pesAutorL[100], pesEditoraL[100], pesIsbnL[20];
	int teste, op, retorno;
		while (op!=6)
		{
			linha("Pesquisa de Livro");
			printf("[1] - Pesquisar por Nome\n");
			printf("[2] - Pesquisar por Autor\n");
			printf("[3] - Pesquisar por Editora\n");
			printf("[4] - Pesquisar por ISBN\n");
			printf("[5] - Pesquisar Todos\n");
			printf("[6] - Sair \n");
			printf("\nResp.: ");
			scanf("%d",&op);
			fflush(stdin);
			switch(op)
			{
			case 1:
				fflush(stdin);
				printf("\n\nDigite o NOME para pesquisa: ");
				gets(pesNomeL);
				teste=0;
				int emBranco = 0;
				emBranco = strcmp(pesNomeL, "\0");
				
				if(emBranco == 0){
					while(emBranco ==0){
						printf("Favor digitar o nome: ");
						gets(pesNomeL);
						emBranco = strcmp(pesNomeL, "\0");
					}
				}
				for(i=0; i<100; i++)
				{
					
					if (strcmp(bdLivro[i].nomel, pesNomeL) == 0 && emBranco != 0)
					{
							printf("Nome......:  %s\n", bdLivro[i].nomel);
							printf("Autor.....:  %s\n", bdLivro[i].autorl);
							printf("Editora...:  %s\n", bdLivro[i].editoral);
							printf("ISBN......:  %s\n", bdLivro[i].isbnl);
							printf("Quantidade:  %d\n", bdLivro[i].nLivrosDisponiveis);

						printf("\n\n---------------------------------------\n");
						teste = -1;
					}else{
						teste++;
						if( teste == 99 ){
							printf("\n\nLivro nao encontrado.\n");
						}
					}
				}
			printf("Pressione uma tecla para continuar...");
			getch();
			break;

			case 2:
				fflush(stdin);
				printf("\n\nDigite AUTOR para pesquisa: ");
				gets(pesAutorL);
				teste=0;
				emBranco = 0;
				emBranco = strcmp(pesAutorL, "\0");

				if(emBranco == 0){
					while(emBranco ==0){
						printf("Favor digitar o Autor: ");
						gets(pesAutorL);
						emBranco = strcmp(pesAutorL, "\0");
					}
				}
				for (i=0; i<100; i++)
				{
				  
					 if (strcmp(bdLivro[i].autorl, pesAutorL)==0 && emBranco != 0)
					{
							printf("Nome......:  %s\n", bdLivro[i].nomel);
							printf("Autor.....:  %s\n", bdLivro[i].autorl);
							printf("Editora...:  %s\n", bdLivro[i].editoral);
							printf("ISBN......:  %s\n", bdLivro[i].isbnl);
							printf("Quantidade:  %d\n", bdLivro[i].nLivrosDisponiveis);

						printf("\n\n---------------------------------------\n");
						teste = -1;
					}else {
						teste++;
						if (teste==99){
							printf("\n\nNao encontrado.");
						}
					}
				}
				
			printf("Pressione uma tecla para continuar...");
			getch();
			break;

			case 3:
				fflush(stdin);
				printf("Digite a EDITORA para pesquisa: \n");
				gets(pesEditoraL);
				teste=0;
				emBranco = 0;
				emBranco = strcmp(pesEditoraL, "\0");

				if(emBranco == 0){
					while(emBranco == 0){
						printf("Favor digitar a Editora: ");
						gets(pesEditoraL);
						emBranco = strcmp(pesEditoraL, "\0");
					}
				}
				for (i=0; i<100; i++)
				{
			
					if (strcmp(bdLivro[i].editoral,pesEditoraL)==0 && emBranco != 0)
					{
							printf("Nome......:  %s\n", bdLivro[i].nomel);
							printf("Autor.....:  %s\n", bdLivro[i].autorl);
							printf("Editora...:  %s\n", bdLivro[i].editoral);
							printf("ISBN......:  %s\n", bdLivro[i].isbnl);
							printf("Quantidade:  %d\n", bdLivro[i].nLivrosDisponiveis);

						printf("\n\n---------------------------------------\n");
						teste = -1;
					} else{
						teste++;

     					if(teste==99){
							printf("\nLivro nao encontrado.");
						}
					}
				}
			printf("Pressione uma tecla para continuar...");
			getch();
			break;

			case 4:
				fflush(stdin);
				printf("Digite o ISBN para pesquisa: \n");
				fflush(stdin);
				teste=0;
				gets(pesIsbnL);

				emBranco = 0;
				emBranco = strcmp(pesIsbnL, "\0");

				if(emBranco == 0){
					while(emBranco ==0){
						printf("Favor digitar o ISBN: ");
						gets(pesIsbnL);
						emBranco = strcmp(pesIsbnL, "\0");
					}
				}

				
				for (i=0; i<100; i++)
				{
				
				if (strcmp(bdLivro[i].isbnl,pesIsbnL)==0 && pesIsbnL != 0 )
					{
							printf("Nome......:  %s\n", bdLivro[i].nomel);
							printf("Autor.....:  %s\n", bdLivro[i].autorl);
							printf("Editora...:  %s\n", bdLivro[i].editoral);
							printf("ISBN......:  %s\n", bdLivro[i].isbnl);
							printf("Quantidade:  %d\n", bdLivro[i].nLivrosDisponiveis);

							printf("\n\n---------------------------------------\n");
							teste = -1;
					} else{
						teste++;
					
						if(teste==99){
							printf("\nLivro nao encontrado.");
						}
						
					}
				}
			printf("Pressione uma tecla para continuar...");
			getch();
			break;

			case 5:
				fflush(stdin);
				for(i=0;i<100;i++){
					if(strcmp(bdLivro[i].nomel,"")!=0){
							printf("Nome......:  %s\n", bdLivro[i].nomel);
							printf("Autor.....:  %s\n", bdLivro[i].autorl);
							printf("Editora...:  %s\n", bdLivro[i].editoral);
							printf("ISBN......:  %s\n", bdLivro[i].isbnl);
							printf("Quantidade:  %d\n", bdLivro[i].nLivrosDisponiveis);

						printf("\n\n---------------------------------------\n\n");

					}
				}
				getch();
				break;

				case 6:
					menuLivro();
			default:
				printf("\n\nOpcao Invalida");
				printf("\n\nDeseja continuar? [1] - Sim | [2] - Nao");
				scanf("%d", &retorno);
				if (retorno ==1){
					return 1;
				} else {
					return 2;
			}

			}
		}
	}

int alterarLivro(){
	int retorno =0;
	linha("Alterar");
	printf("\n[1] - Nome do Livro\n[2] - ISBN\n");
	printf("\nResp.: ");
	scanf("%d", &op);
	teste=0;
	char nome[100], isbn[20];
	struct Livro livro;
	switch(op){
		case 1:
			fflush(stdin);
			printf("Digite o nome.: ");
			gets(nome);


			for(i=0;i<100;i++){
				if(strcmp(bdLivro[i].nomel, nome)==0){
					printf("Nome......:  %5s\n",livro.nomel);
					printf("Autor.....:  %5s\n",livro.autorl);
					printf("Editora...:  %5s\n",livro.editoral);
					printf("ISBN......:  %5s\n",livro.isbnl);
					printf("Quantidade:  %5d\n",livro.nLivrosDisponiveis);
					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					op=0;
					scanf("%d",&op);

					if(op==1){
						printf("\n\nO que deseja alterar?\n");
						printf("[1] - Nome\n[2] - AutorRG\n[3] - Editora\n[4] - ISBN\n[5] - Livros Disponiveis");
						printf("\n\nResp.:");
						scanf("%d", &op);
						fflush(stdin);
						switch(op){
							case 1:
								fflush(stdin);
								printf("Nome......: %s\n", bdLivro[i].nomel);
								printf("Novo nome.: ");
								gets(bdLivro[i].nomel);
								getch();
							break;

							case 2:
								fflush(stdin);
								printf("\nAutor........: %s\n", bdLivro[i].autorl);
								printf("Novo Autor...:");
								gets(bdLivro[i].autorl);
								getch();
							break;

							case 3:
								fflush(stdin);
								printf("\nEditora.......: %s\n", bdLivro[i].editoral);
								printf("Nova Editora..: ");
								gets(bdLivro[i].editoral);
								getch();
							break;

							case 4:
								fflush(stdin);
								printf("\nLivros Disponiveis.......: %s\n", bdLivro[i].nLivrosDisponiveis);
								printf("Nova Quantidade..:");
								scanf("%d", &bdLivro[i].nLivrosDisponiveis);
								getch();
							break;

							default:
								printf("opcao invalida");
						} return;
					}
				}  else {
					if(teste==99){
						printf("\n\nNao encontrado!\n");
						getch();
						alterarLivro();
					}
				}

			}
		getch();
		break;

		case 2:
			fflush(stdin);
			printf("Digite o ISBN.: ");
			gets(isbn);


			for(i=0;i<100;i++){
				if(strcmp(bdLivro[i].isbnl, isbn)==0){
							printf("Nome......:  %5s\n",livro.nomel);
							printf("Autor.....:  %5s\n",livro.autorl);
							printf("Editora...:  %5s\n",livro.editoral);
							printf("ISBN......:  %5s\n",livro.isbnl);
							printf("Quantidade:  %5d\n",livro.nLivrosDisponiveis);

					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					op=0;
					scanf("%d",&op);


					if(op==1){

						printf("\n\nO que deseja alterar?\n");
						printf("[1] - Nome\n[2] - AutorRG\n[3] - Editora\n[4] - ISBN\n[5] - Livros Disponiveis");
						printf("\n\nResp.:");
						scanf("%d", &op);
						fflush(stdin);
						switch(op){
						case 1:
							fflush(stdin);
							printf("Nome......: %s\n", bdLivro[i].nomel);
							printf("Novo nome.: ");
							gets(bdLivro[i].nomel);
							getch();
						break;

						case 2:
							fflush(stdin);
							printf("\nAutor........: %s\n", bdLivro[i].autorl);
							printf("Novo Autor...:");
							gets(bdLivro[i].autorl);
							getch();
						break;

						case 3:
							fflush(stdin);
							printf("\nEditora.......: %s\n", bdLivro[i].editoral);
							printf("Nova Editora..: ");
							gets(bdLivro[i].editoral);
							getch();
						break;

						case 4:
							fflush(stdin);
							printf("\nLivros Disponiveis.......: %s\n", bdLivro[i].nLivrosDisponiveis);
							printf("Nova Quantidade..:");
							scanf("%d", &bdLivro[i].nLivrosDisponiveis);
							getch();
						break;

						default:
							printf("opcao invalida");
						} return;
					}
				}  else {
					if(teste==99){
						printf("\n\nNao encontrado!\n");
						getch();
						alterarLivro();
					}
				}

			}
			break;

			default:
				printf("\nValor invalido.\n");
				printf("\nPressione uma tecla para continuar...\n");
				getch();
				return;
		}

	printf("Deseja continuar? [1] - Sim | [2] - Nao");
	scanf("%d", &retorno);

	if (retorno == 1){
		return 1;
	} else {
		return 2;
	}
}

int inativarLivro(){
	linha("Inativar Livro");

	printf("\n\nInforme o ISBN do lIVRO a ser inativado.\nResp.: ");
	scanf("%d",&inativaL);

	for(i=0; i<100; i++){
		if (bdLivro[i].regiL==inativaL)	{

			printf("Nome......:  %5s\n",bdLivro[i].nomel);
			printf("Autor.....:  %5s\n",bdLivro[i].autorl);
			printf("Editora...:  %5s\n",bdLivro[i].editoral);
			printf("ISBN......:  %5s\n",bdLivro[i].isbnl);
			printf("Quantidade:  %5d\n",bdLivro[i].nLivrosDisponiveis);

			printf("\n\n---------------------------------------");

			printf("Deseja mesmo inativar este livro?       [1] - Sim | [2] - Nao");
			scanf("%d", &op);
			if (op==1){
				// 1 = inativo
				bdLivro[i].statusL = 1;
				return 1;
			}else{
				inativarLivro();
			}
		}
	}

}

int menuLivro(){
	linha("Acervo");
	printf("\n\[1] - Incluir\n[2] - Pesquisar\n[3] - Alterar\n[4] - Voltar\nResp.:");
	scanf("%d",&teste);
	valida = 0;
	switch(teste){
		case 1:
			fflush(stdin);
			valida = 1;
			while (valida != 2){
				valida = inLivro();
			}
			menuLivro();
			break;
		case 2:
			fflush(stdin);
			valida = 1;
			while(valida != 2){
				valida = pesLivro();
			}
			menuLivro();
			break;
		case 3:
			fflush(stdin);
			valida = 1;
			while(valida != 2){
				valida = alterarLivro();
			}
			menuLivro();
			break;
		case 4:
			fflush(stdin);
			valida = 1;
			mainMenu();
			break;
		default:
			printf("\nOpcao inválida.");
			break;
			valida = 1;
			menuLivro();
	}
	return;
}

											/* Movimentação	*/
char nomeLivro[100];
int comparaLivro=0, raAluno = 0, validaIsbn=0;
int contadorI = 0, contadorJ=0, contadorH=0, controleMovimentacao= 0;
int regMov = 0,pos1=0, pos2=0;

typedef struct Movimentacao{
	int idMovimentacao, RA, dataEmp, dataDev, status;
	char isbn[20];
} Movimentacao;

Movimentacao bdMovimentacao[100];

int emprestimoDeLivros(){
	fflush(stdin);
	linha("Emprestimo de Livros");

	printf("Para realizar o emprestimo, favor entrar com o nome do Livro.\nResp.:");
	gets(nomeLivro);
	
	int emBranco = 0;
	emBranco = strcmp(nomeLivro, "\0");
	
	if(emBranco == 0){
		while(emBranco ==0){
			printf("Favor digitar o nome do livro: ");
			gets(nomeLivro);
			emBranco = strcmp(nomeLivro, "\0");
		}
	}

	int opcaoMenu=0, validaAluno=0;
	for (contadorI = 0; contadorI < 100 ;contadorI++){
		comparaLivro = strcmp(bdLivro[contadorI].nomel, nomeLivro);

		if (comparaLivro == 0){
			printf("\nDeseja reservar o livro abaixo? ");
			printf("\nNome.......: %s", bdLivro[contadorI].nomel);
			printf("\nQuantidade.: %d", bdLivro[contadorI].nLivrosDisponiveis);
			printf(" \n\n1-Sim | 2-Nao\n");
			scanf("%d", &opcaoMenu);
			fflush(stdin);

			if(opcaoMenu == 1 && bdLivro[contadorI].nLivrosDisponiveis>1){
				printf("Digite o RA do aluno: \nResp.:");
				scanf("%d", &raAluno);

				for (contadorJ = 0; contadorJ < 100; contadorJ++ ){
					validaAluno = (bdconsulente[contadorJ].regiC == raAluno && bdconsulente[contadorJ].status == 1);

					validaNLivros = (bdconsulente[contadorJ].nLivrosEmprestados<3 );
					if(validaAluno != 0 ){
						if(validaNLivros != 0){
							 for(contadorH=0; contadorH<100; contadorH++)
							 {
							 	strcpy(bdMovimentacao[contadorH].isbn, bdLivro[contadorI].isbnl);

							 	if (validaIsbn != 1)
								 {
									system("cls");
									printf("Livro Reservado!\n");
									fflush(stdin);
									controleMovimentacao++;
									bdMovimentacao[regMov].idMovimentacao = controleMovimentacao;
									regMov++;
									pos1 = contadorI;
									strcpy(bdMovimentacao[regMov-1].isbn, bdLivro[contadorI].isbnl);
									bdMovimentacao[regMov-1].RA=bdconsulente[contadorJ].regiC;
									bdMovimentacao[regMov-1].status = 1;
									//bdMovimentacao[regMov]
									//bdMovimentacao[regMov]
								 	printf("\nAluno: %s", bdconsulente[contadorJ].nomeC);
								 	printf("\nLivro: %s", bdLivro[contadorI].nomel);
								 	printf("\nISBN.: %s", bdLivro[contadorI].isbnl);
								 	

									bdLivro[contadorI].nLivrosDisponiveis -= 1;
								 	bdLivro[contadorI].nLivrosEmprestados++;
								 	bdLivro[contadorI].statusL = 1;

									bdconsulente[contadorJ].nLivrosEmprestados++;
									printf("\nNo de Livros disponiveis: %d\n", bdLivro[contadorI].nLivrosDisponiveis);
								 	printf("Pressione uma tecla para continuar...");
									 getch();
									menuMovimentacao();
								 }else{
							 		printf("Aluno ja possui este item reservado\n");
									getch();
									system("cls");
									emprestimoDeLivros();
								 }
							 }
						 } else {
						 	printf("Este aluno já atingiu o limite de emprestimos simultaneos. \n");
						 	contadorH=100;
						 	emprestimoDeLivros();
						 }
						}else{
							if(contadorH==99){

								printf("\nRA nao localizado.\n");
								getch();
								emprestimoDeLivros();
							}
							printf("\nRa inativo.\n");
					}
				}
			break;
			}else {
				if(bdLivro[contadorI].nLivrosDisponiveis < 2 ){
					printf("Numero de livros disponiveis insuficientes para emprestimo.\n");
				}
				printf("\n\nPressione uma tecla para continuar...\n\n");
				getch();
				mainMenu();
			}
		}else{
			if(contadorI ==99){
				printf("\n\nLivro nao encontrado. ");
				printf("\n\nPressione uma tecla para continuar...\n\n");
				getch();
				menuMovimentacao();
			}
		}
	}

	printf("\n\nDeseja continuar? \n[1] - Sim\n[2] - Nao\nResp.: ");
	scanf("%d",&op);

	if (op==1){
		return 1;
	} else {
		return 2;
	}

}

int pesMovimentacao(){
	teste = 0;
	int ra=0;
	int opcaoMenu= 0;
	
	linha("Pesquisa");

	printf("favor entrar com o RA do Aluno.\n\nResp.:");
		scanf("%d", &ra);
		int comparaRA = 0;
		for (contadorI = 0; contadorI < 100 ;contadorI++){
			comparaRA = (bdconsulente[contadorI].regiC == ra);

			if ( comparaRA == 1 ){
				for (contadorJ=0; contadorJ<100 ;contadorJ++){

					if(bdMovimentacao[contadorJ].RA == ra){
						printf("\nLivros Emprestados:\n\n");

						printf("No da Movimentacao..: %d", bdMovimentacao[contadorJ].idMovimentacao);
						printf("\nNome do Livro.....: %s", bdLivro[contadorJ].nomel);
						printf("\nNome do Consulente: %s", bdconsulente[contadorI].nomeC);
						if	(bdMovimentacao[contadorJ].status == 1){
							printf("\n\nStatus......: Devolvido\n");
						} else {
							printf("\n\nStatus......: Em Aberto\n");
						}

						printf("\n\n");
						fflush(stdin);
						printf("----------------------------------------\n ");
						teste = -2;
					} else {
						teste++;
							if(contadorJ == 99 && teste==99 ){
								printf("Usuario nao encontrado");
							}
					}
					
				}
			} else{
				teste++;
				if(contadorI==99 && teste == 99){
					
						printf("Ra nao localizado.");
					
					printf("\n\nPressione uma tecla para continuar...");
					getch();
					return 2;
				}
			}
		}

		printf("\nDeseja Continuar? \n[1] - Sim\n[2] - Nao\nResp.:");
		scanf("%d",&op);

		if (op==1){
			return 1;
		} else {
			return 2;
		}
	}


int menuMovimentacao(){

	linha("Movimentacao");
	printf("[1] - Emprestimo\n[2] - Devolucao\n[3] - Relatorios\n[4] - Voltar\nResp.:");
	op=0;
	scanf("%d", &op);

	while(op!=5){
		switch(op){
			case 1:
				valida=0;
				while(valida!=2){
					valida = emprestimoDeLivros();
				}
				menuMovimentacao();
				break;
			case 2:
				valida=0;
				while(valida!=2){
					valida = devolucaoDeLivros();
				}
				menuMovimentacao();
				break;
			case 3:
				valida=0;
				while(valida!=2){
					valida = pesMovimentacao();
				}
				menuMovimentacao();
				break;
			case 4:
				mainMenu();
			default:
				printf("Opcao invalida.");
				printf("\n\nPressione uma tecla para continuar...");
				getch();
				fflush(stdin);
				menuMovimentacao();
		}
	}
}

int devolucaoDeLivros(){
	int devRA=0, comparaRA=0;

	fflush(stdin);
	
	linha("Devolucao");

	int opcaoMenu=0;

		printf("favor entrar com o RA do Aluno.\n\nResp.:");
		scanf("%d", &devRA);

		for (contadorI = 0; contadorI < 100 ;contadorI++){
			comparaRA = (bdconsulente[contadorI].regiC == devRA);

			if ( comparaRA == 1 ){
				for (contadorJ=0; contadorJ<100 ;contadorJ++){

					if(bdMovimentacao[contadorJ].RA == devRA && bdMovimentacao[contadorJ].status == 1){
						printf("\nEmprestimos\n\n");

						printf("No da Movimentacao: %d", bdMovimentacao[contadorJ].idMovimentacao);
						printf("\nNome............: %s", bdLivro[contadorJ].nomel);
						printf("\nQuantidade......: %d", bdLivro[contadorJ].nLivrosDisponiveis);
						printf("\nDigite o No da movimentacao desejada: ");
						scanf("%d", &opcaoMenu);
						
						teste=0;
						for (contadorH = 0; contadorH < 100; contadorH++){
							if(bdMovimentacao[contadorH].idMovimentacao == opcaoMenu){
								teste = -2;
								bdMovimentacao[contadorH].status = 0;
							} else {
								teste++;
								if(contadorH==99 && teste ==99){
									printf("Numero de movimentacao invalida.");
								}
							}
						}
						fflush(stdin);
						printf("----------------------------------------\n ");
						teste =-1;
					}
				}
			} else{
				teste++;
				if(contadorI==99 && teste == 99){
					printf("Ra nao localizado.");
					
					printf("\n\nPressione uma tecla para continuar...");
					getch();
					return 2;
				}
			}
		}
	
		printf("\nDeseja nContinuar? \n[1] - Sim\n[2] - Nao\nResp.:");
		scanf("%d",&op);

		if (op==1){
			return 1;
		} else {
			return 2;
		}
	
}

								/* Usuario */
								
int regU=0;
typedef struct usuario{

		char nomeUsuario[50],cpfUsuario[12],loginUsuario[16],senhaUsuario[50];
		int codUsuario,statusUsuario;


	}usuario;
		
usuario bdUsuario[10];

char nusuario[15];

int inUsuario(){
	
	
	char confirmaSenha[50];
	usuario usuario;
	fflush(stdin);
	linha("Cadastro de usuario");
	
	printf("\nNome:");
	gets(usuario.nomeUsuario);
	printf("\nCPF: ");
	scanf("%s",&usuario.cpfUsuario);
	fflush(stdin);

	int len=0;
	len = strlen(usuario.cpfUsuario);
	if(strcmp(usuario.cpfUsuario,bdUsuario[contadorI].cpfUsuario)==0||len>12){

		contadorI=0;
		while(strcmp(usuario.cpfUsuario,bdUsuario[contadorI].cpfUsuario)==0){

			printf("Numero de CPF invalido, digite novamente: ");
			gets(usuario.cpfUsuario);

			len = strlen(usuario.cpfUsuario);
				if(len>12){
					printf("\nCPF com tamanho invalido.");
				}
			contadorI++;
		}
	}

	printf("\ndigite seu login: ");
	gets(usuario.loginUsuario);
	
	while(strcmp(bdUsuario[i].loginUsuario, usuario.loginUsuario)==0){
		if(strcmp(bdUsuario[i].loginUsuario, usuario.loginUsuario)==0){
				printf("\nLogin ja existente! \n");
				i=0;
				printf("\ndigite seu login: ");
				gets(usuario.loginUsuario);
		}
		i++;
	}

	printf("\ndigite sua senha: ");
	gets(usuario.senhaUsuario);
	printf("\ndigite sua senha novamente: ");
	gets(confirmaSenha);
	i=0;
	while(strcmp(usuario.senhaUsuario, confirmaSenha)!=0){
				
		printf("\nSenha incorreta! \n");
		printf("\ndigite sua senha: ");
		gets(usuario.senhaUsuario);
		printf("\ndigite sua senha novamente: ");
		gets(confirmaSenha);
		
	}
	usuario.statusUsuario = 1;
	bdUsuario[regU] = usuario;

	regU++;
	bdUsuario[regU-1].codUsuario = regU;

	printf("\nNome.......: %s", bdUsuario[regU-1].nomeUsuario);
	printf("\nCPF........: %s", bdUsuario[regU-1].cpfUsuario);

	printf("\n\nContinuar cadastrando? \n[1] - Sim\n[2] - Nao\nResp.:");
	scanf("%d",&op);

	if (op==1){
		return 1;
	} else {
		return 2;
	}

}

int pesUsuario(){
	
	linha("Pesquisa de usuario");
	for (i=0; i<10 ; i++){
		if (strcmp(bdUsuario[i].nomeUsuario,"") != 0){
			printf("\nNome.....: %s", bdUsuario[i].nomeUsuario);
			printf("\nLogin....: %s", bdUsuario[i].loginUsuario);
			printf("\n---------------------------------------\n\n");
		}
	}
	
	printf("Digite uma tecla para continuar...");
	getch();
	
	return 2;
}

int altUsuario(){
	linha("Alteracao de Usuario");
	int ehAdmin = strcmp(nusuario, "admin");
	usuario user;
	char confirmaSenha[50];
	teste =0;
	if(ehAdmin){
		fflush(stdin);
		printf("\n\nDigite o login a ser alterado: ");
		gets(user.loginUsuario);
		int emBranco = 0;
		emBranco = strcmp(user.loginUsuario, "\0");
				
		if(emBranco == 0){
			while(emBranco ==0){
				printf("Favor digitar o login: ");
				gets(user.loginUsuario);
				emBranco = strcmp(user.loginUsuario, "\0");
			}
		}
	
		for	(i=0; i<10; i++){
			if (strcmp(bdUsuario[i].loginUsuario, user.loginUsuario)==0){
					printf("Id.....: %d\n", bdUsuario[i].codUsuario);
					printf("Nome...: %s\n", bdUsuario[i].nomeUsuario);
					printf("CPF....: %s\n", bdUsuario[i].cpfUsuario);
					printf("Login..: %s\n", bdUsuario[i].loginUsuario);
					printf("Status.: %d\n", bdUsuario[i].statusUsuario);
				
					printf("\n\nDeseja mesmo alterar este registro?    [1] - Sim | [2] - Nao \nResp...: ");
					op=0;
					scanf("%d",&op);
					if(op==1){

						printf("\n\nO que deseja alterar?\n");
						printf("[1] - Nome\n[2] - CPF\n[3] - Login\n[4] - status\n[5] - Senha\n");
						printf("\n\nResp.:");
						scanf("%d", &op);
						fflush(stdin);
						switch(op){
							case 1:
							printf("Nome.......: %s\n", bdUsuario[i].nomeUsuario);
							printf("Novo Nome...: \n");
							gets(bdUsuario[i].nomeUsuario);
							printf("\n\nId.....: %d\n", bdUsuario[i].codUsuario);
							printf("Nome...: %s\n", bdUsuario[i].nomeUsuario);
							printf("CPF....: %s\n", bdUsuario[i].cpfUsuario);
							printf("Login..: %s\n", bdUsuario[i].loginUsuario);
							printf("Status.: %d\n", bdUsuario[i].statusUsuario);
							printf("\nPressione uma tecla para continuar...\n");
							getch();
							i=9;
							break;
							
							case 2:
							printf("CPF........: %s\n", bdUsuario[i].cpfUsuario);
							printf("Novo CPF...: \n");
							gets(bdUsuario[i].cpfUsuario);
							
							int len=0;
							len = strlen(bdUsuario[i].cpfUsuario);
							if(strcmp(bdUsuario[i].cpfUsuario,bdUsuario[contadorI].cpfUsuario)==0||len>12){

							contadorI=0;
							while(strcmp(bdUsuario[i].cpfUsuario,bdUsuario[contadorI].cpfUsuario)==0){

									printf("Numero de CPF invalido, digite novamente: ");
									gets(bdUsuario[i].cpfUsuario);

									len = strlen(bdUsuario[i].cpfUsuario);
							if(len>12){
									printf("\nCPF com tamanho invalido.");
								}
							contadorI++;
						}
					}
					
					
							printf("\n\nId.....: %d\n", bdUsuario[i].codUsuario);
							printf("Nome...: %s\n", bdUsuario[i].nomeUsuario);
							printf("CPF....: %s\n", bdUsuario[i].cpfUsuario);
							printf("Login..: %s\n", bdUsuario[i].loginUsuario);
							printf("Status.: %d\n", bdUsuario[i].statusUsuario);
							printf("\nPressione uma tecla para continuar...\n");
							getch();
							i=9;
							break;
							
							case 3:
							
							printf("Login........: %s\n", bdUsuario[i].loginUsuario);
							printf("Novo Login...: \n");
							gets(user.loginUsuario);
							
							
							//percorre user
							for (contadorI = 0; contadorI<9; contadorI++){
								if(strcmp(bdUsuario[contadorI].loginUsuario, user.loginUsuario)==0){
									while(strcmp(bdUsuario[contadorI].loginUsuario, user.loginUsuario)==0){
										printf("Usuario ja cadastrado.\n\n");
										printf("Novo Login...: \n");
										gets(user.loginUsuario);
									}
								}
							}
							
							strcpy(bdUsuario[i].loginUsuario, user.loginUsuario);
							
							printf("\n\nId.....: %d\n", bdUsuario[i].codUsuario);
							printf("Nome...: %s\n", bdUsuario[i].nomeUsuario);
							printf("CPF....: %s\n", bdUsuario[i].cpfUsuario);
							printf("Login..: %s\n", bdUsuario[i].loginUsuario);
							printf("Status.: %d\n", bdUsuario[i].statusUsuario);
							printf("\nPressione uma tecla para continuar...\n");
							getch();
							i=9;
							break;
							
							case 4:
							if(bdUsuario[i].statusUsuario==1){
								printf("\nUsuario ativo, deseja desativar? \n [1] - SIM | [2] - NAO \nResp.: ");
								scanf("%d", &op);
								if (op ==1){
									bdUsuario[i].statusUsuario = 0;
									printf("\nUsuario inativado");
								}
								}else{
									printf("\nUsuario inativo, deseja ativar? \n [1] - SIM | [2] - NAO \nResp.: ");
								scanf("%d", &op);
								if (op ==1){
									bdUsuario[i].statusUsuario = 1;
									printf("\nUsuario reativado");
								}
								}
							getch();
							i=9;
							break;
							
							case 5:
									printf("\ndigite sua senha: ");
									gets(bdUsuario[i].senhaUsuario);
									printf("\ndigite sua senha novamente: ");
									gets(confirmaSenha);
									
										if(strcmp(bdUsuario[i].senhaUsuario, confirmaSenha)!=0){
									
											while(strcmp(bdUsuario[i].senhaUsuario, confirmaSenha)!=0){
													
													printf("\nSenha incorreta! \n");
													printf("\ndigite sua senha: ");
													gets(bdUsuario[i].senhaUsuario);
													printf("\ndigite sua senha novamente: ");
													gets(confirmaSenha);
											}
										}
								
							printf("\nId.....: %d\n", bdUsuario[i].codUsuario);
							printf("Nome...: %s\n", bdUsuario[i].nomeUsuario);
							printf("CPF....: %s\n", bdUsuario[i].cpfUsuario);
							printf("Login..: %s\n", bdUsuario[i].loginUsuario);
							printf("Senha..: %s\n", bdUsuario[i].senhaUsuario);
							printf("Status.: %d\n", bdUsuario[i].statusUsuario);
							printf("\nPressione uma tecla para continuar...\n");
							getch();
							i=9;		
							break;
							
							default:
								printf("Opcao invalida. \nPressione uma tecla para continuar...");
								return 1;
								getch();
							break;
							}
						}
						teste = -1;
				}else {
					teste++;
						if(teste == 9){
							printf("\nUsuario nao encontrado. \n\n");
						}
				}
				
			}
			printf("\nDeseja continar alterando?\n [1] - Sim  |  [2] - Nao\n Resp.: ");
			scanf("%d", &op);
			if(op==1){
				return 1;
			} else {
				return 2;
			}
		}
	
	}

int menuUsuario(){
	linha("Menu usuario");

	printf("\n\[1] - Incluir\n[2] - Pesquisar\n[3] - Alterar\n[4] - Voltar\nResp.:");
	scanf("%d",&op);
		while(op!=5){

		switch(op){
			case 1:
				fflush(stdin);
				valida = 1;
				while(valida != 2){
					valida = inUsuario();
				}
				menuUsuario();
				break;
			case 2:
				valida = 1;
				while(valida != 2){
					valida = pesUsuario();
				}
				menuUsuario();
				break;
			case 3:
				fflush(stdin);
				valida = 1;

				while(valida != 2){
					valida = altUsuario();
				}
				menuUsuario();
				break;
			case 4:
				fflush(stdin);
				valida = 1;
				while(valida != 2){
					valida = mainMenu();
				}
				
				break;
			default:
				printf("\n opcao invalida\n ");
				mainMenu();
			}
	}

	
}

int inicia = 0;
void iniciaVariavel(){

	Livro livro1, livro2;

	strcpy(livro1.autorl,"Herbert Schildt");
	strcpy(livro1.editoral,"Pearson");
	strcpy(livro1.isbnl, "97885346");
	livro1.nLivrosDisponiveis = 5;
	strcpy(livro1.nomel,"C Completo e Total");
	livro1.qt = 5;

	strcpy(livro2.autorl,"Herbert Schildt");
	strcpy(livro2.editoral,"Pearson");
	strcpy(livro2.isbnl, "97885347");
	livro2.nLivrosDisponiveis = 5;
	strcpy(livro2.nomel,"C++ Completo e Total");
	livro2.qt = 5;

	bdLivro[0] = livro1;
	bdLivro[1] = livro2;

printf("%s", bdLivro[0].nomel);

	Consulente consulente1, consulente2;

	consulente1.cepC  = 0450230;
	strcpy(consulente1.compC , "Pq. cocaia");
	strcpy(consulente1.cpfC  , "12345678901");
	consulente1.nLivrosEmprestados = 0;
	strcpy(consulente1.nomeC , "Nadia Fujimoto");
	regC++;
	consulente1.regiC = regC;
	strcpy(consulente1.rgC  , "355627897");
	strcpy(consulente1.ruaC , "Dr. Nuno Guerner de Almeida");
	consulente1.status = 1;
	consulente1.telC  = 958610424;

	consulente2.cepC  = 0450220;
	strcpy(consulente2.compC , "Pq. cocaia");
	strcpy(consulente2.cpfC  , "43053286823");
	consulente2.nLivrosEmprestados = 0;
	strcpy(consulente2.nomeC , "Kevyn Marinho");
	regC++;
	consulente2.regiC = regC;
	strcpy(consulente2.rgC  , "386200877");
	strcpy(consulente2.ruaC , "Ugo Foscolo");
	consulente2.status = 1;
	consulente2.telC = 958610424;

	bdconsulente[0] = consulente1;
	bdconsulente[1] = consulente2;
	inicia = 1;
	
	usuario admin;
	fflush(stdin);
	strcpy(admin.cpfUsuario,"xxxxxxxxxx");
	fflush(stdin);
	strcpy(admin.loginUsuario,"admin");
	strcpy(admin.nomeUsuario,"admin");
	strcpy(admin.senhaUsuario,"admin");
	admin.statusUsuario = 1;
	admin.codUsuario = regU+1;
	bdUsuario[0] = admin;
	regU++;
	
	
}

int mainMenu(){

	system("cls");

	linha("Menu Principal");
	printf("[1] - Acervo\n[2] - Consulente\n[3] - Movimentacao\n[4] - Usuario\n\nResp.: ");
	scanf("%d",&op);

	while(op!=5){

		switch(op){
			case 1:
				fflush(stdin);
				valida = 1;
				while(valida != 2){
					valida = menuLivro();
				}
				mainMenu();
				break;
			case 2:
				valida = 1;
				while(valida != 2){
					valida = menuConsulente();
				}
				mainMenu();
				break;
			case 3:
				fflush(stdin);
				valida = 1;

				while(valida != 2){
					valida = menuMovimentacao();
				}
				mainMenu();
				break;
			case 4:
				fflush(stdin);
				valida = 1;
				while(valida != 2){
					valida = menuUsuario();
				}
				mainMenu();
				break;
			default:
				printf("\n opcao invalida\n ");
				mainMenu();
			}
	}

	return;
}

int main(){	
	if (inicia == 0){
		iniciaVariavel();
	}

	mainMenu();
	return 0;
	system("EXIT");
}
