// Json_Parser.cpp : Defines the entry point for the application.
//
#include <json/json.h>
#include <fstream>
#include "Json_Parser.h"
#include <json/reader.h>
#include <json/value.h>
//#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    //std::cout << "There are " << argc << " arguments:\n";
    for (int count = 0; count < argc; ++count)
        std::cout << count << " " << argv[count] << '\n';
    if (argc == 2){
        std::cout << "you are in" <<std::endl;
        string text2 = argv[1];
        std::cout << text2 << std::endl;
        Json_parser obj2(text2);
        obj2.parseFile(text2);
        obj2.output();
        auto b = obj2.operator[]("marks");
        TargetFunction(obj2);
    return 0;
    }
    if (argc == 1) {
        std::cout << "you are in standard" << std::endl;
        string text2 = "C:\\Users\\ADMIN\\source\\repos\\Json_Parser\\Json_Parser\\input00.json";
        std::cout << text2 << std::endl;
        Json_parser obj2(text2);
        obj2.parseFile(text2);
        obj2.output();
        auto b = obj2.operator[]("marks");
        TargetFunction(obj2);
        return 0;
    }
    return 0;
}
//C:\\Users\\Dmitriy\\source\\repos\\Json_Parser\\Json_Parser\\input00.json
//C:\Users\Dmitriy\source\repos\Json_Parser\Json_Parser\input00.json

Json_parser::Json_parser(const std::string& s)
{
    Json::Reader reader;
    //json_string = 0;
    reader.parse(s, json_string);
    //auto a = json_string;
    //cout << json_string;
}


bool Json_parser::is_array() const
{
    return json_string.isArray();
}

bool Json_parser::is_object() const
{
    return json_string.isObject();
}

bool Json_parser::output() const
{
    //auto a = json_string;
    cout << json_string << endl;
    return false;
}

Json::Value Json_parser::set_json_string(Json::Value str)
{
    json_string = str;
    return json_string;
}



std::any Json_parser::operator[](const std::string& key)
{

    if (!json_string.isObject()) {
        cout << "not json object" << endl;
        return 0;
    }

    if (json_string[key].isArray()) {
        cout << "its array" << endl;
        return json_string[key];
    }

    if (json_string[key].isString()) {
        return json_string[key].asString();
    }

    if (json_string[key].isDouble()) {
        return json_string[key].asDouble();
    }

    if (json_string[key].isBool()) {
        return json_string[key].asBool();
    }
    return json_string[key];


}

std::any Json_parser::operator[](int index)
{
    if (json_string.isObject()) {
        cout << "its json object" << endl;
        return 0;
    }

    if (json_string.isArray()) {

        return json_string[index];
    }
}

Json_parser Json_parser::parseString(const std::string& s)
{
    /*Json::Reader reader;
    Json::Value Sjson_string;
    reader.parse(s, Sjson_string);
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(Sjson_string);*/
    return Json_parser(s);
}

Json_parser Json_parser::parseFile(const std::string& path_to_file)
{
    std::ifstream fin;
    fin.open(path_to_file);
    if (!fin) {
        cout << "Opening error!!!";
        system("pause");
        return 0;
    }
    //std::string str;
    Json::Reader reader;
    Json::Value Sjson_string;
    reader.parse(fin, Sjson_string);
    //set_json_string(Sjson_string);
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(Sjson_string);
    //path_to_file = output;
    //istream& getline(istream & fin, std::string & str);
    //getline(fin, str);
    //fin >> str;
    //cout << output << endl;
    //cout << Sjson_string << endl;
   // path_to_file = output;
    json_string = Sjson_string;

    return Json_parser(output);
}

bool TargetFunction(Json_parser json)
{
    auto key = (std::any_cast<string>(json["key1"]));
    auto search_type = (std::any_cast<string>(json["search_type"]));
    if (key != "static string")
        return false;
    if (search_type == "QUEUE") {
        // основная логика функции, дальнейший парсинг json 
        json.is_array();
        json.is_object();
        return true;
    }
    else if (search_type == "STACK") {
        // основная логика функции, дальнейший парсинг json 
        json.is_array();
        json.is_object();
        return true;
    }
    else {
        // основная логика функции, дальнейший парсинг json 
        json.is_array();
        json.is_object();
        return true;
    }
    return false;
}
