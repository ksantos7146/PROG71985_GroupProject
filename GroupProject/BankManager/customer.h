#pragma once
#define MAXNAME 30

//group3  - karls, madisont, adilf - prog71985 - group project - customer object interface

#ifndef CUSTOMER_LIBRARY_H
#define CUSTOMER_LIBRARY_H

typedef struct customer {
    int customerID;
    char lastName[MAXNAME];
    char firstName[MAXNAME];
}CUSTOMER;







#endif //CUSTOMER_LIBRARY_H