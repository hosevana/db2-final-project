// created 2026-11-22
// last updated 2026-11-22 by hosevana
// header for class MongoDatabase, makes crud easier

#pragma once

#include <mongocxx/client.hpp>
#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

class MongoDatabase
{
public:
    MongoDatabase();
    mongocxx::database& getDatabase();

private:
    mongocxx::instance instance_;
    mongocxx::uri uri_;
    mongocxx::client client_;
    mongocxx::database database_;
};