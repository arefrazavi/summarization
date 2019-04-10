//
// Created by Aref Razavi on 2019-04-10.
//

#include "DB.h"
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "string"

#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "Aref_4313347"
#define EXAMPLE_DB "summarization_db"

// Define the static Singleton pointer
DB *DB::instance = NULL;

/**
 * Access to one single instance of DB class (if it doesn't exist, create one instance)
 * @return
 */
DB *DB::getInstance() {
    if (instance == NULL) {
        instance = new DB();
    }
    return (instance);
}

/**
 * Define constructor of DB class which makes a connection to db
 */
DB::DB() {
    cout << "New Instance!\n";
    sql::Driver *driver;
    sql::Connection *sql_connection = nullptr;

    /* Create a connection */
    driver = get_driver_instance();
    try {
        sql_connection = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
        /* Connect to database */
        sql_connection->setSchema(EXAMPLE_DB);

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    connection = sql_connection;
}