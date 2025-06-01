#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;

/*
Funkcja sprawdzaj¹ca, czy podana liczba znajduje siê w okreœlonym zakresie
@param podana - sprawdzana liczba
@param poczatek - poczatek zakresu, w którym ma byæ liczba
@param koniec - koniec zakresu, w którym ma byæ liczba
@return - TRUE je¿eli liczba jest w zakresie, FALSE gdy nie jest
*/
bool f_czyWzakresie(int podana, int poczatek, int koniec);

/*
Funkcja rekurencyjna wyszukuj¹ca indeks pierwszego wyst¹pienia elementu w tablicy
@param tablica - vector przechowuj¹cy tablicê dwuwymiarow¹
@param cel - liczba, której pozycji szukamy
@param wiersz - pozycja startowa dla wierszy (0)
@param kolumna - pozycja startowa dla kolumn (tab[0].size() - 1)
@param wynik - zmienna przechowuj¹ca wynik
@return para indeksów
*/
pair<int, int> f_pierwszeWystRek(vector<vector<int>>& tablica, int cel, int wiersz, int kolumna, pair<int, int> wynik);


/*
Funkcja iteracyjna wyszukuj¹ca indeks pierwszego wyst¹pienia elementu w tablicy
@param tablica - vector przechowuj¹cy tablicê dwuwymiarow¹
@param cel - liczba, której pozycji szukamy
@return para indeksów
*/
pair<int, int> f_pierwszeWystIter(vector<vector<int>> tablica, int cel);

/*
Funkcja rekurencyjna wyszukuj¹ca indeks ostatniego wyst¹pienia elementu w tablicy
@param tablica - vector przechowuj¹cy tablicê dwuwymiarow¹
@param cel - liczba, której pozycji szukamy
@param wiersz - pozycja startowa dla wierszy (0)
@param kolumna - pozycja startowa dla kolumn (tab[0].size() - 1)
@return para indeksów
*/
pair<int, int> f_ostatnieWystRek(vector<vector<int>>& macierz, int cel, int wiersz, int kolumna);



/*
Funkcja iteracyjna wyszukuj¹ca indeks ostatniego wyst¹pienia elementu w tablicy
@param tablica - vector przechowuj¹cy tablicê dwuwymiarow¹
@param cel - liczba, której pozycji szukamy
@return para indeksów
*/
pair<int, int> f_ostatnieWystIter(vector<vector<int>> tablica, int cel);


#endif


