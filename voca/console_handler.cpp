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
        
        cout<<"1. Store vocabulary  2. Quiz  3. List words  4. Exit"<<endl;
        cout<<">>";
        int choice;
        cin>>choice;
        
        if (choice == 1 || choice == 2 || choice == 3){
            return choice;
        }
        else if (choice == 0){
            cout<<"Exit program"<<endl;
            exit(0);
        }
        else{
            cout<<"wrong input"<<endl;
            continue;
        }
        
    }
    
}

void console_handler::print_full_voca(word temp_word){
    cout<<temp_word.put_eng_word()<<"   "<<temp_word.put_kor_word(0)<<endl;
}
