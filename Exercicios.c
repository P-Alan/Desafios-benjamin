#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// VARIÁVEIS UNIVERSAIS
int menu = 1;
int rodando = 1;
int fim;
int loop = 1;

// VARIÁVEIS DE CADA QUESTÃO
int questao_bas, questao_med, questao_fib;

//======= BASKHARA =======
void bhaskara()
{
    // LAÇO PARA PODER ENTRAR NA QUESTÃO
    while (rodando == 1)
    {
        questao_bas = 1;
        // LAÇO PARA PODER REINICIAR A QUESTÃO
        while (questao_bas == 1)
        {
            // VARIÁVEIS DA QUESTÃO
            float a, b, c;

            printf("Digite os valores da fórmula de bhaskara (a, b, c):\n");
            scanf("%f", &a);
            scanf("%f", &b);
            scanf("%f", &c);

            float delta = (b * b) - (4 * a * c);

            // CÁLCULO
            if (delta >= 0)
            {
                float bhaskarapos = (-b + (sqrt(delta))) / (2 * a);
                float bhaskaraneg = (-b - (sqrt(delta))) / (2 * a);

                printf("%.2f é o x'\n", bhaskarapos);
                printf("%.2f é o x''\n\n", bhaskaraneg);

                while (loop == 1)
                {

                    printf("Pressione [1] para fazer um novo cálculo ou [0] para voltar ao menu: ");
                    scanf("%d", &fim);
                    if (fim == 1)
                    {
                        break;
                    }
                    if (fim == 0)
                    {
                        rodando = 0;
                        return;
                    }
                    else
                    {
                        printf("\n\n==========================\nINSIRA UM VALOR VÁLIDO!!!\n==========================\n\n");
                    }
                }
            }
            else
            {
                while (loop == 1)
                {

                    // ELSE PARA CASO VALORES INVÁLIDOS SEJAM INSERIDOS. COMO É O ULTIMO COMANDO DO LAÇO, PRESSIONAR '1' SÓ REINICIA O LAÇO

                    printf("valores inválidos (raiz negativa [%.2f]), precione '1' para digitar novos valores ou '0' para voltar ao menu ", delta);
                    scanf("%d", &fim);

                    if (fim == 1)
                    {
                        break;
                    }
                    if (fim == 0)
                    {
                        rodando = 0;
                        return;
                    }
                    else
                    {
                        printf("\n\n==========================\n INSIRA UM VALOR VÁLIDO!!!\n==========================\n\n");
                    }
                }
            }
        }
    }
}

/*OBS: DESCOBRIR COMO EVITAR O USO DE VÍRGULA E IMPEDIR QUE O USUÁRIO COLOQUE CARACTERES QUE NÃO SEJAM NÚMEROS NO CÁLCULO DA MÉDIA*/

//======= MÉDIA =======
void media()
{
    // LAÇO PARA PODER ENTRAR NA QUESTÃO
    while (rodando == 1)
    {
        questao_med = 1;
        // LAÇO PARA PODER REINICIAR A QUESTÃO
        while (questao_med == 1)
        {
            // VARIÁVEIS DA QUESTÃO
            float quantidade, quant_auxiliar;
            int quant_controle;
            float soma = 0;
            int contador = 0;

            printf("Insira um valor inteiro para quantos números você quer inserir: ");

            // IF PARA VERIFICAR SE O NÚMERO INSERIDO É INTEIRO
            if (scanf("%f", &quant_auxiliar) != 1 || quant_auxiliar != (int)quant_auxiliar)
            {
                while (getchar() != '\n')
                    ;

                while (loop == 1)
                {
                    printf("valor inválido. Aperte [1] para inserir um novo número inteiro ou [0] para voltar ao menu: ");
                    scanf("%i", &fim);
                    if (fim == 1)
                    {
                        break;
                    }
                    if (fim == 0)
                    {
                        rodando = 0;
                        return;
                    }
                    else
                    {
                        printf("\n\n==========================\n INSIRA UM VALOR VÁLIDO!!!\n==========================\n\n");
                    }
                }
            }

            // ELSE PARA CASO VALORES VÁLIDOS SEJAM INSERIDOS
            else
            {

                float valor;

                quantidade = quant_auxiliar;

                // LAÇO PARA INSERIR E ARMAZENAR A SOMA DOS VALORES
                for (quant_controle = 0; quant_controle < quantidade; quant_controle++)
                {
                    contador++;

                    printf("Digite o %i° número: ", contador);
                    scanf(" %f", &valor);

                    soma += valor;
                }

                // CÁLCULO DA MÉDIA
                float media = soma / quantidade;

                while (loop == 1)
                {
                    printf("A média dos valores digitados é de: %.2f\n\n", media);

                    // VOLTAR AO MENU OU REINICIAR
                    printf("\nPressione [1] para fazer um novo cálculo, ou [0] para voltar ao menu\n");
                    scanf("%i", &fim);
                    if (fim == 1)
                    {
                        break;
                    }
                    if (fim == 0)
                    {
                        rodando = 0;
                        return;
                    }
                    else
                    {
                        printf("\n\n==========================\n INSIRA UM VALOR VÁLIDO!!!\n==========================\n\n");
                    }
                }
            }
        }
    }
}

void fibonacci()
{
    while (rodando = 1)
    {
        questao_fib = 1;
        while (questao_fib == 1)
        {
            int valor1 = 0, valor2 = 1, valor3;
            int termos;
            int contador = 1;

            printf("Digite até que termo da sequência de Fibonacci você quer que imprima: ");
            scanf("%i", &termos);

            printf("%i° termo: 0\n", contador);
            contador++;

            printf("%i° termo: 1\n", contador);
            contador++;

            while (contador <= termos)
            {
                valor3 = valor1 + valor2;
                printf("%i° termo: %i\n", contador, valor3);
                contador++;

                if (contador > termos)
                {
                    valor1 = valor2 + valor3;
                    printf("%i° termo: %i\n", contador, valor1);
                    contador++;

                    if (contador > termos)
                    {
                        valor2 = valor3 + valor1;
                        printf("%i° termo: %i\n", contador, valor2);
                        contador++;
                    }
                }
            }
        }
    }
}

int main()
{
    while (menu == 1)
    {
        int questao;

        printf("\n===== QUESTÕES =====\n");
        printf("[1] Bhaskara\n");
        printf("[2] Média\n");
        printf("[3] Fibonacci\n");
        printf("[4] Calculadora\n");
        printf("[5] Primo\n");
        printf("[6] Palíndromo\n");
        printf("[7] Dado\n");
        printf("[8] Conversor\n");
        printf("[9] Formatação\n");
        printf("[10] Senha\n");
        printf("[11] Autenticação\n");
        printf("[12] Crescente\n");

        scanf("%d", &questao);

        switch (questao)
        {
        case 1:
            rodando = 1;
            bhaskara();
            questao = 0;
            break;

        case 2:
            rodando = 1;
            media();
            questao = 0;
            break;
        case 3:
            rodando = 1;
            fibonacci();
            questao = 0;
            break;
        /*case 4:
            rodando = 1;
            calculadora();
            questao = 0;
            break;
        case 5:
            rodando = 1;
            primo();
            questao = 0;
            break;
        case 6:
            rodando = 1;
            palindromo();
            questao = 0;
            break;
        case 7:
            rodando = 1;
            dado();
            questao = 0;
            break;
        case 8:
            rodando = 1;
            conversor();
            questao = 0;
            break;
        case 9:
            rodando = 1;
            formatacao();
            questao = 0;
            break;
        case 10:
            rodando = 1;
            senha();
            questao = 0;
            break;
        case 11:
            rodando = 1;
            autenticacao();
            questao = 0;
            break;
        case 12:
            rodando = 1;
            crescente();
            questao = 0;
            break;*/
        default:
            printf("\n\n===============\nINSIRA UM VALOR VÁLIDO\n===============\n\n");
            break;
        }
    }
    return 0;
}
