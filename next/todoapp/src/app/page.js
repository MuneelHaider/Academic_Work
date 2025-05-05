'use client';
import { useEffect, useState } from 'react';

export default function Home() {
  const [tasks, setTasks] = useState([]);
  const [text, setText] = useState('');

  useEffect(() => {
    fetchTasks();
  }, []);

  const fetchTasks = async () => {
    const res = await fetch('/api/tasks');
    const data = await res.json();
    setTasks(data);
  };

  const addTask = async () => {
    if (!text.trim()) return;
    await fetch('/api/tasks', {
      method: 'POST',
      body: JSON.stringify({ text }),
    });
    setText('');
    fetchTasks();
  };

  const deleteTask = async (id) => {
    await fetch(`/api/tasks/${id}`, { method: 'DELETE' });
    setTasks(tasks.filter(task => task._id !== id));
  };

  return (
    <div className="todo-container">
      <h1 className="todo-title">📝 My ToDo App</h1>

      <div className="todo-form">
        <input
          className="todo-input"
          value={text}
          onChange={(e) => setText(e.target.value)}
          placeholder="Enter a new task"
        />
        <button className="todo-add-button" onClick={addTask}>Add Task</button>
      </div>

      <ul className="todo-list">
        {tasks.map(task => (
          <li className="todo-item" key={task._id}>
            <span>{task.text}</span>
            <button className="todo-delete-button" onClick={() => deleteTask(task._id)}>✖</button>
          </li>
        ))}
      </ul>
    </div>
  );
}
