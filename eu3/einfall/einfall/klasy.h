/* plik klasy.h
 * einfall - program stworzony dla einfalla tworz¹cy heirów atomtycznie
 * na podstawie monarchów by konserw
 * Copyright (C) 2009 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
 * rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej
 * Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
 * Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ
 * z póŸniejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
 * u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
 * gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
 * ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License);
 * jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#pragma once;

#include <string>
typedef unsigned short ability;

void save (const std::string& it, std::vector<std::string>& historia);
void load (const std::string& it, std::vector<std::string>& historia);

class lead{
protected:
	ability fire, shock, manuever, siege;
public:
	lead(ability _fire,
		ability _shock,
		ability _manuever,
		ability _siege):
			fire(_fire),
			shock(_shock),
			manuever(_manuever),
			siege(_siege){
	}
	lead(){
		fire = 0;
		shock = 0;
		manuever = 1;
		siege = 0;
	}
};

class monarch: public lead{
protected:
	std::string monarch_name; //w pliku name=
	std::string dynasty;
	ability DIP, ADM, MIL;
	bool female;
	bool leader;
	std::string date;
public:
	monarch(){
		monarch_name = "unknown";
		dynasty = "unknown";
		date = "1.1.1";
		DIP = 3;
		ADM = 3;
		MIL = 3;
		female = false;
		leader = false;
	}
	monarch(
		const std::string& _date,
		const std::string& _name, 
		const std::string& _dynasty,
		ability _DIP,
		ability _ADM,
		ability _MIL,
		bool _female
		);
	monarch(
		const std::string& _date,
		const std::string& _name, 
		const std::string& _dynasty,
		ability _DIP,
		ability _ADM,
		ability _MIL,
		bool _female,
		lead _leader
		);
	monarch(
		const std::string& _name,
		const std::string& _dynasty):
			monarch_name(_name),
			dynasty(_dynasty){
	}
	bool operator==(monarch &q){
		if(monarch_name == q.monarch_name && dynasty == q.dynasty)
			return true;
		return false;
	}
	const std::string& imie()const{
		return monarch_name;
	}
	const std::string& dynastia()const{
		return dynasty;
	}
	const std::string& data()const{
		return date;
	}
};

typedef std::vector<monarch> vMonarch;
typedef const vMonarch::iterator& iterator;

class heir: public monarch{
protected:
	std::string name;
	std::string birth_date;
	std::string death_date;
	unsigned short claim;
	bool nowy;
public:
	heir(){
		name = "unknown";
		birth_date = "1.1.1";
		death_date = "1.1.2";
		claim = 0;
		nowy = false;
		monarch();
	}
	heir(iterator ten, iterator end);
	heir(const std::string& _monarch_name, const std::string& _dynasty):
		monarch(_monarch_name, _dynasty){ nowy = false;
	}
	bool jest_nowy() const{
		return nowy;
	}
	std::string print() const;
};
