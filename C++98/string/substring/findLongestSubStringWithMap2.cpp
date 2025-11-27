//
//  findLongestSubStringWithMap2.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-12.
//

#include <stdio.h>
#include "headers.h"

string findLongestSubStringWithMap2(const string &s)
{
    std::string::size_type current_start_pos = 0;
    std::string::size_type current_length = 0;
    std::string::size_type max_length = 0;
    std::string::size_type max_length_start_pos = 0;
    std::unordered_map<std::string::value_type, std::string::size_type> char_position_map;

    std::string::size_type current_index = 0;

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        current_index = std::distance(s.begin(), iter);
        auto find_iter = char_position_map.find(*iter);

        if (find_iter == char_position_map.end()) {
            // not a repeat. store char and position in map
            char_position_map.insert(std::make_pair(*iter, current_index));
        } else {
            // found a repeat character. check if its position is in the current substring
            //if (char_position_map[*iter] >= current_start_pos) {
                // update length and start position.
                current_length = current_index - current_start_pos;
                if (current_length > max_length ) {
                    max_length = current_length;
                    max_length_start_pos = current_start_pos;
                }

                current_start_pos = char_position_map[*iter] + 1;
            //}
            //update the position stored in the map
            char_position_map[*iter] = current_index;
        }
    }
    // current index is at the end of the string after completing the loop
    current_index++;

    if (max_length < current_index - current_start_pos) {
        max_length = current_index - current_start_pos;
        max_length_start_pos = current_start_pos;
    }

    return s.substr(max_length_start_pos, max_length);
}

void findLongestSubStringWithMapMain2()
{
    string s = "abcabcdefabcd";
    cout << findLongestSubStringWithMap2(s) << endl;
    s = "abcabcdef";
    cout << findLongestSubStringWithMap2(s) << endl;
    s = "abcdef";
    cout << findLongestSubStringWithMap2(s) << endl;
}
