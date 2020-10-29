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
    handler handler_voca;
    handler_voca.read_voca_file();
    while (true) {
        int choice = handler_voca.choice();
        
        if (choice == 1) {
            //store vocabulary
        }
        else if (choice == 2){
            //Quiz
        }
        else if (choice == 3){
            //list all words
            handler_voca.print_full_voca();
        }
    }
    
    
    return 0;
}
