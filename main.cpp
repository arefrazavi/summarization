#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
//#include <cppconn/prepared_statement.h>

//#define EXAMPLE_HOST "localhost"
//#define EXAMPLE_USER "root"
//#define EXAMPLE_PASS "Aref_4313347"
//#define EXAMPLE_DB "summarization_db"

#include "Models/Word.h"
#include "Helpers/DB.h"

int main() {
//    string url(argc >= 2 ? argv[1] : EXAMPLE_HOST);
//    const string user(argc >= 3 ? argv[2] : EXAMPLE_USER);
//    const string pass(argc >= 4 ? argv[3] : EXAMPLE_PASS);
//    const string database(argc >= 5 ? argv[4] : EXAMPLE_DB);

    cout << "Connector/C++ tutorial framework..." << endl;
    cout << endl;

    DB *db = DB::getInstance();
    //sql::Connection *connection = db->create_connection();

    sql::Statement *statement = db->connection->createStatement();
    string query_str = "SELECT id FROM test ORDER BY id ASC";
    sql::ResultSet *result;
    result = statement->executeQuery(query_str);
    /* Fetch in reverse = descending order! */
    result->afterLast();
    while (result->previous()) {
        cout << "\t row: " << result->getInt("id") << endl;
    }
    delete result;

    cout << "New query" << endl;
    DB *db2 = DB::getInstance();
    query_str = "SELECT id FROM test ORDER BY id DESC";
    result = statement->executeQuery(query_str);
    /* Fetch in reverse = descending order! */
    result->afterLast();
    while (result->previous()) {
        cout << "\t row: " << result->getInt("id") << endl;
    }
    delete result;

    return 1;

}


//    try {
//        sql::Driver *driver;
//        sql::Connection *con;
//        sql::Statement *stmt;
//        sql::ResultSet *res;
//        sql::PreparedStatement *pstmt;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
//        /* Connect to the MySQL test database */
//        con->setSchema(EXAMPLE_DB);
//
//        stmt = con->createStatement();
//        stmt->execute("DROP TABLE IF EXISTS test");
//        stmt->execute("CREATE TABLE test(id INT)");
//        delete stmt;
//
//        /* '?' is the supported placeholder syntax */
//        pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
//        for (int i = 1; i <= 10; i++) {
//            pstmt->setInt(1, i);
//            pstmt->executeUpdate();
//        }
//
//        delete pstmt;
//
//        /* Select in ascending order */
//        pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
//        res = pstmt->executeQuery();
//
//        /* Fetch in reverse = descending order! */
//        res->afterLast();
//        while (res->previous())
//            cout << "\t... MySQL counts: " << res->getInt("id") << endl;
//        delete res;
//
//        delete pstmt;
//        delete con;
//
//
//    } catch (sql::SQLException &e) {
//        cout << "# ERR: SQLException in " << __FILE__;
//        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
//        cout << "# ERR: " << e.what();
//        cout << " (MySQL error code: " << e.getErrorCode();
//        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//    }

