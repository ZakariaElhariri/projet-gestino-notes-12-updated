#include <iostream>
#include <string>
#include "Personne.h"
using namespace std;
int main()
{
    Personne Mohamed_zwin;
    Mohamed_zwin.test();
    Mohamed_zwin.set_nom("mohamed new :)");
    cout << Mohamed_zwin.get_nom()<<endl;
    return 0;
}

/*
 #pragma once

class MyClass {
public:
    // Constructor
    MyClass(int value);

    // Destructor
    ~MyClass();

    // Member function declarations
    void setValue(int value);
    int getValue() const;

private:
    int m_value;
};
#include "MyClass.h"

// Constructor definition
MyClass::MyClass(int value) : m_value(value) {}

// Destructor definition
MyClass::~MyClass() {}

// Member function definitions
void MyClass::setValue(int value) {
    m_value = value;
}

int MyClass::getValue() const {
    return m_value;
}


------------------------------------------------------
#pragma once

class MyClass {
public:
    // Constructor
    MyClass(int value) : m_value(value) {}

    // Destructor
    ~MyClass() {}

    // Member function definitions
    void setValue(int value) {
        m_value = value;
    }

    int getValue() const {
        return m_value;
    }

private:
    int m_value;
};




*/