/*
 * piorko_main.cpp
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */
#include "includy.h"

#include "piorko.h"

void piorko_main()
{
	piorko::czy_mozna(tak);

	piorko czarne("SMOLISTE");
	piorko zielone("ZIELONIUTKIE");

	czarne.jazda(0, 0);
	zielone.jazda(1100, 1100);

	// zabraniamy ruch piórkom
	piorko::czy_mozna(nie);

	czarne.jazda(10, 10);
	zielone.jazda(1020, 1020);

	// zezwalamy w taki sposób
	zielone.czy_mozna(tak);
	czarne.jazda(50, 50);
	zielone.jazda(1060, 1060);
}
