using namespace std;
#include<iostream>
#include<vector>

//Convert a date int the form YY /MM /DD into the days since BC
int convertToDaysSinceBC(int year, int month, int day);

//printng Menu
void menu();

//Date class consisting of the information of a date in the form YY/MM/DD
class Date{
    private:
        int year, day;
        string month;
        
    public:
        
        //constructors for Date
        Date(){}
        
        Date(int year, string month, int day):year(year), month(month), day(day){}
        
        //getters Date
        int getYear(){return year;}
        int getDay(){return day;}
        string getMonth(){return month;}
        
        //Overload << to print the date
        friend ostream& operator << (ostream& out, Date & date);

};

//All information on a book, the name, author, genre, availability, and id
class BookInfo{
    protected:
    string bookName, author, genre;
    bool availability;
    int id;
    
    public:
    
    //constructers for BookInfo
    BookInfo(){}
    
    BookInfo(string bookName, string author, string genre,int id)
    :bookName(bookName), author(author), genre(genre), id(id){availability = true;}
    
    //Printing info for book
    void printInfo();
    
    //setters for BookInfo
    void setBookName(string bookName){this->bookName=bookName;}
    
    void setAuthor(string author){this->author=author;}
    
    void setGenre(string genre){this->genre=genre;}
    
    void setAvailability(bool availability){this->availability=availability;}
    
    void setId(int id){this->id=id;}

    //getters for BookInfo
    string getBookName(){return bookName;}
    
    int getId(){return id;}
    
    string getAuthor(){return author;}
    
    string getGenre(){return genre;}
    
    bool getAvailability(){return availability;}
    
};

//LateCharges class
class LateCharges:public BookInfo{
    private:
        int dateOut, dueDate, dateReturned;
    
    public:
        
        //constructor for LateCharges
        LateCharges():BookInfo(){}
        
        //setters for LateCharges
        void setDateOut(int dateOut){
            this->dateOut = dateOut;
            dueDate = dateOut+14;
        }
        
        void setDateReturned(int dateReturned){this->dateReturned=dateReturned;}
        
        //calculateLateFees
        double calculateLateFees();
};

class Inventory{
    private:
    vector<BookInfo> books;
    vector<LateCharges> booksOut;
    
    public:
    
    //add a book to the books vector
    void addBook(string bookName, string author, string genre){
        int id = books.size();
        BookInfo book(bookName, author, genre, id);
        books.push_back(book);
        
    }
    
    //add a book into the booksOut vector
    void addOut(BookInfo book, int dateOut){
        LateCharges outBook;
        outBook.setId(book.getId());
        outBook.setDateOut(dateOut);
        booksOut.push_back(outBook);
    }
    
    //print the invenotry of books starting from index 0 
    void printInventory();
    
    //sorting functions
    void sortAuthor();
    
    void sortGenre();
    
    void sortBookName();
    
    //search function
    vector<int> search(int typeSearch, string searchPrompt);
    
    //take out and return options 
    void takeOutBook(int id, int dateOut);
    
    void returnBook(int id,int currentDate);
    
    //print list of ids obtained from search functions
    void printId(vector<int> vec);
};