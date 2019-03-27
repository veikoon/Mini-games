/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette_russe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinc <vinc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 11:00:04 by vinc              #+#    #+#             */
/*   Updated: 2019/03/24 11:25:43 by vinc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define TRUE 1
#define FALSE 0
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int fire(int count, int nombreMystere)
{
	printf("Appuyer sur enter pour tirer :\n");
	char c;
	c = getchar();
	sleep(1);
	if (count == nombreMystere){
		printf("vous etes mort\n");
		return TRUE;
	}
	else {
		printf("\'click\'\n");
		return FALSE;
	}
}

int fireia(int count, int nombreMystere)
{
	printf("Votre adversaire tire ...\n");
	sleep(1);
	if (count == nombreMystere){
		printf("Votre adversaire est mort\n");
		return TRUE;
	}
	else {
		printf("\'click\'\n");
		return FALSE;
	}
}

int main(int argc, char const *argv[])
{
	printf("Bienvenue au jeu de la roulette russe !\n");
	printf("Remplissage de barillet ...\n");
	int i;
	int nombreMystere;
	char c;
	i = 1;
	srand(time(NULL));
	nombreMystere = (rand() % (8 - 1 + 1)) + 1;

	while (i<=8){
		printf("remplissage de la balle numero %d\n", i);
		sleep(1);
		i++;
	}

	i = 1;

	while (TRUE){
		if (fire(i, nombreMystere))
			break;
		i++;
		if (fireia(i, nombreMystere))
			break;
		i++;
	}

	return 0;
}