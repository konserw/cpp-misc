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

V. 1.2 120kB | 1041 linii | 25.11.08(?)
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

###################
## do zrobienia: ##
###################

* !PRZEPROJEKTOWANIE PROGRAMU! Dzi�ki temu ma czytelniejsz� sk�adni�. Zmina IDE na MS Visual C++. 
* Zmiana instrukcja wprowadzania danych na funkcj� - redukcja d�ugo�ci kodu :)
* poprawki w dziale wielomian�w
* uzupe�nienie dzia��w ostros�upy i graniastos�upy
* Wyszukiwanie pierwiastk�w wielomianu w�r�d liczb wymiernych

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

Znane bugi:
	
* !Naprawiony:D! Wpisanie litery, kiedy program ��da liczby powoduje wykrzaczenie,
poniewa� nie mo�e przypisa� zmiennej typu float/int/double/etc. warto�ci znakowej, tego zmieni� nie mog�/nie umiem 
Og�lnie nie polecam wpisywania z�ego typu danych, np. ujemnych d�ugo�ci odinka czy nieca�kowitych wsp�czynnik�w wielomianu
W wi�kszo�ci przypadk�w spowoduje to wykrzaczenie si� programu, w niekt�rych przypadkach zostaniesz poinformowany, �e wpisa�e� z�� zmienn�.

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
* Barte Krawczyk