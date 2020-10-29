//
//  main.cpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#include <iostream>
#include "handler.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    handler test_handler;
    test_handler.read_voca_file();
    test_handler.print_voca();
    return 0;
}
