//Jeu du pile ou face
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int cote=0, mise=0, random, thune = 20;
	while(1)
	{
		printf("Vous possedez %d\n", thune);
		printf("Sur quelle face pariez vous ? pile (0)  face(1)\n");
		scanf("%d", &cote);

		while(1)
		{
			printf("Combien pariez vous ?\n");
			scanf("%d", &mise);
			if (mise>thune) printf("Vous n'avez pas autant d'argent !\n");
			else if (mise == 0) printf("Vous ne pouvez pas ne rien parier !\n");
			else break;
		}
			srand(time(NULL));
		random = (rand() % 2);

		if (random == 1)
		{
			printf("Perdu !\n");
			thune-=mise;
			if (thune<=0)
			{
				printf("Tu es hors-jeu tu n'as pas assez d'argent !\n");
				break;
			}
		}
		else
		{
			printf("Gagné !\n");
			thune+=mise;
		}
	}
	return 0;
}