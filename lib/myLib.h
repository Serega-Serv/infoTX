#ifndef LIB
#define LIB


#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <mutex>

class CFile { //declaration
private:
	std::string fileName;
	std::ofstream outFile;
	std::mutex mtx;

public:
	enum ImportanceLevel
	{
		chill,
		hot,
		emergency

	};
	int makeRecord(std::string record, ImportanceLevel level);
	ImportanceLevel importanceLevel;
	CFile(std::string fileName, ImportanceLevel importanceLevel);

	static ImportanceLevel stringToImportanceLevel(const std::string& level) {
	    if (level == "chill") return CFile::chill;
	    else if (level == "hot") return CFile::hot;
	    else if (level == "emergency") return CFile::emergency;
	    else throw std::invalid_argument("Ошибка: нет такого уровня");    
	}
};

#endif