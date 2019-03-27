#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arme Arme;
struct Arme
{
	int max;
	int min;
};

typedef struct Player Player;
struct Player
{
	char name[15];
	Arme arme;
	int vie;
};

void action(Player *ordi, Player *joueur);
void iaction(Player *ordi, Player *joueur);
void act(Player *one, Player *two, int act);
void tirer(Player *zbeub);
void baisser(Player *zbeub);
int welcome(Player *joueur);
int end(Player *one, Player *two);

int end(Player *one, Player *two)
{
	if ((*one).vie <= 0){
		printf("%s à perdu !\n", (*one).name);
		return (0);
	}

	if ((*two).vie <= 0){
		printf("%s à perdu !\n", (*two).name);
		return (0);
	}

	return (1);
}

void baisser(Player *zbeub){
	(*zbeub).arme.min += 1;
	(*zbeub).arme.max += 1;
	printf("%s s'est baissé\n", (*zbeub).name);
}

void act(Player *one, Player *two, int act)
{
	if (act == 1){
		tirer(two);
	}

	if (act == 0){
		baisser(one);
	}

	printf("%d %d\n", (*one).vie, (*two).vie);
}

void action(Player *ordi, Player *joueur)
{
	int actions;
	printf("choisissez entre (0) vous baisser  (1) tirer\n>");
	scanf("%d", &actions);
	act(joueur, ordi, actions);
}

void iaction(Player *ordi, Player *joueur)
{
	int random = (rand() % 2);
	act(ordi, joueur, random);
}

void tirer(Player *zbeub)
{
	int nombreMystere = (rand() % (5)) + 1;

	switch (nombreMystere){
	case 1:
	case 2:
		printf("%s à été touché !\n", (*zbeub).name);
		int random = (rand() % ((*zbeub).arme.max -
		(*zbeub).arme.min + 1)) + (*zbeub).arme.min;
		(*zbeub).vie -= random;
		break;
	case 3:
	case 4:
		printf("%s à été raté !\n", (*zbeub).name);
		break;
	case 5:
		printf("Headshot !\n");
		(*zbeub).vie = 0;
	}

}

int welcome(Player *joueur)
{
	int choix;
	char nom[50];
	printf("Comment vous appelez vous ?\n>");
	scanf("%s", nom);
	printf("Bienvenu dans Counter Strike\n");
	printf("Première choisissez une arme entre :");
	printf("(0) AK-47  (1) M4A1-S\n>");
	scanf("%d", &choix);
	strcpy((*joueur).name, nom);
	return (choix);
}

int main(int argc, char const *argv[])
{
	int stop;
	Player joueur;
	Player ordi;
	Arme ak_47;
	Arme m4a1_s;
	stop		= 1;
	ak_47.max 	= 4;
	ak_47.min 	= 2;
	m4a1_s.max 	= 5;
	m4a1_s.min 	= 1;
	ordi.arme 	= ak_47;
	strcpy(ordi.name, "L'ordi");
	srand(time(NULL));

	while (1){
		int choix;
		choix 		= welcome(&joueur);
		joueur.vie 	= 20;
		ordi.vie 	= 20;
		if (choix == 0){
			joueur.arme = ak_47;
		}

		if (choix == 1){
			joueur.arme = m4a1_s;
		}

		while (1){

			printf("Au tour du joueur\n\n");
			action(&ordi, &joueur);
			if(!end(&ordi, &joueur))
				break;
			action(&ordi, &joueur);
			if(!end(&ordi, &joueur))
				break;

			printf("Au tour de l'ordi\n\n");
			iaction(&ordi, &joueur);
			if(!end(&ordi, &joueur))
				break;
			iaction(&ordi, &joueur);
			if(!end(&ordi, &joueur))
				break;
		}

	}

	return (0);
}