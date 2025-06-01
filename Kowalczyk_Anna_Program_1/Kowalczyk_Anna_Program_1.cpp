#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "libFunctions.h"
#include "libExceptions.h" 

using namespace std;

int main() {
    string wynik = ""; // Zmienna przechowująca wynik
    int liczbaZestawow;
    cin >> liczbaZestawow;

    try {
        // Pętla przechodząca przez wszystkie zestawy
        for (int j = 0; j < liczbaZestawow; j++) {
            int wiersze;
            int kolumny;

            // Wczytywanie liczby wierszy z obsługą wyjątków
            do {
                try {
                    cin >> wiersze;
                    if (!f_czyWzakresie(wiersze, 1, 100)) {
                        throw MainException("Liczba wierszy poza zakresem 1-100");
                    }
                }
                catch (const MainException& e) {
                    cerr << "Blad wczytywania liczby wierszy: " << e.what() << endl;
                    cin.clear(); // Czyszczenie błędów wejścia
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie błędnych danych
                    continue; // Powtórzenie pętli wczytywania
                }
            } while (wiersze < 1 || wiersze > 100);

            // Wczytywanie liczby kolumn z obsługą wyjątków
            do {
                try {
                    cin >> kolumny;
                    if (!f_czyWzakresie(kolumny, 1, 100)) {
                        throw MainException("Liczba kolumn poza zakresem 1-100");
                    }
                }
                catch (const MainException& e) {
                    cerr << "Blad wczytywania liczby kolumn: " << e.what() << endl;
                    cin.clear(); // Czyszczenie błędów wejścia
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie błędnych danych
                    continue; // Powtórzenie pętli wczytywania
                }
            } while (kolumny < 1 || kolumny > 100);

            // Tworzenie tablicy
            vector<vector<int>> tab(wiersze, vector<int>(kolumny));
            for (size_t i = 0; i < wiersze; i++) {
                for (size_t j = 0; j < kolumny; j++) {
                    int podana;
                    do {
                        try {
                            cin >> podana;
                            if (!f_czyWzakresie(podana, -32768, 32768)) {
                                throw MainException("Liczba poza zakresem -32768 do 32768");
                            }
                        }
                        catch (const MainException& e) {
                            cerr << "Blad wczytywania elementu tablicy: " << e.what() << endl;
                            cin.clear(); // Czyszczenie błędów wejścia
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie błędnych danych
                            continue; // Powtórzenie pętli wczytywania
                        }
                    } while (podana < -32768 || podana > 32768);
                    tab[i][j] = podana;
                }
            }

            int szukana;
            cin >> szukana; // Dodane wczytywanie szukanej liczby

            // Wywołanie funkcji rekurencyjnych i iteracyjnych
            pair<int, int> para = f_pierwszeWystRek(tab, szukana, 0, tab[0].size() - 1, make_pair(-1, -1));
            if (para.first == -1 && para.second == -1) {
                wynik += "RekPier: nie ma " + to_string(szukana) + "\n";
            }
            else {
                wynik += "RekPier: " + to_string(szukana) + " w (" + to_string(para.first) + ", " + to_string(para.second) + ")" + "\n";
            }

            para = f_ostatnieWystRek(tab, szukana, 0, tab[0].size() - 1);
            if (para.first == -1 && para.second == -1) {
                wynik += "RekOst: nie ma " + to_string(szukana) + "\n";
            }
            else {
                wynik += "RekOst: " + to_string(szukana) + " w (" + to_string(para.first) + ", " + to_string(para.second) + ")" + "\n";
            }

            para = f_pierwszeWystIter(tab, szukana);
            if (para.first == -1 && para.second == -1) {
                wynik += "IterPier: nie ma " + to_string(szukana) + "\n";
            }
            else {
                wynik += "IterPier: " + to_string(szukana) + " w (" + to_string(para.first) + ", " + to_string(para.second) + ")" + "\n";
            }

            para = f_ostatnieWystIter(tab, szukana);
            if (para.first == -1 && para.second == -1) {
                wynik += "IterOst: nie ma " + to_string(szukana) + "\n";
            }
            else {
                wynik += "IterOst: " + to_string(szukana) + " w (" + to_string(para.first) + ", " + to_string(para.second) + ")" + "\n";
            }

            wynik += "---\n";
        }

        cout << endl;
        cout << wynik;

    }
    catch (const MainException& e) {
        cerr << "Wystapil blad: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Nieoczekiwany blad: " << e.what() << endl;
    }

    return 0;
}
