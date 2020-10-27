//
//  handler.hpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#ifndef handler_hpp
#define handler_hpp

#include <stdio.h>

#include "data_structure.hpp"
#include "console_handler.hpp"
#include "file_handler.hpp"

class handler{
    
    word word_list[WORD_LIST_MAX];
    
public:
    handler();
    
    //단어장 파일을 읽는 함수
    void read_voca_file();
};

#endif /* handler_hpp */
