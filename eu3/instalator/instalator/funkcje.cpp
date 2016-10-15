/*
 * Plik funkcje.cpp
 * Instalator - program instalacyjny moda Divide et Impera
 * wiêcej informacji: http://wayofwar.org/showthread.php?t=34092
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
#include "instalator.h"

int range;
std::string ver_here, ver_there;
const DWORD kilo = 1024;
std::string url;
HICON hIco;
int page = 0, oldpage = -1;
std::string rej_ver, path;
dlgproc procesy[] = {
	first,
	second,
	third,
	fourth,
	fifth
};
int wersja = -1;
/*
0 - h3t
1 - in
2 - na
3 - vanila
*/
bool opcje[4];
/*
0 - cache
1 - ustawienia
2 - manual
3 - patch
*/
void notify(HWND hDlg, const char* wiadomosc){
	HWND hEdit = GetDlgItem(hDlg, IDC_EDIT1);
	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)"usuwanie: ");
	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)wiadomosc);
	SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)"\r\n");
}

bool kosz(HWND hDlg){
	log("kosz", "start");
	std::string buff;
	SHFILEOPSTRUCT sh;
	char pat[MAX_PATH];

	buff = path;
	buff += "mod\\Divide et Impera.mod";
	DeleteFile(buff.c_str());
	notify(hDlg, buff.c_str());

	buff = path;
	buff += "mod\\Divide et Impera\\*";
	log("kosz", "sciezka", buff.c_str());
	strcpy_s(pat, MAX_PATH, buff.c_str());
	pat[buff.size()] = 0;
	pat[buff.size()+1] = 0;

	ZeroMemory(&sh, sizeof(SHFILEOPSTRUCT));
	sh.fFlags = FOF_NOCONFIRMATION;
	sh.pFrom = pat;
	sh.wFunc = FO_DELETE;
	sh.hwnd = hDlg;

	notify(hDlg, pat);

	if(SHFileOperation(&sh)){
		log("shfile", "error");
		MessageBox(hDlg, "Wystapi³ b³ad podczas usuwania poprzedniej wersji moda", "ERROR", MB_ICONWARNING | MB_OK);
		return false;
	}

	WaitForSingleObject(GetWindow(hDlg, GW_ENABLEDPOPUP), INFINITE);

	buff = path;
	buff += "mod\\Divide et Impera";
	notify(hDlg, buff.c_str());
	RemoveDirectory(buff.c_str());

	SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_REPLACESEL, 0, (LPARAM)"\r\n");
	log("kosz", "koniec");
	return true;
}

void ex(const std::string& in, std::vector<std::vector<std::string> >& vec){
	std::vector<std::string> temp, t;
	explode(in, "\n", t);
	log("ex", "linii", t.size());
	for(UINT i=0; i < t.size(); i++){
		temp.clear();
		explode(t[i], "|", temp);
		log("ex", "wyrazow", temp.size());
		vec.push_back(temp);
	}
}

void cache(HWND hDlg){
	log("cache", "start");
	std::string buff = path;
	buff += "map\\cache\\*";
	log("cache", "sciezka", buff.c_str());
	WIN32_FIND_DATA wfd; 
	HANDLE uchwyt = FindFirstFile(buff.c_str(), &wfd); 
	if(uchwyt != INVALID_HANDLE_VALUE){ 
		do{
			if((std::string)(wfd.cFileName) == "." || (std::string)(wfd.cFileName) == "..") continue;
			buff = path;
			buff += "map\\cache\\";
			buff += wfd.cFileName;
			if(wfd.dwFileAttributes == FILE_ATTRIBUTE_READONLY)
				SetFileAttributes(buff.c_str(), FILE_ATTRIBUTE_NORMAL);
			notify(hDlg, buff.c_str());
			DeleteFile(buff.c_str());
		}while(FindNextFile(uchwyt, &wfd)); 
		FindClose(uchwyt); 
		log("cache", "koniec czyszczenia");
	}else{
		log("cache", "error, id", GetLastError());
	}
	SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_REPLACESEL, 0, (LPARAM)"\r\n");
	log("cache", "koniec");
}

void ustawienia(HWND hDlg){
	log("ustawienia", "start");
	std::vector<std::string> set;
	std::string pat = path;
	std::string buff;

	buff += "settings.txt";
	std::ifstream ifile(pat.c_str());
	while(getline(ifile, buff)){
		if(buff.find("language") != -1)buff = "language=l_polish";
		set.push_back(buff);
	}
	ifile.close();

	std::ofstream ofile(pat.c_str());
	for(iter i = set.begin(); i < set.end(); ++i)
		ofile << *i << '\n';
	ofile.close();

}

void manual(HWND hDlg){
/*reserved 4 future :P */
}

void version(HWND hDlg){
	log("version", "start");	

	std::vector<std::vector<std::string> > vec;
	std::string buf;
	HINTERNET hInternet, hOpenURL;
	char buffer[kilo];
	DWORD dwRead;


	/*pobranie dei.ver*/
	hInternet = InternetOpen("DeI_downloader", /*NTERNET_OPEN_TYPE_PRECONFIG*/ 0, NULL, NULL, 0);//INTERNET_FLAG_ASYNC );
	if(!hInternet){
		MessageBox(hDlg, "nie udalo sie otworzyæ po³aczenia internetowego", "error", MB_OK);
		log("version", "nie udalo sie otworzyæ po³aczenia internetowego");
		return;
	}
	hOpenURL = InternetOpenUrl(hInternet, "http://download.eufi.org/eu3/mody/dei.ver", NULL, 0, 0, 0 );
	if(hOpenURL){
		log("version", "po³aczono z plikiem wersji");
		while(InternetReadFile(hOpenURL, buffer, kilo - 1, &dwRead)){
			log("version", "wczytano bajtów", dwRead);
			if(dwRead == 0) break;
			buffer[dwRead] = 0;
			buf += buffer;
		}
		InternetCloseHandle(hOpenURL);
		ex(buf, vec);
		buf.clear();
	}
	else{
		MessageBox(hDlg, "Nie uda³o siê po³¹czyæ z plikiem wersji", "error", MB_ICONERROR | MB_OK);
		log("version", "Nie uda³o siê po³¹czyæ z plikiem wersji");
		InternetCloseHandle(hInternet);
		return;
	}
	InternetCloseHandle(hInternet);

	if(vec.size() != 4){
		log("version", "z³y rozmiar wektora, size", vec.size());
		return;
	}
	url = vec[wersja][2];
	log("version", "url", url.c_str());

	log("version", "rozmiar pliku str [B]", vec[wersja][3].c_str());
	range =	atoi(vec[wersja][3].c_str())/1024;
	log("version", "rozmiar pliku uint [kB]", range);
//	InternetCloseHandle(hInternet);
	log("version", "koniec czêœci interntowej");
	/*po pobieraniu*/

	buf = path;
	buf += "mod\\Divide et Impera.mod";
	std::ifstream plik(buf.c_str());
	if(plik.fail()){
		log("version", "brak pliku mod");
		ver_here = "NONE";
		return;
	}

	std::getline(plik, buf);
	buf = buf.substr(buf.find('"'));

	ver_here = buf;
	ver_there = vec[wersja][4];
}

void patch(HWND hDlg){
	log("patch", "start");
	std::string buff = path;
	buff += "mod\\pacz.exe";
	SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_REPLACESEL, 0, (LPARAM)"uruchamianie paczera...\r\n");
	ShellExecute(NULL, "OPEN", buff.c_str(), NULL, NULL, SW_SHOW);
}

bool rejestr(){
	HKEY hkSoftware, hkParadox, hkEU;
	LONG result;
	DWORD dwBufSize = kilo;
	char buf [kilo + 1];
	DWORD typ_klucza = REG_SZ; 

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, KEY_ALL_ACCESS, &hkSoftware) == ERROR_SUCCESS)
		log("rejestr", "Udalo sie otworzyc klucz software.");
	else{
		log("rejestr", "nie uda³o siê otworzyæ klucza software");
		return false;
	}	

	if(RegOpenKeyEx(hkSoftware, "Paradox Interactive", 0, KEY_ALL_ACCESS, &hkParadox) == ERROR_SUCCESS)
		log("rejestr", "Udalo sie otworzyc klucz Paradox Interactive");
	else{
		log("rejestr", "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)");
		return false;
	}

	if(RegOpenKeyEx(hkParadox, "Europa Universalis III", 0, KEY_ALL_ACCESS, &hkEU) == ERROR_SUCCESS)
		log("rejestr", "Udalo sie otworzyc klucz Europa Universalis III");
	else{
		log("rejestr", "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)");
		return false;
	}

	result = RegQueryValueEx(hkEU, "path", NULL, &typ_klucza, (LPBYTE)buf, /*(LPDWORD)*/&dwBufSize);
	if(result == ERROR_SUCCESS){
		path = buf;
		log("rejestr", "œcie¿ka do folderu gry", buf);
	}
	else if(result == ERROR_FILE_NOT_FOUND){
		log("rejestr", "nie odnaleziono wartosci - gra zostala nieprawidlowo zainstalowana");
		return false;
	}
	else{
		log("rejestr", "unknown error");
		return false;
	}
	char dodatek[4][20] = {
		"HeirToTheThrone",
		"InNomine",
		"Napoleon",
		"version"
	};
	for(int i=0; i<4; i++){
		result = RegQueryValueEx(hkEU, dodatek[i], NULL, &typ_klucza, (LPBYTE)buf, /*(LPDWORD)*/&dwBufSize);
		if(result == ERROR_SUCCESS){
			wersja = i;
			rej_ver = buf;
			log("rejestr", "id dodatku", wersja);
			log("rejestr", "oznaczenie patcha", buf);
			break;
		}
	}
	if(rej_ver.size() == 0 || wersja == -1){
		log("rejestr", "nie znaleziono wersji");
		return false;
	}
	log("rejestr", "koniec");
	return true;
}

void download(HWND hDlg){
	HINTERNET hInternet, hOpenURL;
	char buffer[kilo+1];
	DWORD dwRead, suma = 0, licz = 0;
	time_t prev, next;
	double dif, v;

	SendDlgItemMessage(hDlg, IDC_PROGRESS, PBM_SETRANGE, 0, MAKELPARAM(0, range));
	SendDlgItemMessage(hDlg, IDC_PROGRESS, PBM_SETSTEP, 0, 0);

	hInternet = InternetOpen("DeI_downloader", 0, NULL, NULL, 0);
	hOpenURL = InternetOpenUrl(hInternet, url.c_str(), NULL, 0, 0, 0 );

	if(hOpenURL){
		log("download", "po³¹czono z plikiem moda");
		std::ofstream plik("dei.7z", std::fstream::binary);
		UINT i = 1;
		UINT st = 1;
		time(&prev);
		while(InternetReadFile(hOpenURL, buffer, kilo, &dwRead)){
			if(i%1024 == 0)log("download", "postêp pobierania [MB]", i/1024);
			if(dwRead == 0){
				log("download", "zakoñczono pobieranie, rozmiar [byte]", 1024*i);
				log("download", "\t\t rozmiar [kB]", i);
				break;
			}
			time(&next);
			dif = difftime(next, prev);
			if(dif > 0.99 && dif < 1.1){
				std::stringstream ss;
				v = i - st;
				suma += static_cast<DWORD>(v);
				licz++;
				ss << "download: " << v << " [kB/s]\tETA: " << (int)((range - i)*licz/suma) << " [s]";// << (range - i)%(v*60) <<"s";
				SetDlgItemText(hDlg, IDC_SPEED, ss.str().c_str());
				st = i;
				time(&prev);
			}
			SendDlgItemMessage(hDlg, IDC_PROGRESS, PBM_SETPOS, (WPARAM)i++, 0);
			plik.write(buffer, kilo);
			
		}
		InternetCloseHandle(hOpenURL);	
	}
	else{
		MessageBox(hDlg, "Nie uda³o siê po³¹czyæ z plikiem moda", "error", MB_ICONERROR | MB_OK);
		log("download", "Nie uda³o siê po³¹czyæ z plikiem moda");
		page = -1;
		InternetCloseHandle(hInternet);
		return;
	}
	InternetCloseHandle(hInternet);
	SendMessage(hDlg, WM_TIMER, 0, 0);
}

bool unpack(HWND hDlg){
	log("unpack", "start");
	std::stringstream ss;
	HANDLE hRead, hWrite;
	char buff[128];
	DWORD read;
	std::string str = "Rozpoczeto rozpakowywanie\r\n";
	DWORD id;
	SECURITY_ATTRIBUTES sa;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HWND hEdit = GetDlgItem(hDlg, IDC_EDIT1);

	ss << "7zr.exe" << " x dei.7z -y -o" << '"' << path << "mod\\" << '"';// << "-bd";
	strncpy_s(buff, 128, ss.str().c_str(), ss.str().size());
	log("unpack", "command line", buff);

	ZeroMemory(&sa, sizeof(SECURITY_ATTRIBUTES));
	sa.bInheritHandle = true;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);

	if(!CreatePipe(&hRead, &hWrite, &sa, 0)){
		log("unpack", "nie uda³o siê utworzyc rury");
		MessageBox(hDlg, "error", "error", 0);
		return false;
	}
	log("unpack", "utworzono rurê");

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.hStdOutput = hWrite;
	si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;

	if(!CreateProcess("7zr.exe", buff, NULL, NULL, TRUE, NULL, 0, 0, &si, &pi)){
		id = GetLastError();
		log("unpack", "nie uda³o siê utworzyc procesu, error id", id);
		MessageBox(hDlg, "error", "error", 0);
		return false;
	}

	for(;;){
		PeekNamedPipe(hRead, 0, 0, 0, &id, 0);
		if(id == 0){
		//	log("unpack", "brak znaków w rurze");
			GetExitCodeProcess(pi.hProcess, &id);
			if(id != STILL_ACTIVE){
				log("unpack", "proces zakoñczony, kod wyjscia", id);
				break;
			}
		//	log("unpack", "proces aktywny, kontynuacja");
			Sleep(100);
			continue;
		}
		ReadFile(hRead, buff, 127, &read, NULL);
		buff[read] = '\0';
		SendMessage(hEdit, EM_REPLACESEL, 0, (LPARAM)buff);
	}
	log("unpack", "koniec rozpakowywania");

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(hRead);
	CloseHandle(hWrite);
	return true;
}