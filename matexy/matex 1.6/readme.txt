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
Changelog dla wersji wczeœniejszych ni¿ 1.0 (czyli dla Bet) nie bêdzie dostêpny.

V. 1.0
/Dyziu w³¹czony do projektu/
* Dodano program Dyzia licz¹cy pierwiastki równania kwadratowego.
* Dodano program Dyzia rozwi¹zuj¹cy uk³ad 2 równañ z 2 niewiadomymi
* Dodano wyszukiwarkê liczb pierwszych mniejszych ni¿ zadana

V. 1.1 141kB | 1034 linie
* Dodano wyszukiwarke pierwiastków ca³kowitych wielomianu dowolnego stopnia o wspó³czynnikach ca³kowitych
* Poprawiono orta znalezionego przez W¹tora :)

V. 1.2 120kB | 1041 linii | 25.11.08(?)
* Naprawiono brak "BREAK;" na koñcu wielomianów
* Dodano informacjê o tym, wielomian wiêcej pierwiastków ju¿ nie ma i zapytanie o wyjœcie.
* Rozszerzono zakres mozliwosci wprowadzenia danych jako wspó³czynniki wielomianu do 64 bitowych liczb ca³kowitych
* Dodano zlicznie wypisanych liczb pierwszych
* Naprawiono brak zapytania o zakonczenie programu na koncu liczb pierwszych
* Usunieto badziewne pytanie o imiê
* Dodano ten plik
* Usuniêto bug powoduj¹cy, ¿e program nie szuka³ ujemnych dzielników wyrazu wolnego wielomianu
* Poprawiono Obliczanie pierwiastków wielomianu, tak, ¿e teraz nie liczy W(x) nie bêd¹cego dzielnikiem, co przyœpieszy³o dzia³anie algorytmu :D
* Dodano licznik pierwiastków wielomianu

V. 1.3 122kB | 1100 linii | 25.11.08
/kosmetyka/
* Dodano czyszczenie ekranu na koniec ka¿dej pêtli
* Dodano logo
* Dodano mo¿liwoœæ zakoñczenia programu z poziomu g³ównego menu
* Dodano mo¿liwoœæ sprawdzenia danej liczby czy jest liczb¹ pierwsz¹
* Utworzono katygoriê bry³y w menu g³ównym, do której przeniesiono bry³y które ju¿ by³y :P 
* Zmieniono kolejnoœæ katygorii w menu g³ównym
* Zmieniono wiêkszoœæ zmiennych globalnych w zmienne lokalne
* Poprawiony drobny b³¹d z deklaracji funkcji heron.

V. 1.4 /beta/ 140kB | 1759 linii | 30.11.08
/Optymalizacja kodu i sprawdzanie zmiennych/
* Zmienione typy zmiennych (by zmniejszyæ iloœæ potrzebnej pamiêci lub zwiêkszyæ zakres danych)
* Dodany dzia³ geometria analityczna:
	- liczenie odleg³oœci punktu od prostej by Dyziu
	- -----//----------- miêdzy dwoma punktami by Dyziu
* Zmniejszona ilosc zmiennych, by zmniejszyc iloœæ wymaganej pamiêci (przejscie na tablice)
* Pytanie o wyjscie przeniesione na koniec pêtli, by³o na koñcu ka¿dego case - brak powtórzeñ => mniej linii kodu :D 
* Dodane sprawdzenie we wzorze herona, czy trójk¹t o podanych bokach jest mo¿liwy do skonstuowania w geometri eukildesowej 
* Dodano sprawdzanie poprawnoœci wprowadzonych danych
* Uniêta "Pauza" na koñcu ka¿dego case (kto j¹ tam da³?)

V. 1.4 /beta2/ 141kB | 1779 linii | 30.11.08
* Poprawione zbugowane liczenie liczb pierwszych
* ------------- // ------------ pierwiastków wielomianu

V. 1.4 /beta3/ 141kB | 1767 linii | 1.12.08
* Naprawiono b³¹d w bry³ach obrotowych powoduj¹cy wywalanie siê walca :P (thx to Krycha) 

V. 1.5 | 141 kB | 1566 linii | 18.12.08
* Sprawdzanie czy n>=1 w permutacji
* Zamiana ze zmiennych literowych na tablice w geometrii analitycznej
* Dodane przekszta³cenie wielomianu do postaci iloczynowej, je¿eli da siê roz³orzyæ na dwumiany
* Dodane dzielenie wielomianow za pomoca schematu Hornera,
* U³amki nie s¹ ju¿ traktowane jako liczba mniejsza od 0
* Drobne poprawki
* Instrukcja sprawdzaj¹ca poprawnoœæ danych przesuniêta do funkcji 
	- redukcja d³ugoœci kodu o ok. 320 linii (czemu wczeœniej na to nie wpad³em?)
* Dodano mo¿liwoœæ wyszuiwania dzielników danej liczby (na podstawie algorytmu liczby pierwszej)

V. 1.6 | 142 kB | 1611 linii | 25.01.09
* Poprawiono b³êdn¹ nazwê dwumian kwadratowy na trójmian (thx to Tomasz)
* Poprawiono dzia³anie modu³u licz¹cego pierwiastki trójmianu
* Drobne poprawki
* Po wpisaniu z³ego formatu danych program ju¿ nie nic nie powinien obliczaæ
* Usprawniony kod uk³adu 2 równañ z 2 niewiadomymi
* Dodano #if windows, dziêki czemu program powinien œmigaæ na innych systemach

###################
## do zrobienia: ##
###################

* !PRZEPROJEKTOWANIE PROGRAMU! Dziêki temu ma czytelniejsz¹ sk³adniê. Zmina IDE na MS Visual C++. 
* Zmiana instrukcja wprowadzania danych na funkcjê - redukcja d³ugoœci kodu :)
* poprawki w dziale wielomianów
* uzupe³nienie dzia³ów ostros³upy i graniastos³upy
* Wyszukiwanie pierwiastków wielomianu wœród liczb wymiernych

###########################
## Og³oszenia parafialne ##
###########################

#########################################################################################################
#													#
#						Poszukiwani:						#
#													#
#	* Ludzi maj¹cych czas i ochotê wspó³tworzyæ taki program matematyczny,				#
#	Przedewszystkim, je¿eli maj¹ ju¿ gotowe jakieœ swoje programy					#
#	licz¹ce ró¿ne dziwne rzeczy z zakresu Matmy i Fizy :D (w C++)					#
#													#
#	* Porz¹dnych beta-testerów, maj¹cych czas powy³apywaæ bugi wszelkiego typu w tym¿e programie.	#
#	najlepiej kumaj¹cych C++, by podpowiedzieli sposób naprawy wykrytego buga			#
#													#
#	* Ludzi do "wklepania" w program wszystkich (podstawowych) bry³					#
#													#
#########################################################################################################

Znane bugi:
	
* !Naprawiony:D! Wpisanie litery, kiedy program ¿¹da liczby powoduje wykrzaczenie,
poniewa¿ nie mo¿e przypisaæ zmiennej typu float/int/double/etc. wartoœci znakowej, tego zmieniæ nie mogê/nie umiem 
Ogólnie nie polecam wpisywania z³ego typu danych, np. ujemnych d³ugoœci odinka czy nieca³kowitych wspó³czynników wielomianu
W wiêkszoœci przypadków spowoduje to wykrzaczenie siê programu, w niektórych przypadkach zostaniesz poinformowany, ¿e wpisa³eœ z³¹ zmienn¹.

###############
##  Credits  ##
###############

* Kamil 'konsi' Strzempowicz
* Bartek 'Dyziu' Nizio³

##################
## Beta testers ##
##################

* Serek
* Tomasz
* Krycha (W¹tor)

####################
## Special thanks ##
####################

* Ludzie z forum Programuj.com
* Barte Krawczyk