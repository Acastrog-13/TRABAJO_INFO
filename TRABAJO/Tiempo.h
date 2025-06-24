#pragma once
#include <iostream>

using namespace std;

struct Tiempo
{
	int minutos{}, segundos{};

	//constructor
	Tiempo(int, int);

	//operator
	bool operator < (const Tiempo&) const;					//para ver si es menos t1<t2?
	bool operator == (const Tiempo&)const;					//para ver si t1 == t2
	Tiempo& operator--();									//predecremento
	Tiempo operator--(int);									//postdecremento
	operator int() const;									//para poder pasar de Tiempo a int
};

inline Tiempo::Tiempo(int m, int s) {
	if (m >= 0 && m < 60 && s >= 0 && s < 60) {
		minutos = m; segundos = s;
		if (s / 60 >= 1) {
			minutos = s / 60;
			segundos = s % 60;
		}
	}
}

inline bool Tiempo::operator<(const Tiempo& t2) const {
	return (minutos < t2.minutos) || (minutos == t2.minutos && segundos < t2.segundos);
}

inline bool Tiempo::operator == (const Tiempo& t2) const {
	return (minutos == t2.minutos && segundos == t2.segundos);
}
inline Tiempo::operator int() const {
	return minutos * 60 + segundos;
}

inline Tiempo& Tiempo::operator--() {
	segundos = (segundos == 0) ? 59 : segundos - 1;
	minutos = (segundos == 59 && minutos > 0) ? minutos - 1 : minutos;
	return *this;
}

inline Tiempo Tiempo::operator--(int) {
	Tiempo temp = *this;
	--(*this);
	return temp;
}
