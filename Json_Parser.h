// Json_Parser.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <any>

//#include <experimental/any>

#include <json/json.h>
#include <fstream>
//#include "Json_Parser.h"
#include <json/reader.h>
#include <json/value.h>

class Json_parser {
private:
    Json::Value json_string;
	
	//static Json::Value Sjson_string;

public:
	// Конструктор из строки, содержащей Json-данные.
	Json_parser(const std::string& s);

	// Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
	bool is_array() const;
	// Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
	bool is_object() const;

	bool output() const;

    Json::Value set_json_string(Json::Value str);


	// Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
	// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
	// Если экземпляр является JSON-массивом, генерируется исключение.
	std::any operator[](const std::string& key);

	// Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
	// Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
	// Если экземпляр является JSON-объектом, генерируется исключение.
	std::any operator[](int index);
	// Метод возвращает объект класса Json из строки, содержащей Json-данные.
	Json_parser parseString(const std::string& s);

	// Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
	Json_parser parseFile(const std::string& path_to_file);
};
// TODO: Reference additional headers your program requires here.
