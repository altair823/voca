//
//  data_structure.cpp
//  voca
//
//  Created by 김태현 on 2020/10/28.
//

#include "data_structure.hpp"

//만약 영어단어의 입력 없이 단어 인스턴스가 만들어지면 요류를 뱉음
word::word(){
    cout<<"there is no english word error!"<<endl;
    
    //exit(8);
}

//영어단어만이 입력되었고 뜻은 입력받지 못했을 때
word::word(const std::string& eng_word_new){
    eng_word = eng_word_new;
    kor_word_count = 0;
}

//영어단어와 그 뜻을 입력받고 뜻의 개수를 입력받음
//가장 선호해야할 생성자
word::word(const std::string& eng_word_new, std::string* kor_word_new_list, int kor_word_count_new){
    eng_word = eng_word_new;
    kor_word = new string[kor_word_count_new];
    for (int i=0; i<kor_word_count_new; i++) {
        kor_word[i] = kor_word_new_list[i];
    }
    kor_word_count = kor_word_count_new;
}

word::~word(){
    //delete kor_word;
}

word::word(const word& ref){
    eng_word = ref.eng_word;
    kor_word_count = ref.kor_word_count;
    kor_word = new string[ref.kor_word_count];
    for (int i=0; i<kor_word_count; i++) {
        kor_word[i] = ref.kor_word[i];
    }
}

const int word::put_kor_word_count(){
    return kor_word_count;
}

std::string const word::put_eng_word(){
    return eng_word;
}

const std::string word::put_kor_word_random(){
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, kor_word_count);
    dis(gen);
    
    int random_num = dis(gen);
    
    return kor_word[random_num];
}

const std::string word::put_kor_word(){
    std::string kor_words;
    //cout<<kor_word_count<<endl;
    for (int i=0; i<kor_word_count; i++) {
        kor_words += kor_word[i];
        if (i != kor_word_count-1) {
            kor_words += ", ";
        }
    }
    return kor_words;
}

const std::string word::put_kor_word_index(int index){
    return kor_word[index-1];
}

void word::print_test(){
    cout<<eng_word<<" ";
    for (int i=0; i<kor_word_count; i++) {
        cout<<kor_word[i]<<" ";
    }
    cout<<endl;
}
