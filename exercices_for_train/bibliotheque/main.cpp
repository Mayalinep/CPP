#include "Book.class.hpp"
#include "ReaderA.class.hpp"
#include "ReaderB.class.hpp"

int main() {
    {
        Book book("The Great Gatsby");
        ReaderA alice("Alice", book);
        alice.read();
        book.setTitle("1984");
        alice.read();
    }
    {
        Book book("The Great Gatsby");
        ReaderB bob("Bob");
        bob.read();
        bob.setBook(book);
        bob.read();
        book.setTitle("1984");
        bob.read();
    }
    return 0;
}