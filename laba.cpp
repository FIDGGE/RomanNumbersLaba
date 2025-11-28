/***********************
 *Автор: Гончаров Роман*
 *Вариант: 4           *
 ***********************/

#include <iostream>
#include <string>
#include <vector>
#include <map>  // словари для сопоставления римских чисел и их значений, например 48 строка

using namespace std;

// функция для преобразования арабских чисел в римские
// принимает целое число а возвращает строку с римским числом
  int safeLimit = 3999;
  string arabicToRoman(int num) {
  //проверяет число из допустимого диапазона или нет
  //создал ограничение для корректной работы программы, чтобы пользователь не мог ввести бесконечно большое число
  if (num <= 0 || num > safeLimit) {
    return "Invalid number! Must be between 1 and 3999";
  }
  // вектор пар "число-римская цифра", сортирует по убыванию
  // включает не только основные символы, а еще их комбинации
  vector<pair<int, string>> values = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
      {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
      {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
      {1, "I"}
  };
  // строка для накопления результата
  string result = "";
  // этот цикл проходится по всем парам значений
  for (auto& pair : values) {  //?
  // пока текущее число больше либо равно значению из пары
    while (num >= pair.first) {
      // здесь добавляется римская цифра к результату
      result += pair.second;
      // вычитаем значение из исходного числа
      num -= pair.first;
    }
  }

  return result;
}

// функция для преобразования римских чисел в арабские
// принимает строку с римским числом а выводит строки с арабским
  int romanToArabic(string& roman) {   //? const string&
  // создаем словарь для сопоставления римских символов и их значений
  map<char, int> romanMap = {
      {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}
  };
 
  int result = 0;
  //эта переменная хранит предыдущее значение
  int prevValue = 0;
  int currentValue;
  //обрабатываем строку справа налево, так будет проще
  for (int indL = roman.length() - 1; indL >= 0; indL--) {  //? ?
    // приводим все символы к верхнему регистру 
    char currentChar = toupper(roman[indL]);  //? 
    // проверка, является ли число допустимой римской цифрой
    if (romanMap.find(currentChar) == romanMap.end()) {
      // если символ некорректен, вернется -1
      return -1; 
    }
    // получаем значение текущего символа
    currentValue = romanMap[currentChar];  //?
    // по особенностям вычитания римских чисел, если число типа IX, то 10-1, если иначе то прибавляем
    if (currentValue < prevValue) {
      result -= currentValue;
    } else {
      result += currentValue;
    }
    // сохраняем текущее значение до следующей итерации
    prevValue = currentValue;
  }

  return result;
}
  enum modeOfProgram {
  ARABIC_TO_ROMAN = 1,
  ROMAN_TO_ARABIC = 2
  };
int main() {
  
  int choice;
  int arabicNumber;
  string romanNumber;

  cout << "Roman numeral converter\n" //?
       << "1. Arabic to Roman\n"
       << "2. Roman to Arabic\n"
       << "Enter your choice: " ;
  cin  >> choice;
  //переключение между двумя случаями(с арабских в римские и наоборот)
  switch (choice) {
  case ARABIC_TO_ROMAN : {   // 1 - enum
    cout << "Enter Arabic number (1-3999): ";
    cin  >> arabicNumber;
    // выводится если число в недопустимом диапазоне
    if (cin.fail() || arabicNumber < 1 || arabicNumber > safeLimit) {
      cout << "Invalid input! Must be integer between 1 and 3999\n";
      return 1;
    }

    string result = arabicToRoman(arabicNumber);  //?
    cout << arabicNumber << " in Roman numerals: " << result << endl;
    break;
  }

  case ROMAN_TO_ARABIC : {
    cout << "Enter Roman number: ";
    cin  >> romanNumber;

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
