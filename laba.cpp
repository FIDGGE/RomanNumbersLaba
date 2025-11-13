/***********************
 *Автор: Гончаров Роман*
 *Вариант: 4           *
 ***********************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Функция для преобразования арабских чисел в римские
string arabicToRoman(int num) {
    if (num <= 0 || num > 3999) {
        return "Invalid number! Must be between 1 and 3999";
    }
    
    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    
    string result = "";
    
    for (auto& pair : values) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    
    return result;
}

// Функция для преобразования римских чисел в арабские
int romanToArabic(const string& roman) {
    map<char, int> romanMap = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int prevValue = 0;
    
    for (int i = roman.length() - 1; i >= 0; i--) {
        char currentChar = toupper(roman[i]);
        
        if (romanMap.find(currentChar) == romanMap.end()) {
            return -1; // Некорректный символ
        }
        
        int currentValue = romanMap[currentChar];
        
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
        
        prevValue = currentValue;
    }
    
    return result;
}

int main() {
    int choice;
    int arabicNumber;
    string romanNumber;
    
    cout << "Roman numeral converter\n";
    cout << "1. Arabic to Roman\n";
    cout << "2. Roman to Arabic\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            cout << "Enter Arabic number (1-3999): ";
            cin >> arabicNumber;
            
            if (cin.fail() || arabicNumber < 1 || arabicNumber > 3999) {
                cout << "Invalid input! Must be integer between 1 and 3999\n";
                return 1;
            }
            
            string result = arabicToRoman(arabicNumber);
            cout << arabicNumber << " in Roman numerals: " << result << endl;
            break;
        }
        
        case 2: {
            cout << "Enter Roman number: ";
            cin >> romanNumber;
            
            int result = romanToArabic(romanNumber);
            
            if (result == -1) {
                cout << "Invalid Roman numeral!\n";
            } else {
                cout << romanNumber << " in Arabic numerals: " << result << endl;
            }
            break;
        }
        
        default:
            cout << "Invalid choice!\n";
            return 1;
    }
    
    return 0;
}
