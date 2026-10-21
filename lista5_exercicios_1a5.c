#include <stdio.h>
#include <stdlib.h>

#define PI 3.1414592   /* valor de PI pedido no enunciado */

/* EXERCICIO 1 - Retorna o maior entre dois numeros */
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

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("O maior numero e: %.2f\n", maior(n1, n2));
}

/* EXERCICIO 2 - Mostra o mes e a quantidade de dias */
void mostraMes(int numero)
{
    switch (numero)
    {
        case 1:  printf("janeiro - 31 dias\n");   break;
        case 2:  printf("fevereiro - 28 dias (29 em ano bissexto)\n"); break;
        case 3:  printf("marco - 31 dias\n");     break;
        case 4:  printf("abril - 30 dias\n");     break;
        case 5:  printf("maio - 31 dias\n");      break;
        case 6:  printf("junho - 30 dias\n");     break;
        case 7:  printf("julho - 31 dias\n");     break;
        case 8:  printf("agosto - 31 dias\n");    break;
        case 9:  printf("setembro - 30 dias\n");  break;
        case 10: printf("outubro - 31 dias\n");   break;
        case 11: printf("novembro - 30 dias\n");  break;
        case 12: printf("dezembro - 31 dias\n");  break;
        default: printf("Numero invalido! Digite um valor de 1 a 12.\n");
    }
}

void exercicio2()
{
    int mes;

    printf("Digite o numero do mes (1 a 12): ");
    scanf("%d", &mes);

    mostraMes(mes);
}

/* EXERCICIO 3 - Converte Fahrenheit para Celsius */
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

    printf("%.2f F = %.2f C\n", f, fahrenheitParaCelsius(f));
}

/* EXERCICIO 4 - Volume do cilindro: V = PI * raio^2 * altura */
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

/* EXERCICIO 5 - Volume da esfera: V = 4/3 * PI * raio^3 */
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

/* PROGRAMA PRINCIPAL - menu para testar os exercicios */
int main()
{
    int opcao;

    do
    {
        printf("\nLISTA DE EXERCICIOS - PARTE 1\n");
        printf(" 1 - Maior de dois numeros\n");
        printf(" 2 - Mes e quantidade de dias\n");
        printf(" 3 - Fahrenheit para Celsius\n");
        printf(" 4 - Volume do cilindro\n");
        printf(" 5 - Volume da esfera\n");
        printf(" 0 - Sair\n");
        printf("Escolha um exercicio: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1:  exercicio1();  break;
            case 2:  exercicio2();  break;
            case 3:  exercicio3();  break;
            case 4:  exercicio4();  break;
            case 5:  exercicio5();  break;
            case 0:  printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
