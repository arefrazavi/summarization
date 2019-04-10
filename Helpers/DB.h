//
// Created by Aref Razavi on 2019-04-10.
//
#ifndef SUMMARIZATION_DB_H
#define SUMMARIZATION_DB_H

#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class DB {
public:
    sql::Connection* connection; //Connection to db
    static DB* getInstance(); //This is how clients can access the single instance

private:
    static DB* instance; //The one, single instance
    DB(); //Private constructor
};


#endif //SUMMARIZATION_DB_H
