//
//  console_handler.hpp
//  voca
//
//  Created by 김태현 on 2020/10/27.
//

#ifndef console_handler_hpp
#define console_handler_hpp

#include <iostream>

#include "declaration.hpp"

using namespace std;

class console_handler{
    
public:
    console_handler();
    
    //초기 선택 화면
    int choice_store_quiz();
};

#endif /* console_handler_hpp */
