#ifndef MY_REPLACE_H
#define MY_REPLACE_H

#include <cstddef>  // Для size_t

// Замінює частину рядка str, починаючи з pos, довжиною len, рядком repl
void my_replace(char* str, size_t pos, size_t len, const char* repl);

#endif // MY_REPLACE_H
