#include <stdio.h>
#include <stdlib.h>


#define quantidade_de_produtos 7
char* produtos[quantidade_de_produtos] = {
    "Misto Quente",
    "Salgado",
    "Bolos",
    "Empadao",
    "Cafe",
    "Agua",
    "Refrigerante"
};
float valor[quantidade_de_produtos] = { 3.50, 5.50, 6.00, 8.00, 4.00, 2.50, 5.00 };

int menu(void) {
    printf("####################################\n");
    printf("Bem Vindo a Cafeteria Del Luna\n");
    printf("####################################\n");

    printf("*****Menu dos Produtos*****\n");
    printf("####################################\n");

    int i;
    for (i = 1; i <= quantidade_de_produtos; ++i) {
        printf("%d- %s: %.2f\n", i, produtos[i - 1], valor[i - 1]);
    };

    printf("0- Para finalizar o pedido\n");
    printf("#####################################\n");
    printf("\n");

    return 0;
}


int main(void)
{

    menu();

    FILE *pont_arquivo; // variável ponteiro
    int qtd, opcao; //variável de escolha
    char Nome[20];// array para alocar nome do cliente 
    float resultado = 0;
    char c;

    pont_arquivo = fopen("Arquivo de Pedidos.txt", "a");// abrindo o arquivo com tipo a

    if (pont_arquivo == NULL) // testando se o arquivo foi criado
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    else 
    {
        printf("Digite seu nome:\n");
        scanf_s("%s", &Nome);
        fprintf(pont_arquivo, "%s\n", Nome);// usando fprintf para aramazenar a string no arquivo

        while ((c = getchar()) != '\n' && c != EOF) {}; //Linha de código para executar a limpeza de buffer de teclado, para evitar erros de entrada.

        printf("Digite sua escolha:\n");
        scanf_s("%d", &opcao);
        fprintf(pont_arquivo, "%d\n", opcao);

        printf("Digite a quantidade de %s desejada:\n", produtos[opcao - 1]);
        scanf_s("%d", &qtd);
        fprintf(pont_arquivo, "%d\n", qtd);

        fclose(pont_arquivo);// fclose para fechar o arquivo

        printf("Dados gravados com Sucesso");
    }
    

    while ((opcao < 0) || (opcao > 7))
    {
      
        printf("Digite sua escolha e quantidade\n");
        scanf_s("%d, %d", &opcao, &qtd);
    }

    while (opcao != 0)//para entrar na sessão das escolhas.
    {

        switch (opcao)//função usada para separar por escolha, caso o usuário escolha 1 opcão vai rodar os comandos dentro dela.
        {
        case 1:
            //resultado = resultado + qtd * 5.00;
            resultado += qtd * 3.50;// conta para calcular o quanto vai se gastar.
            printf("O valor da compra eh: %.2f reais\n", resultado);
            break;
        case 2:
            resultado += qtd * 5.50;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;
        case 3:
            resultado += qtd * 6.00;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;

        case 4:
            resultado += qtd * 8.00;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;

        case 5:
            resultado += qtd * 4.00;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;

        case 6:
            resultado += qtd * 2.50;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;

        case 7:
            resultado += qtd * 5.00;
            printf("O valor da compra eh:%.2f reais\n", resultado);
            break;
        }

        printf("Deseja algo mais? Digite sua escolha e quantidade\n");//caso exista outra escolha pelo usuário.
        scanf_s("%d, %d", &opcao, &qtd);
        while ((opcao < 0) || (opcao > 7))//loop
        {
            printf("Digite sua escolha e quantidade\n");
            scanf_s("%d, %d", &opcao, &qtd);
        }
        if (opcao == 0) {//para finalizar o codigo.

            printf("A senha eh: %s\n", Nome);
            printf("O valor final da compra eh:%.2f reais\nVolte Sempre!\n\n", resultado);
           
        }

    }

    system("Pause");
    return 0;
}

