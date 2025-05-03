export default async function CustomerDetailPage({ params }) {
  const res = await fetch(`https://dummyjson.com/users/${params.id}`, {
    cache: "no-store",
  });
  const user = await res.json();

  return (
    <div>
      <h1>Customer Detail - Muneel Haider</h1>
      <p><strong>Name:</strong> {user.firstName} {user.lastName}</p>
      <p><strong>Email:</strong> {user.email}</p>
      <p><strong>Phone:</strong> {user.phone}</p>
      <p><strong>Age:</strong> {user.age}</p>
      <p><strong>Address:</strong> {user.address?.address}</p>
    </div>
  );
}
