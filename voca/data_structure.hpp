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
    std::string kor_word1;
    std::string kor_word2;
    std::string kor_word3;
    
public:
    
    //단어의 생성자
    word();
    word(std::string eng_word_new);
    word(std::string eng_word_new, std::string kor_word_new1);
    word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2);
    word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2, std::string kor_word_new3);
    
    //단어를 변경하기 위한 함수
    void set_eng_word(string eng_word_new);
    void set_kor_word(string kor_word_new);
    
    //
    std::string put_eng_word();
    std::string put_kor_word(int word_type);
    
    //테스트용 단어 표시
    void print_test();
};

#endif /* data_structure_hpp */
