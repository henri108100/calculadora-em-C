#include <stdio.h>
#include <math.h>

void limpar_tela() { 
//limpa o termimal usando sequências de escape ANSI
//OBS: versões antigas do CMD do Windows não suportam ANSI por padrão
    printf("\033[H\033[J"); //esse conjunto de sequências de escape ANSI (comandos que o terminal interpreta) consegue limpar o terminal
    fflush(stdout); //garante que a tela vai limpar na mesma hora  
}

int mostrar_opcoes(){ 
//mostra as opções e retorna o que o usuario digitar
    printf("selecione uma das opcoes: \n");
    printf("1. adicao\n");
    printf("2. multiplicacao\n");
    printf("3. divisao\n");
    printf("4. exponenciacao\n\n");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void calcular(int opcao){
//pergunta ao usuário os dois termos da operação e calcula o resultado dependendo da opcao
    float a;
    printf("digite o primeiro numero: ");
    scanf("%f", &a);

    float b;
    printf("digite o segundo numero: ");
    scanf("%f", &b);

    float resultado;
    switch (opcao)
    {
        case 1:
            resultado = a + b;
            break;
        case 2:
            resultado = a * b;
            break;
        case 3:
            if (b == 0){
                printf("erro: nao e possivel dividir por 0");
                return; //encerra a função antes do fim
            }
            resultado = a / b;
            break;
        case 4:
            resultado = pow(a, b);
            break;
    }
    printf("resultado: %.2f\n\n", resultado);
}

int main() {
    while (1) //loop principal
    {
        limpar_tela();
        
        int opcao = mostrar_opcoes();
        if (opcao > 0 && opcao <= 4){
            calcular(opcao);
        }else{
            printf("opcao invalida\n");
        }

        while (1) //perguntar se deseja continuar
        {
            char resposta;
            printf("deseja continuar? (S/N)\n");
            scanf(" %c", &resposta);
            
            if (resposta == 'S' || resposta == 's'){
                //quebra apenas o loop de perguntar se deseja continuar
                //executa novamente loop principal
                break;
            }else if (resposta == 'N' || resposta == 'n'){
                //encerra o programa
                return 0;
            }else{
                //pergunta novamente se deseja continuar
                printf("resposta invalida\n\n");
            }
        }
    }
}