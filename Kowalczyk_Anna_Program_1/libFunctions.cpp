#include "libFunctions.h"

// Funkcja sprawdzaj¹ca, czy podana liczba znajduje siê w okreœlonym zakresie
bool f_czyWzakresie(int podana, int poczatek, int koniec)
{
    if (podana >= poczatek and podana <= koniec) {
        return true;  // Zwraca true, jeœli liczba znajduje siê w zakresie
    }
    else {
        return false; // Zwraca false, jeœli liczba nie znajduje siê w zakresie
    }
}



//Funkcja rekurencyjna wyszukuj¹ca indeks pierwszego wyst¹pienia elementu w tablicy
pair<int, int> f_pierwszeWystRek(vector<vector<int>>& tablica, int cel, int wiersz, int kolumna, pair<int, int> wynik) {
    // Jeœli jesteœmy poza granicami tablicy, zwracamy wynik
    if (wiersz >= tablica.size() || kolumna < 0)
        return wynik;

    // Jeœli znaleŸliœmy element, aktualizujemy wynik, jeœli to pierwsze wyst¹pienie lub leksykograficznie wczeœniejsze
    if (tablica[wiersz][kolumna] == cel && (wynik.first == -1 || wiersz < wynik.first || (wiersz == wynik.first && kolumna < wynik.second))) {
        wynik = make_pair(wiersz, kolumna);
    }

    // Jeœli element jest mniejszy, przechodzimy do kolejnego wiersza
    if (tablica[wiersz][kolumna] < cel) {
        return f_pierwszeWystRek(tablica, cel, wiersz + 1, kolumna, wynik);
    }
    // W przeciwnym razie,idziemy w lewo w tym samym wierszu
    else {
        return f_pierwszeWystRek(tablica, cel, wiersz, kolumna - 1, wynik);
    }
}



//Funkcja iteracyjna wyszukuj¹ca indeks pierwszego wyst¹pienia elementu w tablicy
pair<int, int> f_pierwszeWystIter(vector<vector<int>> tablica, int cel) {
    int wiersz = 0, kolumna = tablica[0].size() - 1; // Zaczynamy od prawego górnego rogu tablicy

    pair<int, int> wynik = make_pair(-1, -1); // Inicjalizujemy wynik jako (-1, -1)

    while (wiersz < tablica.size() && kolumna >= 0) {
        if (tablica[wiersz][kolumna] == cel) {
            // Aktualizujemy wynik, jeœli to pierwsze wyst¹pienie lub leksykograficznie wczeœniejsze
            if (wynik.first == -1 || wiersz < wynik.first || (wiersz == wynik.first && kolumna < wynik.second)) {
                wynik = make_pair(wiersz, kolumna);
            }
            // Poniewa¿ znaleŸliœmy element, przechodzimy dalej w lewo
            kolumna--;
        }
        else if (tablica[wiersz][kolumna] > cel)
            kolumna--; // Idziemy w lewo w tej samej kolumnie
        else
            wiersz++; // Idziemy w dó³ w tym samym wierszu
    }

    return wynik; // Zwracamy wynik (mo¿e byæ (-1, -1) jeœli nie znaleŸliœmy elementu)
}


//Funkcja rekurencyjna wyszukuj¹ca indeks ostatniego wyst¹pienia elementu w tablicy
pair<int, int> f_ostatnieWystRek(vector<vector<int>>& macierz, int cel, int wiersz, int kolumna) {
    // Warunek zakoñczenia rekurencji: gdy wiersz lub kolumna wychodz¹ poza granice macierzy
    if (wiersz >= macierz.size() || kolumna < 0)
        return make_pair(-1, -1); // Zwraca (-1, -1), jeœli tablica jest pusta lub szukany element nie zosta³ znaleziony

    // SprawdŸ aktualny element
    if (macierz[wiersz][kolumna] == cel) {
        // Jeœli znaleziono szukany element, aktualizuj ostatnie wyst¹pienie
        pair<int, int> ostatnieWystapienie = f_ostatnieWystRek(macierz, cel, wiersz + 1, kolumna);
        if (ostatnieWystapienie.first == -1 && ostatnieWystapienie.second == -1) {
            // Jeœli ostatnie wyst¹pienie nie zosta³o jeszcze znalezione, to jest to ostatnie wyst¹pienie
            return make_pair(wiersz, kolumna);
        }
        // Jeœli ostatnie wyst¹pienie zosta³o ju¿ znalezione, zwróæ je dalej
        return ostatnieWystapienie;
    }
    else if (macierz[wiersz][kolumna] < cel) {
        // Jeœli aktualny element jest mniejszy od szukanego, idziemy w dó³ w tej samej kolumnie
        return f_ostatnieWystRek(macierz, cel, wiersz + 1, kolumna);
    }
    else {
        // Jeœli aktualny element jest wiêkszy od szukanego, idziemy w lewo w tej samej kolumnie
        return f_ostatnieWystRek(macierz, cel, wiersz, kolumna - 1);
    }
}




//Funkcja iteracyjna wyszukuj¹ca indeks ostatniego wyst¹pienia elementu w tablicy
pair<int, int> f_ostatnieWystIter(vector<vector<int>> tablica, int cel) {
    int wiersz = 0, kolumna = tablica[0].size() - 1; // Zaczynamy od prawego górnego rogu tablicy

    pair<int, int> wynik = make_pair(-1, -1); // Inicjalizujemy wynik jako (-1, -1)

    while (wiersz < tablica.size() && kolumna >= 0) {
        if (tablica[wiersz][kolumna] == cel) {
            // Aktualizujemy wynik, jeœli to pierwsze wyst¹pienie lub leksykograficznie póŸniejsze
            if (wynik.first == -1 || wiersz > wynik.first || (wiersz == wynik.first && kolumna > wynik.second)) {
                wynik = make_pair(wiersz, kolumna);
            }
            // Poniewa¿ znaleŸliœmy element, przechodzimy dalej 
            wiersz++;
        }
        else if (tablica[wiersz][kolumna] > cel)
            kolumna--; // Idziemy w lewo w tym samym wierszu
        else
            wiersz++; // Idziemy o jeden wiersz ni¿ej
    }

    return wynik;
}

