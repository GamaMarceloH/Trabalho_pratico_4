/*Exercicio 524 do Leetcode
    Marcelo Hemp Gama 
    Turma M2
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ve se a palavra pode ser formada tirando letras da string s
bool ehSubsequencia(char* s, char* palavra) {
int i = 0; 
int j = 0; 
    
    while (s[i] != '\0' && palavra[j] != '\0') 
    {
        if (s[i] == palavra[j]) {
           j++;
        }
        i++;
}
    
// Se  j chegar no fim da palavra, ela eh valida
    return palavra[j] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char* melhor_palavra = "";
    
    for (int i = 0; i < dictionarySize; i++) {
        char* p_atual = dictionary[i];
        //Analisa se a palavra atual pode ser formada
        if (ehSubsequencia(s, p_atual)) {
            int tamanho_da_agora = strlen(p_atual);
            int tamanho_da_melhor = strlen(melhor_palavra);
            

            // criterio de desempate e tamanho
            if (tamanho_da_agora > tamanho_da_melhor || 
               (tamanho_da_agora == tamanho_da_melhor && strcmp(p_atual, melhor_palavra) < 0)) {
                melhor_palavra = p_atual;
            }
     }
    }
    
    return melhor_palavra;
}

int main() {
    char s[1001];
    int qtd;

printf("Digite a string principal (ex: abpcplea): ");
    scanf("%s", s);

printf("Quantas palavras vai colocar no dicionario? ");
    scanf("%d", &qtd);

    char* lista[qtd];
    char armazenamento[1001][1001];

    for (int i = 0; i < qtd; i++) 
    {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", armazenamento[i]);
        lista[i] = armazenamento[i]; 
}

    char* resultado_final = findLongestWord(s, lista, qtd);

printf("\nResultado: %s\n", strlen(resultado_final) > 0 ? resultado_final : "Vazio");
    return 0;
}