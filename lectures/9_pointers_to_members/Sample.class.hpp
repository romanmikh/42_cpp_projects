/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

struct Sample {

public: 

    int    foo;

    Sample(void);
    ~Sample(void);
    
    void   bar(void) const;

};

#endif  // SAMPLE_CLASS_H