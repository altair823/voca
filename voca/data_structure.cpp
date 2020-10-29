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
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 2);
    dis(gen);
    
    if (word_type == 0){
        std::string kor_words;
        if (kor_word2 != "" && kor_word3 == ""){
            kor_words = kor_word1 + ", " + kor_word2;
        }
        else if (kor_word2 == "" && kor_word3 == ""){
            kor_words = kor_word1;
        }
        else{
            kor_words = kor_word1 + ", " + kor_word2 + ", " + kor_word3;
        }
        return kor_words;
    }
    
    //첫번째 뜻 반환
    else if (word_type == 1){
        return kor_word1;
    }
    //두번째 뜻 반환
    else if (word_type == 2){
        //두번째 뜻이 비어있다면 첫번째 뜻 반환
        if (kor_word2 == ""){
            return kor_word1;
        }
        return kor_word2;
    }
    //세번째 뜻 반환
    else if (word_type == 3){
        //세번쨰 뜻이 비어있다면 무작위로 다른 뜻을 반환
        if (kor_word3 == ""){
            int random_num = dis(gen);
            if (random_num == 2){
                //무작위로 선택된 두번째 뜻이 비어있다면 첫번째 뜻 반환
                if (kor_word2 == "") {
                    return kor_word1;
                }
                return kor_word2;
            }
            else if (random_num == 1){
                return kor_word1;
            }
        }
        return kor_word3;
    }
    else{
        std::cout<<"kor_word loading error!"<<std::endl;
        exit(9);
    }
}

void word::print_test(){
    cout<<eng_word<<" "<<kor_word1<<", "<<kor_word2<<", "<<kor_word3<<endl;
}
