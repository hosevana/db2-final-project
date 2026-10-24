// Created 2026-10-11 by hosevana
// Test code to setup the git and codespaces
// Last edited 2026-10-24 by hosevana
// CODE IS WORKING AS OF 2026-10-24

using MongoDB.Driver;
using MongoDB.Bson;

var username = Environment.GetEnvironmentVariable("SECRET_USERNAME");
var password = Environment.GetEnvironmentVariable("SECRET_MONGO_PASS");

string connectionUri = $"mongodb+srv://{username}:{password}@project-cluster.2a5curs.mongodb.net/";

var settings = MongoClientSettings.FromConnectionString(connectionUri);

// Create a new client and connect to the server
var client = new MongoClient(settings);

// Send a ping to confirm a successful connection
try {
    var result = client.GetDatabase("admin").RunCommand<BsonDocument>(new BsonDocument("ping", 1));
    Console.WriteLine("Pinged your deployment. You successfully connected to MongoDB!");
} catch (Exception ex) {
    Console.WriteLine(ex);
}