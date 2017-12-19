#pragma once
#include "List.h"

template <typename T>
class Graph {
private:
	T *_tops; //вершины
	int **_matrOfAdj; //матрица смежности
	int n; // кол-во вершин
    //минимальное между a b
	int Min(int a, int b) {
		return a < b ? a : b;
	}

	//поиск в глубину
	void Search(bool* mrk, TList lst, int num, int end)
	{
		if (num == end) {
			lst.AddEl(num);
			lst.Print();
			std::cout << std::endl;
			return;
		}

		lst.AddEl(num);
		mrk[num] = true;
		for (int i = 0; i < n; ++i) {
			if (_matrOfAdj[num][i] != 0 && !mrk[i]) {
				Search(mrk, lst, i, end);
			}
		}
		mrk[num] = false;
		lst.DelEl();
	}
public:
	//конструктор
	Graph(int N) {
		n = N;
		_tops = new T[n];
		_matrOfAdj = new int *[n];
		for (int i = 0; i < n; ++i) {
			_matrOfAdj[i] = new int[n];
			for (int j = 0; j < n; ++j) {
				_matrOfAdj[i][j] = 0;
			}
		}
	}

	//освобождение памяти
	void Clear() {
		for (int i = 0; i < n; ++i) {
			delete[] _matrOfAdj[i];
		}
		delete[] _matrOfAdj;
		delete[] _tops;
	}

	//возврат кол-ва вершин
	int GetCount() {
		return n;
	}

	//установка вершины
	bool SetTop(T el, int num) {
		if (num >= 0 && num < n) {
			_tops[num] = el;
			return true;
		}
		else
		{
			return false;
		}
	}

	//воврат вершины
	T GetTop(int num) {

		return _tops[num];
	}

	//добавление вершины
	void NewTop() {
		++n;
		//создаем дополнительные указатели
		T * p1 = _tops;
		int ** p2 = _matrOfAdj;
		//увеличиваем кол-во вершин
		p1 = (T*)realloc(p1, sizeof(T) * n);
		//увеличиваем кол-во строк
		p2 = (int**)realloc(p2, sizeof(int**) * n);
		//выделяем память под новую строку
		p2[n - 1] = new int[n];
		//в изначальных строках увеличиваем кол-во
		for (int i = 0; i < n - 1; ++i) {
			p2[i] = (int*)realloc(p2[i], sizeof(int) * n);
		}
		//если удалось выделить память переприсваеваем указатели
		if (p1 != nullptr && p2 != nullptr) {
			_tops = p1;
			_matrOfAdj = p2;
			//заполнение новой строки и столбца нулями
			for (int i = 0; i < n; ++i) {
				_matrOfAdj[n - 1][i] = 0;
				_matrOfAdj[i][n - 1] = 0;
			}
		}
		else {
			std::cout << "Ошибка перераспределения памати";
		}
	}

	//удалене вершины
	bool DeleteTop(int num) {
		if (num < 0 || num >(n - 1)) {
			return false;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = num; j < n - 1; ++j) {
				_matrOfAdj[i][j] = _matrOfAdj[i][j + 1];
			}
			_matrOfAdj[i] = (int*)realloc(_matrOfAdj[i], sizeof(int) * (n - 1));
		}
		delete[] _matrOfAdj[num];
		for (int i = num; i < n - 1; ++i) {
			_matrOfAdj[i] = _matrOfAdj[i + 1];
			_tops[i] = _tops[i + 1];
		}
		_tops = (T*)realloc(_tops, sizeof(T) * (n - 1));
		_matrOfAdj = (int**)realloc(_matrOfAdj, sizeof(int**) * (n - 1));
		--n;
		return true;
	}


	//установка длины ребра
	bool SetWay(int start, int end, int way) {
		if (start >= 0 && start < n && end >= 0 && end < n) {
			_matrOfAdj[start][end] = way > 0 && start != end ? way : 0;
			return true;
		}
		else
		{
			return false;
		}
	}

	//возврат длины ребра
	int GetWay(int start, int end) {
		if (start >= 0 && start < n && end >= 0 && end < n) {
			return _matrOfAdj[start][end];
		}
		return 0;
	}

	//проверка на существование элемента в графе
	bool IsTop(T el) {
		for (int i = 0; i < n; ++i) {
			if (el == _tops[i]) {
				return true;
			}
		}
		return false;
	}

	//печать матрицы смежности
	void ConsolePrintWays() {
		std::cout << "+  ";
		for (int i = 0; i < n; ++i) {
			std::cout << i << "  ";
		}
		std::cout << std::endl;
		for (int i = 0; i < n; ++i) {
			std::cout << i << "  ";
			for (int j = 0; j < n; ++j) {
				std::cout << _matrOfAdj[i][j] << "  ";
			}
			std::cout << std::endl;
		}
	}

	//печать вершины
	void ConsolePrintTop(int num) {
		if (num >= 0 && num < n) {
			cout << _tops[num]
		}
		else {
			cout << "Такой вершины нет";
		}
	}

	//поиск кратчайшего пути по алгоритму Дейкстры
	int TheShortestWay(int start, int end) {
		if (start >= 0 && start < n && end >= 0 && end < n) {
			bool *marks = new bool[n];
			int *ways = new int[n];
			for (int i = 0; i < n; ++i) {
				marks[i] = false;
				ways[i] = INT_MAX; //бесконечность
			}
			int i, index, min;
			ways[start] = 0;
			do {
				index = min = INT_MAX;
				for (int i = 0; i < n; ++i) {
					if (!marks[i] && ways[i] < min) {
						min = ways[i];
						index = i;
					}
				}
				if (index != INT_MAX) {
					for (i = 0; i < n; ++i) {
						if (_matrOfAdj[index][i] != 0) {
							ways[i] = Min(ways[i], min + _matrOfAdj[index][i]);
						}
					}
					marks[index] = true;
				}
			} while (index != INT_MAX);
			int res = ways[end] == INT_MAX ? -1 : ways[end];
			delete[] ways;
			delete[] marks;
			return res;
		}
		else
		{
			return -1;
		}
	}

	//печать всех путей между двумя вершинами
	void PrintAllWaysBetween2Tops(int start, int end) {
		if (start >= 0 && start < n && end >= 0 && end < n) {
			bool* marks = new bool[n];
			TList list;
			for (int i = 0; i < n; ++i) {
				marks[i] = false;
			}
			Search(marks, list, start, end);
			list.Clear();
			delete[] marks;
		}
	}

	void PrintAllTops() {
		for (int i = 0; i < n; ++i) {
			std::cout << _tops[i] << std::endl;
		}
	}

	//ввод путей с консоли
	void ConsoleInputWays() {
		int start, end, way;
		std::cout << "Для отмены введите любоe отрицательное значение в любом поле" << std::endl;
		std::cout << "Всего вершин: " << n << std::endl;
		for (;;) {
			std::cout << "Введите номер начальной вершины: ";
			std::cin >> start;
			if (start < 0) {
				break;
			}
			std::cout << "Введите номер конечной вершины: ";
			std::cin >> end;
			if (end < 0) {
				break;
			}
			if (start >= 0 && start < n && end >= 0 && end < n) {
				std::cout << "Введите длину пути: ";
				std::cin >> way;
				if (way < 0) {
					break;
				}
				SetWay(start, end, way);
				std::cout << "Путь установлен" << std::endl;;
			}
			else {
				std::cout << "неверно задан номер вершины" << std::endl;
			}
		}
	}
};

