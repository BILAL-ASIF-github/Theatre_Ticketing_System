#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 15;
const int COLS = 30;

void initializeArrays(char arr[ROWS][COLS], int prices[ROWS][COLS]);
void seatReservation(char arr[ROWS][COLS], int prices[ROWS][COLS], int &totalPrice);
void printArray(const char arr[ROWS][COLS]);
void displayPrices();
void displaySoldTickets(const char arr[ROWS][COLS]);
void displaySeatingChart(const char arr[ROWS][COLS]);

int main() {
    char seatingChart[ROWS][COLS];
    int priceChart[ROWS][COLS];
    int totalPrice = 0;

    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::: CINEPAX CINEMA ::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "................................................... WELCOME TO OUR CINEMA ............................................." << endl;

    initializeArrays(seatingChart, priceChart);

    while (true) {
        cout << "\n SELECT ANY ONE OPERATION YOU WANT TO PERFORM:" << endl
             << " A) BUY A TICKET" << endl
             << " B) CHECKOUT THE PRICES" << endl
             << " C) CHECKOUT NUMBER OF SOLD TICKETS" << endl
             << " D) EXIT THE PROGRAM" << endl;

        char option;
        cout << "\n YOUR CHOICE: ";
        cin >> option;

        switch (option) {
            case 'A':
            case 'a':
                seatReservation(seatingChart, priceChart, totalPrice);
                break;
            case 'B':
            case 'b':
                displayPrices();
                break;
            case 'C':
            case 'c':
                displaySoldTickets(seatingChart);
                break;
            case 'D':
            case 'd':
                cout << " EXITING YOUR PROGRAM. THANK YOU!" << endl;
                return 0;
            default:
                cout << " WRONG INPUT" << endl;
                break;
        }
    }

    return 0;
}

void initializeArrays(char arr[ROWS][COLS], int prices[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = '#';
            if (i < 5) {
                prices[i][j] = 1500;
            } else if (i < 10) {
                prices[i][j] = 1000;
            } else {
                prices[i][j] = 500;
            }
        }
    }
}

void seatReservation(char arr[ROWS][COLS], int prices[ROWS][COLS], int &totalPrice) {
    int row, col;
    string choice;
    displaySeatingChart(arr);

    do {
        cout << "\nLET'S BUY YOUR TICKETS!" << endl;
        cout << " ENTER ROW NUMBER (1-15): ";
        cin >> row;
        cout << " ENTER COLUMN NUMBER (1-30): ";
        cin >> col;
        row--;
        col--;

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            if (arr[row][col] == '#') {
                arr[row][col] = '*';
                totalPrice += prices[row][col];
                cout << " YOU HAVE SUCCESSFULLY RESERVED A SEAT AT ROW " << row + 1 << " AND COLUMN " << col + 1 << " FOR " << prices[row][col] << " PKR" << endl;
            } else {
                cout << " THIS SEAT HAS ALREADY BEEN RESERVED." << endl;
            }
        if (row>='A'&&row<='Z'&&col>='A'&&col<='Z')
		{
			cout<<" INVALID ENTRY";
		}   
        } else {
            cout << " INVALID ENTRY :(" << endl;
        }

        cout << " DO YOU WANT TO BUY ANOTHER TICKET? (yes/no): ";
        cin >> choice;
    } while (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y");

    cout << "\n UPDATED SEATING CHART:" << endl;
    printArray(arr);
    cout << "\n TOTAL SPENT: " << totalPrice << " PKR" << endl;
}

void printArray(const char arr[ROWS][COLS]) {
    cout << "   ";
    for (int i = 1; i <= COLS; i++) {
        cout << setw(2) << i << " ";
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << setw(2) << i + 1 << "  ";
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void displayPrices() {
    cout << "\nPRICE CHART:" << endl;
    cout << " ROWS 1-5: 1500 PKR" << endl;
    cout << " ROWS 6-10: 1000 PKR" << endl;
    cout << " ROWS 11-15: 500 PKR" << endl;
}

void displaySoldTickets(const char arr[ROWS][COLS]) {
    int soldTickets = 0;
    int seatsAvailable = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == '*') {
                soldTickets++;
                seatsAvailable--;
            }
        }
    }

    cout << "\n NUMBER OF SOLD TICKETS: " << soldTickets << endl;
    cout << " NUMBER OF SEATS LEFT: " << seatsAvailable << endl;
}

void displaySeatingChart(const char arr[ROWS][COLS]) {
    cout << "\n SEATING CHART:" << endl;
    printArray(arr);
}

