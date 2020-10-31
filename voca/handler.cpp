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
        word_list[i] = new word(file_voca.read_a_word());
        
        //단어를 생성할 때는 되도록이면 빈 단어를 생성하지 않도록 한다. 
        //*word_list[i] = file_voca.read_a_word();
        
    }
}

int handler::choice(){
    return console_voca.choice();
}

void handler::print_full_voca(){
    for (int i=0; i<list_size; i++) {
        console_voca.print_full_voca(*word_list[i]);
    }
}

void handler::store_voca(){
    //cout<<list_size<<endl;
    word_list[list_size] = new word(console_voca.input_word());
    //*word_list[list_size] = console_voca.input_word();
    list_size++;
    print_full_voca();
}

void handler::delete_voca(){
    
}

void handler::end_program(){
    file_voca.store_initial(list_size);
    for (int i=0; i<list_size; i++) {
        file_voca.store_word(*word_list[i]);
    }
    exit(0);
}
