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
    list_size = file_voca.read_list_size();
    file_voca.read_a_word();
    file_voca.read_a_word();
}
