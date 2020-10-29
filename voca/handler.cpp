//
//  handler.cpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#include "handler.hpp"

handler::handler(){
}

void handler::read_voca_file(){
    
    //단어장의 크기를 읽고 저장
    list_size = file_voca.read_list_size();
    
    //단어장의 단어들을 모두 읽고 저장
    for (int i=0; i<list_size; i++){
        word_list[i] = new word;
        *word_list[i] = file_voca.read_a_word();
        //word_list[i]->print_test();
    }
}

int handler::choice(){
    return console_voca.choice_store_quiz();
}

void handler::print_full_voca(){
    for (int i=0; i<list_size; i++) {
        console_voca.print_full_voca(*word_list[i]);
    }
}

void handler::store_voca(){
    
}
