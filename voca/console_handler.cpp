//
//  console_handler.cpp
//  voca
//
//  Created by 김태현 on 2020/10/27.
//

#include "console_handler.hpp"

console_handler::console_handler(){
    std::cout<<"<"<<VERIFY<<">"<<std::endl;
    
    //choice_store_quiz();
}

int console_handler::choice_store_quiz(){
    
    while (true) {
        
        cout<<"1. Store vocabulary  2. Delete word  3. Quiz  4. List words  0. Exit"<<endl;
        cout<<">>";
        int choice;
        cin>>choice;
        
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4){
            return choice;
        }
        else if (choice == 0){
            cout<<"Exit program"<<endl;
            return choice;
        }
        else{
            cout<<"wrong input"<<endl;
            continue;
        }
        
    }
    
}

void console_handler::print_full_voca(word temp_word){
    cout<<temp_word.put_eng_word()<<"   "<<temp_word.put_kor_word()<<endl;
}


word console_handler::input_word(){
    //word input_word;
    cin.clear();
    cin.ignore();
    cout<<"English word: ";
    string eng_word;
    getline(cin, eng_word);
    
    cin.clear();
    cin.ignore();
    cout<<"Korean mean(split with /): ";
    string kor_word;
    getline(cin, kor_word);
    
    //입력받은 한국어 뜻을 /를 기준으로 분할
    char* temp_c_str = new char[kor_word.size()];
    strcpy(temp_c_str, kor_word.c_str());
    
    //입력받을 한국어 뜻을 저장할 문자열들
    string temp_kor_mean_list[20];
    int kor_mean_list_size = 0;
    
    char* tok = strtok(temp_c_str, "/");
    while (tok != nullptr) {
        temp_kor_mean_list[kor_mean_list_size] = string(tok);
        tok = strtok(nullptr, "/");
        kor_mean_list_size++;
    }
    
    //분할한 한국어 뜻을 올바르게 저장
    string* kor_mean_list;
    kor_mean_list = new string[kor_mean_list_size];
    for (int i=0; i<kor_mean_list_size; i++) {
        if (temp_kor_mean_list[i] != ""){
            kor_mean_list[i] = temp_kor_mean_list[i];
        }
    }
    word new_word(eng_word, kor_mean_list, kor_mean_list_size);
    return new_word;
}
 
