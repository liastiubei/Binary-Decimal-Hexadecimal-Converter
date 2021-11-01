#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <conio.h>
#include <stdio.h>

using namespace std;

void Menu();

//This is the implementation of the function that converts binary numbers to decimal ones, using the Positional Notation Method
int BinaryToDecimal(string binary) {
    int decimal = 0;
    int poweredTwo = 1;
    for (int i = binary.length()-1; i >= 0 ; i--) {
        if (binary[i] == '1') {
            decimal += poweredTwo;
        }
        poweredTwo *= 2;
    }
    return decimal;
}

//This is the implementation of the function that converts decimal numbers to binary ones, using the Successive Divission Method
string DecimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        stringstream remains;
        remains << decimal % 2;
        binary += remains.str();
        decimal = decimal / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

//This is the implementation of the function that converts hexadecimal numbers to decimal ones, using the Positional Notation Method
int HexadecimalToDecimal(string hex) {
    map<char, int> hexToDecMap = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
    {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
    };

    int decimal = 0;
    int poweredSixteen = 1;
    for (int i = hex.length() - 1; i >= 0; i--) {
        decimal += poweredSixteen * hexToDecMap[hex[i]];
        poweredSixteen *= 16;
    }
    return decimal;
}

//This is the implementation of the function that converts decimal numbers to hexadecimal ones, using the Successive Divission Method
string DecimalToHexadecimal(int decimal) {
    string decToHex = "0123456789ABCDEF";
    string hex = "";
    while (decimal > 0) {
        hex += decToHex[decimal % 16];
        decimal /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

//This is the implementation of the function that converts binary numbers to hexadecimal ones
string BinaryToHexadecimal(string binary)
{
    string binToHex = "0123456789ABCDEF";
    string hex = "";
    string substring;
    int sum = 0;
    int i = binary.length() % 4;
    if (i != 0) {
        substring = binary.substr(0, i);
        int j = i-1;
        int poweredTwo = 1;
        while (j >= 0) {
            if (substring[j] == '1') sum += poweredTwo;
            poweredTwo *= 2;
            j--;
        }
        hex += binToHex[sum];
    }
    for (; i < binary.length(); i += 4) {
        sum = 0; 
        int poweredTwo = 8;
        int j = i;
        while (j < i+4) {
            if (binary[j] == '1') sum += poweredTwo;
            poweredTwo /= 2;
            j++;
        }
        hex += binToHex[sum];
    }
    return hex;
}

//This is the implementation of the function that converts hexadecimal numbers to binary ones
string HexadecimalToBinary(string hex) {
    map<char, string> hexToBinMap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };
    string binary = "";
    for (char c : hex) {
        binary += hexToBinMap[c];
    }
    return binary;
}

//This function is called at the end of each conversion and gives the option to return to the menu for another conversion, or exit the program
void Finish() {
    cout << "How would you like to continue?" << endl;
    cout << "1. Exit the program" << endl;
    cout << "2. Do another conversion" << endl;
    cout << "Please write your choice: " << endl;

    string choices = "12";
    char choice = _getch();
    while (choices.find(choice)==-1) {
        cout << endl << "Please write your choice again: ";
        choice = _getch();
    }

    switch (choice) {
    case '1':
        return;
    case '2':
        system("CLS");
        Menu();
        return;
    }
}


//The role of the following functions is to get the binary, decimal or hexadecimal number needed for each type of conversion, call the needed conversion function, display the result and either return to the menu or exit the program

void BinDecMenu() {
    string binary;
    cout << "Please write the binary number you wish to convert: " << endl;
    cin >> binary;
    cout << endl << "The conversion is complete. This is the result: " << BinaryToDecimal(binary) << endl << endl;
    Finish();
}

void DecBinMenu() {
    int decimal;
    cout << "Please write the decimal number you wish to convert: " << endl;
    cin >> decimal;
    cout << endl << "The conversion is complete. This is the result: " << DecimalToBinary(decimal) << endl << endl;
    Finish();
}

void BinHexMenu() {
    string binary;
    cout << "Please write the binary number you wish to convert: " << endl;
    cin >> binary;
    cout << endl << "The conversion is complete. This is the result: " << BinaryToHexadecimal(binary) << endl << endl;
    Finish();
}

void HexBinMenu() {
    string hex;
    cout << "Please write the hexadecimal number you wish to convert: " << endl;
    cin >> hex;
    cout << endl << "The conversion is complete. This is the result: " << HexadecimalToBinary(hex) << endl << endl;
    Finish();
}

void HexDecMenu() {
    string hex;
    cout << "Please write the hexadecimal number you wish to convert: " << endl;
    cin >> hex;
    cout << endl << "The conversion is complete. This is the result: " << HexadecimalToDecimal(hex) << endl << endl;
    Finish();
}

void DecHexMenu() {
    int decimal;
    cout << "Please write the decimal number you wish to convert: " << endl;
    cin >> decimal;
    cout << endl << "The conversion is complete. This is the result: " << DecimalToHexadecimal(decimal) << endl << endl;
    Finish();
}

//This function creates the user interface, is given the user's choice for the proceeding action and continues by calling the necessary functions to complete said action

void Menu() {
    char choice;
    string choices = "1234567";

    cout << "This is a converter between Binary, Decimal and Hexadecimal numbers." << endl << endl;
    cout << "****************************************" << endl << endl;
    cout << "1. Convert a number from the Binary base to the Decimal base" << endl;
    cout << "2. Convert a number from the Binary base to the Hexadecimal base" << endl;
    cout << "3. Convert a number from the Decimal base to the Binary base" << endl;
    cout << "4. Convert a number from the Decimal base to the Hexadecimal base" << endl;
    cout << "5. Convert a number from the Hexadecimal base to the Binary base" << endl;
    cout << "6. Convert a number from the Hexadecimal base to the Decimal base" << endl;
    cout << "7. Exit the program" << endl << endl;
    cout << "Please input your choice: ";

    choice = _getch();
    while (choices.find(choice) == -1) {
        cout << endl << "Sorry, please try again: ";
        choice = _getch();
    }

    system("CLS");

    switch (choice) {
    case '1':
        BinDecMenu();
        break;
    case '2':
        BinHexMenu();
        break;
    case '3':
        DecBinMenu();
        break;
    case '4':
        DecHexMenu();
        break;
    case '5':
        HexBinMenu();
        break;
    case '6':
        HexDecMenu();
        break;
    case '7':
        return;
    }

}

int main()
{
    Menu();
}