#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

class Seats
{
private:
    vector<vector<int>> Seat;

public:
    Seats() : Seat(5, vector<int>(10, 1)) {}

    int getSeatStatus(int row, int seatNumber)
    {
        if (row < 1 || row > 5 || seatNumber < 1 || seatNumber > 10)
        {
            return -1;
        }
        return Seat[row - 1][seatNumber - 1];
    }

    void reserveSeat(int row, int seatNumber)
    {
        if (row < 1 || row > 5 || seatNumber < 1 || seatNumber > 10)
        {
            return;
        }
        Seat[row - 1][seatNumber - 1] = 0;
    }

    void display()
    {
        cout << " ";
        for (int i = 0; i < 10; i++)
        {
            cout << " " << i + 1;
        }
        cout << endl;

        for (int row = 0; row < 5; row++)
        {
            cout << row + 1 << " ";
            for (int col = 0; col < 10; col++)
            {
                if (Seat[row][col] == 1)
                {
                    cout << "- ";
                }
                else
                {
                    cout << "X ";
                }
            }
            cout << "|" << endl;
        }
        cout << "-----------------------" << endl;
    }
};

int main()
{
    Seats s;

    bool exit = false;
    while (!exit)
    {
        system("cls");
        cout << endl;
        cout << "Welcome To Movie Ticket Booking System" << endl;
        cout << "******************************************" << endl;
        cout << "1. Reserve A Ticket" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter Your Choice: ";
        int val;
        cin >> val;

        if (val == 1)
        {
            s.display();

            int row, col;
            cout << "Enter Row (1-5): ";
            cin >> row;
            cout << "Enter Seat Number (1-10): ";
            cin >> col;

            if (row < 1 || row > 5 || col < 1 || col > 10)
            {
                cout << "Invalid Row or Seat Number!" << endl;
                Sleep(3000);
                continue;
            }
            int seatStatus = s.getSeatStatus(row, col);
            if (seatStatus == -1)
            {
                cout << "Invalid Row or Seat Number!" << endl;
                Sleep(3000);
                continue;
            }

            if (seatStatus == 0)
            {
                cout << "Sorry: Seat is already reserved!" << endl;
                Sleep(3000);
                continue;
            }

            s.reserveSeat(row, col);
            cout << "Seat Is Reserved Successfully in Row " << row << " and Seat Number " << col << endl;
            Sleep(3000);
        } // if1

        else if (val == 2)
        {
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
        else
        {
            cout << "Invalid Input" << endl;
            Sleep(3000);
        }
    }
    return 0;
}
