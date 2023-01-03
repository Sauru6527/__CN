#include <iostream>
using namespace std;

int main()
{
    int send[7], receive[7], d1, d2, d3, d4, i, c1, c2, c3, j, c;
    cout << "Enter four bit of data:" << endl;
    cin >> d1 >> d2 >> d3 >> d4;
    send[4] = d1; // 3
    send[2] = d2; // 5
    send[1] = d3; // 6
    send[0] = d4; // 7

    // Calculation of even parity
    send[6] = send[4] ^ send[2] ^ send[0];
    send[5] = send[4] ^ send[1] ^ send[0];
    send[3] = send[2] ^ send[1] ^ send[0];

    cout << "Encoded data is:";
    for (i = 0; i <= 6; i++)
        cout << send[i]; // 7 bit code generated

    cout << "\nEnter the received code:";
    for (j = 0; j <= 6; j++)
        cin >> receive[j];

    // Error checking phase for 7bit send and recieve code
    c1 = receive[6] ^ receive[4]     ^ receive[2] ^ receive[0];
    c2 = receive[5] ^ receive[4] ^ receive[1] ^ receive[0];
    c3 = receive[3] ^ receive[2] ^ receive[1] ^ receive[0];
    c = c3 * 4 + c2 * 2 + c1; // something related to binary format like 1,2,4,8..........2^n.
    // We find even 1s then 'c=0' otherwise 'c=1'. So is the 'c' equation.

    if (c == 0)
    {
        cout << "No errors found.";
    }
    else
    {
        cout << "\nError found on position:" << c;
        cout << "\nData sent:";
        for (i = 0; i <= 6; i++)
            cout << send[i];
        cout << "\nData recieved:";
        for (j = 0; j <= 6; j++)
            cout << receive[j];

        // Correcting the error bit form code.Just Complement the bit on error's position.
        if (receive[7 - c] == 0)
            receive[7 - c] = 1;
        else
            receive[7 - c] = 0;
        cout << "\nCorrected data is:";
        for (j = 0; j <= 6; j++)
            cout << receive[j];
    }
    return 0;
}

