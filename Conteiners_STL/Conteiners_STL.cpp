#include <iostream>
#include <random>

// коллекции для демонстрации работы алгоритмов
#include <list>
#include <vector>

// библиотеки облегчающие обработку коллекций и в принципе работу с данными
#include <algorithm>
#include <functional>

template <typename T>
void Randomize(std::vector<T>& coll, int hi, int low, int amount)
{
    std::uniform_int_distribution<int> provider(low, hi);    // генератор псевдослучайных чисел
    std::random_device rd;
    for (size_t i = 0; i < amount; i++)
    {
        coll.push_back(rd() % (hi + 1) + low);
    }
}

template <typename T>
void Randomize( std::list<T>& coll, int hi, int low, int amount)
{
    std::uniform_int_distribution<int> provider(low, hi);    // генератор псевдослучайных чисел
    std::random_device rd;
    for (size_t i = 0; i < amount; i++)
    {
        coll.push_back(rd() % (hi + 1) + low);
    }
}

bool IsMore(int a, int b)
{
    return a > b;
}

bool Equal(int a, int b)
{
    return a == b;
}

void Print(const std::vector<int> vec)
{
    for (const auto& el : vec)
        std::cout << el << ' ';
    std::cout << std::endl;
}

int main()
{
    std::random_device rd;                                  // non-deterministic generator // генератор энтропии
    std::mt19937 gen(rd());                                 // to seed mersenne twister.
    std::uniform_int_distribution<int> provider(10, 99);    // генератор псевдослучайных чисел
    std::list<int> coll1;
    std::vector<int> coll2;

    /*for (size_t i = 0; i < 20; i++)
    {
        coll1.push_back(rd() % 100);
    }*/

   // Randomize(coll1, 99, 10, 20);
   // Randomize(coll2, 99, 10, 20);
   // int count = 0;
   // // ищем количество повторений чисел в сoll1 и в coll2
   ///* for (const auto& el : coll1)
   // {
   //     for (const auto& el2 : coll2)
   //     {
   //         if (el == el2)
   //         {
   //             count++;
   //             std::cout << el << " == " << el2 << std::endl;
   //             break;
   //         }
   //     }
   // }*/

   // for (const auto& el : coll1)
   // {
   //     count += std::count(coll2.begin(), coll2.end(), el);
   // }
   // std::cout << "count = " << count << std::endl;

   // //--------------------------------------------------------

   // // удаляем дубликаты

   // if (count > 0)
   // {
   //     for (const auto& el : coll1)
   //     {
   //         auto it = std::find(coll2.begin(), coll2.end(), el);
   //         if (it != coll2.end())
   //         {
   //             coll2.erase(it);
   //         }
   //     }

   // }
   // count = 0;
   // for (const auto& el : coll1)
   // {
   //     count += std::count(coll2.begin(), coll2.end(), el);
   // }
   // std::cout << "count = " << count << std::endl;
   // 
   // // max, min, min_max
   // // sort, shuffle, split

   // std::sort(coll2.begin(), coll2.end(), IsMore);

   // auto lamb = [](int a, int b)
   // {
   //     return a > b;
   // };

   // std::sort(coll2.begin(), coll2.end(), [](int a, int b)->bool{return a > b;});

    /*
    в коллекции заполненной случайными элементами, убрать повторяющиеся элементы, но перед этим переместить один из них в другую коллекцию
    */

    std::vector<int> vec1;
    std::vector<int> vec2;
    
    Randomize(vec1, 100, 0, 20);
    Print(vec1);
    for (size_t i = 0; i < vec1.size()-1; i++)
    {
        for (size_t j = i+1; j < vec1.size(); j++)
        {
            if (vec1[i] == vec1[j])
            {
                vec2.push_back(vec1[i]);
                break;
            }
        }

    }
    for (const auto& el : vec2)
    {
        for (size_t i = 0; i < vec1.size(); )
        {
            if (el == vec1[i])
                vec1.erase(vec1.begin() + i);
            else
                i++;
        }
    }
    std::cout << "\n\n\n";
    Print(vec1);
    Print(vec2);

    for (auto& el : vec1)
    {
        /*if (el > 25 && el < 75)
        {
            el = 0;
        }*/
    }
    Print(vec1);

    return 0;
}

