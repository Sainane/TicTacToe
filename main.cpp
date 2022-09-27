#include <iostream>

using namespace std;
const uint8_t gridSize = 3;
int gameGrid[gridSize][gridSize] = {};


bool joueur = 0;
int coordonee = 0;
int gagnant;
void printGrid();
bool win(int &gagnant_);
bool draw();
bool legalMove = false;
bool fin = false;
int main() {
    joueur = false;
    cout << "Entrez les coordonnees comme 11, 12...33"  << endl;
    while(!fin) {
        do {
            legalMove = false;

            cout << "Joueur " << joueur << " : " << endl;
            cin >> coordonee;
            int x = coordonee/10;
            int y = coordonee%10;
            if(x >= 0 and x <= 2 and y >= 0 and y<= 2 and gameGrid[x][y] == 0) {
                legalMove = true;
            } else {
                cout << "Coup illegal, reesayez : " << endl;
            }
        } while(!legalMove);
        gameGrid[coordonee / 10][coordonee % 10] = 1 + joueur;

        printGrid();
        if (win(gagnant)) {
            fin = true;
            if (gagnant == 1) {
                cout << "Le joueur 1 a gagne" << endl;
            } else if (gagnant == 2) {
                cout << "Le joueur 2 a gagne" << endl;
            }
        } else if (draw()) {
            cout << "Match nul" << endl;
            fin = true;
        } else {
            joueur = !joueur;
        }
    }

    return 0;
}
bool win(int &gagnant_) {
    for (int i = 0; i < gridSize; i++) {
        if(gameGrid[i][0] != 0 and gameGrid[i][0] == gameGrid[i][1] and gameGrid[i][0] == gameGrid[i][2]) {
            gagnant = gameGrid[i][0];
            return true;

        }
        if(gameGrid[0][i] != 0 and gameGrid[0][i] == gameGrid[1][i] and gameGrid[0][i] == gameGrid[2][i]) {
            gagnant = gameGrid[0][i];
            return true;

        }
    }
    if(gameGrid[0][0] != 0 and gameGrid[0][0] == gameGrid[1][1] and gameGrid[0][0] == gameGrid[2][2]) {

        gagnant = gameGrid[0][0];
        return true;
    }
    if(gameGrid[2][0] != 0 and gameGrid[2][0] == gameGrid[1][1] and gameGrid[2][0] == gameGrid[0][2]) {
        gagnant = gameGrid[2][0];
        return true;
    }
    return false;
}

bool draw() {
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            if(gameGrid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void printGrid() {
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            switch(gameGrid[i][j]) {
                case 0 :
                    cout << '-';
                    break;
                case 1 :
                    cout << 'X';
                    break;
                case 2 :
                    cout << 'O';
                    break;
            }
            cout << ' ';
        }
        cout << endl;
    }
}