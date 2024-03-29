#include <iostream>

// - Конструкции обработки исключений
// - способы создания и передачи исключений
// - встроенные в язык исключения 
// - типы исключений 
// - рекомендации по взаимодействию с исключениями в программе
// 
// Ключевые слова языка:
//  throw try catch
// 
// try блок может экранировать и передать в catch только ошибки сгенерированные
// внутри программы
// Для неизвестных ошибок используется catch(...)
// 
// категория ошибок операционной системы runtime_error не может быть
// обработана внутри приложения и её надо предотвращать
// 
// Правила по внедрению исключений в ваши программы:
// - не обрабатываем исключительные ситуации если мы сами их не породили 
//    в этом случае используется только throw конструкция 
// - try-catch используется только в коде который не уверен, что его
// данные могут быть корректно обработаны внешним кодом 
// - не использовать базовые типы для ловли исключений 
// 
// Типы исключений:
// -runtime_error -- живут в операционке и не могут быть обработаны 
// - программные исключения:
//	 - logic_exception
//		* invalid_argumen
//		* domain_error
//		* length_error
//		* out_of_range
//   - runtime_error
//		* range_error
//		* overflow_error
//		* underflow_error
//		* regex_error
//		* system_error
//	 - bad_tipeid
//	 - bad_cast
//	 - bad_exception
//	 - bad_alloc
//   


#include <exception> // либо пользовательские классы исключения
#include <limits>

#include <stdlib.h>
#include <time.h>


void F00(int a) {
	if (a) {
		throw std::exception("Bad luck");
	}
}

void F01(int a) {
	if (a) {
		//throw std::make_exception_ptr(std::exception("Bad luck"));
		throw std::exception("Bad luck");
	}
}

int Summ(int a, int b) {
	if (std::numeric_limits<int>::max() - b > a) {
		throw std::overflow_error("more then return can handle");
	}


	return int(a + b);
}

int Summ2(int a, int b) noexcept {
	return int(a + b);
}

int main() {
	setlocale(0, "");
	
	//try_catch
	/*try {
		int a{ 5 }, b{ 0 };
		int c{};
		if (!b) throw 0.7;
		c = a / b;
	}
	catch (int ex) {
		if (ex == -1) {
			std::cout << "divide by 0\n";
		}
	}
	catch (...) {
		std::cout << "Something go wrong\n";
	}
	*/

	::srand(::time(NULL));
	try {
		int i{};
		i = rand() % 2;
		//F00(i);
		Summ2(2e30, 4e31);
	}
	catch (std::exception_ptr& ex) {
		
	}
	catch (...) {
		std::cout << "Something go wrong\n";
	}


	return 0;
}