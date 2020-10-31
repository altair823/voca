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
    
    //단어장의 단어 개수
    int list_size;
    
    //단어장의 단어 리스트
    word* word_list[WORD_LIST_MAX];
    
    file_handler file_voca;
    
    console_handler console_voca;
    
public:
    handler();
    
    //단어장 파일을 읽는 함수
    void read_voca_file();
    
    //무엇을 할지 선택할 때 사용할 함수
    int choice();
    
    //단어장의 단어들을 모두 출력하는 함수
    void print_full_voca();
    
    //단어를 입력받아 저장하는 함수
    void store_voca();
    
    //단어를 삭제하는 함수
    void delete_voca();
    
    //파일을 저장하고 프로그램을 끝내는 함수
    void end_program();
};

#endif /* handler_hpp */
