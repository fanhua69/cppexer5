//
//  ranges_1.cpp
//  testcpp3
//
//  Created by hua fan on 5/12/25.
//
#include <vector>
#include <ranges>
#include <algorithm>

struct Student
{
    int year_{};
    int score_{};
    std::string name_{};
// ...
};

auto get_max_score(const std::vector<Student>& students, int year)
{
    auto by_year = [=](const auto& s)
    {
        return s.year_ == year;
    };
    
   // The student list needs to be copied in
   // order to filter on the year
   auto v = std::vector<Student>{};
   std::ranges::copy_if(students, std::back_inserter(v), by_year);
   auto it = std::ranges::max_element(v, std::less{}, &Student::score_);
   return it != v.end() ? it->score_ : 0;
}
