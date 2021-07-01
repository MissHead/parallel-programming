# parallel-programming
Disciplina de Programação Paralela utilizando openmpi

[1](https://github.com/MissHead/parallel-programming/blob/main/1.c) - Com base na estrutura aluno abaixo realize seguintes operações: 

![alt text](https://github.com/MissHead/parallel-programming/blob/main/1.png)

a) O processo 0 deverá alocar um vetor e preencher um vetor de N alunos digitados pelo usuário. O processo 0 ( o principal ) deverá alocar um vetor de alunos de tamanho N onde N será um valor digitado pelo usuário ou carregado diretamente no seu código. O valor de alunos pode ser 10,20, 30, ou seja, qualquer valor.


b) O Processo 1 deverá ler 1/3 (primeira parte) das matrículas e devolver para o processo 0. 

c) O processo 2 deverá ler 1/3 (segunda parte) das matrículas e devolver para o processo 0. 

d) O processo 3 deverá ler 1/3 (terceira parte) das matrículas e devolver para o processo 0. SUpondo que tenhamos 15 alunos. O processo 1 deverá ler a matricula de 5 alunos, o processo 2 de mais 5 alunos e o processo 3 dos outros 5 completando a leitura de todas as matriculas dos 15 alunos.

e) Cada processo (0-3) deverá ler uma das notas de cada aluno. Cada aluno possui 4 notas, cada processo deverá ler 1 nota. Por exemplo:
- Processo 0 lê a primeira nota do aluno A.
- Processo 1 lê a segunda nota do aluno A.
- Processo 2 lê a terceira nota do aluno A.
- Processo 3 lê a quarta nota do aluno A.

f) O processo 0 deverá mostrar na tela qual o aluno com o maior média.

---

[2](https://github.com/MissHead/parallel-programming/blob/main/2.c) - Faça um programa que siga as seguintes orientações: 

![alt text](https://github.com/MissHead/parallel-programming/blob/main/2.png)

a) Cada um dos 4 processos deverá ler um valor (x,y,w,z). 

b) O processo 0 deverá receber o valor lido pelo processo 1 e o processo 1 deverá receber o valor lido do processo 0.  

c) O processo 2 deverá receber o valor lido pelo processo 3 e o processo 3 deverá receber o valor lido pelo processo 2. 

d) O processo 0 deverá somar 1 no número recebido. 

e) O processo 1 deverá somar 2 no número recebido. 

f) O processo 2 deverá somar 3 no número recebido. 

g) O processo 3 deverá somar 4 no número recebido. 

h) O processo 0 deverá sumarizar todos os valores dos processos 0,1,2 e 3. 

i) Os processos 0,1,2 e 3 deverão saber o valor do somatório adquirido na etapa h. 

j) O processo  0 deverá multiplicar por 2 o valor do somatório. 

k) O processo 1 deverá multiplicar por 3 o valor do somatório. 

l) O processo  2deverá multiplicar por 4 o valor do somatório. 

m) O processo 3 deverá multiplicar o valor do somatório por 5. 

n) O processo 0 deverá enviar o produto calculado para o processo 1. 

o) O processo 1 deverá enviar para o processo 2 o produto calculado. 

p) O processo 2 deverá enviar para o processo 3 o produto calculado. 

q) O processo 3 deverá enviar para o processo 0 o produto calculado. 

r) O processo 0 deverá somar 10 no valor recebido. 

s) o processo 1 deverá somar 11 no valor recebido. 

t) o processo 2 deverá somar 12 no valor recebido. 

u) o processo 3 deverá somar 13 no valor recebido. 

v) O processo 0 deverá receber os valores de todos processos, realizar a sumarização e mostrar na tela o resultado.

---

[3](https://github.com/MissHead/parallel-programming/blob/main/3.c) - Construa um programa em C, utilizando a biblioteca omp.h que realize as seguintes instruções:

a) Dispare 3 threads onde todas devem falar seu ID

b) Apenas 1 das threads ( a 1ª disponível ) deve mostrar na tela os números pares de 1 a 10

c) Apenas 1 das threads ( a 1ª disponível ) deve mostrar na tela os números ímpares de 1 a 10

d) Apenas 1 das threads ( a 1ª disponível ) deve mostrar na tela os números primos entre 1 a 10

---

[4](https://github.com/MissHead/parallel-programming/blob/main/4.c) - Construa um programa em C, utilizando a biblioteca omp.h que diga quantos números primos há em um vetor de tamanho  n digitado pelo usuário e preenchido com valores de 1 a N de forma sequencial e paralela. Evidencie a melhora do desempenho utilizando programação paralela.

