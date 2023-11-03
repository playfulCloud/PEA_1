//
// Created by Jakub on 27.10.2023.
//

#include <iostream>
#include "Menu.h"

/*TODO
 * 1. Wczytywanie danych z pliku.
 * 2. Wygenerowanie losowych danych.
 * 3. Wyświetlenie ostatnio wczytanych daynch.
 * 4. Wyświetlenie ostatnio wygenerowanych danych.
 * 5. Uruchomienie algorytmu dla wygenerowanych danych bądź wczytanych danych.
 * Wyświetlenie Wynik: Długość ścieżki: X  Ciąg Wierzchołków: X-Y-Z Czas Wykonywania: X.XXms
 * */



void Menu::displayMenu() {
    std::cout <<"=========================== Effective algorithm design ===========================" << std::endl;
    int gate = 0;
    while(gate != 8){
        std::cout <<"Choose what do you want to do: " << std::endl;
        std::cout <<"1 - Read data from file" << std::endl;
        std::cout <<"2 - Generate random data" << std::endl;
        std::cout <<"3 - Display read data" << std::endl;
        std::cout <<"4 - Display randomly generated data" << std::endl;
        std::cout <<"5 - Choose algorithm with read data" << std::endl;
        std::cout <<"6 - Choose algorithm with randomly generated data" << std::endl;
        std::cout <<"7 - Exit" << std::endl;
        std::cin >> gate;
        switch (gate) {
            case 1:
                graph = fileReader->readFromFile();
                graph.displayMatrixTable();
                break;
            case 2:
                randomGraph = generator->generateRandomMatrix();
                randomGraph.displayMatrixTable();
                break;
            case 3:
                graph.displayMatrixTable();
                break;
            case 4:
                randomGraph.displayMatrixTable();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;

        }
    }
}



