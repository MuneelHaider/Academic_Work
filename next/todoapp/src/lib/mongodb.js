import { MongoClient } from 'mongodb';

const uri = 'mongodb+srv://bondusdanger:69BONDAL69@demotest.tms07.mongodb.net/';
const options = {};

let client;
let clientPromise;

if (!global._mongoClientPromise) {
  client = new MongoClient(uri, options);
  global._mongoClientPromise = client.connect();
}
clientPromise = global._mongoClientPromise;

export default clientPromise;
