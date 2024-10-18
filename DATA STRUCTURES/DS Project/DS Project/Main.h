#pragma once
#include <iostream>
#include "Classes.h"
using namespace std;
    
/****************************************
* 
*   Muneel Haider 21i-0640
*   Muhammad Abdullah 21i-0643
*   Abdullah Zahoor 21i-2481
*   
*   Data Structures Project 2023 Spring
* 
*                                       */

int rows = 0;
int cols = 0;
int counter = 0;

void Detecting_Start_End(int& start, int& end, map** game) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (game[i][j].letter == 'X') {

                start = (i * 20) + j;
            }
            if (game[i][j].letter == '*') {

                end = (i * 20) + j;
            }
        }
    }
}

void printMap(map** game) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << game[i][j].letter << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void printMapWeights(map** game) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            cout << game[i][j].weight << "\t";
        }
        cout << endl;
    }

    cout << endl << endl << endl;
}

Player Spawn(map** game) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if(game[i][j].letter == 'C') {
            
                Player Hero(i, j);

                game[i][j].letter = Hero.letter;
                game[i][j].weight = 1;
                game[i][j].id = counter;
                counter++;

                return Hero;
            }
        }
    }
}

map** CreateMap() {

    map** game = new map * [rows];
    for (int i = 0; i < rows; i++) {

        game[i] = new map[cols];

        for (int j = 0; j < cols; j++) {

            game[i][j].letter = 'C';
            game[i][j].weight = 1;
        }
    }

    int x = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            x = rand() % 30;

            if (x <= 10 || x >= 19) {

                game[i][j].letter = 'C';
                game[i][j].weight = 1;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 11) {

                game[i][j].letter = 'J'; // 50
                game[i][j].weight = 50;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 12) {

                game[i][j].letter = 'P'; // 70
                game[i][j].weight = 70;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 13) {

                game[i][j].letter = 'W'; // 30
                game[i][j].weight = 30;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 14) {

                game[i][j].letter = '%'; // Death
                game[i][j].weight = 2;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 15) {

                game[i][j].letter = '#'; // Obstacle
                game[i][j].weight = 10000;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 16) {

                game[i][j].letter = '&'; // Dragon
                game[i][j].weight = 50;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 17) {

                game[i][j].letter = '$'; // Globlin
                game[i][j].weight = 70;
                game[i][j].id = counter;
                counter++;
            }
            else if (x == 18) {

                game[i][j].letter = '@'; // WereWolf
                game[i][j].weight = 30;
                game[i][j].id = counter;
                counter++;
            }
        }
    }

    x = rand() % (cols);

    game[17][x].letter = '*';
    game[17][x].weight = 1;
    game[17][x].id = counter;
    counter++;

    return game;
}

void MainOfProject() {

    system("color E4");
    
    cout << "Enter the dimensions of the game." << endl;
    cout << "Rows:\t";
    cin >> rows;

    cout << endl << "Columns:\t";
    cin >> cols;
    cout << endl << endl;

    map** game = CreateMap();

    Player Hero = Spawn(game);

    printMap(game);

    graphClass graph(rows * cols);
    AVL Tree;

    int** matrix = graph.CreateAdjacencyMatrix_From_Map(game, rows, cols);
    
    // Uncomment to print adjacency matrix
    // graph.print_adjacency_matrix(matrix, rows, cols);

    cout << "Legend:" << endl << endl;
    cout << "Player: X" << endl;
    cout << "Clear Path: C" << endl;
    cout << "Jewel: J" << endl;
    cout << "Potion: P" << endl;
    cout << "Weapon: W" << endl;
    cout << "Death Point: %" << endl;
    cout << "Obstacle: #" << endl;
    cout << "Dragon: &" << endl;
    cout << "Goblin: $" << endl;
    cout << "Werewolf: @" << endl;
    cout << "Crystal: *" << endl;

    int o1 = 0;
    int o2 = 0;
    int score = 0;

    cout << endl << endl << endl;
    cout << "What do you want to do?" << endl;
    cout << "1. Use Floyd's Algorithm" << endl;
    cout << "2. Use Prim's Algorithm" << endl;
    cout << "3. Use Kruskal's Algorithm" << endl;
    cout << "4. Use Dijkstra's Algorithm" << endl;
    cout << "-1. Exit" << endl;
    cin >> o1;

    if (o1 == 1) {

        cout << endl << endl << "Choose:" << endl;
        cout << "1. Shortest Path between player and crystal." << endl;
        cout << "2. Shortest Path between two chosen points." << endl;
        cout << "-1. Back" << endl;
        cin >> o2;

        if (o2 == 1) {

            int start = 0;
            int end = 0;

            Detecting_Start_End(start, end, game);

            graph.Floyd(matrix, 400, start, end);
        }
        else if (o2 == 2) {

            int t1 = 0;
            int t2 = 0;

            cout << endl << endl;
            cout << "Enter starting point: ";
            cin >> t1;

            cout << endl;
            cout << "Enter ending point: ";
            cin >> t2;

            cout << endl << endl;
            graph.Floyd(matrix, 400, t1, t2);
        }
    }
    else if (o1 == 2) {

        graph.PrimsAlgorithm(matrix, 0, (rows * cols) - 1, game, rows, cols);
    }
    else if (o1 == 3) {

        // Kruskal Algorithm
    }
    else if (o1 == 4) {

        cout << endl << endl << "Choose:" << endl;
        cout << "1. Shortest Path between player and crystal." << endl;
        cout << "2. Shortest Path between two chosen points." << endl;
        cout << "-1. Back" << endl;
        cin >> o2;

        if (o2 == 1) {

            int start = 0;
            int end = 0;

            Detecting_Start_End(start, end, game);

            graph.dijkstra(matrix, start, end, game, rows, cols);
        }
        else if (o2 == 2) {

            int t1 = 0;
            int t2 = 0;

            cout << endl << endl;
            cout << "Enter starting point: ";
            cin >> t1;

            cout << endl;
            cout << "Enter ending point: ";
            cin >> t2;

            cout << endl << endl;
            graph.dijkstra(matrix, t1, t2, game, rows, cols);
        }
    }

    Tree.InOrderTraversal(Tree.root, score);
    Tree.DeathNote();
}