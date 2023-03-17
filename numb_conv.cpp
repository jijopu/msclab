#include <iostream>
#include <bitset>
#include <iomanip>
#include <sstream>

using namespace std;

string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

string decimalToHex(int decimal) {
    stringstream ss;
    ss << hex << uppercase << decimal;
    return ss.str();
}

string decimalToBinary(int decimal) {
    bitset<32> binary(decimal);
    return binary.to_string();
}

string onesComplement(string binary) {
    for (int i = 0; i < binary.length(); i++) {
        binary[i] = (binary[i] == '0') ? '1' : '0';
    }
    return binary;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    string octal = decimalToOctal(decimal);
    string hex = decimalToHex(decimal);
    string binary = decimalToBinary(decimal);
    string onesComp = onesComplement(binary);

    cout << "Octal: " << octal << endl;
    cout << "Hexadecimal: " << hex << endl;
    cout << "Binary: " << binary << endl;
    cout << "One's Complement: " << onesComp << endl;

    return 0;
}
