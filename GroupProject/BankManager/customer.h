#pragma once
#define MAXNAME 50

//group3  - karls, madisont, adilf - prog71985 - group project - customer object interface

#ifndef CUSTOMER_LIBRARY_H
#define CUSTOMER_LIBRARY_H

typedef struct customer {
    char firstName[MAXNAME];
    char lastName[MAXNAME];
}CUSTOMER;

#endif //CUSTOMER_LIBRARY_H