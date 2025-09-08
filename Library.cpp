using namespace std;
#include <iostream>
#include "Library.h"
#include <vector>


void menu(){
    
    cout<<"Library program"<<endl;
    cout<<"1. Sort inventory"<<endl;
    cout<<"2. Search inventory"<<endl;
    cout<<"3. Take Out book"<<endl;
    cout<<"4. Return book"<<endl;
    cout<<"5. Print inventory"<<endl;
    cout<<"6. clear console"<<endl;
    cout<<"7. Quit"<<endl;
    cout<<"Please enter an option: ";
}//..end of menu

int convertToDaysSinceBC(int year, int month, int day){
    
    bool isLeapYear;
    
    int numOfLeapDays=0;
    
        numOfLeapDays += year/4;
        numOfLeapDays -= year/100;
        numOfLeapDays += year/400;
    
    int timeSinceBC=0;
    
    if (year%4 == 0  && year%100 != 0 || year%400 == 0)
        isLeapYear = true;
    
    if(isLeapYear == true && (month>2||month==2&&day == 29))
     numOfLeapDays+=1;
     
    timeSinceBC +=year*365 + numOfLeapDays + day;
    
    switch(month){

        case 2:
        timeSinceBC+=31;
        break;
        case 3:
        timeSinceBC+=59;
        break;
        case 4:
        timeSinceBC+=90;
        break;
        case 5:
        timeSinceBC+=120;
        break;
        case 6:
        timeSinceBC+=151;
        break;
        case 7:
        timeSinceBC+=181;
        break;
        case 8:
        timeSinceBC+=212;
        break;
        case 9:
        timeSinceBC+=243;
        break;
        case 10:
        timeSinceBC+=273;
        break;
        case 11:
        timeSinceBC+=304;
        break;
        case 12:
        timeSinceBC+=334;
        break;
        
    
    }//...end of switch
    return timeSinceBC;
}//..end of convertToDaysSinceBC


ostream& operator <<(ostream & out, Date & date){
    
    return out<<date.getYear()<<", "<<date.getMonth()<<", "<<date.getDay();
    
}//..end of << operator overload for Date


void BookInfo::printInfo(){
    
    cout<<"Book name: "<<bookName<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Genre: "<<genre<<endl;
    cout<<"availability: ";
    cout<<(availability == true? "Available":"Not available")<<endl;
    cout<<"Id: "<<id<<endl;
}



vector<int> Inventory::search(int typeSearch, string searchPrompt){
    
    int match=0, max=0;
    vector<int> ids;
    
    if (typeSearch == 1){
        for (int i = 0; i<books.size();i++){
            
            for(int j = 0; j<books[i].getBookName().length();j++){
                if(books[i].getBookName()[j] == searchPrompt[match]){
                    match++;
                    if (max<match)
                        max = match;
                }//..end of if
                
                    else {
                        match=0;
                        break;
                    }//..end else
            }//..end of book loop
            if(max==searchPrompt.length())
                ids.push_back(books[i].getId());
            max=0;
            match=0;
            
        }//..end of book seach
    }//..end of if
    
    
    else if (typeSearch ==2){
        for (int i = 0; i<books.size();i++){
            
            for(int j = 0; j<books[i].getAuthor().length();j++){
                if(books[i].getAuthor()[j] == searchPrompt[match]){
                    match++;
                    if (max<match)
                        max = match;
                }//..end of if
                
                else {
                    match = 0;    
                    break;
                }//..end of else
            }//..end of book loop
            if(max==searchPrompt.length())
                ids.push_back(books[i].getId());
            max=0;
            match=0;
            
        }//..end of books search
    }//..end of else if
    
    else if (typeSearch ==3){
        for (int i = 0; i<books.size();i++){
            
            for(int j = 0; j<books[i].getGenre().length();j++){
                if(books[i].getGenre()[j] == searchPrompt[match]){
                    match++;
                    if (max<match)
                        max = match;
                }//..end of if
                
                else {
                    match = 0;
                    break;
                }//..end of else
            }//..end of book loop
            if(max==searchPrompt.length())
                ids.push_back(books[i].getId());
            max=0;
            match=0;
        }//..end of books search
    }//..end of else if
    
    return ids;
}//...end of search function


void Inventory::sortBookName(){
    int sorted=0;
    for(int i =65; i<90; i++){
        
        for(int j=sorted; j<books.size()-1;j++){
            
            if(books[j].getBookName()[0]==i){
                vector<BookInfo>::iterator itr = books.begin();
                books.insert(itr+sorted, books[j]);
                itr = books.begin();
                books.erase(itr+j+1);
                sorted++;
            }//...end of if
        } //...end of for
    }//...end of for
}//..end of sortBookName

void Inventory::sortAuthor(){
    int sorted=0;
    for(int i =65; i<90; i++){
        
        for(int j=sorted; j<books.size()-1;j++){
            
            if(books[j].getAuthor()[0]==i){
                vector<BookInfo>::iterator itr = books.begin();
                books.insert(itr+sorted, books[j]);
                itr = books.begin();
                books.erase(itr+j+1);
                sorted++;
            }//...end of if
        } //...end of for
    }//...end of for
}//..end of sortBookName

void Inventory::sortGenre(){
    int sorted=0;
    for(int i =65; i<90; i++){
        for(int j=sorted; j<books.size()-1;j++){
            if(books[j].getGenre()[0]==i){
                vector<BookInfo>::iterator itr = books.begin();
                books.insert(itr+sorted, books[j]);
                itr = books.begin();
                books.erase(itr+j+1);
                sorted++;
            }//...end of if
        } //...end of for
    }//...end of for
}//..end of sortBookName

void Inventory::takeOutBook(int id, int dateOut){
    
    
    for(int i = 0;i<books.size();i++){
        if(id==books[i].getId()){
            if(books[i].getAvailability()==true){
                books[i].setAvailability(false);
                addOut(books[i], dateOut);
                cout<<"You have loaned out: "<<books[i].getBookName()<<endl;
                cout<<"Your book will be due 2 weeks from now"<<endl;
            }//..end of if
            else
                cout<<"The book is not available, it has been loaned out already"<<endl;
            
        }//..end of if
    }//...end of for
}//...end of takeOutBook


void Inventory::returnBook(int id, int currentDate){
bool presence=false;
    for(int i = 0; i<booksOut.size();i++){
        if(booksOut[i].getId()==id){
            booksOut.erase(booksOut.begin()+i);
            presence=true;
            booksOut[i].setDateReturned(currentDate);
            cout<<"Your book has been returned"<<endl;
            cout<<"You owe: $"<<booksOut[i].calculateLateFees();
            for(int j = 0; j<books.size();j++){
                if(books[j].getId() == id)
                    books[j].setAvailability(true);
            }//..end of for
        }//..end of if
    }//..end of for
    if(presence == false){
        cout<<"The book id you entered has not been taken out"<<endl;
        
    }//..end of if
}//..end of returnBook




void Inventory::printInventory(){
    
    char printMore;
    
    for(int i = 0; i < books.size() ;i++ ){
        books[i].printInfo();
        if(i%10 == 0&&i>0){
            cout<<"Would you like to print more?('Y'/'N'): ";
            cin>>printMore;
            if(printMore=='N'||printMore=='n')
                break;
        }//..end of if
    }//..end of for
}//..end of printInventory

void Inventory::printId(vector<int> vec){
    
    for (int i = 0;i<vec.size();i++){
        for(int j = 0 ; j<books.size() ; j++){
            
            if(books[j].getId() == vec[i]){
                books[j].printInfo();
            }//..end of if
        }//..end of for
        cout<<endl;
    }//..end of for
}//..end of printVector 

double LateCharges::calculateLateFees(){
    
    int dateDifference = dateReturned-dateOut;
    
    if(dateDifference > 14)
        return (dateDifference-14)*2;
    
    else
        return 0;
    
}