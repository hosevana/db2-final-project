// Created 2026-10-11 by hosevana
// Test code to set up connection to atlas
// Last edited: 2026-10-24 by hosevana
// NOT WORKING AS OF: 2026-10-24

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>


int main()
{
    const std::string username = std::getenv("SECRET_USERNAME");
    if (username.length()) {
        std::cout << "Secret Value: " << username << std::endl;
    } else {
        std::cout << "Secret not found." << std::endl;
    }
    const std::string password = std::getenv("SECRET_MONGO_PASS");
    if (password.length()) {
        std::cout << "Secret Value: " << password << std::endl;
    } else {
        std::cout << "Secret not found." << std::endl;
    }

    try
    {
        // Create an instance.
        mongocxx::instance inst{};

        // Replace the placeholder with the Atlas connection string
        const auto uri = mongocxx::uri{"mongodb+srv://" + username + ":" +
            password + "@project-cluster.2a5curs.mongodb.net/"};

        // Setup the connection and get a handle on the "admin" database.
        mongocxx::client conn{ uri };
        mongocxx::database db = conn["admin"];

        // Ping the database.
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    }
    catch (const std::exception& e)
    {
        // Handle errors
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}