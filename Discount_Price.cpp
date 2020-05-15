/* Написать программу вычисления стоимости покупки с учётом скидки. 
Скидка в 3% предоставляется, если сумма покупки больше 500 руб., в 5% — если сумма покупки больше 1000 руб.*/

#include <iostream>
#include <Windows.h> // для кириллицы
#include <string>    // для std::string
#include "Discounts.h" // для использования данных о скидках

using std::cout; using std::cin; using std::endl; using std::string;

// получаем от пользователя сумму покупки
double get_summ()
{
	cout << "Введите сумму покупки в рублях: ";
	double summ;
	cin >> summ;
	while (cin.fail() || (summ < 0))  // если вводит буквы или отрицательное число
	{
		cin.clear();
		cin.ignore(1000, '\n'); //очищаем cin
		cout << "Вы ввели нечто некорректное, введите положительное число: ";
		cin >> summ;      //снова вводит число
		continue;
	}
	return summ;
}

// считаем цену по общей сумме покупки:
double total_price(const double summ)
{
	return (summ - (summ*(DiscountConst::get_discount_by_summ(summ)/100)));
}

// возвращает истину, если игрок хочет рассчитать цену ещё раз и ложь, если не хочет
bool wantsContinue()
{
	cout << endl;
	cout << "Хотите рассчитать цену ещё раз? Нажмите 'y', если да или 'n', если нет ";
	string answer;
	cin.ignore(1000, '\n');   // очищаем cin
	std::getline(cin, answer);
	while ((answer != "y") && (answer != "n"))
	{
		cout << "Ваш ответ не понятен! Хотите рассчитать цену ещё раз? Нажмите 'y', если да или 'n', если нет ";
		std::getline(cin, answer);
	}
	cout << endl;
	if (answer == "y") return true;
	else return false;
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); // для ввода-вывода на кириллице

	do
		cout << "Сумма с учётом скидки: " << total_price(get_summ()) << " руб. " << endl;
	while (wantsContinue());

	cout << "Ждём Вас снова! " << endl;
	return 0;
}