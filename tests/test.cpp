// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <fstream>
#include <nlohmann/json.hpp>

#include "MyJsonParse.hpp"

TEST(Print, All_is_Correct) {
    std:: string test_string = \
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
    std::ofstream testFile;
    testFile.open("json_file.json");
    testFile << test_string;
    testFile.close();
    MyJsonParse List;
    std::string str = "json_file.json";
    List.set_data(str);
    List.from_json();
    std::cout << "Hello!!!" << std::endl;

    std::string res_string = \
 R"(| name          | group  | avg  | debt    |
|---------------|--------|------|---------|
| Ivanov Petr   | 1      | 4.25 | Null    |
|---------------|--------|------|---------|
| Sidorov Ivan  | 31     | 4    | C++     |
|---------------|--------|------|---------|
| Pertov Nikita | IU8-31 | 3.33 | 3 items |
|---------------|--------|------|---------|)";
    EXPECT_EQ(List.print(),res_string);
}
TEST(AddData,Correctfile){
  std:: string test_string = \
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta": {
    "count": 3
  }
})";
  std::ofstream testFile;
  testFile.open("json_file.json");
  testFile << test_string;
  testFile.close();
  MyJsonParse List;
  std::string str = "json_file.json";
  List.set_data(str);
  std::ifstream file("json_file.json");
  EXPECT_EQ(json::parse(file),List.get_data());
}
TEST(AddData,UncorrectFile){
  std::string res_str = "Unable to open file: json_fil.json";
  MyJsonParse List;
  std::string str = "json_fil.json";
  try{
    List.set_data(str);
  }
  catch (std::runtime_error& err) {
    EXPECT_EQ(err.what(),res_str);
  }
}
TEST(AddData,Emptyfile){
  std::string res_str = "Your file is empty";
  std::ofstream testFile;
  testFile.open("json_file.json");
  testFile.close();
  try{
    MyJsonParse List;
    std::string str = "json_fil.json";
    List.set_data(str);
  }
  catch (std::runtime_error& err) {
    EXPECT_EQ(err.what(),res_str);
  }
}
TEST(AddData,EmptyItems){
  std::string res_str = "No items in file";

  std:: string test_string = \
 R"({
  "items":
  "_meta": {
    "count": 3
  }
})";
  std::ofstream testFile;
  testFile.open("json_file.json");
  testFile << test_string;
  testFile.close();

  try{
    MyJsonParse List;
    std::string str = "json_file.json";
    List.set_data(str);
  }
  catch (std::runtime_error& err) {
    EXPECT_EQ(err.what(),res_str);
  }
}
TEST(AddData,EmptyMeta){
  std:: string test_string = \
 R"({
  "items": [
    {
      "name": "Ivanov Petr",
      "group": "1",
      "avg": "4.25",
      "debt": null
    },
    {
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    },
    {
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    }
  ],
  "_meta":
})";
  std::ofstream testFile;
  testFile.open("json_file.json");
  testFile << test_string;
  testFile.close();
  MyJsonParse List;
  std::string str = "json_file.json";
  std::string res_str = "No _meta data in file";
  try{
    List.set_data(str);
  }
  catch (std::runtime_error& err) {
    EXPECT_EQ(err.what(),res_str);
  }
}