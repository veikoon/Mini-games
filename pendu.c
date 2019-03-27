#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void jouer(void);

int main(int argc, char *argv[])
{
	int mode;
	int count;
	int continuer;
	int nbLettre;
	mode = 1;
	count = 1;
	continuer = 1;
	nbLettre = 0;
	char mot[100];
	char essai;
	char temp[100];
	char motCache[100];
	while (1){
		printf("Voulez vous jouer (1) seul ou à deux (2) ? \n>");
		scanf("%d", &mode);
		if (mode == 1){
			sprintf(mot, "bonjour");
		}
		else
		{
			printf("Le premier joueur peut entrer un mot : ");
			scanf("%s", &temp);
			sprintf(mot, temp);
			printf("C'est au tour du second joueur !\n");
		}
		nbLettre = strlen(mot);
		for (int i = 0; i < nbLettre; ++i){
			motCache[i] = '*';
		}
		motCache[nbLettre + 1] = '\0';


		while (1){
			printf("%s\n", motCache);
			printf("Veuillez entrer un charactere\n>");
			scanf(" %c", &essai);
			for (int i = 0; i < nbLettre; ++i){
				if (mot[i] == essai){
					printf("Vous avez trouvé une lettre !\n");
					motCache[i] = essai;
				}
			}
			if (strchr(motCache, '*') == NULL){
				printf("Vous avez gagné en %d coups !\n", count);
				break;
			}
			count++;
		}

		printf("Voulez vous rejouer ? (1) oui (0) non\n>");
		scanf("%d", &continuer);
		if (!continuer) break;
		count = 0;
	}
}