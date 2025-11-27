//
//  filesystem_path.cpp
//  testcpp3
//
//  Created by hua fan on 2024-02-07.
//

#include <stdio.h>
#include <filesystem>
#include "headers.h"

namespace file_system
{

void file_system_path_main()
{
    std::filesystem::path sp = std::filesystem::current_path();
    std::filesystem::path mfp = sp / "Makefile.debug";

    cout << sp.string() << endl;
    cout << sp.root_name() << endl;
}

}
