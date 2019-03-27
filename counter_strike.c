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

Player joueur;
Player ordi;
Arme ak_47;
Arme m4a1_s;

void action(void);
void iaction(void);
void tirer(Player zbeub);
void baisser(Player zbeub);
void welcome(void);

void baisser(Player zbeub){
	zbeub.arme.min += 1;
	zbeub.arme.max += 1;
	printf("%s s'est baissé\n", zbeub.name);
}

void action(void)
{
	int act;
	printf("choisissez entre (1) vous baisser  (2) tirer\n>");
	scanf("%d", &act);
	if (act == 2){
		tirer(ordi);
	}
	if (act == 1){
		baisser(joueur);
	}
}

void iaction(void)
{
	srand(time(NULL));
	int random = (rand() % 2);
	if (random == 1){
		tirer(joueur);
	}
	if (random == 0){
		baisser(ordi);
	}
}

void tirer(Player zbeub)
{
	srand(time(NULL));
	int nombreMystere = (rand() % (5)) + 1;
	switch (nombreMystere){
	case 1:
	case 2:
		printf("%s à été touché !\n", zbeub.name);
		srand(time(NULL));
		int random = (rand() % (zbeub.arme.max -
		zbeub.arme.min + 1)) + zbeub.arme.min;
		zbeub.vie -= random;
		break;
	case 3:
	case 4:
		printf("%s à été raté !\n", zbeub.name);
		break;
	case 5:
		printf("Headshot !\n");
		zbeub.vie = 0;
	}
	if (joueur.vie <= 0){
		printf("%s à perdu !\n", joueur.name);
	}
	if (ordi.vie <= 0){
		printf("%s à perdu !\n", ordi.name);
	}
}

void welcome(void)
{
	int choix;
	char nom[50];
	printf("Comment vous appelez vous ?\n>");
	scanf("%s", nom);
	printf("Bienvenu dans Counter Strike\n");
	printf("Première choisissez une arme entre :");
	printf("(1) AK-47  (2) M4A1-S\n>");
	scanf("%d", &choix);
	if (choix == 1){
		joueur.arme = ak_47;
	}
	if (choix == 2){
		joueur.arme = m4a1_s;
	}
	strcpy(joueur.name, nom);
}

int main(int argc, char const *argv[])
{
	ak_47.max = 4;
	ak_47.min = 2;
	m4a1_s.max = 5;
	m4a1_s.min = 1;
	ordi.arme = ak_47;
	joueur.vie = 20;
	ordi.vie = 20;
	strcpy(ordi.name, "L'ordi");
	while (1){
		welcome();
		while (1){
			printf("Au tour du joueur\n\n");
			action();
			action();
			printf("Au tour de l'ordi\n\n");
			iaction();
			iaction();
		}
	}
	return 0;
}