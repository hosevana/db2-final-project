# Created 2026-10-11 by Hosevana 
# last edited: 2026-10-22
# add code for connecting to mongodb (UNTESTED)

import os
username = os.environ.get("SECRET_USERNAME")
password = os.environ.get("SECRET_MONGO_PASS")

import asyncio
from pymongo import AsyncMongoClient

async def main():
    uri = f"mongodb+srv://{username}:{password}@project-cluster.2a5curs.mongodb.net/"
    client = AsyncMongoClient(uri)

    await client.admin.command("ping")
    print("Connected successfully")
    await client.close()

asyncio.run(main())