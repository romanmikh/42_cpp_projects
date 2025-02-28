/*
- Like in C, header file for prototypes of class, its const/destructors and attributes
*/

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

struct Sample {

public: 

    Sample(void);
    ~Sample(void);
    
    static int getNbInst(void);  // non-member function

private:

    static int _nbInst;  // number of instances created

};

#endif  // SAMPLE_CLASS_H