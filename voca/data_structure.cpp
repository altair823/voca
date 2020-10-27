//
//  data_structure.cpp
//  voca
//
//  Created by 김태현 on 2020/10/28.
//

#include "data_structure.hpp"

word::word(){
    
}
word::word(std::string eng_word_new){
    eng_word = eng_word_new;
}
word::word(std::string eng_word_new, std::string kor_word_new1){
    eng_word = eng_word_new;
    kor_word1 = kor_word_new1;
}
word::word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2){
    eng_word = eng_word_new;
    kor_word1 = kor_word_new1;
    kor_word2 = kor_word_new2;
}
word::word(std::string eng_word_new, std::string kor_word_new1, std::string kor_word_new2, std::string kor_word_new3){
    eng_word = eng_word_new;
    kor_word1 = kor_word_new1;
    kor_word2 = kor_word_new2;
    kor_word3 = kor_word_new3;
}

std::string word::put_eng_word(){
    return eng_word;
}

std::string word::put_kor_word(int word_type){
    
    if (word_type == 0){
        std::string kor_words;
        kor_words = "1. " + kor_word1 + ", 2. " + kor_word2 + ", 3. " + kor_word3;
        return kor_words;
    }
    else if (word_type == 1){
        return kor_word1;
    }
    else if (word_type == 2){
        return kor_word2;
    }
    else if (word_type == 3){
        return kor_word3;
    }
    else{
        std::cout<<"kor_word loading error!"<<std::endl;
        exit(9);
    }
}
