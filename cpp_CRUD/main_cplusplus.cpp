// created 2026-11-22
// last updated 2026-11-22 by hosevana
// main function, all crud happens here!
#include "database.hpp"

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <iostream>

// function headers for crud operations
void create(mongocxx::database& db);
void read(mongocxx::database& db);
void update(mongocxx::database& db);
void del(mongocxx::database& db);

int main()
{
    try {
        MongoDatabase mongo;
        mongocxx::database& db = mongo.getDatabase();
        // code for a database that doesnt exist in our cluster
        /*mongocxx::cursor cursor =
            db["students"].find({});
        for (const auto& document : cursor)
        {
            std::cout << bsoncxx::to_json(document) << '\n';
        }*/
        // same code as the test file, pings deployment and nothing else
        const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
        db.run_command(ping_cmd.view());
        std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    } catch (const std::exception& error)
    {
        std::cerr << "MongoDB error: " << error.what() << '\n';
        return 1;
    }
}

// TODO: properly define functions
void create(mongocxx::database& db)
{
    return;
}
void read(mongocxx::database& db)
{
    return;
}
void update(mongocxx::database& db)
{
    return;
}
void del(mongocxx::database& db)
{
    return;
}