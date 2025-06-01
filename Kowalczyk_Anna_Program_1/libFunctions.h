#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;

/*
Funkcja sprawdzaj�ca, czy podana liczba znajduje si� w okre�lonym zakresie
@param podana - sprawdzana liczba
@param poczatek - poczatek zakresu, w kt�rym ma by� liczba
@param koniec - koniec zakresu, w kt�rym ma by� liczba
@return - TRUE je�eli liczba jest w zakresie, FALSE gdy nie jest
*/
bool f_czyWzakresie(int podana, int poczatek, int koniec);

/*
Funkcja rekurencyjna wyszukuj�ca indeks pierwszego wyst�pienia elementu w tablicy
@param tablica - vector przechowuj�cy tablic� dwuwymiarow�
@param cel - liczba, kt�rej pozycji szukamy
@param wiersz - pozycja startowa dla wierszy (0)
@param kolumna - pozycja startowa dla kolumn (tab[0].size() - 1)
@param wynik - zmienna przechowuj�ca wynik
@return para indeks�w
*/
pair<int, int> f_pierwszeWystRek(vector<vector<int>>& tablica, int cel, int wiersz, int kolumna, pair<int, int> wynik);


/*
Funkcja iteracyjna wyszukuj�ca indeks pierwszego wyst�pienia elementu w tablicy
@param tablica - vector przechowuj�cy tablic� dwuwymiarow�
@param cel - liczba, kt�rej pozycji szukamy
@return para indeks�w
*/
pair<int, int> f_pierwszeWystIter(vector<vector<int>> tablica, int cel);

/*
Funkcja rekurencyjna wyszukuj�ca indeks ostatniego wyst�pienia elementu w tablicy
@param tablica - vector przechowuj�cy tablic� dwuwymiarow�
@param cel - liczba, kt�rej pozycji szukamy
@param wiersz - pozycja startowa dla wierszy (0)
@param kolumna - pozycja startowa dla kolumn (tab[0].size() - 1)
@return para indeks�w
*/
pair<int, int> f_ostatnieWystRek(vector<vector<int>>& macierz, int cel, int wiersz, int kolumna);



/*
Funkcja iteracyjna wyszukuj�ca indeks ostatniego wyst�pienia elementu w tablicy
@param tablica - vector przechowuj�cy tablic� dwuwymiarow�
@param cel - liczba, kt�rej pozycji szukamy
@return para indeks�w
*/
pair<int, int> f_ostatnieWystIter(vector<vector<int>> tablica, int cel);


#endif


