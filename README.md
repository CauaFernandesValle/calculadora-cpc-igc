Calculadora de CPC e IGC em Linguagem C

Projeto acadêmico para a disciplina de Fundamentos de Programação

Este repositório contém o código-fonte de uma aplicação de console desenvolvida em Linguagem C. O objetivo do programa é calcular o Conceito Preliminar de Curso (CPC) para múltiplos cursos e o Índice Geral de Cursos (IGC) para uma instituição de ensino, com base em dados de entrada fornecidos através de um arquivo de texto.

O projeto demonstra a aplicação de conceitos fundamentais da programação estruturada, incluindo manipulação de arquivos, alocação dinâmica de memória e utilização de structs para a organização de dados complexos.

Funcionalidades
Leitura de Dados Estruturados: O programa realiza a leitura de dados de um arquivo (cursos.txt) e os armazena em um vetor de structs alocado dinamicamente, onde cada elemento representa um curso.

Entrada de Dados Interativa: Oferece ao usuário a opção de adicionar novos registros de cursos ao arquivo de dados em tempo de execução.

Cálculo de CPC: Para cada curso processado, o sistema calcula os seguintes indicadores:

CPC Contínuo: Média ponderada de oito indicadores de qualidade.

CPC Faixa: Valor discreto de 1 a 5, mapeado a partir do CPC Contínuo.

Classificação de Satisfação: Determina se o curso é "Satisfatório" ou "Insatisfatório" com base no seu CPC Faixa.

Cálculo de IGC: Processa os dados de todos os cursos para obter o índice geral da instituição:

IGC Contínuo: Média dos CPCs contínuos, ponderada pelo número de alunos em cada curso.

IGC Faixa: Classificação da instituição de 1 a 5, baseada no IGC Contínuo.

Geração de Relatórios: Exibe os resultados de forma organizada no console:

Um relatório individual para cada curso com seu código, CPC Contínuo, CPC Faixa e classificação.

Um relatório que agrupa e lista os cursos de acordo com cada uma das cinco faixas de CPC.

Um relatório final apresentando o IGC Contínuo e o IGC Faixa da instituição.

Tecnologias Utilizadas
Linguagem C

Bibliotecas Padrão: stdio.h, stdlib.h, ctype.h

Técnicas Aplicadas: manipulação de arquivos, ponteiros e structs.

Formato do Arquivo de Entrada (cursos.txt)
O programa requer que cada linha do arquivo cursos.txt represente um curso, com os dados separados pelo caractere pipe (|).

Ordem dos campos:
codigo do curso|nota enade|idd|doutores|mestres|regime de trabalho|organização didático-pedagógica|infraestrutura|oportunidades de ampliação acadêmica e profissional|quantidade de alunos do curso

Exemplo de uma linha válida:

1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258
