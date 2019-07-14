#include <stdio.h>

void show(char game[6][7]);
void init(char game[6][7]);
void place(char game[6][7], int col, char car);
int win(char game[6][7]);

int win(char game[6][7])
{
	//verif horizonale
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if ((game[i][j] != ' ') && (game[i][j] == game[i][j+1]) && (game[i][j+1] == game[i][j+2]) && (game[i][j+2] == game[i][j+3])){
				return (1);
			}
		}
	}

	//verif verticale
	for (int k = 0; k < 7; ++k)
	{
		for (int l = 0; l < 3; ++l)
		{
			if ((game[l][k] != ' ') && (game[l][k] == game[l+1][k]) && (game[l+1][k] == game[l+2][k]) && (game[l+2][k] == game[l+3][k])){
				return (1);
			}

		}
	}

	//verif diag montante droite
	for (int m = 5; m >= 3 ; --m)
	{
		for (int n = 0; n <= 3; ++n)
		{
			if ((game[m][n] != ' ') && (game[m][n] == game[m-1][n+1]) && (game[m-1][n+1] == game[m-2][n+2]) && (game[m-2][n+2] == game[m-3][n+3])){
				return (1);
			}
		}
	}

	//verif diag montante gauche
	for (int o = 5; o >= 3 ; --o)
	{
		for (int p = 6; p >= 3; --p)
		{
			if ((game[o][p] != ' ') && (game[o][p] == game[o-1][p-1]) && (game[o-1][p-1] == game[o-2][p-2]) && (game[o-2][p-2] == game[o-3][p-3])){
				return (1);
			}
		}
	}

	return (0);
}

void place(char game[6][7], int col, char car)
{
	for (int i = 6; i >= 0; --i)
	{
		if (game[i][col] == ' ')
		{
			game[i][col] = car;
			break;
		}
	}
	show(game);
}

void init(char game[6][7])
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			game[i][j] = ' '; 
		}
	}
}

void show(char game[6][7])
{
	printf("\n%s\n", " 1 2 3 4 5 6 7 ");
	for (int i = 0; i < 6; ++i)
	{
		printf("%s\n", "---------------");
		for (int j = 0; j < 7; ++j)
		{
			printf("%c", '|');
			printf("%c", game[i][j]); 
		}
		printf("%s\n", "|");
	}
	printf("%s\n", "---------------");
}



int main(int argc, char const *argv[])
{
	while (1){
		int mode;
		int col;
		char game[6][7];
		init(game);
		printf("Bienvenu dans le jeu puissance 4 !\n");
		printf("Souhaitez vous jouer seul (1) ou a deux (0)?\n>");
		scanf("%d", &mode);
		if(mode == 0){
			while(1){
				printf("Joueur \"o\" choisissez une colonne : ");
				scanf("%d", &col);
				place(game, col-1, 'o');
				if(win(game)){
					printf("Le joueur \"o\" gagne\n");
					break;
				}
				printf("Joueur \"x\" choisissez une colonne : ");
				scanf("%d", &col);
				place(game, col-1, 'x');
				if(win(game)){
					printf("Le Joueur \"x\" gagne\n");
					break;
				}
			}
		}
		else
			printf("Non developpe\n");
	}
	return 0;
}