// Copyright 2018 Your Name <your_email>

#include <Studlist.hpp>

MyJsonParse::MyJsonParse()
{
    std::string filepath;
    std::cout << "Enter full path to .json file" << std::endl;
    std::cin >> filepath;
    std::ifstream ifs(filepath); // TODO:1
    if(!ifs.is_open()){
      throw std::runtime_error{"Can not open json file for this path: "
                               + filepath};
    }
    this->data = json::parse(ifs);            // TODO:2
    if(this->data.is_null()){
      throw std::runtime_error{"This file has no content"};
    }
      //    this->MyTestString = data.dump();
//    std::cout << MyTestString << std::endl;
    this->StudList = new struct Students;
    this->StudList->_meta.count = 0;
}
MyJsonParse::~MyJsonParse()
{
  if(!this->StudList->Items.empty()){
    for(auto & Item : this->StudList->Items){
      delete Item;
    }
  }
    delete this->StudList;
}
void MyJsonParse::get_meta()
{
  if(this->data.at("_meta").is_null())          //TODO:3
    throw std::runtime_error{"Block _meta is empty"};
  if(this->data.at("_meta").at("count").is_null())  //TODO:4
    throw std::runtime_error{"Block \"count\" is empty"};

  this->StudList->_meta.count = this->data["_meta"]["count"].get<int>();
//    std::cout << this -> StudList -> _meta.count << std::endl;
}
int MyJsonParse::get_count()
{
    return this->StudList->_meta.count;
}
std::string MyJsonParse::get_name(const json& jit)
{
  if(!jit.is_string()) {
    throw std::runtime_error{"Invalid expression in name"};
  }
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
  if (get_count() == 0)
    get_meta();
  //      Создание вектора объектов json
  std::vector<json> ItemsVec;
  //      Перенос "Items" в вектор ItemVec
  data["items"].get_to(ItemsVec);
  if (ItemsVec.size() != (unsigned long)get_count())
    throw std::runtime_error{"content of _meta != real count of items"};//TODO:5
  if (this->StudList->Items.empty() && get_count() != 0) {
    for (int i = 0; i < get_count(); i++) {
//      std::cout << ItemsVec[i] << std::endl;
      item_fjson(ItemsVec[i]);
    }
  }
}
void MyJsonParse::print()
{
  const int spaces_w = 2;
  size_t nMax = 4;
  size_t gMax = 5;
  size_t aMax = 3;
  size_t dMax = 4;

  size_t arr_size = this->StudList->Items.size();
  for (size_t i = 0; i<arr_size; i++)
  {
    Item* tmp = this->StudList->Items[i];
//    std::cout <<"Name " << i << " :"<< tmp->name;
    if (tmp->name.length() > nMax) {
      nMax = tmp->name.length();
    }

//    std::cout <<" |Group " << i << ":"<< tmp->avg.type().name();
    if(convert_to_string(tmp->group) == "bad_any_cast") {
      throw std::runtime_error{"Incorrect type group"};  // TODO: 6
    }
    if(convert_to_string(tmp->group).length() > gMax) {
      gMax = convert_to_string(tmp->group).length();
    }

//    std::cout <<" |Avg " << i << ":"<< tmp->avg.type().name();
    if(convert_to_string(tmp->avg) == "bad_any_cast") {
      throw std::runtime_error{"Incorrect type avg"};    // TODO: 7
    }
    if(convert_to_string(tmp->avg).length() > aMax) {
      aMax = convert_to_string(tmp->avg).length();
    }

    if(convert_to_string(tmp->debt) == "bad_any_cast")
      throw std::runtime_error{"Incorrect type debt"};   //TODO: 8
    if(convert_to_string(tmp->debt).length() > dMax)
      dMax = convert_to_string(tmp->debt).length();
//    std::cout <<" |Debt " << i << ":"<< tmp->debt.type().name() << std::endl;

  }
  std::string sep;
  sep += "|";
  for(size_t i = 0; i < nMax + spaces_w; i++)
  {
    sep += "-";
  }
  sep += "|";
  for(size_t i = 0; i <   gMax + spaces_w; i++)
  {
    sep += "-";
  }
  sep += "|";
  for(size_t i = 0; i < aMax + spaces_w; i++)
  {
    sep += "-";
  }
  sep += "|";
  for(size_t i = 0; i < dMax + spaces_w; i++)
  {
    sep += "-";
  }
  sep += "|";

  std::cout << "| name ";
  for(size_t i = 0; i< nMax -4; i++)
      std::cout << " ";
  std::cout << "| group ";
  for(size_t i = 0; i< gMax -5; i++)
    std::cout << " ";
  std::cout << "| avg ";
  for(size_t i = 0; i< aMax -3; i++)
    std::cout << " ";
  std::cout << "| debt ";
  for(size_t i = 0; i< dMax -4; i++)
    std::cout << " ";
  std::cout << "|" << std::endl << sep << std::endl;

  for(size_t i = 0; i<arr_size; i++)
  {
    Item* temp = this->StudList->Items[i];
    std::cout << "| ";
    std::cout << temp->name << " ";
    for(size_t j = 0; j < nMax - temp->name.length(); j++)
      std::cout << " ";
    std::cout <<"| " << convert_to_string(temp->group) << " ";
    for(size_t j = 0; j < gMax - convert_to_string(temp->group).length(); j++)
      std::cout << " ";
    std::cout <<"| " << convert_to_string(temp->avg) << " ";
    for(size_t j = 0; j < aMax - convert_to_string(temp->avg).length(); j++)
      std::cout << " ";
    std::cout <<"| " << convert_to_string(temp->debt) << " ";
    for(size_t j = 0; j < dMax - convert_to_string(temp->debt).length(); j++)
      std::cout << " ";
    std::cout << "|" << std::endl << sep << std::endl;
  }
}
std::string MyJsonParse::convert_to_string(const std::any& any) {
  if(!strcmp(any.type().name(),
             "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"))
  { //TODO: 9
    return std::any_cast<std::string>(any);
  }
  if(!strcmp(any.type().name(),"m")) //код
  {
    std::stringstream ret;
    ret << std::any_cast<size_t>(any);
    std::string my_string;
    ret >> my_string;
    return my_string;
  }//TODO:10
  if(!strcmp(any.type().name(),"d"))
  {
    std::stringstream ret;
    ret << std::any_cast<double>(any);
    std::string my_string;
    ret >> my_string;
    return my_string;
  }//TODO 11
  if(!strcmp(any.type().name(),
     "St6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE"))
  {
    size_t ret = std::any_cast<std::vector<std::string> >(any).size();
    std::stringstream my_stream;
    std::string my_string;
    my_stream << ret << my_string;
    my_stream >> my_string;
    return my_string + " items";
  }//TODO 12
  if(!strcmp(any.type().name(),"Dn"))
  {
    return "Null";
  }//TODO 13
  return "bad_any_cast";
}