export default async function CustomerListPage() {
  const res = await fetch("https://dummyjson.com/users", {
    cache: "no-store", 
  });
  const data = await res.json();

  return (
    <div>
      <h1>Customer List - Muneel Haider</h1>
      <ul>
        {data.users.map((user) => (
          <li key={user.id}>
            <a href={`/dashboard/customer/${user.id}`}>
              {user.firstName} {user.lastName}
            </a>
          </li>
        ))}
      </ul>
    </div>
  );
}
