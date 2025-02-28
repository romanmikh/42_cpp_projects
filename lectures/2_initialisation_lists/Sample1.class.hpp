/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_1_H
# define SAMPLE_CLASS_1_H

class Sample1 {

public:

    char    a1;
    int     a2;
    float   a3;

    Sample1(char p1, int p2, float p3);  // constructor
    ~Sample1(void); // destructor
};

#endif // SAMPLE_CLASS_1_H