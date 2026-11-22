// Created (remade) 2026-10-25 by hosevana
// last edited 2026-11-15 by hosevana
//  WORKING AS OF 2026-11-22
// only a test to connect to the database,
// does not contain real project data

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

int main() {

    const char* username = std::getenv("MONGO_USER");
    const char* password = std::getenv("MONGO_PASS");
    if (username == nullptr || username[0] == '\0') {
        std::cerr << "MONGO_USER is not set.\n";
        return 1;
    }
    if (password == nullptr || password[0] == '\0') {
        std::cerr << "MONGO_PASS is not set.\n";
        return 1;
    }
    const std::string db_username(username);
    const std::string db_password(password);
    try {
        mongocxx::instance instance{};
        const mongocxx::uri uri("mongodb+srv://" + db_username + ":" + 
            db_password + "@project-cluster.2a5curs.mongodb.net/");
        mongocxx::client client(uri);
        mongocxx::database db = client["admin"];

        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
