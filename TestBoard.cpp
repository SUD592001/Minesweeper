#include "TestBoard.h"

TestBoard::TestBoard() {

}

void TestBoard::OpenFile(int choice) {
    if (choice == 1) {
        activeFile.open("boards/testboard1.brd");
    }
    else if (choice == 2) {
        activeFile.open("boards/testboard2.brd");
    }
    else if (choice == 3) {
        activeFile.open("boards/testboard3.brd");
    }
    else {

    }
}

void TestBoard::ReadFile() {
    if (activeFile.is_open()) {
        for (int j = 0; j < 16; j++) {
            for (int i = 0; i < 25; i++) {
                activeFile >> fileArray[i][j];
            }
        }
    }
}

void TestBoard::LoadArray(char(&numbers)[25][16]) {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 25; i++) {
            numbers[i][j] = fileArray[i][j];
        }
    }
}