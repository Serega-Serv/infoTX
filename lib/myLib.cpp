#include "myLib.h"

CFile::CFile(std::string fileName, ImportanceLevel importanceLevel)
:fileName(fileName),importanceLevel(importanceLevel) { // definition
	
}


int CFile::makeRecord(std::string record, ImportanceLevel level) {
	std::lock_guard<std::mutex> lock(mtx);
	int result = 0;
	if (level < importanceLevel) {
    	result++; 
	} else {  
		outFile.open(fileName,std::ios::app); 

		if (!outFile) {
		    std::cerr << "Не удалось открыть файл для записи!\n";
		    result++; 
		} else {


			time_t now = time(0);

			outFile <<  record + "\t" + std::to_string(static_cast<int>(level)) 
			+ "\t" + ctime(&now) + "\n";

			outFile.close();

		}
	}
	return result;
}
/* Часть 1. 
Разработать библиотеку для записи текстовых сообщений 
в журнал. В качестве журнала использовать текстовый файл.
Требования к разрабатываемой библиотеке
    1. Библиотека должна быть динамической.
    2. Библиотека при инициализации должна принимать 
    следующие параметры:
        a. Имя файла журнала.
        b. Уровень важности сообщения по умолчанию. 
        Сообщения с уровнем ниже заданного не должны 
        записываться в журнал. Уровень рекомендуется 
        задавать с помощью перечисления с понятными 
        именами. Достаточно трех уровней важности.
    3. В журнале должны быть сохранена следующая 
    информация:
        a. Текст сообщения.
        b. Уровень важности.
        c. Время получения сообщения.
    4. После инициализации должна быть возможность 
    менять уровень важности сообщений по умолчанию.*/