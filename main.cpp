#include <iostream>

using namespace std;
const uint8_t gridSize = 3;
int gameGrid[gridSize][gridSize] = {
        {0,2, 1},
        {0,2, 0},
        {1, 2, 1} };




int gagnant;
bool win(int &gagnant_);
bool draw();
int main() {
    if(win(gagnant)) {
        if(gagnant == 1) {
            cout << "Le joueur 1 a gagne" << endl;
        } else if (gagnant == 2) {
            cout << "Le joueur 2 a gagne" << endl;
        }
    } else if(draw()) {
        cout << "Match nul" << endl;
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