// src/app/user-list/user-list.component.ts
import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
import { UserService, User } from '../services/user.service';

@Component({
  selector: 'app-user-list',
  standalone: true,
  imports: [CommonModule],
  template: `
    <h2>User List</h2>
    <div *ngIf="loading">Loading…</div>
    <div *ngIf="error">{{ error }}</div>

    <ul *ngIf="!loading && !error">
      <li *ngFor="let u of users">
        {{ u.name }} ({{ u.email }})
        <button (click)="onUpdate(u)">Update</button>
        <button (click)="onDelete(u.id)">Delete</button>
      </li>
    </ul>
  `
})
export class UserListComponent implements OnInit {
  users: User[] = [];
  loading = false;
  error = '';

  constructor(private userService: UserService) {}

  ngOnInit() {
    this.fetchUsers();
  }

  fetchUsers() {
    this.loading = true;
    this.userService.getUsers().subscribe({
      next: data => { 
        this.users = data; 
        this.loading = false; 
      },
      error: () => { 
        this.error = 'Failed to load users'; 
        this.loading = false; 
      }
    });
  }

  onUpdate(user: User) {
    const updated = { ...user, name: user.name + ' ✔' };
    this.userService.updateUser(updated).subscribe(resp => {
      this.users = this.users.map(u => u.id === resp.id ? resp : u);
    });
  }

  onDelete(id: string) {
    this.userService.deleteUser(id).subscribe(ok => {
      if (ok) this.users = this.users.filter(u => u.id !== id);
    });
  }
}
