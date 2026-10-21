#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* EXERCICIO 6 - Formas de pagamento */

/* Imprime as opcoes, le e retorna a opcao escolhida */
char escolheOpcao()
{
    char opcao;

    printf("\nFORMAS DE PAGAMENTO\n");
    printf("a) A vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preco da etiqueta)\n");
    printf("c) De 3 ate 10 vezes com 3%% de juros ao mes (compras acima de R$ 100,00)\n");
    printf("Digite a opcao desejada: ");
    scanf(" %c", &opcao);   /* o espaco antes do %c ignora o ENTER anterior */

    return opcao;
}

/* Opcao a: a vista com 10% de desconto */
void pagamentoAVista(float total)
{
    float valorFinal;
    valorFinal = total - (total * 0.10);
    printf("Valor a vista: R$ %.2f\n", valorFinal);
}

/* Opcao b: duas vezes sem juros */
void pagamentoDuasVezes(float total)
{
    float parcela;
    parcela = total / 2;
    printf("2 parcelas de R$ %.2f\n", parcela);
    printf("Valor total: R$ %.2f\n", total);
}

/* Opcao c: de 3 a 10 vezes com 3% de juros ao mes */
void pagamentoParcelado(float total)
{
    int vezes, i;
    float totalComJuros, parcela;

    if (total <= 100)
    {
        printf("Opcao disponivel somente para compras acima de R$ 100,00.\n");
        return;
    }

    printf("Em quantas vezes (3 a 10)? ");
    scanf("%d", &vezes);

    if (vezes < 3 || vezes > 10)
    {
        printf("Numero de parcelas invalido!\n");
        return;
    }

    /* aplica 3% de juros para cada mes (juros compostos) */
    totalComJuros = total;
    for (i = 1; i <= vezes; i++)
    {
        totalComJuros = totalComJuros * 1.03;
    }

    parcela = totalComJuros / vezes;

    printf("%d parcelas de R$ %.2f\n", vezes, parcela);
    printf("Valor total: R$ %.2f\n", totalComJuros);
}

void exercicio6()
{
    float total;
    char opcao;

    printf("Digite o total gasto pelo cliente: R$ ");
    scanf("%f", &total);

    opcao = escolheOpcao();

    if (opcao == 'a' || opcao == 'A')
        pagamentoAVista(total);
    else if (opcao == 'b' || opcao == 'B')
        pagamentoDuasVezes(total);
    else if (opcao == 'c' || opcao == 'C')
        pagamentoParcelado(total);
    else
        printf("Opcao invalida!\n");
}

/* EXERCICIO 7 - Locadora: 1 locacao gratis a cada 15 filmes */
#define TAM_LOCADORA 500

/* Recebe o vetor A e preenche o vetor B com as locacoes gratis */
void calculaGratis(int A[], int B[])
{
    int i;
    for (i = 0; i < TAM_LOCADORA; i++)
    {
        B[i] = A[i] / 15;   /* divisao inteira */
    }
}

void exercicio7()
{
    int A[TAM_LOCADORA], B[TAM_LOCADORA];
    int i;

    /* Para testar, o vetor e preenchido com valores aleatorios (0 a 60),
       ja que digitar 500 valores seria inviavel. */
    for (i = 0; i < TAM_LOCADORA; i++)
    {
        A[i] = rand() % 61;
    }

    calculaGratis(A, B);

    printf("Mostrando os 10 primeiros clientes:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Cliente %3d: %2d filmes -> %d locacao(oes) gratis\n",
               i + 1, A[i], B[i]);
    }
}

/* EXERCICIO 8 - Trocas na matriz 10x10 (no C os indices comecam em 0: linha 2 = indice 1, etc.) */
void trocasMatriz(int A[10][10])
{
    int i, aux;
    int auxVetor[10];

    /* troca a linha 2 com a linha 8 (indices 1 e 7) */
    for (i = 0; i < 10; i++)
    {
        aux = A[1][i];
        A[1][i] = A[7][i];
        A[7][i] = aux;
    }

    /* troca a coluna 4 com a coluna 10 (indices 3 e 9) */
    for (i = 0; i < 10; i++)
    {
        aux = A[i][3];
        A[i][3] = A[i][9];
        A[i][9] = aux;
    }

    /* troca a diagonal principal com a secundaria */
    for (i = 0; i < 10; i++)
    {
        aux = A[i][i];
        A[i][i] = A[i][9 - i];
        A[i][9 - i] = aux;
    }

    /* troca a linha 5 com a coluna 10 (linha indice 4, coluna indice 9) */
    for (i = 0; i < 10; i++)
    {
        auxVetor[i] = A[4][i];      /* guarda a linha 5 */
    }
    for (i = 0; i < 10; i++)
    {
        A[4][i] = A[i][9];          /* linha 5 recebe a coluna 10 */
    }
    for (i = 0; i < 10; i++)
    {
        A[i][9] = auxVetor[i];      /* coluna 10 recebe a antiga linha 5 */
    }
}

void imprimeMatriz10(int A[10][10])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

void exercicio8()
{
    int A[10][10];
    int i, j;

    /* preenche com valores faceis de acompanhar: 11, 12, ... */
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            A[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    printf("Matriz original:\n");
    imprimeMatriz10(A);

    trocasMatriz(A);

    printf("\nMatriz alterada:\n");
    imprimeMatriz10(A);
}

/* EXERCICIO 9 - Matriz 61x10: soma das colunas na 61a linha */
void somaColunas(int M[61][10])
{
    int i, j, soma;

    for (j = 0; j < 10; j++)
    {
        soma = 0;
        for (i = 0; i < 60; i++)
        {
            soma = soma + M[i][j];
        }
        M[60][j] = soma;   /* 61a linha = indice 60 */
    }
}

void exercicio9()
{
    int M[61][10];
    int i, j;

    /* Para testar, as 60 primeiras linhas recebem valores aleatorios (0 a 9) */
    for (i = 0; i < 60; i++)
    {
        for (j = 0; j < 10; j++)
        {
            M[i][j] = rand() % 10;
        }
    }

    somaColunas(M);

    printf("Soma de cada coluna (61a linha da matriz):\n");
    for (j = 0; j < 10; j++)
    {
        printf("Coluna %2d: %d\n", j + 1, M[60][j]);
    }
}

/* EXERCICIO 10 - Idade em anos, meses e dias */
int diasDoMes(int mes, int ano)
{
    if (mes == 2)
    {
        /* ano bissexto */
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
            return 29;
        else
            return 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;
    else
        return 31;
}

void calculaIdade(int diaNasc, int mesNasc, int anoNasc)
{
    int diaAtual, mesAtual, anoAtual;
    int anos, meses, dias;
    time_t agora;
    struct tm *hoje;

    /* pega a data de hoje do computador */
    agora = time(NULL);
    hoje = localtime(&agora);
    diaAtual = hoje->tm_mday;
    mesAtual = hoje->tm_mon + 1;
    anoAtual = hoje->tm_year + 1900;

    anos  = anoAtual - anoNasc;
    meses = mesAtual - mesNasc;
    dias  = diaAtual - diaNasc;

    /* se os dias ficaram negativos, "pega emprestado" um mes */
    if (dias < 0)
    {
        meses--;
        if (mesAtual == 1)
            dias = dias + diasDoMes(12, anoAtual - 1);
        else
            dias = dias + diasDoMes(mesAtual - 1, anoAtual);
    }

    /* se os meses ficaram negativos, "pega emprestado" um ano */
    if (meses < 0)
    {
        anos--;
        meses = meses + 12;
    }

    printf("Data de hoje: %02d/%02d/%d\n", diaAtual, mesAtual, anoAtual);
    printf("Idade: %d anos, %d meses e %d dias\n", anos, meses, dias);
}

void exercicio10()
{
    int dia, mes, ano;

    printf("Digite o dia de nascimento: ");
    scanf("%d", &dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);

    calculaIdade(dia, mes, ano);
}

/* PROGRAMA PRINCIPAL - menu para testar os exercicios */
int main()
{
    int opcao;

    srand(time(NULL));

    do
    {
        printf("\nLISTA DE EXERCICIOS - PARTE 2\n");
        printf(" 6 - Formas de pagamento\n");
        printf(" 7 - Locadora (locacoes gratis)\n");
        printf(" 8 - Trocas na matriz 10x10\n");
        printf(" 9 - Soma das colunas (matriz 61x10)\n");
        printf("10 - Idade em anos, meses e dias\n");
        printf(" 0 - Sair\n");
        printf("Escolha um exercicio: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 6:  exercicio6();  break;
            case 7:  exercicio7();  break;
            case 8:  exercicio8();  break;
            case 9:  exercicio9();  break;
            case 10: exercicio10(); break;
            case 0:  printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
