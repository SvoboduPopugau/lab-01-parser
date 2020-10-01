// Copyright 2018 Your Name <your_email>
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <any>
#include <fstream>
#include <vector>
#include <variant>
using json = nlohmann::json;
struct Item
{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};
struct Meta
{
    int count;
};
struct Students
{
   struct Meta _meta;
   std::vector <struct Item*> Items;
};

class MyJsonParse {
    public:
     MyJsonParse();
     ~MyJsonParse();
     int get_count();
     void get_meta();
     void get_name(json Student, int i);
     void get_group(json Student, int i);

    private:
    json j;
//    std::string MyTestString;
    Students* StudList;
};
#endif // INCLUDE_HEADER_HPP_

