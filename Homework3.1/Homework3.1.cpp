//генерация случайного пароля
#include <iostream>
#include <string>
#include <random>

using namespace std;

string generatePassword(int length, bool includeSymbols);

int main()
{
    setlocale(LC_ALL, "RU");
    int length, includeSymbols;
    cout << "Длина: " << endl;
    cin >> length;
    cout << "Символы: " << endl;
    cin >> includeSymbols;
    cout << "Пароль: " << generatePassword(length, includeSymbols) << endl;
    return 0;
}

string generatePassword(int length, bool includeSymbols) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const string symbols = "!@#$%^&*()_+=-`~[]\{}|;':\",./<>?";
    string res = chars;
    res += includeSymbols ? symbols : "";
    string p;
    for (int i = 0; i < length; i++){
        p += chars[rand() % chars.size()];
    }
    return p;
}
