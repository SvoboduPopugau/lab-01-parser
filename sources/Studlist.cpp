// Copyright 2018 Your Name <your_email>

#include <Studlist.hpp>

MyJsonParse::MyJsonParse()
{
    std::ifstream ifs("../Students.json"); // TODO: Проверка открывается ли файл, переделать под ввод Path
    this->j = json::parse(ifs);            // TODO: Проверка на отсутствие контента в файле
//    this->MyTestString = j.dump();
//    std::cout << MyTestString << std::endl;
    this->StudList = new struct Students;
    this->StudList->_meta.count = 0;
}

MyJsonParse::~MyJsonParse()
{
    delete this->StudList;
}

void MyJsonParse::get_meta()
{
    this->StudList->_meta.count = this->j["_meta"]["count"].get<int>();
//    std::cout << this -> StudList -> _meta.count << std::endl;

}

int MyJsonParse::get_count()
{
    return this->StudList->_meta.count;
}
std::string MyJsonParse::get_name(const json& jit)
{
   return jit.get<std::string>();
}
std::any MyJsonParse::get_group(const json& jit)
{
    if (jit.is_null())
    return nullptr;
    else if (jit.is_string())
      return jit.get<std::string>();
    else
      return jit.get<std::size_t>();
}
std::any MyJsonParse::get_avg(const json& jit)
{
  if (jit.is_null())
    return nullptr;
  else if (jit.is_string())
    return jit.get<std::string>();
  else if (jit.is_number_float())
    return jit.get<double>();
  else
    return jit.get<std::size_t>();
}
std::any MyJsonParse::get_debt(const json& jit)
{
    if (jit.is_null())
      return nullptr;
    else if (jit.is_string())
      return jit.get<std::string>();
    else
      return jit.get<std::vector<std::string> >();
}
void MyJsonParse::item_fjson(const json& jit)
{
    this->StudList->Items.push_back(new Item);
    Item* tmp = this->StudList->Items.back();
    tmp->name = get_name(jit.at("name"));
    tmp->group = get_group(jit.at("group"));
    tmp->avg = get_avg(jit.at("avg"));
    tmp->debt = get_debt(jit.at("debt"));
}
void MyJsonParse::from_json() {
  //      Создание вектора объектов json
  std::vector<json> ItemsVec;
  //      Перенос "Items" в вектор ItemVec
  j["items"].get_to(ItemsVec);
  if (ItemsVec.size() != (unsigned long)get_count())
    std::cout << "_meta != real count";  // TODO: выкинуть из программы
  if (this->StudList->Items.empty() && get_count() != 0) {
    for (int i = 0; i < get_count(); i++) {
//      std::cout << ItemsVec[i] << std::endl;
      item_fjson(ItemsVec[i]);
    }
  }
}

