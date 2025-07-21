#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
	int codigoCur, quantAlunos, satisfacao, faixa;
	float notaENADE, idd, doutores, mestres, regimeTrab,
	orgDidatic, inflaestru, oportunidades, continuo;
} TCurso;

void printCursos(char arquivo[]);

void adicionarCurso(char arquivo[]);

int contLinha(char arquivo[]);

void armazenaCursosNoStruct(char arquivo[], int tamanhoArq, TCurso listaDeCursos[]);

void calculaCPC(int tamanhoStru, TCurso listaDeCursos[]);

void printCPC(int tamanhoStru, TCurso listaDeCursos[]);

void printFaixa(int tamanhoStru, TCurso listaDeCursos[]);

void calculaIGC(int tamanhoStru, TCurso listaDeCursos[],int *igcFaixa, float *igcContinuo);

int main ()
{

	char confirmacao;
	int quantLinhas, igcFaixa;
	float igcContinuo;

	//declara uma array pro struct mas sem declarar a quantidade de elementos
	TCurso *listaDeCursos;

	//chama a função que printa todos os cursos e seus parametros cadastrados
	printCursos("cursos.txt");

	//pergunta se você gostaria de adicionar um cursos
	printf("\n\ngostaria de adicionar um curso? (S/N) ");

	//lê qual foi a resposta do usuario e altera pra maiuscula
	scanf(" %c", &confirmacao);
	confirmacao = toupper(confirmacao);
	
	//se o usuario respondeu que sim, ele chama a função de adicionar curso
	if(confirmacao == 'S'){
		printf("\n");
		adicionarCurso("cursos.txt");
	}

	//chama a função que conta a quantidade de linhas no arquivo e a armazena
	quantLinhas = contLinha("cursos.txt");
	
	//usa a locação dinamica pra declarar agora o tamanho da array de structs baseado na quantidade de linhas que tem no arquivo txt
	listaDeCursos = (TCurso*)malloc(sizeof(TCurso) * quantLinhas);

	//verifica se a locação de memoria deu certo, se não, notifica e encerra o programa
	if (listaDeCursos == NULL) {
        printf("\n\nErro na alocacao memoria!");
		return;
    }

	//pergunta se você gostaria de ver os cursos novamente, para caso você tenha alterado os cursos no arquivo txt
	printf("\n\ngostaria de ver os cursos? (S/N) ");

	//lê qual foi a resposta do usuario e altera pra maiuscula
	scanf(" %c", &confirmacao);
	confirmacao = toupper(confirmacao);

	//se o usuario respondeu que sim, printa na tela os cursos novamente
	if(confirmacao == 'S'){
		printf("\n");
		printCursos("cursos.txt");
		
	}

	
	//chama a função que armazena as informações de cada curso numa struct
	armazenaCursosNoStruct("cursos.txt", quantLinhas, listaDeCursos);

	//chama a função que calcula os CPCs e a satisfação
	calculaCPC(quantLinhas, listaDeCursos);


	//pergunta ao usuario se ele gostaria de ver o CPC de todos os cursos
	printf("\n\ngostaria de ver os CPCs de cada curso? (S/N) ");
	
	//lê qual foi a resposta do usuario e altera pra maiuscula
	scanf(" %c", &confirmacao);
	confirmacao = toupper(confirmacao);

	//se o usuario respondeu que sim, printa os CPCs na tela
	if(confirmacao == 'S'){
		printf("\nos CPCs dos cursos foram:\n\n");
		printCPC(quantLinhas, listaDeCursos);
	}
	
	//pergunta se o usuario gostaria de ver os cursos separados por faixa
	printf("\n\ngostaria de ver todos os cursos separados por CPC faixa? (S/N) ");

	//lê qual foi a resposta do usuario e altera pra maiuscula
	scanf(" %c", &confirmacao);
	confirmacao = toupper(confirmacao);

	//se o usuario respondeu que sim, pergunta qual faixa
	if(confirmacao == 'S'){

		//chama a função que printara os cursos separados por faixa
		printFaixa(quantLinhas, listaDeCursos);
	}

	
	//chama a função que calcula IGC
	calculaIGC(quantLinhas, listaDeCursos, &igcFaixa, &igcContinuo);

	//printa IGC continuo e IGC faixa
	printf("\n\n\no IGC Continuo da instituicao e: %.3f\no IGC faixa da instituicao e: %d", igcContinuo, igcFaixa);

}

void printCursos(char arquivo[]){

	char caracter;
	int termino = 0, i, numero;
	float racional;

	FILE *arq;
	//abre o arquivo "cursos.txt como leitura"
	arq = fopen(arquivo, "r");

	//printa a primeira linha da tabela, que vai ser o cabeçalho
	printf ("codigo do curso	nota ENADE	idd		doutores	mestres		regimeTrab	orgDidatic	inflaestru	oportunidades	quantidade de alunos\n");

	//verifica se o arquivo foi aberto corretamente
	if (arq == NULL)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
	}
	else
	{
		//enquanto não chegar no fim do arquivo
		while (termino != 1)
		{
			//lê e printa o codigo do curso 
			fscanf(arq, "%d", &numero);
			printf("%d", numero);

			//um for que roda 8 vezes, um pra cada dado float
			for(i=0;i<8;i++){
			
				//avança o leitor do arquivo para o "|", mas não o armazena
				fscanf(arq, "%*c");
				//printa duas tabelações
				printf("\t\t");

				//lê e printa os valores que são float
				fscanf(arq, "%f", &racional);
				printf("%.2f", racional);


			}

			//avança o leitor do arquivo para o "|", mas não o armazena
			fscanf(arq, "%*c");
			printf("\t\t");

			//lê e printa a quantidade de alunos
			fscanf(arq, "%d", &numero);
			printf("%d", numero);

			//se o proximo caracter for o fim do arquivo, altera o valor da variavel "termino" para que encerre o while
			if(fscanf(arq, "%c", &caracter) == EOF){
				termino = 1;
			}else{
				//se não, printa uma quebra de linha e continue o while
				printf("\n");
			}

		}
		
		//fecha o arquivo
		fclose (arq);
		
	}

}

void adicionarCurso (char arquivo[]){
	
	//declaração de variáveis
	char confirmacao;
	int num;
	float num2;
	FILE *arq;  
	
	//abrindo os arquivos
	arq = fopen (arquivo, "a");	
	
	//verificando se ocorreu erro na abertura dos arquivos
	if (!arq){

		printf ("\n\nErro na abertura do arquivo!\n");
		
	}
	else
	{
		
		//printa uma quebra de linha
		fprintf (arq, "\n" );

		//pergunta as informações do curso e já as coloca no arquivo 
		printf("\nentre com o codigo do curso: ");
		scanf("%d", &num);
		fprintf(arq, "%d|", num);

		printf("\nentre com a nota enade: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com o idd: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com o doutores: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com o mestres: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com o regime de trabalho: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com a organizacao Didatico pedagogica: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com a infraestrutura: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);

		printf("\nentre com a oportunidades de ampliacao academica e profissional: ");
		scanf("%f", &num2);
		fprintf(arq, "%.2f|", num2);
		
		printf("\nentre com a quantida de alunos: ");
		scanf("%d", &num);
		fprintf(arq, "%d", num);


		
		//fechando os arquivos
		fclose (arq);
		
		//pergunta se o usuario gostaria de adicionar mais algum curso, armazena a resposta e a coloca em maiuscula
		printf("\ngostaria de adicionar mais um curso? (S/N) ");
		scanf(" %c", &confirmacao);
		confirmacao = toupper(confirmacao);

		//se o usuario respondeu que sim, chama a função novamente
		if(confirmacao == 'S'){
			adicionarCurso(arquivo);
		}

	}
}

int contLinha(char arquivo[]){

	char caracter;
	int cont = 1;

	FILE *arq;
	//abre o arquivo "cursos.txt como leitura"
	arq = fopen(arquivo, "r");

	//verifica se o arquivo foi aberto corretamente
	if (arq == NULL)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
		return 0;
	}
	else
	{
		//enquanto não chegar no fim do arquivo
		while (fscanf(arq, "%c", &caracter) != EOF)
		{
			
			//a cada quebra de linha, adiciona 1 ao contador
			if(caracter == '\n'){
				cont++;
			}

		}
		
		//fecha o arquivo
		fclose (arq);
		return cont;
	}

}

void armazenaCursosNoStruct(char arquivo[], int tamanhoArq, TCurso listaDeCursos[]){

	
	int i, numero;
	float racional;

	FILE *arq;
	//abre o arquivo "cursos.txt como leitura"
	arq = fopen(arquivo, "r");

	//verifica se o arquivo foi aberto corretamente
	if (arq == NULL)
	{
		printf ("\n\nErro na abertura do arquivo!\n");
		
	}else{

		//for que percorre cada linha lendo os valores da linha e armazendo no struct
		for(i = 0; i < tamanhoArq; i++){
		
			fscanf(arq, "%d", &numero);
			listaDeCursos[i].codigoCur = numero;
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].notaENADE = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].idd = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].doutores = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].mestres = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].regimeTrab = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].orgDidatic = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].inflaestru = racional; 
			fscanf(arq, "%*c");

			fscanf(arq, "%f", &racional);
			listaDeCursos[i].oportunidades = racional;
			fscanf(arq, "%*c");

			fscanf(arq, "%d", &numero);
			listaDeCursos[i].quantAlunos = numero;
			fscanf(arq, "%*c");
		}

		
		//fecha o arquivo
		fclose(arq);
		
	}
	
}

void calculaCPC( int tamanhoStru, TCurso listaDeCursos[]){

	int i;
	float somatorio = 0;
	
	//for para ler individualmente o struct de cada curso
	for(i=0;i<tamanhoStru;i++){

		//vai adicionando no somatorio o valor de cada nota multiplicado pela contribuição de cada uma
		somatorio+= listaDeCursos[i].notaENADE*0.2;
		somatorio+= listaDeCursos[i].idd*0.35;
		somatorio+= listaDeCursos[i].doutores*0.15;
		somatorio+= listaDeCursos[i].mestres*0.075;
		somatorio+= listaDeCursos[i].orgDidatic*0.075;
		somatorio+= listaDeCursos[i].regimeTrab*0.075;
		somatorio+= listaDeCursos[i].inflaestru*0.05;
		somatorio+= listaDeCursos[i].oportunidades*0.025;

		//passa esse somatorio para o valor do cpc continuo
		listaDeCursos[i].continuo = somatorio;

		//zera o somatorio
		somatorio = 0;

		//baseado no cpc continuo, diz qual faixa ele pertence
		if(listaDeCursos[i].continuo<0.945){
			listaDeCursos[i].faixa = 1;
		}else{
			if(listaDeCursos[i].continuo<1.945){
				listaDeCursos[i].faixa = 2;
			}else{
				if(listaDeCursos[i].continuo<2.945){
					listaDeCursos[i].faixa = 3;
				}else{
					if(listaDeCursos[i].continuo<3.945){
						listaDeCursos[i].faixa = 4;
					}else{
						listaDeCursos[i].faixa = 5;
					}
				}
			}
		}

		//se faixa menor que 3, insatisfatorio, se não, satisfatorio
		if(listaDeCursos[i].faixa < 3){
			listaDeCursos[i].satisfacao = 0;
		}else{
			listaDeCursos[i].satisfacao = 1;
		}

	}
	
}

void printCPC(int tamanhoStru, TCurso listaDeCursos[]){

	int i;

	//um for que percorre os structs
	for(i=0;i<tamanhoStru;i++){

		//se satisfacao do struct[i] for igual a 1, printa todos os cpcs e diz que foi satisfatorio, se não printa todos os cpcs e diz que foi insatisfatorio
		if(listaDeCursos[i].satisfacao == 1){
			printf("curso: %d |	 CPC continuo: %.3f	 |	 CPC faixa: %d	 |	 satisfacao: SATISFATORIO\n", listaDeCursos[i].codigoCur, listaDeCursos[i].continuo, listaDeCursos[i].faixa);
		}else{
			printf("curso: %d |	 CPC continuo: %.3f	 |	 CPC faixa: %d	 |	 satisfacao: INSATISFATORIO\n", listaDeCursos[i].codigoCur, listaDeCursos[i].continuo, listaDeCursos[i].faixa);
		}

	}
}

void printFaixa(int tamanhoStru, TCurso listaDeCursos[]){

	int i, j, cont = 0;

	for(i=1;i<=5;i++){


		printf("\nos cursos da faixa %d sao: ", i);

		//um for que percorre os structs
		for(j=0;j<tamanhoStru;j++){

			cont = 0;

			//se o igc faixa do estruct[j] for igual a faixa pedida pelo usuario, printa ocodigo do curso, uma '|' e incrementa um contador
			if(listaDeCursos[j].faixa == i){
				printf("%d | ", listaDeCursos[j].codigoCur);
				cont++;
			}

		}
		//se contador igual a 0, printa que não há cursos na faixa escolhida pelo usuario
		if(cont == 0){
				printf(" nao ha nenhum curso nessa faixa");
			}
	}
}

void calculaIGC(int tamanhoStru, TCurso listaDeCursos[],int *igcFaixa, float *igcContinuo){

	int i, somatorioAlunos = 0;
	float somatorioCPCs = 0;

	//um for que percorre os structs armazenando os alunos e armazendo a soma dos cpcs
	for(i=0;i<tamanhoStru;i++){

		somatorioAlunos+=listaDeCursos[i].quantAlunos;
		somatorioCPCs+=listaDeCursos[i].continuo*listaDeCursos[i].quantAlunos;
	}

	//calcula o igc continuo
	*igcContinuo = somatorioCPCs/somatorioAlunos;

	//calcula a faixa do igc
	if(*igcContinuo<0.945){
			*igcFaixa = 1;
		}else{
			if(*igcContinuo<1.945){
				*igcFaixa = 2;
			}else{
				if(*igcContinuo<2.945){
					*igcFaixa = 3;
				}else{
					if(*igcContinuo<3.945){
						*igcFaixa = 4;
					}else{
						*igcFaixa = 5;
					}
				}
			}
		}

}