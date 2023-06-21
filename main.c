#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


// PARA ESSE TRABALHO, USAMOS O CONCEITO DE RECURSIVIDADE JÁ QUE ACHAMOS MAIS SIMPLES PARA O NOSSO ENTENDIMENTO,
// PORÉM, FUTURAMENTE QUEREMOS IMPLEMENTAR NESSA MESMA QUESTÃO O CONCEITO DINAMICO E O GENÉTICO, VISTO QUE PARECE-NOS 
// SER MAIS EFICIENTE E MAIS RÁPIDO PARA NÚMEROS GRANDES DE ITEMS. MAS COM A RECURSIVIDADE JÁ CONSEGUIMOS MELHORES RESULTADOS
// DE VELOCIDADE EM COMPARAÇÃO COM A MANEIRA QUE A GENTE ESTAVA FAZENDO ANTES, QUE ERA BUSCANDO TODAS AS COMBINAÇÕES POSSÍVEIS 
// DE ELEMENTOS, VERIFICANDO QUAIS TINHAM O PESO TOTAL MENOR OU IGUAL AO QUE ERA SUPORTADO PELAS MOCHILA E DEPOIS PEGANDO AQUELA
// COMBINAÇÃO DE MAIOR VALOR, COM A RECURSIVIDADE NOS CONSEGUIMOS RESULTADOS ATÉ 3X MAIS RÁPIDO PARA ALGUNS CASOS DE TESTES.


//CRIAÇÃO DE ESTRUTURA STRUCT PARA ARMAZENAR VALOR E PESO DO ITEM
struct item{
    int valor;
    int peso;
};

int recursive(int cap, int n, int *v, int *p);
int max(int primeiro, int segundo);


int main(){

    // RECOLHENDO DADOS PASSADOS PELO USUÁRIO
    int numero_items;
    int pesoMax;
    printf("Digite a quantidade de items e o peso máximo suportado: \n");
    scanf("%d %d", &numero_items, &pesoMax);
    // CRIANDO VETOR STRUCT COM A QUANTIDADE DE ITEMS PASSADO PELO USUÁRIO
    struct item items[numero_items];
    // GUARDANDO PESO E VALOR DOS ITEMS NO VETOR STRUCT
    for(int i=0; i < numero_items; i++){
        printf("Digite o peso e o valor do item: \n");
        scanf("%d %d", &items[i].peso, &items[i].valor);
    }


    int vetorPeso[numero_items];
    int vetorValor[numero_items];

    for(int j=0; j<numero_items; j++){
        vetorPeso[j] = items[j].peso;
        vetorValor[j] = items[j].valor;
    }

    
    int resultado = recursive(pesoMax, numero_items, vetorValor, vetorPeso);

    printf("%d", resultado);



    

}

// A FUNÇÃO RECEBE COMO PARÂMETRO A CAPACIDADE DA MOCHILA, O NUMERO DE ITEMS FALTANTES,
// O VETOR COM OS VALORES DOS ITEMS E O VETOR COM O PESO DOS ITEMS
int recursive(int cap, int n, int *v, int *p){
    // CASO N SEJA IGUAL A 0, SIGNIFICA QUE NÃO TEM MAIS ITEMS A SEREM BUSCADOS
    if(n==0){
        return 0;
    }
    //CASO O PESO DO ITEM EM N-1 SEJA MAIOR QUE A CAPACIDADE DA MOCHILA
    //CHAMAMOS A FUNÇÃO NOVAMENTE PARA VERIFICAR O OUTRO ITEM
    else if(p[n-1] > cap){
        return recursive(cap, n-1, v, p);
    }
    //CASO NENHUMA DAS ESTRUTURAS CONDIONAIS ANTERIORES SEJAM SATISFEITAS,
    // VERIFICAMOS QUAL O MAIOR VALOR ENTRE GUARDAR O ITEM ATUAL NA MOCHILA CHAMANDO A FUNÇÃO NOVAMENTE
    // E NÃO GUARDAR O ITEM ATUAL NA MOCHILA E VERIFICAR PARA O PRÓXIMO ITEM CHAMANDO A FUNÇÃO
    // SENDO ASSIM, SEMPRE TEMOS DUAS OPÇÕES, GUARDAM O ITEM NA MOCHILA OU NÃO GUARDAR
    else{
        return max(v[n-1] + recursive(cap-p[n-1], n-1, v, p), recursive(cap, n-1, v, p));
    }


}

// O OBJETIVO DESSA FUNÇÃO É SOMENTE RETORNAR O MAIOR ENTRE DOIS VALORES
int max(int primeiro, int segundo){
    if(primeiro > segundo){
        return primeiro;
    }
    return segundo;
}