#include <iostream>
#include <string>
#include <map>

void task_1() {
	std::cout << "Line: ";
	std::string line_1, line_2 = "";
	getline(std::cin, line_1);

	// убирает пробелы из строки и понижает регистр 
	int len = line_1.length();
	int plus = 0;
	for (int i = 0; i < len; i++) {
		if (line_1[i] != ' ')
			line_2 += tolower(line_1[i]);
	}

	len = line_2.length();
	bool ans = true;
	// проходимся по условию 
	for (int i = 0; i < len; i++) {
		if (line_2[i] != line_2[len - 1 - i]) {
			ans = false;
			break;
		}
	}
	std::cout << '\n';
	if (ans)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
}

void task_2() {
	// напиши
}

void task_3() {
	// Caesar cipher
	int shift;
	std::string line;
	std::cout << "Line: ";
	getline(std::cin, line);
	std::cout << "Shift: ";
	std::cin >> shift;
	std::cout << "\nAnswer: ";
	for (auto i : line) {
		if ((('A' <= i) && (i <= 'Z')) || (('a' <= i) && (i <= 'z'))) {
			// по методу сдвига и преобразования ASCII
			std::cout << (char)((int)i + shift);
		}
		else {
			std::cout << i;
		}
	}
	std::cout << '\n';
}

void task_4() {
	std::string line;
	std::cout << "Line: ";
	getline(std::cin, line);
	bool is_out = false;

	std::cout << "\nAnswer: ";
	for (auto i : line) {
		if (i == '"') {
			is_out = not is_out;  // смена значения булевой перменной
			if (not is_out)
				std::cout << " | ";
		}
		else {
			if (is_out)
				std::cout << i;
		}
	}
	std::cout << "\b\b";
}

int main()
{
	std::cout << "===================================================== TASK 1 =====================================================\n";
	task_1();
	std::cout << "===================================================== TASK 2 =====================================================\n";
	task_2();
	std::cout << "===================================================== TASK 3 =====================================================\n";
	task_3();
	std::cout << "===================================================== TASK 4 =====================================================\n";
	task_4();
}