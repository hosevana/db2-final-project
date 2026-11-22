// created 2026-11-22
// last updated 2026-11-22 by hosevana
// definitions for class MongoDatabase, automatically sets up connection
#include "database.hpp"

#include <cstdlib>
#include <stdexcept>
#include <string>

namespace
{
    // make the uri string
    mongocxx::uri makeUri() {
    const char* username = std::getenv("MONGO_USER");
    const char* password = std::getenv("MONGO_PASS");

    if (username == nullptr || username[0] == '\0')
    {
        throw std::runtime_error("Username not set/not found");
    }
    if (password == nullptr || password[0] == '\0')
    {
        throw std::runtime_error("Password not set/notfound");
    }

    const std::string connection =
        "mongodb+srv://" +
        std::string(username) + ":" +
        std::string(password) +
        "@project-cluster.2a5curs.mongodb.net/";
    return mongocxx::uri(connection);
}
}

// setup mongo instance
MongoDatabase::MongoDatabase()
    : instance_{},
      uri_{makeUri()},
      client_{uri_},
      database_{client_[ "admin" ]} {}

mongocxx::database& MongoDatabase::getDatabase()
{
    return database_;
}