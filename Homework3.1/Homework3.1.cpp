//генерация случайного пароля
#include <iostream>
#include <string>
#include <random>

using namespace std;

string generatePassword(int length, bool includeSymbols);

int main()
{
    setlocale(LC_ALL, "RU");

    int length;
    bool includeSymbols;
    char includeSymbolsInput;

    cout << "Введите длину пароля: ";
    cin >> length;

    cout << "Включать спец символы? (y/n): ";
    cin >> includeSymbolsInput;
    includeSymbols = (includeSymbolsInput == 'y' || includeSymbolsInput == 'Y');

    cout << "Пароль: " << generatePassword(length, includeSymbols) << endl;
    return 0;
}

string generatePassword(int length, bool includeSymbols) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const string symbols = "!@#$%^&*()_+=-`~[]\{}|;':\",./<>?";

    string res = chars;

    if (includeSymbols) {
        res += symbols;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, res.size() - 1);

    string password;

    for (int i = 0; i < length; i++){
        password += res[distrib(gen)];
    }
    return password;
}
