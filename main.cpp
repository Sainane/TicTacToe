/* Rachel Tranchida et Rafael Dousse
 * Rendu le 29.09.2022
 * Labo Tic-Tac-Toe
 */


#include <iostream>
#include <random>
#include <iomanip>


using namespace std;

const uint8_t gridSize = 3;
int gameGrid[gridSize][gridSize] = {};

random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister.
uniform_int_distribution<> dist(0, 2); // distribute results between 1 and 6 inclusive.

bool ai = true;
bool joueur = false;
int coordonee = 0;

bool computer(int joueur);

int gagnant;

void printGrid();

bool win(int &gagnant_);

bool draw();

bool legalMove = false;
bool fin = false;

int main() {
    printGrid();
    joueur = false;

    cout << "\nEntrez les coordonnees du tableau (00, 01, 02, 10...22)" << endl;

    while (!fin) {
        if (!joueur or !ai) {
            do {
                legalMove = false;

                cout << "\nJoueur " << int(joueur) + 1 << " : " << endl;
                if (cin >> coordonee) {
                    int x = coordonee / 10;
                    int y = coordonee % 10;
                    if (x >= 0 and x <= 2 and y >= 0 and y <= 2 and gameGrid[x][y] == 0) {
                        legalMove = true;
                    } else {
                        cout << "Coup illegal, reesayez : " << endl;
                    }
                } else {
                    cout << "Entree invalide : reessayez : " << endl;
                    cin.clear();
                    cin.ignore(1000000000, '\n');

                }
            } while (!legalMove);
            gameGrid[coordonee / 10][coordonee % 10] = 1 + int(joueur);
        } else {
            while (!computer(int(joueur) + 1));
        }
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
        if (gameGrid[i][0] != 0 and gameGrid[i][0] == gameGrid[i][1] and gameGrid[i][0] == gameGrid[i][2]) {
            gagnant = gameGrid[i][0];
            return true;

        }
        if (gameGrid[0][i] != 0 and gameGrid[0][i] == gameGrid[1][i] and gameGrid[0][i] == gameGrid[2][i]) {
            gagnant = gameGrid[0][i];
            return true;

        }
    }
    if (gameGrid[0][0] != 0 and gameGrid[0][0] == gameGrid[1][1] and gameGrid[0][0] == gameGrid[2][2]) {

        gagnant = gameGrid[0][0];
        return true;
    }
    if (gameGrid[2][0] != 0 and gameGrid[2][0] == gameGrid[1][1] and gameGrid[2][0] == gameGrid[0][2]) {
        gagnant = gameGrid[2][0];
        return true;
    }
    return false;
}

bool draw() {
    for (auto &i: gameGrid) {
        for (int j: i) {
            if (j == 0) {
                return false;
            }
        }
    }
    return true;
}

void printGrid() {

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cout << setw(1);
            switch (gameGrid[i][j]) {
                case 0 :
                    cout << ' ';
                    break;
                case 1 :
                    cout << 'X';
                    break;
                case 2 :
                    cout << 'O';
                    break;
            }
            if (j < gridSize - 1) {
                cout << "|";
            }

        }
        cout << endl;
        if (i < gridSize - 1) {
            cout << "-----" << endl;
        }
    }

}

bool computer(int joueur) {

    int x = dist(gen);
    int y = dist(gen);
    if (gameGrid[x][y] == 0) {
        gameGrid[x][y] = joueur;
        cout << "\nOrdinateur : ";
        cout << x << y << endl;
        return true;
    }
    return false;
}