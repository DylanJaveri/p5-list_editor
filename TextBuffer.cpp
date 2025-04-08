
#include "TextBuffer.hpp"

TextBuffer::TextBuffer() : cursor.end(), row(1), column(0), index(0);

bool TextBuffer::forward(){
    if (!cursor){
        return false;
    }
    else {
        if (*cursor == "/n") {
            if (cursor++ == cursor.end()){
                column++;
                index++;
                return true;
            }
            else {
                row++;
                column++;
                index++;
                return true;
            }
        }
        else {
            column++;
            index++;
            return true;
        }
    }
}

bool TextBuffer::backward() {};

void TextBuffer::insert(char c) {
    cursor.insert(this, c);
    column++;
    index++;
}

void TextBuffer::remove() {
    if (!cursor){
        return false;
    }
    else {
        cursor = cursor.erase(cursor);
        column++;
    }
}

void TextBuffer::move_to_row_start() {
    while (collumn != 0){
        backward();
    }
}

 void TextBuffer::move_to_row_end() {
    while (*cursor != "/n" || cursor != cursor.end()) {
        forward();
    }
 }

 void TextBuffer::move_to_column(int new_collumn){

 }

 bool TextBuffer::up() {
    if (row == 1){
        return false;
    }
    else {
        int new_column = column;
        move_to_row_start();
        backward();
        move_to_column(new_column);
    }
 }

 bool TextBuffer::down() {
    if (row == x){   //how do I identify if the row is the last one?
        return false;
    }
    else {
        int new_column = column;
        move_to_row_end();
        forward();
        move_to_column(new_column);
    }
 }

 bool TextBuffer::is_at_end() const {
    if (!cursor && cursor--){
        return true;
    }
    else {
        return false;
    }
 }

 char TextBuffer::data_at_cursor() const{
    return *cursor;
 }

 int TextBuffer::get_row() const {
    return row;
 }

 int TextBuffer::get_column() const {
    return column;
 }

 int TextBuffer::get_index() const{
    return index;
 }

 int TextBuffer::size() const{
    return data.size();
 }





