export default function InvoiceDetailPage({ params }) {
    const { id } = params;
  
    return (
      <div>
        <h1>Invoice Details</h1>
        <p>Invoice ID: {id}</p>
      </div>
    );
  }
  