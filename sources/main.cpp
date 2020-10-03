//
// Created by vladislav on 27.09.2020.
//

#include <Studlist.hpp>

int main(){

  MyJsonParse List;
  List.get_meta();
  List.from_json();




//  Students StudList {};
//  StudList._meta.count = j["_meta"]["count"].get<int>();   // Если не находит, рассмотреть случай
//  std::cout << StudList._meta.count << std::endl; // Количество считывается правильно
//     if(StudList._meta.count > 0  && StudList.Items.empty())
//    {
//        for(int i = 0; i < StudList._meta.count; i++)
//        {
//            StudList.Items.push_back(new Item);
//        }
//    }
//
////    Создание вектора объектов json
//    std::vector <json> ItemsVec;
////    Перенос "Items" в вектор ItemVec
//    j["items"].get_to(ItemsVec);
////    Перенос полученных из вектора ItemVec имен в список студентов
//    for(int i=0;i<3;i++)
//    {
//      StudList.Items[i]->name = ItemsVec.at(i)["name"];
//      std::cout << StudList.Items[i]->name << std::endl;
//    }

}
