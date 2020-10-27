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

std::fstream file_handler::file_open(){
    std::fstream file;
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
