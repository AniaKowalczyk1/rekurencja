#include "libFunctions.h"

// Funkcja sprawdzaj�ca, czy podana liczba znajduje si� w okre�lonym zakresie
bool f_czyWzakresie(int podana, int poczatek, int koniec)
{
    if (podana >= poczatek and podana <= koniec) {
        return true;  // Zwraca true, je�li liczba znajduje si� w zakresie
    }
    else {
        return false; // Zwraca false, je�li liczba nie znajduje si� w zakresie
    }
}



//Funkcja rekurencyjna wyszukuj�ca indeks pierwszego wyst�pienia elementu w tablicy
pair<int, int> f_pierwszeWystRek(vector<vector<int>>& tablica, int cel, int wiersz, int kolumna, pair<int, int> wynik) {
    // Je�li jeste�my poza granicami tablicy, zwracamy wynik
    if (wiersz >= tablica.size() || kolumna < 0)
        return wynik;

    // Je�li znale�li�my element, aktualizujemy wynik, je�li to pierwsze wyst�pienie lub leksykograficznie wcze�niejsze
    if (tablica[wiersz][kolumna] == cel && (wynik.first == -1 || wiersz < wynik.first || (wiersz == wynik.first && kolumna < wynik.second))) {
        wynik = make_pair(wiersz, kolumna);
    }

    // Je�li element jest mniejszy, przechodzimy do kolejnego wiersza
    if (tablica[wiersz][kolumna] < cel) {
        return f_pierwszeWystRek(tablica, cel, wiersz + 1, kolumna, wynik);
    }
    // W przeciwnym razie,idziemy w lewo w tym samym wierszu
    else {
        return f_pierwszeWystRek(tablica, cel, wiersz, kolumna - 1, wynik);
    }
}



//Funkcja iteracyjna wyszukuj�ca indeks pierwszego wyst�pienia elementu w tablicy
pair<int, int> f_pierwszeWystIter(vector<vector<int>> tablica, int cel) {
    int wiersz = 0, kolumna = tablica[0].size() - 1; // Zaczynamy od prawego g�rnego rogu tablicy

    pair<int, int> wynik = make_pair(-1, -1); // Inicjalizujemy wynik jako (-1, -1)

    while (wiersz < tablica.size() && kolumna >= 0) {
        if (tablica[wiersz][kolumna] == cel) {
            // Aktualizujemy wynik, je�li to pierwsze wyst�pienie lub leksykograficznie wcze�niejsze
            if (wynik.first == -1 || wiersz < wynik.first || (wiersz == wynik.first && kolumna < wynik.second)) {
                wynik = make_pair(wiersz, kolumna);
            }
            // Poniewa� znale�li�my element, przechodzimy dalej w lewo
            kolumna--;
        }
        else if (tablica[wiersz][kolumna] > cel)
            kolumna--; // Idziemy w lewo w tej samej kolumnie
        else
            wiersz++; // Idziemy w d� w tym samym wierszu
    }

    return wynik; // Zwracamy wynik (mo�e by� (-1, -1) je�li nie znale�li�my elementu)
}


//Funkcja rekurencyjna wyszukuj�ca indeks ostatniego wyst�pienia elementu w tablicy
pair<int, int> f_ostatnieWystRek(vector<vector<int>>& macierz, int cel, int wiersz, int kolumna) {
    // Warunek zako�czenia rekurencji: gdy wiersz lub kolumna wychodz� poza granice macierzy
    if (wiersz >= macierz.size() || kolumna < 0)
        return make_pair(-1, -1); // Zwraca (-1, -1), je�li tablica jest pusta lub szukany element nie zosta� znaleziony

    // Sprawd� aktualny element
    if (macierz[wiersz][kolumna] == cel) {
        // Je�li znaleziono szukany element, aktualizuj ostatnie wyst�pienie
        pair<int, int> ostatnieWystapienie = f_ostatnieWystRek(macierz, cel, wiersz + 1, kolumna);
        if (ostatnieWystapienie.first == -1 && ostatnieWystapienie.second == -1) {
            // Je�li ostatnie wyst�pienie nie zosta�o jeszcze znalezione, to jest to ostatnie wyst�pienie
            return make_pair(wiersz, kolumna);
        }
        // Je�li ostatnie wyst�pienie zosta�o ju� znalezione, zwr�� je dalej
        return ostatnieWystapienie;
    }
    else if (macierz[wiersz][kolumna] < cel) {
        // Je�li aktualny element jest mniejszy od szukanego, idziemy w d� w tej samej kolumnie
        return f_ostatnieWystRek(macierz, cel, wiersz + 1, kolumna);
    }
    else {
        // Je�li aktualny element jest wi�kszy od szukanego, idziemy w lewo w tej samej kolumnie
        return f_ostatnieWystRek(macierz, cel, wiersz, kolumna - 1);
    }
}




//Funkcja iteracyjna wyszukuj�ca indeks ostatniego wyst�pienia elementu w tablicy
pair<int, int> f_ostatnieWystIter(vector<vector<int>> tablica, int cel) {
    int wiersz = 0, kolumna = tablica[0].size() - 1; // Zaczynamy od prawego g�rnego rogu tablicy

    pair<int, int> wynik = make_pair(-1, -1); // Inicjalizujemy wynik jako (-1, -1)

    while (wiersz < tablica.size() && kolumna >= 0) {
        if (tablica[wiersz][kolumna] == cel) {
            // Aktualizujemy wynik, je�li to pierwsze wyst�pienie lub leksykograficznie p�niejsze
            if (wynik.first == -1 || wiersz > wynik.first || (wiersz == wynik.first && kolumna > wynik.second)) {
                wynik = make_pair(wiersz, kolumna);
            }
            // Poniewa� znale�li�my element, przechodzimy dalej 
            wiersz++;
        }
        else if (tablica[wiersz][kolumna] > cel)
            kolumna--; // Idziemy w lewo w tym samym wierszu
        else
            wiersz++; // Idziemy o jeden wiersz ni�ej
    }

    return wynik;
}

