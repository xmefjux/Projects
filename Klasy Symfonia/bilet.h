/*
 * bilet.h
 *
 *  Created on: 24 lut 2015
 *      Author: xmef
 */

#ifndef BILET_H_
#define BILET_H_
//*****************************************************************************************
class bilet
{
public:
	enum rodzaj_pociagu {
		osobowy, przyspieszony, pospieszny, ekspres
	};

	void zapamietaj(const char* sk, const char* dok, rodzaj_pociagu poc, int kl = 2);
	void zmien_rodzaj_pociagu(rodzaj_pociagu poc);
	void wypisz();

private:
	char skad[80];
	char dokad[80];
	int klasa;
	rodzaj_pociagu jaki_pociag;
	const char* opis_rodzaju();
};
//*****************************************************************************************
inline void bilet::zmien_rodzaj_pociagu(rodzaj_pociagu poc)
{
	this->jaki_pociag = poc;
}
//*****************************************************************************************
#endif /* BILET_H_ */
