//
//  file_handler.hpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#ifndef file_handler_hpp
#define file_handler_hpp

#include <fstream>
#include <string.h>

#include "data_structure.hpp"
#include "declaration.hpp"

class file_handler{
    
    //파일 스트림
    fstream file_voca;
    
public:
    
    //파일 스트림 생성
    file_handler();
    
    fstream file_open();
    
    //단어장 파일이 맞는지 확인하는 함수
    void verify_file();
    
    //단어장의 단어 개수를 확인하는 함수
    int read_list_size();
    
    //파일을 읽어 단어를 반환하는 함수
    word read_a_word();
    
    //파일의 첫부분을 저장하는 함수
    void store_initial(int list_size);
    
    //단어들을 파일에 저장하는 함수
    void store_word(word a_word);
    
    //서명의 크기를 반환하는 함수
    int verify_size();
};

#endif /* file_handler_hpp */
