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
            make_temp_file.write(VERIFY, strlen(VERIFY));
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
    
    //파일을 읽을 때 사용할 버퍼
    string buffer;
    
    //영어단어를 저장할 문자열
    string eng_word;
    
    //단어 인스턴스를 만들때 매개변수로 줄 한국어 뜻 리스트 포인터
    string* kor_word;
    
    //한국어 뜻을 읽는 과정에서 이를 저장할 임시 버퍼
    string temp_kor_word[100];
    
    //한국어 뜻의 개수
    int kor_word_count=0;
    
    //영어단어를 읽고 저장
    getline(file_voca, buffer, '<');
    getline(file_voca, eng_word, '>');
    
    //한국어 뜻을 읽고 저장, 그 개수를 저장
    for (int i=0; ; i++) {
        getline(file_voca, buffer, '<');
        getline(file_voca, buffer, '>');
        //만약 더 이상 없다는 표시가 있다면
        if (buffer == "n") {
            //개수를 저장함
            kor_word_count = i;
            break;
        }
        temp_kor_word[i] = buffer;
    }
    
    //지금까지 읽은 개수의 한국어 뜻을 저장할 문자열 배열을 동적 생성
    kor_word = new string[kor_word_count];
    
    //지금까지 읽은 한국어 뜻을 버퍼에서 문자열 배열로 깊은 복사
    for (int i=0; i<kor_word_count; i++) {
        kor_word[i] = temp_kor_word[i];
    }
    
    //반환할 단어 인스턴스를 생성
    word temp_word(eng_word, kor_word, kor_word_count);
    return temp_word;
}

void file_handler::store_initial(int list_size){
    file_voca.close();
    file_voca.open(FILE_PATH, ios::out);
    
    //서명을 파일에 저장
    file_voca.write(VERIFY, strlen(VERIFY));
    file_voca.write("\n", 1);
    
    //단어장의 크기를 저장
    file_voca.write("list size: ", 11);
    file_voca.write(to_string(list_size).c_str(), to_string(list_size).size());
    file_voca.write("\n", 1);
}

void file_handler::store_word(word a_word){
    file_voca.write("<", 1);
    file_voca.write(a_word.put_eng_word().c_str(), a_word.put_eng_word().size());
    file_voca.write("> ", 2);
    for (int i=0; i<a_word.put_kor_word_count(); i++) {
        file_voca.write(" <", 2);
        file_voca.write(a_word.put_kor_word_index(i).c_str(), a_word.put_kor_word_index(i).size());
        file_voca.write(">", 1);
    }
    file_voca.write("\n", 1);
}
