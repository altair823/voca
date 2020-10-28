//
//  file_handler.cpp
//  voca
//
//  Created by 김태현 on 2020/10/24.
//

#include "file_handler.hpp"

file_handler::file_handler(){
    
    //파일 핸들러가 생성되면 단어장 파일을 연다.
    file_voca = file_open();
    verify_file();
}

fstream file_handler::file_open(){
    fstream file;
    while (true) {
        file.open(FILE_PATH);
        
        //단어장 파일이 존재하고 열린다면
        if(file.is_open()){
            std::cout<<"file open successfully"<<std::endl;
            break;
        }
        else{
            std::cout<<"file open error"<<std::endl;
            
            std::cout<<"make a new file"<<std::endl;
            
            std::ofstream make_temp_file(FILE_PATH);
            make_temp_file.write(VERIFY, 22);
            make_temp_file.close();
        }
        
    }
    return file;
}

void file_handler::verify_file(){
    std::string verify_string;
    file_voca >> verify_string;
    std::string a(VERIFY);
    if(verify_string != VERIFY){
        std::cout<<"Invalid file content!"<<std::endl;
        exit(7);
    }
}

int file_handler::read_list_size(){
    
    std::string buffer;
    std::getline(file_voca, buffer, ':');
    
    int size;
    file_voca>>size;
    //std::cout<<size<<std::endl;
    return size;
}

word file_handler::read_a_word(){
    
    string buffer;
    string eng_word;
    string kor_word[3];
    getline(file_voca, buffer, '<');
    getline(file_voca, eng_word, '>');
    
    cout<<eng_word<<endl;
    
    
    for (int i=0; i<3; i++) {
        
        getline(file_voca, buffer, '<');
        getline(file_voca, buffer, '>');
        
        if (buffer != ""){
            kor_word[i] = buffer;
        }
        cout<<kor_word[i]<<endl;
    }
    word temp_word(eng_word, kor_word[0], kor_word[1], kor_word[2]);
    return temp_word;
}
