const express = require("express");
const cors = require("cors");
const jwt = require("jsonwebtoken");
const dotenv = require("dotenv");
const cookieParser = require("cookie-parser");
const { users } = require("./users");

dotenv.config();

const app = express();
const PORT = "5000";
const JWT_SECRET = "kjsbfkjdsbfkjdsbkjdfsbd";

app.use(cors({
  origin: "http://localhost:3000",
  credentials: true
}));
app.use(express.json());
app.use(cookieParser());

app.post("/login", (req, res) => {
  const { username, password } = req.body;
  const user = users.find(
    u => u.username === username && u.password === password
  );

  if (!user) {
    return res.status(401).json({ message: "Invalid credentials" });
  }

  const token = jwt.sign({ id: user.id, username: user.username }, JWT_SECRET, {
    expiresIn: "1h"
  });

  res.cookie("token", token);

  res.json({ message: "Login successful" });
});

app.listen(PORT, () => console.log(`Backend on ${PORT}`));
