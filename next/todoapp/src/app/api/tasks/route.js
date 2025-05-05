import clientPromise from '@/lib/mongodb';

export async function GET() {
  const client = await clientPromise;
  const db = client.db('test');
  const tasks = await db.collection('tasks').find({}).toArray();
  return Response.json(tasks);
}

export async function POST(req) {
  const client = await clientPromise;
  const db = client.db('test');
  const body = await req.json();
  const { text } = body;

  if (!text) return new Response("Task can't be empty", { status: 400 });

  await db.collection('tasks').insertOne({ text });
  return new Response("Task added", { status: 201 });
}
