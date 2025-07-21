O Ministério da Educação, através do Exame
Nacional de Desempenho dos Estudantes
(ENADE), promove avaliação dos cursos de
graduação ofertados pelas diversas Instituições de
Ensino Superior brasileiras.
Esses resultados, combinados com outras
variáveis, permitem ao MEC avaliar a qualidade
destes cursos, assim como das instituições que o
promovem.
Dessa forma, a cada curso de graduação avaliado
pelo ENADE, é atribuído um conceito denominado
Conceito Preliminar de Curso (CPC), na faixa de 1
(qualidade baixa) a 5 (ótima qualidade). Para se
chegar a este conceito, é necessária uma média
ponderada de diversos insumos que são
apresentados na tabela abaixo, juntamente com
os seus pesos:

Insumo Contribuição
Nota ENADE 20%
IDD 35 %
Doutores 15 %
Mestres 7,5 %
Regime de Trabalho 7,5 %

Organização Didático-
pedagógica 7,5 %

Infraestrutura 5 %
Oportunidades de Ampliação
Acadêmica e Profissional 2,5%
Depois de calculado o CPC contínuo através
dessa média, é necessário determinar o CPC faixa
a partir do seguinte mapeamento:
CPC contínuo CPC faixa
CPC < 0,945 1
0,945  CPC < 1,945 2
1,945  CPC < 2,945 3
2,945  CPC < 3,945 4
CPC  3,945 5
Cursos com CPC faixa inferiores a 3 são
considerados de qualidade abaixo da média
nacional (CPC insatisfatório).

Pede-se o desenvolvimento de uma aplicação em
C que obtenha de um arquivo texto as
informações dos diversos cursos de determinada
instituição. Para isto, cada linha do arquivo reunirá
as informações de um curso da instituição,
representadas por uma string (iniciada pelo código
do curso e com o número de alunos matriculados
como último dado da sequência), como no
exemplo abaixo:
Mesma ordem apresentada na tabela
1234|3.45|2.87|1.98|4.05|2.50|1.34|1.76|2.32|258
Todos os dados do arquivo devem ser lidos para
um vetor de structs, cada posição com os insumos
de um curso da instituição.
O programa deve permitir que o usuário opte pela
inclusão de novo(s) curso(s) no vetor ou processar
os seus dados. Neste último caso, deve exibir as
seguintes informações:
1) Para cada curso: código, CPC contínuo, CPC
faixa e a classificação deste (satisfatório ou
insatisfatório);
2) Para cada CPC faixa possível, exibir os cursos
que o obteve;
3) O IGC – Índice Geral de Cursos – da
instituição, contínuo e faixa (baseados na
mesma tabela de mapeamento apresentada
para o CPC), considerando que este é obtido a
partir de uma média ponderada de todos os
CPCs, onde o número de alunos matriculados
no curso representará o peso de seu CPC no
cálculo do IGC.