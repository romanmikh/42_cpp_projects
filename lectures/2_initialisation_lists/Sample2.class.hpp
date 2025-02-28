/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_2_H
# define SAMPLE_CLASS_2_H

class Sample2 {

public:

    char    a1;
    int     a2;
    float   a3;

    Sample2(char p1, int p2, float p3);  // constructor
    ~Sample2(void); // destructor
};

#endif // SAMPLE_CLASS_2_H