/*
 * Plik funkcje.cpp
 * CSV Translator - program u³atwiaj¹cy t³umaczenie plików 
 * lokalizacyjnych gier ParadoxInteractive; wersja kompatybilna z EU3
 * Potrzebujesz wersji pasuj¹cej do innej gry paradoxu - pisz na mojego mejla! ;)
 * Zawsze warto te¿ zajrzeæ na forum strategiczne wayofwar.pl
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
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
#include "stdafx.h"
#include "translator.h"

void update(HWND hDlg, std::deque<cWers>& wersy){
	const UINT max = 5000;
	char buff[max];

	GetDlgItemText(hDlg, IDC_DESC, buff, max);
	wersy.at(wers).set_desc(buff);
	GetDlgItemText(hDlg, IDC_POL, buff, max);
	wersy.at(wers).set_pol(buff);
	GetDlgItemText(hDlg, IDC_ENG, buff, max);
	wersy.at(wers).set_eng(buff);
}
void disable(HWND hDlg){
	EnableWindow(GetDlgItem(hDlg, IDC_DESC), false);
	EnableWindow(GetDlgItem(hDlg, IDC_DEL), false);
	EnableWindow(GetDlgItem(hDlg, IDC_POL), false);
	EnableWindow(GetDlgItem(hDlg, IDC_ENG), false);
	EnableWindow(GetDlgItem(hDlg, IDC_NEXT), false);
	EnableWindow(GetDlgItem(hDlg, IDC_PREV), false);
	EnableWindow(GetDlgItem(hDlg, IDC_SKOK), false);
	EnableWindow(GetDlgItem(hDlg, IDC_GO), false);
	EnableMenuItem(GetMenu(hDlg), ID_FILE_SAVE, MF_GRAYED);
	SetDlgItemText(hDlg, IDC_MAX, "\0");
	SetDlgItemText(hDlg, IDC_DESC, "\0");
	SetDlgItemText(hDlg, IDC_POL, "\0");
	SetDlgItemText(hDlg, IDC_ENG, "\0");
}
void refresh(HWND hDlg, std::deque<cWers>& wersy){
	log("refresh");
	if(wersy.size() == 0){
		log("refresh", "nie wczytano - pomijam");
		return;
	}
	if(wersy.size() == wers){
		log("refresh", "dodawanie wiersza");
		wersy.push_back(cWers());
	}
	if(byl == -1){
		std::stringstream ss;
		log("refresh", "wczytano - enabling");
		ss << "Lines in file:\t" << wersy.size();
		SetDlgItemText(hDlg, IDC_MAX, ss.str().c_str());
		EnableMenuItem(GetMenu(hDlg), ID_FILE_SAVE, MF_ENABLED);
		EnableWindow(GetDlgItem(hDlg, IDC_POL), true);
		EnableWindow(GetDlgItem(hDlg, IDC_ENG), true);
		EnableWindow(GetDlgItem(hDlg, IDC_NEXT), true);
		EnableWindow(GetDlgItem(hDlg, IDC_SKOK), true);
		EnableWindow(GetDlgItem(hDlg, IDC_GO), true);
		EnableWindow(GetDlgItem(hDlg, IDC_DESC), true);
		EnableWindow(GetDlgItem(hDlg, IDC_DEL), true);
	}
	if(wers == 0) EnableWindow(GetDlgItem(hDlg, IDC_PREV), false);
	if(wers > 0) EnableWindow(GetDlgItem(hDlg, IDC_PREV), true);
	if(wers != byl){
		std::stringstream ss;
		byl = wers;
		log("wersy", "zmiana wersu na", wers);
		ss << "Line:\t" << wers << " / " << wersy.size()-1;
		SetDlgItemText(hDlg, IDC_LINE, ss.str().c_str());
		SetDlgItemText(hDlg, IDC_DESC, wersy.at(wers).desc());
		SetDlgItemText(hDlg, IDC_POL, wersy.at(wers).pol());
		SetDlgItemText(hDlg, IDC_ENG, wersy.at(wers).eng());
	}

	log("refresh", "koniec");
}

void explode(const std::string &str, const char *delim, std::deque<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}	

bool wczyt(std::deque<cWers>& wersy, HWND hWnd, char* szFile){
	std::string buff;
	OPENFILENAME ofn;
	std::stringstream ss;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrCustomFilter = NULL;
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "csv files\0*.csv\0";
	ofn.nFilterIndex = 1;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if(!GetOpenFileName(&ofn))
		return false;
	strcpy_s(szFile, MAX_PATH, ofn.lpstrFile);
	log("wczyt", "wybrany plik", ofn.lpstrFile);
	if(byl != -1){
		wersy.clear();
		wers = 0;
		byl = -1;
	}
	std::ifstream plik(ofn.lpstrFile);
	if(!( plik.is_open() && plik.good())){
		MessageBox(hWnd, "Error!", "Error!", MB_OK | MB_ICONERROR);
		log("wczyt", "brak dostepu do pliku wejsciowego");
		return false;
	}
	while(getline(plik, buff).good()){
		wersy.push_back(cWers(buff));
	}
	log("wczyt", "Wczytano linii", wersy.size());
	plik.close();

	ss << "CSV Translator - " << ofn.lpstrFile;
	SetWindowText(hWnd, ss.str().c_str());
	return true;
}

bool zapis(std::deque<cWers>& wersy, HWND hWnd, char* szFile){
	update(hWnd, wersy);

	OPENFILENAME ofn;
	char ext[] = "csv";
	std::stringstream ss;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrCustomFilter = NULL;
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "csv files\0*.csv\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrDefExt = ext;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT;

	if(!GetSaveFileName(&ofn))
		return false;
	log("zapis", "wybrano plik do zapisu", ofn.lpstrFile);

	std::ofstream plik(ofn.lpstrFile);

	if(plik.is_open() && plik.good())
		for(unsigned long i=0; i < wersy.size(); ++i)
			plik << wersy[i].print() << std::endl;
	else{
		MessageBox(hWnd, "Error!", "Error!", MB_OK | MB_ICONERROR);
		log("zapis", "brak dostepu do pliku na wyjsciu");
		return false;
	}
	plik.close();
	log("zapis", "zapisano");
	
	ss << "CSV Translator - " << ofn.lpstrFile;
	SetWindowText(hWnd, ss.str().c_str());
	return true;
}
/*
cWers::cWers(const std::string& linia){
	explode(linia, ";", vec);
/*	sDesc = vec[0];
	sEng = vec[1];
	sPol = vec[lang+1];//4
	switch(gra){
		case EU3:

			break;
		case vic2:

}
*/
std::string cWers::print()const{
	std::stringstream ss;
	for(iter i = vec.begin(); i < vec.end()-1; i++)
		ss << *i << ';';
	ss << 'x';
	return ss.str();
}
