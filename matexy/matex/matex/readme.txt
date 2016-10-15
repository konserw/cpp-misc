Program Matematyczny

           `/dd-      -ymy`                 :hmddhhhhhhhhhyyso`               /dd/         `/hh-  
          .hMMN-     /NMMh`                 .osyyhNMMmyyyhhhho`               /NMN/      .omNh:   
         -dMMMd`    +NMMM+                       `hMd.                         /NMm:   -sNNs-     
        -mMMMMs   `sMMMMm.      ./oyddho-        /MN/         `-+yhddho.        +NMm:-yNNs.       
       :mMhdMN/  -dMh+NMy    `/hNmyo+hMMy`      `dMh`       `/dNho~yNMh`        oMMMMmo.         
      +NNo`hMm. /mNo`/MM/   :dMh:`  .hMy`       +MN:       -dNs.` .odNh-        .sMMMm.           
    `sMN+ .mMd-sNm:  yMm.  +NN+     sMd.       .mMy`      :mMhoh-Dds/.       `:hNmymMN+           
   .hMm:  -NMMNMh.  .mMd` -NMo     -NN/       `sMm-      .dMNdy+-`         .omNd/` :NMm-          
  .dMm-   /MMMNo`   :NMh` oMM+   `-hMm.       :NMo       :NMh.   ``:sh: `:yNNs-     oMMh.         
 `dMd-    /MMd:     +MMs  :mMNdhdmmNMm.      `hNs`       `omMNmdmmNmy:`/dNd+`       `hMMs         
 `//`     `:-`      .o+`   `:/+/:.`.+-          ``           `-://:-.    :+-           .+o-    

					

#################
##  Changelog  ##
#################
Changelog dla wersji wcze�niejszych ni� 1.0 (czyli dla Bet) nie b�dzie dost�pny.

V. 1.0
/Dyziu w��czony do projektu/
* Dodano program Dyzia licz�cy pierwiastki r�wnania kwadratowego.
* Dodano program Dyzia rozwi�zuj�cy uk�ad 2 r�wna� z 2 niewiadomymi
* Dodano wyszukiwark� liczb pierwszych mniejszych ni� zadana

V. 1.1 141kB | 1034 linie
* Dodano wyszukiwarke pierwiastk�w ca�kowitych wielomianu dowolnego stopnia o wsp�czynnikach ca�kowitych
* Poprawiono orta znalezionego przez W�tora :)

V. 1.2
* Naprawiono brak "BREAK;" na ko�cu wielomian�w
* Dodano informacj� o tym, wielomian wi�cej pierwiastk�w ju� nie ma i zapytanie o wyj�cie.
* Rozszerzono zakres mozliwosci wprowadzenia danych jako wsp�czynniki wielomianu do 64 bitowych liczb ca�kowitych
* Dodano zlicznie wypisanych liczb pierwszych
* Naprawiono brak zapytania o zakonczenie programu na koncu liczb pierwszych
* Usunieto badziewne pytanie o imi�
* Dodano ten plik
* Usuni�to bug powoduj�cy, �e program nie szuka� ujemnych dzielnik�w wyrazu wolnego wielomianu
* Poprawiono Obliczanie pierwiastk�w wielomianu, tak, �e teraz nie liczy W(x) nie b�d�cego dzielnikiem, co przy�pieszy�o dzia�anie algorytmu :D
* Dodano licznik pierwiastk�w wielomianu

V. 1.3 122kB | 1100 linii | 25.11.08
/kosmetyka/
* Dodano czyszczenie ekranu na koniec ka�dej p�tli
* Dodano logo
* Dodano mo�liwo�� zako�czenia programu z poziomu g��wnego menu
* Dodano mo�liwo�� sprawdzenia danej liczby czy jest liczb� pierwsz�
* Utworzono katygori� bry�y w menu g��wnym, do kt�rej przeniesiono bry�y kt�re ju� by�y :P 
* Zmieniono kolejno�� katygorii w menu g��wnym
* Zmieniono wi�kszo�� zmiennych globalnych w zmienne lokalne
* Poprawiony drobny b��d z deklaracji funkcji heron.

V. 1.4 /beta/ 140kB | 1759 linii | 30.11.08
/Optymalizacja kodu i sprawdzanie zmiennych/
* Zmienione typy zmiennych (by zmniejszy� ilo�� potrzebnej pami�ci lub zwi�kszy� zakres danych)
* Dodany dzia� geometria analityczna:
	- liczenie odleg�o�ci punktu od prostej by Dyziu
	- -----//----------- mi�dzy dwoma punktami by Dyziu
* Zmniejszona ilosc zmiennych, by zmniejszyc ilo�� wymaganej pami�ci (przejscie na tablice)
* Pytanie o wyjscie przeniesione na koniec p�tli, by�o na ko�cu ka�dego case - brak powt�rze� => mniej linii kodu :D 
* Dodane sprawdzenie we wzorze herona, czy tr�jk�t o podanych bokach jest mo�liwy do skonstuowania w geometri eukildesowej 
* Dodano sprawdzanie poprawno�ci wprowadzonych danych
* Uni�ta "Pauza" na ko�cu ka�dego case (kto j� tam da�?)

V. 1.4 /beta2/ 141kB | 1779 linii | 30.11.08
* Poprawione zbugowane liczenie liczb pierwszych
* ------------- // ------------ pierwiastk�w wielomianu

V. 1.4 /beta3/ 141kB | 1767 linii | 1.12.08
* Naprawiono b��d w bry�ach obrotowych powoduj�cy wywalanie si� walca :P (thx to Krycha) 

V. 1.5 | 141 kB | 1566 linii | 18.12.08
* Sprawdzanie czy n>=1 w permutacji
* Zamiana ze zmiennych literowych na tablice w geometrii analitycznej
* Dodane przekszta�cenie wielomianu do postaci iloczynowej, je�eli da si� roz�orzy� na dwumiany
* Dodane dzielenie wielomianow za pomoca schematu Hornera,
* U�amki nie s� ju� traktowane jako liczba mniejsza od 0
* Drobne poprawki
* Instrukcja sprawdzaj�ca poprawno�� danych przesuni�ta do funkcji 
	- redukcja d�ugo�ci kodu o ok. 320 linii (czemu wcze�niej na to nie wpad�em?)
* Dodano mo�liwo�� wyszuiwania dzielnik�w danej liczby (na podstawie algorytmu liczby pierwszej)

V. 1.6 | 142 kB | 1611 linii | 25.01.09
* Poprawiono b��dn� nazw� dwumian kwadratowy na tr�jmian (thx to Tomasz)
* Poprawiono dzia�anie modu�u licz�cego pierwiastki tr�jmianu
* Drobne poprawki
* Po wpisaniu z�ego formatu danych program ju� nie nic nie powinien oblicza�
* Usprawniony kod uk�adu 2 r�wna� z 2 niewiadomymi
* Dodano #if windows, dzi�ki czemu program powinien �miga� na innych systemach

V. 2.0 beta1 | 111kB | ? | 10.02.09
* !PRZEPROJEKTOWANIE PROGRAMU! (struktura modu�owa) Dzi�ki temu ma czytelniejsz� sk�adni�.
* Zmina IDE na MS Visual C++.
* Zmiana instrukcja wprowadzania danych na funkcj� - redukcja d�ugo�ci kodu :)
* Zmiana statycznych tablic na vectory
* Zmieniona struktura menu 
* Menu przeniesione na curses
* Dodana opcja wy�wietlenia readme
* Konwersja ca�ej planimetri z v 1.6
* Usuni�to jeden z przypadk�w trapezu z kt�rym by� problem (z konwersj�)

V. 2.0 beta2 | 39kB | 14.o2.o9
* Ulepszone menu
* Naprawiony bug spowodowany opcj� prekompilowanego nag��wka
* Zminiony tryb kompilacji z debug na release

V. 2.0 beta3 | 39kB/1.75MB | 18.02.09
* Dodano prekompilowany nag��wek (dzia�aj�cy :))
* Wy�wietlanie loga przeniesiono do osobnej funkcji (+przesuni�cie i kolorek :P)
* Dodano biblioteki umo�liwiaj�ce poprawne funkcjonowanie programu bez .NET Framework

V.2.0 beta4 | 37kB/1.4MB | 1.o3.o9
* Dodano przechodznie kursora w menu z pierwszej do ostatniej pozycji i odwrotnie
* Zmiana standartowego I/O na curses
* Dodano wszystkie opcje menu g��wnego
* Wywolanie okna tylko raz - wcze�niej by�o wielokrotnie - �le
* Poprawiono kilka mniejszych i wi�kszych bug�w
* Biblioteki curses(.lib) teraz s� "wkompilowane" w program :)
* Do��czono licencj� GNU GPL na zasadach kt�rej program b�dzie rozpowszechniany
* Naprawiono b��d uniemo�liwiaj�cy wczytanie danych z klawiatury
* Naprawiono b��d kt�ry powodowa� wy�wietlanie warto�ci 0.0000 mimio pawid�owych oblicze�
* Dodano "uruchamiacz" :)

V.2.0 | 36kB/1.8MB | 8.o3.o9
* Menusy poszczeg�lnych sekcji przeniesione do tych sekcji - usuni�cie pliku menus.cpp
* Planimetria definitywnie sko�czona (chyba ze kto� by si� chcia� pobawi�) :)
* Dodano kombinatoryk�
* Dodano sprawdzanie czy u�ytkownik wprowadzi� prawid�owe dane
* Zmiana kursora w menu - znaczne skr�cenie kodu
* Dodano ci�gi
11.03.09:
* Dodano teorie liczb (podzielnosc, liczby pierwsze)
* Poprawiono algorytm szukaj�cy dzielnik�w liczby, tak �e teraz znajduje tak�e dzielniki ujemne
16.03.09:
* Naprawiono kod kombinacji

V. 2.1:
18.03.09:
* Zrewolucjonizowane menu! :) Lepsze i zajmuj�ce mniej kodu :)
* Naprawiony bug w permutacji bez powt�rze�
* Usuni�to "using std::..."
19.03.09:
* Gotowe ca�e nowe menu :)
20.03.09:
* Ostatnie (narazie) drobne poprawki do menu 
* Poprawiono wyswietlanie wszystkich funkcji programu
* Przekonwertowano geometri� analityczn�
* Dodano pare rzeczy w stosunku do geometrii analitycznej z v. 1.6
21.03.09:
* Przekonwertowano algebr� (bez wielomian�w)
* Jeszcze troch� przer�bek w menu (jednak)
* Zmieniona funkcja wy�wietlaj�ca logo
22.03.09:
* Naprawiony (ostatni mam nadziej�) bug w podmenu graniastos�up�w
* Przekonwertowane wszystkie bry�y z 1.6 (co niestety nie oznacza �e s� ju� wszystie :/)
* Drobne poprawki
25.03.09:
* Dodano dzielenie schematem hornera i szuaknie pierwiastk�w ca�kowitych wielomianu
26.03.09:
* Naprawiony krytyczny b��d w dzieleniu schematem hornera
27.o3.o9:
* Poprawione dzielenie schematem hornera
28.03.09:
* Wy��czone dwa niepotrzebne standartowe nag��wki
* Dodane dzielenie przez znalezione pierwiastki
22.04.09:
* Usprawnienia dotycz�ce wielomian�w

V. 2.2:
1.05.09:
* Menusy zmienione na obiekty - uproszczenie kodu + wi�ksza niezawodno�� + mniejsza pami�cio�erno�� i szybsze dzia�anie

###################
## do zrobienia: ##
###################

* poprawki w dziale wielomian�w
* uzupe�nienie dzia��w ostros�upy i graniastos�upy
* Wyszukiwanie pierwiastk�w wielomianu w�r�d liczb wymiernych
* Installer

###########################
## Og�oszenia parafialne ##
###########################

#########################################################################################################
#													#
#						Poszukiwani:						#
#													#
#	* Ludzi maj�cych czas i ochot� wsp�tworzy� taki program matematyczny,				#
#	Przedewszystkim, je�eli maj� ju� gotowe jakie� swoje programy					#
#	licz�ce r�ne dziwne rzeczy z zakresu Matmy i Fizy :D (w C++)					#
#													#
#	* Porz�dnych beta-tester�w, maj�cych czas powy�apywa� bugi wszelkiego typu w tym�e programie.	#
#	najlepiej kumaj�cych C++, by podpowiedzieli spos�b naprawy wykrytego buga			#
#													#
#	* Ludzi do "wklepania" w program wszystkich (podstawowych) bry�					#
#													#
#########################################################################################################

###############
##  Credits  ##
###############

* Kamil 'konsi' Strzempowicz
* Bartek 'Dyziu' Nizio�

##################
## Beta testers ##
##################

* Serek
* Tomasz
* Krycha (W�tor)

####################
## Special thanks ##
####################

* Ludzie z forum Programuj.com
* Bartek Krawczyk