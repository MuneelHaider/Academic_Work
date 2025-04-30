"use client";

import useSWR from "swr";
import Link from "next/link";

const fetcher = (...args) => fetch(...args).then((res) => res.json());

export default function CustomerListPage() {
  const { data, error, isLoading } = useSWR("https://dummyjson.com/users", fetcher);

  if (isLoading) return <p>Loading...</p>;
  if (error) return <p>Failed to load users.</p>;

  const users = data.users;

  return (
    <div>
      <h1>Customer List</h1>
      <ul>
        {users.map((user) => (
          <li key={user.id}>
            <Link href={`/dashboard/customer/${user.id}`}>
              {user.firstName} {user.lastName}
            </Link>
          </li>
        ))}
      </ul>
    </div>
  );
}
