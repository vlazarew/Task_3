#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "Shablon.h"
#include "Point.h"


int MainMenu() {
	
	const int a = 8;
	int ans;
	do {

		std::cout << "1 - Добавить вершину" << std::endl;
		std::cout << "2 - Удалить вершину" << std::endl;
		std::cout << "3 - Установить пути" << std::endl;
		std::cout << "4 - Показать матрицу смежности" << std::endl;
		std::cout << "5 - Проверка на существование элемента в графе" << std::endl;
		std::cout << "6 - Кратчайшее расстояние между вершинами" << std::endl;
		std::cout << "7 - Всевозможные пути между вершинами" << std::endl;
		std::cout << "8 - Напечатать все вершины" << std::endl;
		std::cout << "0 - Выход" << std::endl;
		std::cin >> ans;
	} while (ans < 0 || ans > a);
	return ans;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int s, e, ans;
	Graph<Point> grp(0);
	Point top(1,2);
	for (;;) {
		ans = MainMenu();
		switch (ans) {
		case 1:
			grp.NewTop();
			grp.SetTop(top, grp.GetCount() - 1);
			std::cout << "Вершина добавлена" << std::endl;
			break;
		case 2:
			int num;
			std::cout << "Введите номер вершины" << std::endl;
			std::cin >> num;
			getchar();
			if (grp.DeleteTop(num)) {
				std::cout << "Вершина удалена" << std::endl;
			}
			else {
				std::cout << "Вершины с таким номером не существует" << std::endl;
			}
			break;
		case 3:
			grp.ConsoleInputWays();
			break;
		case 4:
			grp.ConsolePrintWays();
			break;
		case 5:
			if (grp.IsTop(top)) {
				std::cout << "Данная вершина есть" << std::endl;
			}
			else {
				std::cout << "Данной вершины нет" << std::endl;
			}
			break;
		case 6:
			std::cout << "Введите начальную вершину" << std::endl;
			std::cin >> s;
			getchar();
			std::cout << "Введите конечную вершину" << std::endl;
			std::cin >> e;
			getchar();
			std::cout << "Кратчайший путь: " << grp.TheShortestWay(s, e) << std::endl;
			break;
		case 7:
			std::cout << "Введите начальную вершину" << std::endl;
			std::cin >> s;
			getchar();
			std::cout << "Введите конечную вершину" << std::endl;
			std::cin >> e;
			getchar();
			grp.PrintAllWaysBetween2Tops(s, e);
			break;
		case 8:
			grp.PrintAllTops();
		}
		getchar();
		if (ans == 0) {
			break;
		}
	}
	return 0;
}

