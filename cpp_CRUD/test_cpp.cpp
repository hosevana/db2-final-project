// Created (remade) 2026-10-25 by hosevana
// last edited 2026-11-15 by hosevana
// WORKING AS OF 2026-11-15

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

    const std::string db_username = std::getenv("MONGO_USER");
    if (db_username.length() <= 0) {
        std::cout << "Username not found.\n ";
    }
    const std::string db_password = std::getenv("MONGO_PASS");
    if (db_password.length() <= 0) {
        std::cout << "Password not found.\n";
    }
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
