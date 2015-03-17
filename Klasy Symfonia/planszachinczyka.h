/*
 * planszachinczyka.h
 *
 *  Created on: 17 mar 2015
 *      Author: xmef
 */

#ifndef PLANSZACHINCZYKA_H_
#define PLANSZACHINCZYKA_H_

#include <iostream>
using namespace std;

// aby zainicjalizować składnik klasy wewnątrz definicji klasy musi on być: statyczny, stały (const) i typu całkowitego
// a jego inicjalizator musi być wyrażeniem stałym

class plansza_chinczyka {
public:
	enum { max_pionow = 16, max_graczy = 4 };
	static const int ile_pol = 120; // ten składnik nie posiada definicji poza ciałem klasy, więc nie została mu przydzielona pamięć
	static const int ile_kolorow = 4;

	void jedna_kolejka()
	{
		for(int i = 0; i < max_graczy; i++)
		{
			if(gracz[i]) cout << "Twoj ruch...\n";
		}
	}
	plansza_chinczyka();
	~plansza_chinczyka();
private:
	bool gracz[max_graczy];
	double pole[ile_pol];
};

#endif /* PLANSZACHINCZYKA_H_ */
