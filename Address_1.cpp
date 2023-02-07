#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;
class Address {
private:
    string city;
    string street;
    int house;
    int flat;

public:
    Address(string city_, string street_, int house_, int flat_)
    {
        city = city_;
        street = street_;
        house = house_;
        flat = flat_;
    }


    string get_output_address() {
        string address_string = city + ", " + street + ", " + to_string(house) + ", " + to_string(flat);
        return address_string;
    }

};

void rec(string* arr, int size, ofstream& out) {
    out << size << endl;
    for (int i = size-1; i >= 0; i--) {
        out << arr[i] << " ";
        out << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in.is_open() || (!out.is_open())) {
        cout << "Файл не найден";
        exit(0);
    }

    int size;
    in >> size;
    string* address_book = new string[size];
    string city;
    string street;
    int house;
    int flat;
    int i = 0; // счётчик
    while (!in.eof()) {
        in >> city;
        in >> street;
        in >> house;
        in >> flat;
        Address address(city, street, house, flat);
        address_book[i] = address.get_output_address();
        i++;
    }
    in.close();
    rec(address_book, size, out);
    delete[] address_book;
    out.close();
    return 0;
}
