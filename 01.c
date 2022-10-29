/*
    Aula 166: Jogo da velha
*/
#include <stdio.h>

typedef struct{
    char Jogador1[30];
    char Jogador2[30];

    int jogadas;
} dadosGame;


//@Return: retorna qual jogador quanhou se foi X ou O
char verficaGame(int jogadas, char mapa[3][3]){  // Função que verifa se o jogador ganhou
    
    for (int i = 0; i < 3; i++){
        if ((mapa[i][0] == mapa[i][1]) && (mapa[i][1] == mapa[i][2]))  // Verificando todas as três linhas
            return mapa[i][0];

        else if((mapa[0][i] == mapa[1][i]) && (mapa[1][i] == mapa[2][i]))  // Verificando as três colunas
            return mapa[0][i];
    }

    if ((mapa[0][0] == mapa[1][1]) && (mapa[1][1] == mapa[2][2])) // Verificando a diagonal principal
        return mapa[0][0];
    
    else if ((mapa[0][2] == mapa[1][1]) && (mapa[1][1] == mapa[2][0])) // Verificando a diagonal secundária
        return mapa[0][2];
}


void showMap(char mapa[3][3]){  // Função que mostra o mapa
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (mapa[i][j] == 65)  // 65 == A na tabela ascii
                printf(" - ");
            else
                printf(" %c ", mapa[i][j]);
        }
        printf("\n");
    }
}


void mapaPreenche(char mapa[3][3]){ // Função que preenche com A, para representar que está vázia
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            mapa[i][j] = 65;
    }   
}


void verificaLineColun(int **line, int **colun){  // Função que verifica se o numeros são válidos

    while(((**line < 1) || (**line > 3)) || ((**colun < 1) || (**colun > 3))){
        printf("Valor invalido!\nDigite o numero da [linha x Coluna]: ");
        scanf("%d %d", &**line, &**colun);
    }
}


void addInMap(char mapa[3][3],int jogada, char nomeJog[30], char nomeJog2[30], int *line, int *colun){  // Função que adicona as jogadas no mapa de com a vez do jogador

    if(jogada % 2 == 0){
        printf("Vez do jogador %s: X\nDigite o numero da [linha x Coluna]: ", nomeJog);
        scanf("%d %d", &*line, &*colun);
        verificaLineColun(&line, &colun);
        mapa[*line - 1][*colun - 1] = 88;
    }
    else if (jogada % 2 == 1){
        printf("Vez do jogador %s: O\nDigite o numero da [linha x Coluna]: ", nomeJog2);
        scanf("%d %d", &*line, &*colun);
        verificaLineColun(&line, &colun);
        mapa[*line - 1][*colun - 1] = 79;
    }
}

void verificSpace(){  // Em andamento - Função que verifica se o espaco seleciona está ocupado
    printf("TESTE");
}


int main(){
    char mapaGame[3][3];
    int controle = 0;

    int *line = 0, *colun = 0;

    dadosGame nomeJogador, verifcaJog;

    printf("Digite o nome jogador 1: ");
    scanf("%s", &nomeJogador.Jogador1);

    printf("Digite o nome jogador 2: ");
    scanf("%s", &nomeJogador.Jogador2);

    verifcaJog.jogadas = 0;


    mapaPreenche(mapaGame); // Preechendo mapa com A

    showMap(mapaGame);  // Mostrando MAPA

    while(verifcaJog.jogadas != 9) {

        addInMap(mapaGame,verifcaJog.jogadas, nomeJogador.Jogador1, nomeJogador.Jogador2, &line, &colun);

        if(verifcaJog.jogadas > 4)
            verficaGame(verifcaJog.jogadas, mapaGame);

        showMap(mapaGame);  // Mostrando MAPA

        if (verficaGame(verifcaJog.jogadas, mapaGame) == 88){
            printf("Jogador X [%s], GANHOU", nomeJogador.Jogador1);
            break;
        }

        else if (verficaGame(verifcaJog.jogadas, mapaGame) == 79){
            printf("Jogador O [%s], GANHOU", nomeJogador.Jogador2); 
            break;        
        }

    verifcaJog.jogadas++;
}   
    if (verifcaJog.jogadas == 9)
         printf("EMPATE!!!");
    return 0;
}
