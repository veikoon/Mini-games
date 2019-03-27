#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int nombreMystere = 0, nombre = 0, boucle = 0, continuer = 1, mode = 1, max, min;
	while(1){
		printf("Veuillez choisir la difficulté : 1-100 (1)   1-1 000 (2)   1-10 000 (3)");
		scanf("%d",&mode);
		switch(mode){
			case 1:
				max = 100, min = 1;
				break;
			case 2:
				max = 1000, min = 1;
				break;
			default:
				max = 10000, min = 1;
		}
		printf("Voulez vous jouer en mode un joueur (1) ou deux joueurs (2) ?");
		scanf("%d",&mode);
		if(mode == 1){
			srand(time(NULL));
                        nombreMystere = (rand() % (max - min + 1)) + min;
                        printf("%d",nombreMystere);
                }
                else{
			while(nombreMystere>max||nombreMystere<min){
	                        printf("Le premier joueur peut entrer le nombre mystere : ");
				scanf("%d",&nombreMystere);
       	       		        if(nombreMystere>max||nombreMystere<min) printf("Ce nombre doit etre compris entre %d et %d\n", min, max);
       		        }
		}
		while(continuer){
			printf("Faites une proposition : ");
			scanf("%d",&nombre);
			if(nombre == nombreMystere){
				printf("Bravo tu as trouvé la réponse en %d coups !\nVoulez vous continuer ? (1 pour oui, 0 pour non)", boucle);
				scanf("%d",&continuer);
				break;
			}
			if(nombre>nombreMystere) printf("C'est plus bas !\n\n");
			if(nombre<nombreMystere) printf("C'est plus haut !\n\n");
			boucle += 1;
		}
		if(continuer==0) break;
	}
return 0;
}
