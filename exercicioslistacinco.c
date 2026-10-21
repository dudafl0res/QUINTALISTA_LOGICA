/*
 * LÓGICA DE PROGRAMAÇÃO E ALGORITMOS - GPE17N20094
 * Lista de exercícios - Funções e Procedimentos
 *
 * Cada exercício está separado em funções.
 * O main() mostra um menu para testar qualquer exercício.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define PI 3.1414592   /* valor de PI pedido no enunciado */

/* EXERCÍCIO 1 - Retorna o maior entre dois números */
float maior(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}

void exercicio1()
{
    float n1, n2;

    printf("Digite o primeiro número: ");
    scanf("%f", &n1);
    printf("Digite o segundo número: ");
    scanf("%f", &n2);

    printf("O maior número é: %.2f\n", maior(n1, n2));
}

/* EXERCÍCIO 2 - Mostra o mês e a quantidade de dias */
void mostraMes(int numero)
{
    switch (numero)
    {
        case 1:  printf("janeiro - 31 dias\n");   break;
        case 2:  printf("fevereiro - 28 dias (29 em ano bissexto)\n"); break;
        case 3:  printf("março - 31 dias\n");     break;
        case 4:  printf("abril - 30 dias\n");     break;
        case 5:  printf("maio - 31 dias\n");      break;
        case 6:  printf("junho - 30 dias\n");     break;
        case 7:  printf("julho - 31 dias\n");     break;
        case 8:  printf("agosto - 31 dias\n");    break;
        case 9:  printf("setembro - 30 dias\n");  break;
        case 10: printf("outubro - 31 dias\n");   break;
        case 11: printf("novembro - 30 dias\n");  break;
        case 12: printf("dezembro - 31 dias\n");  break;
        default: printf("Número inválido! Digite um valor de 1 a 12.\n");
    }
}

void exercicio2()
{
    int mes;

    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &mes);

    mostraMes(mes);
}

/* EXERCÍCIO 3 - Converte Fahrenheit para Celsius */
float fahrenheitParaCelsius(float f)
{
    float c;
    c = (f - 32.0) * (5.0 / 9.0);
    return c;
}

void exercicio3()
{
    float f;

    printf("Digite a temperatura em Fahrenheit: ");
    scanf("%f", &f);

    printf("%.2f °F = %.2f °C\n", f, fahrenheitParaCelsius(f));
}

/* EXERCÍCIO 4 - Volume do cilindro: V = PI * raio² * altura */
float volumeCilindro(float altura, float raio)
{
    float volume;
    volume = PI * raio * raio * altura;
    return volume;
}

void exercicio4()
{
    float altura, raio;

    printf("Digite a altura do cilindro: ");
    scanf("%f", &altura);
    printf("Digite o raio do cilindro: ");
    scanf("%f", &raio);

    printf("Volume do cilindro: %.2f\n", volumeCilindro(altura, raio));
}

/* EXERCÍCIO 5 - Volume da esfera: V = 4/3 * PI * raio³ */
float volumeEsfera(float raio)
{
    float volume;
    volume = (4.0 / 3.0) * PI * raio * raio * raio;
    return volume;
}

void exercicio5()
{
    float raio;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    printf("Volume da esfera: %.2f\n", volumeEsfera(raio));
}

/* EXERCÍCIO 6 - Formas de pagamento */

/* Imprime as opções, lê e retorna a opção escolhida */
char escolheOpcao()
{
    char opcao;

    printf("\nFORMAS DE PAGAMENTO\n");
    printf("a) À vista com 10%% de desconto\n");
    printf("b) Em duas vezes (preço da etiqueta)\n");
    printf("c) De 3 até 10 vezes com 3%% de juros ao mês (compras acima de R$ 100,00)\n");
    printf("Digite a opção desejada: ");
    scanf(" %c", &opcao);   /* o espaço antes do %c ignora o ENTER anterior */

    return opcao;
}

/* Opção a: à vista com 10% de desconto */
void pagamentoAVista(float total)
{
    float valorFinal;
    valorFinal = total - (total * 0.10);
    printf("Valor à vista: R$ %.2f\n", valorFinal);
}

/* Opção b: duas vezes sem juros */
void pagamentoDuasVezes(float total)
{
    float parcela;
    parcela = total / 2;
    printf("2 parcelas de R$ %.2f\n", parcela);
    printf("Valor total: R$ %.2f\n", total);
}

/* Opção c: de 3 a 10 vezes com 3% de juros ao mês */
void pagamentoParcelado(float total)
{
    int vezes, i;
    float totalComJuros, parcela;

    if (total <= 100)
    {
        printf("Opção disponível somente para compras acima de R$ 100,00.\n");
        return;
    }

    printf("Em quantas vezes (3 a 10)? ");
    scanf("%d", &vezes);

    if (vezes < 3 || vezes > 10)
    {
        printf("Número de parcelas inválido!\n");
        return;
    }

    /* aplica 3% de juros para cada mês (juros compostos) */
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
        printf("Opção inválida!\n");
}

/* EXERCÍCIO 7 - Locadora: 1 locação grátis a cada 15 filmes */
#define TAM_LOCADORA 500

/* Recebe o vetor A e preenche o vetor B com as locações grátis */
void calculaGratis(int A[], int B[])
{
    int i;
    for (i = 0; i < TAM_LOCADORA; i++)
    {
        B[i] = A[i] / 15;   /* divisão inteira */
    }
}

void exercicio7()
{
    int A[TAM_LOCADORA], B[TAM_LOCADORA];
    int i;

    /* Para testar, o vetor é preenchido com valores aleatórios (0 a 60),
       já que digitar 500 valores seria inviável. */
    for (i = 0; i < TAM_LOCADORA; i++)
    {
        A[i] = rand() % 61;
    }

    calculaGratis(A, B);

    printf("Mostrando os 10 primeiros clientes:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Cliente %3d: %2d filmes -> %d locação(ões) grátis\n",
               i + 1, A[i], B[i]);
    }
}

/* EXERCÍCIO 8 - Trocas na matriz 10x10 (no C os índices começam em 0: linha 2 = índice 1, etc.) */
void trocasMatriz(int A[10][10])
{
    int i, aux;
    int auxVetor[10];

    /* troca a linha 2 com a linha 8 (índices 1 e 7) */
    for (i = 0; i < 10; i++)
    {
        aux = A[1][i];
        A[1][i] = A[7][i];
        A[7][i] = aux;
    }

    /* troca a coluna 4 com a coluna 10 (índices 3 e 9) */
    for (i = 0; i < 10; i++)
    {
        aux = A[i][3];
        A[i][3] = A[i][9];
        A[i][9] = aux;
    }

    /* troca a diagonal principal com a secundária */
    for (i = 0; i < 10; i++)
    {
        aux = A[i][i];
        A[i][i] = A[i][9 - i];
        A[i][9 - i] = aux;
    }

    /* troca a linha 5 com a coluna 10 (linha índice 4, coluna índice 9) */
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

    /* preenche com valores fáceis de acompanhar: 11, 12, ... */
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

/* EXERCÍCIO 9 - Matriz 61x10: soma das colunas na 61ª linha */
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
        M[60][j] = soma;   /* 61ª linha = índice 60 */
    }
}

void exercicio9()
{
    int M[61][10];
    int i, j;

    /* Para testar, as 60 primeiras linhas recebem valores aleatórios (0 a 9) */
    for (i = 0; i < 60; i++)
    {
        for (j = 0; j < 10; j++)
        {
            M[i][j] = rand() % 10;
        }
    }

    somaColunas(M);

    printf("Soma de cada coluna (61ª linha da matriz):\n");
    for (j = 0; j < 10; j++)
    {
        printf("Coluna %2d: %d\n", j + 1, M[60][j]);
    }
}

/* EXERCÍCIO 10 - Idade em anos, meses e dias */
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

    /* se os dias ficaram negativos, "pega emprestado" um mês */
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
    printf("Digite o mês de nascimento: ");
    scanf("%d", &mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);

    calculaIdade(dia, mes, ano);
}

/* PROGRAMA PRINCIPAL - menu para testar os exercícios */
int main()
{
    int opcao;

    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    do
    {
        printf("\nLISTA DE EXERCÍCIOS\n");
        printf(" 1 - Maior de dois números\n");
        printf(" 2 - Mês e quantidade de dias\n");
        printf(" 3 - Fahrenheit para Celsius\n");
        printf(" 4 - Volume do cilindro\n");
        printf(" 5 - Volume da esfera\n");
        printf(" 6 - Formas de pagamento\n");
        printf(" 7 - Locadora (locações grátis)\n");
        printf(" 8 - Trocas na matriz 10x10\n");
        printf(" 9 - Soma das colunas (matriz 61x10)\n");
        printf("10 - Idade em anos, meses e dias\n");
        printf(" 0 - Sair\n");
        printf("Escolha um exercício: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1:  exercicio1();  break;
            case 2:  exercicio2();  break;
            case 3:  exercicio3();  break;
            case 4:  exercicio4();  break;
            case 5:  exercicio5();  break;
            case 6:  exercicio6();  break;
            case 7:  exercicio7();  break;
            case 8:  exercicio8();  break;
            case 9:  exercicio9();  break;
            case 10: exercicio10(); break;
            case 0:  printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}