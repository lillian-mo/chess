#include <iostream>
#include <string>
#include "textdisplay.h"
#include "board.h"
#include "piece.h"
using namespace std;

/*
In this display, capital letters denote white pieces, and lower case letters denote black pieces. Unoccupied squares are denoted
by a blank space for white squares, and an underscore character for dark squares. The above board also represents the initial
configuration of the game.
*/

char pieceToChar(PieceType p) {
    switch (p) {
        case PieceType::Pawn:
            return 'p';
        case PieceType::Bishop:
            return 'b';
        case PieceType::Knight:
            return 'k';
        case PieceType::Rook:
            return 'r';
        case PieceType::Queen:
            return 'q';
        case PieceType::King:
            return 'k';
        case PieceType::Empty:
            return ' ';
        
    }
}

TextDisplay::TextDisplay() {
    char whiteSquare = ' ';
    char darkSquare = '_';
    char curSquare = darkSquare;

    for (int i = 0; i < boardSize; ++i) {
        std::vector<char> newRow;
        for (int j = 0; j < boardSize; ++j) {
            // init row
            // if i is even, start with dark
            // if i is odd, start with white
            newRow.emplace_back(curSquare);

            // toggle square
            if (curSquare == darkSquare) {
                curSquare = whiteSquare;
            } else {
                curSquare = darkSquare;
            }
        }
        theDisplay.emplace_back(newRow);
    }
}

void TextDisplay::notify(Piece *p, int row, int col) {
    if (p == nullptr) {
        int rowParity = row % 2;
        int colParity = col % 2;
        if (rowParity == colParity) {
            theDisplay[row][col] == '_';
        } else {
            theDisplay[row][col] == ' ';
        }
        return;
    }
    theDisplay[row][col] == pieceToChar(p->getState());
    if (p->getColour() == Colour::WHITE) {
        theDisplay[row][col] = theDisplay[row][col] - 32;
    }

}

TextDisplay::~TextDisplay() {
    
}

ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    int size = td.boardSize;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            out << td.theDisplay[i][j];
        }
    }
    return out;
}