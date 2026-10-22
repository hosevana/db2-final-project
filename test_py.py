# Created 2026-10-11 by Hosevana 
# last edited: 2026-10-22
# add code for connecting to mongodb (UNTESTED)

from pymongo import MongoClient
username = Environment.GetEnvironmentVariable("SECRET_USERNAME")
password = Environment.GetEnvironmentVariable("SECRET_MONGO_PASS")
uri = f"mongodb+srv://{username}:{password}@project-cluster.2a5curs.mongodb.net/"
client = MongoClient(uri)
try:
    client.admin.command("ping")
    print("Connected successfully")
    client.close()

except Exception as e:
    raise Exception(
        "The following error occurred: ", e)
