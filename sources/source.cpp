// Copyright 2018 Your Name <your_email>

#include <header.hpp>

MyJsonParse::MyJsonParse()
{
    std::ifstream ifs("../Students.json"); // Сделать проверку, открывается ли файл
    this->j = json::parse(ifs);
//    this->MyTestString = j.dump();
//    std::cout << MyTestString << std::endl;
    this->StudList = new struct Students;
}

MyJsonParse::~MyJsonParse()
{
    delete this->StudList;
}
void MyJsonParse::get_count()
{
    this->StudList->_meta.count = this->j["_meta"]["count"].get<int>();
//    std::cout << this -> StudList -> _meta.count << std::endl;

}
void MyJsonParse::get_name()
{

}
