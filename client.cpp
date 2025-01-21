#include "lib/myLib.h"

int main(int argc, char* argv[]) {

	if (argc != 3) 
		std::cerr << "Ожидались два параметра\n";
	else {
		std::string fileName = argv[1];
		CFile::ImportanceLevel importanceLevel = CFile::stringToImportanceLevel(argv[2]);

		while(1) {
			std::cout << "\nвведите запись :";
			std::string record;
			std::getline(std::cin, record);


			std::cout << "\nвведите уровень важности :"; 
			std::string levelText;
			std::getline(std::cin, levelText);
			CFile::ImportanceLevel level;

			if (levelText[0] == '\0') 
				level = importanceLevel;
			else 
				level = CFile::stringToImportanceLevel(levelText);


			CFile myFile(
				fileName
				, importanceLevel
				);
			std::cout <<  myFile.makeRecord(record, level) << std::endl;
		}
	}
}

/* Часть 2.
Разработать консольное многопоточное приложение 
для проверки библиотеки записи сообщений в журнал.
Требования к приложению
    1. Приложение должно:
        a. Подключать и использовать библиотеку, 
        реализованную в Части 1, для записи 
        сообщений в журнал.
        b. В консоли принимать от пользователя сообщение 
        и его уровень важности. Уровень важности может 
        отсутствовать.
        c. Передавать принятые данные от пользователя 
        в отдельный поток для записи в журнал. Передача 
        данных должна быть потокобезопасной.
        d. Ожидать нового ввода от пользователя после 
        передачи данных.
    2. Параметрами приложения должны быть имя файла журнала 
        и уровень важности сообщения по умолчанию.
    3. Внутреннюю логику приложения придумать самостоятельно.*/