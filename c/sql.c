#include <stdio.h>
#include <unistd.h>
#include <mysql/mysql.h>

void error(MYSQL* con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main(int argc, char* argv[]) {
    MYSQL* con = NULL;

    char const server[] = "localhost";
    char const user[] = "sunnyraj";
    char const *password;
    char const database[] = "new";

    con = mysql_init(NULL);

    if(con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    password = get_tty_password("Enter Password: ");
    
    
    if(!mysql_real_connect(con, server, user, password,
                            database, 0, NULL, 0)) {
            error(con);
    }

    mysql_query(con, "SELECT * FROM Student WHERE Name LIKE '%Kumar'");

    MYSQL_RES* result = mysql_store_result(con);

    if(result == NULL)
        error(con);

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while(row = mysql_fetch_row(result)) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return 0;
}