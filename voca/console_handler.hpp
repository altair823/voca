//
//  console_handler.hpp
//  voca
//
//  Created by 김태현 on 2020/10/27.
//

#ifndef console_handler_hpp
#define console_handler_hpp

#include <iostream>

#include "data_structure.hpp"
#include "declaration.hpp"

class console_handler{
    
public:
    console_handler();
    
    //초기 선택 화면
    int choice_store_quiz();
    
    //단어 한 개를 출력하는 함수
    void print_full_voca(word temp_word);
    
    //단어를 입력받아 word형식으로 반환하는 함수
    word input_word();
};

#endif /* console_handler_hpp */
