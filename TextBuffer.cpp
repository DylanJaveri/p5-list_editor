
#include "TextBuffer.hpp"
#include <list>
#include <string>

TextBuffer::TextBuffer() : row(1), column(0), index(0) {
    cursor = data.begin();
};

bool TextBuffer::forward(){
    if (cursor == data.end()){
        return false;
    }
    if (*cursor == '\n') {
                cursor++;
                row++;
                column++;
                index++;
                return true;
        }
        else {
            cursor++;
            column++;
            index++;
            return true;
        }
}

bool TextBuffer::backward() {
    if (index == 0){
        return false;
    }
    else {
        if (column == 0) {
            row--;    
        }
        cursor--;
        index--;
        column = compute_column();
        return true;
    }
}

void TextBuffer::insert(char c) {
    data.insert(cursor, c);
    index++;
    if (c == '\n'){
        row++;
        column = 0;
    }
    else {
        column++;
    }
}

bool TextBuffer::remove() {
    if (cursor == data.end() || *cursor == '\n'){
        return false;
    }
    else {
        cursor = data.erase(cursor);
        index--;
        return true;
    }
}

void TextBuffer::move_to_row_start() {
    while (column != 0){
        backward();
    }
}

 void TextBuffer::move_to_row_end() {
    while (*cursor != '\n' && cursor != data.end()) {
        forward();
    }
 }

 void TextBuffer::move_to_column(int new_column){
    move_to_row_start();
    while (new_column > column){
        if (cursor == data.end() || *cursor == '\n'){
            break;
        }
        forward();
    }
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
        return true;
    }
 }

 bool TextBuffer::down() {
    int new_column = column;
    move_to_row_end();
    if (!forward()) {
        move_to_column(new_column);
        return false;
    }
    move_to_column(new_column);
    return true;
 }

 bool TextBuffer::is_at_end() const {
    if (cursor == data.end()){
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

 int TextBuffer::compute_column() const {
    if (cursor == data.end()) {
        return column;
    }
    Iterator new_cursor = cursor;
    int computedColumn = 0;
    while (new_cursor != data.begin()) {
        --new_cursor;
        if (*new_cursor == '\n') {
            break;
        }
        ++computedColumn;
    }
    return computedColumn;
 }

 std::string TextBuffer::stringify() const {
    return std::string(data.begin(), data.end());
 }
