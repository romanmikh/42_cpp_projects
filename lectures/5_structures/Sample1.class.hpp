/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_1_H
# define SAMPLE_CLASS_1_H

struct Sample1 {

    int foo;

    Sample1();
    ~Sample1(void);

    void bar(void) const;
};

#endif // SAMPLE_CLASS_1_H