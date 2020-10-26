//
//  file_handler.hpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#ifndef file_handler_hpp
#define file_handler_hpp

#include <fstream>

#include "declaration.hpp"

class file_handler{
    
    //파일 스트림
    std::fstream file_voca;
    
public:
    
    //파일 스트림 생성
    file_handler();
    
    std::fstream file_open();
    
    //단어장 파일이 맞는지 확인하는 함수
    void verify_file();
};

#endif /* file_handler_hpp */
