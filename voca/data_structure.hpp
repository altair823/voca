//
//  data_structure.hpp
//  voca
//
//  Created by 김태현 on 2020/10/28.
//

#ifndef data_structure_hpp
#define data_structure_hpp

#include "declaration.hpp"

class word{
    
    //영어 단어
    std::string eng_word;
    
    //한국어 뜻
    std::string kor_word1;
    std::string kor_word2;
    std::string kor_word3;
    
public:
    word();
    word(std::string eng_word_new);
    word(std::string eng_word_new, std::string kor_word_new1);
    word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2);
    word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2, std::string kor_word_new3);
    
    std::string put_eng_word();
    std::string put_kor_word(int word_type);
};

#endif /* data_structure_hpp */
