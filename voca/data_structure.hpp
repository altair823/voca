//
//  data_structure.hpp
//  voca
//
//  Created by 김태현 on 2020/10/28.
//

#ifndef data_structure_hpp
#define data_structure_hpp

#include <random>

#include "declaration.hpp"

class word{
    
    //영어 단어
    std::string eng_word;
    
    //한국어 뜻
    std::string* kor_word;
    int kor_word_count;
    
public:
    
    //단어의 생성자
    word();
    word(const std::string& eng_word_new);
    word(const std::string& eng_word_new, std::string* kor_word_new_list, int kor_word_count);
    //~word();
    
    word(const word& ref);
    
    //단어를 변경하기 위한 함수
    //미구현
    void set_eng_word(string eng_word_new);
    void set_kor_word(string kor_word_new);
    
    //
    const int put_kor_word_count();
    
    //
    const std::string put_eng_word();
    const std::string put_kor_word_random();
    const std::string put_kor_word();
    const std::string put_kor_word_index(int index);
    
    //테스트용 단어 표시
    void print_test();
};

#endif /* data_structure_hpp */
