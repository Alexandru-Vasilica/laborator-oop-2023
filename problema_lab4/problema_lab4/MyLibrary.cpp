#include "MyLibrary.h"


MyLibrary::MyLibrary(std::ostream& output_stream): output_stream(output_stream),books_count(0),books(nullptr)
{
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream), books_count(books_count)
{
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream), books_count(books_count)
{
    srand(time(NULL));
    books = new int[100];
    for(unsigned int i=0; i<books_count;i++)
        books[i]= rand()%(max - min) + min;
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream),books_count(0)
{
    books = new int[100];

    char* getbooks = new char[300];    
    strcpy(getbooks, books_values);
    char* p = strtok(getbooks,";");
    while (p)
    {
        books[books_count] = std::stoi(p);
        books_count++;
        p = strtok(NULL, ";");
    }

}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream), books_count(books_count)
{
    books = new int[100];
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; i++) {
        books[i] = va_arg(args, int);
    }
        va_end(args);
    
}

MyLibrary::MyLibrary(std::initializer_list<int> v): output_stream(std::cout), books_count(0)
{
    books = new int[100];
    
    for (const int* i = v.begin(); i != v.end(); i++)
    {
            books[books_count] = *i;
            books_count++;
    }
}

MyLibrary::MyLibrary(const MyLibrary& other):output_stream(other.output_stream),books_count(other.books_count)
{
    books = new int[books_count];
    for (int i = 0; i < books_count; i++)
        this->books[i] = other.books[i];
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const
{
    if (books_count == 0)
        output_stream <<"Found 0 books:"<<-1;
    else {
        output_stream << "Found " << books_count << " books:";
        for (unsigned i = 0; i < books_count; i++)
        {
            output_stream << books[i] << " ";
        }
    }
    output_stream << "\n";
        
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id)
{
    if(book_index<books_count)
    books[book_index] = book_id;
}

int MyLibrary::get_books_count() const
{
    return books_count;
}

int MyLibrary::get_book_id_by_index(unsigned int book_index) const
{
    if (book_index < books_count)
        return books[book_index];
    return -1;
}



