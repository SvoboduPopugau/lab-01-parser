// Copyright 2018 Your Name <your_email>

#include <header.hpp>

MyJsonParse::MyJsonParse()
{
    std::ifstream ifs("../Students.json"); // TODO: Проверка открывается ли файл, переделать под ввод Path
    this->j = json::parse(ifs);            // TODO: Проверка на отсутствие контента в файле
//    this->MyTestString = j.dump();
//    std::cout << MyTestString << std::endl;
    this->StudList = new struct Students;
}

MyJsonParse::~MyJsonParse()
{
    delete this->StudList;
}

void MyJsonParse::get_meta()       //This method will be used by "super method" <from_json>
{
    this->StudList->_meta.count = this->j["_meta"]["count"].get<int>();
//    std::cout << this -> StudList -> _meta.count << std::endl;

}

int MyJsonParse::get_count()
{
    return this->StudList->_meta.count;
}

void MyJsonParse::get_name(json Student, int i)    //This method will be used by "super method" <from_json>
{
    this->StudList->Items[i]->name = Student["name"];
}
void MyJsonParse::get_group(json Student, int i)
{
    if(Student["group"].is_string())
    {
        this->StudList->Items[i]->group = Student.get<std::string>();
    }
    else
    {
        this->StudList->Items[i]->group = Student.get<std::size_t>();
    }
}
