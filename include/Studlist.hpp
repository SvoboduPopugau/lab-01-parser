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
#include <cstring>

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

     void get_meta();
     int get_count();

     static std::string get_name(const json& jit);
     static std::any get_group(const json& jit);
     static std::any get_avg(const json& jit);
     static std::any get_debt(const json& jit);

     void item_fjson(const json& jit);
     void from_json();
     void print();

     static std::string convert_to_string(const std::any& any);

    private:
    json data;
//    std::string MyTestString;
    Students* StudList;
};
#endif // INCLUDE_HEADER_HPP_

