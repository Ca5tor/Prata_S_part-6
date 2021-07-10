#include <iostream>
#include <cctype>

void Ex1() {
/*
Напишите программу которая читает клав. ввод до символа @ и 
повторяет eго за искл. десят-х цифр, преобразуя каждую букву верхнего
регистра в нижний и наоборот. ( функции семейства cctype в помощь)
*/
	const int max = 256;	// Ограничение для заполения массива
	char mas[max] = "";		// Статический массив символов
	int i = 0;				// Счётчик

	std::cout << "Введите Ваш текст и нажмите Enter: ";

	while (i < max && std::cin >> mas[i] ){								// Вводим пока i меньше max = 256
		if (mas[i] == '@') break;										// Если символ @, прекращаем ввод
			if (!(mas[i] >= '0' && mas[i] <= '9')) {					// Выводим знаки прип. и англ. буквы
				if (islower(mas[i])) std::cout << (char)toupper(mas[i]);// Символ в ↓ регистре, выводим в ↑
					else std::cout << (char)tolower(mas[i]);			// Иначе ↑ регистр, выводим в ↓
			} 
		i++;															// Увеличиваем счётчик
	}

}

void Ex2() {
/*
Напишите программу читающую в массив double до 10 значений пожертвований.
(Можно использовать шаблонный объект array)
Программа должна прекращать ввод при получении нечисловой величины.
Она должна выдавать сред.знач. полученных чисел а также кол-во знач. в
массиве превышающих среднее
*/
	const int max = 10;
	double mas[max] = { 0.0 };
	double sum = 0;
	int i = 0;

	std::cout << "Введите число и нажмите Enter: ";

	while (i < max && std::cin >> mas[i] ) {	// Если счётчик не превышает лимит max, принимаем ввод
		if (sizeof(mas[i]) != 8 ) {				// Если элемент массива не double (размер не 8 байт) 
			std::cout << "Error: ";				// то выводим ошибку в консоль 
			break;								// и прекращаем ввод
		} 

		sum += mas[i];							// Суммируем все вводимые значения
		i++;									// Увеличиваем счётчик кол-ва значений
		std::cout << "Введите число и нажмите Enter: ";
	}

	int iter = 0;								// Счётчик кол-ва значений превышающих сред.знач.

	std::cout << "Cреднее значение: ";
	std::cout << sum / i << std::endl;			// Cред.знач.полученных чисел
	
	// проходимся по всему массиву и ищем числа большие чем сред.знач.
	for (int j = 0; j < i; j++) if (mas[j] > sum / i) iter++;

	std::cout << "Кол-во значений в массиве превышающих среднее: ";
	std::cout << iter << std::endl;

}

void Ex3() {
	/*
	Напишите предшественник программы, управляемой меню.
	Она должна отображать меню из 4-х пунктов, каждый из них помечен буквой.
	Если пользователь вводит букву, отичающуюся от 4-х допустимых,
	программа должна повторно приглашать его ввести правильное значение
	до тех пор, пока он этого не сделает. Затем она должна выполнить
	некоторое простое действие на основе пользовательского выбора.
	Работа программы должна выглядеть примерно так:

	Please enter one of the fallowing choices:
	c) carnivore  p) pianist
	t) tree		  g) game
	f
	Please enter a c, p, t or g: q
	Please enter a c, p, t or g: t
	A maple is a tree.
	*/
	const int SIZE = 4;
	std::string str = "A maple is a ";
	std::string out_str[SIZE] = { "carnivore\n", "pianist\n", "tree\n", "game\n" };
	char choice[SIZE] = { 'c', 'p', 't', 'g' };
	char var;									// символ хранящий вариант выбора меню

	std::cout << "Please enter one of the fallowing choices:\n";
	std::cout << "c) carnivore  p) pianist\n";
	std::cout << "t) tree       g) game\n";
	std::cout << "Enter: ";

	bool flag = true;							// Что-то вроде флага для while

	while (flag && std::cin >> var) {			// Сидим в цикле пока v истинно
		for (int i = 0; i < SIZE; i++) {		// проходим по всему массиву и
			if (var == choice[i]) {				// если введенный символ совпадёт с символом из массива choice,
				std::cout << str + out_str[i];	// выводим строку ответа
				flag = false;					// Откл while
				break;							// выходим из for т.к. символ найден
			}
		}

		if (flag) std::cout << "Please enter a c, p, t or g: ";	// Просим юзера о вводе из предложенных символов
		
	}
		
}

void main() {
	setlocale(0, "");		// Поддержка рус. 

	Ex3();

	system("pause");
	//std::cin.get();
	//std::cin.get();
}