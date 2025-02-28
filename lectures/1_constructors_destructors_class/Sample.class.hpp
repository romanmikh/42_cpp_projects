/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

    int foo; // attribute

    Sample(void);  // constructor
    ~Sample(void); // destructor

    void bar(void); // impossible to add functions to structures in C, C++ allows it
};

#endif // SAMPLE_CLASS_H