// src/app/services/user.service.ts
import { Injectable } from '@angular/core';
import { Apollo, gql } from 'apollo-angular';
import { map, Observable } from 'rxjs';
import { InMemoryCache } from '@apollo/client/core';

export interface User {
  id: string;
  name: string;
  email: string;
}

@Injectable({ providedIn: 'root' })
export class UserService {
  constructor(private apollo: Apollo) {}

  getUsers(): Observable<User[]> {
    return this.apollo
      .query<{ users: { data: User[] } }>({
        query: gql`
          query GetUsers {
            users(options: { paginate: { page: 1, limit: 10 } }) {
              data { id name email }
            }
          }
        `
      })
      .pipe(
        map(res => res.data!.users.data) // assert data is non-null
      );
  }

  updateUser(user: User): Observable<User> {
    return this.apollo
      .mutate<{ updateUser: User }>({
        mutation: gql`
          mutation UpdateUser($id: ID!, $name: String!, $email: String!) {
            updateUser(id: $id, input: { name: $name, email: $email }) {
              id name email
            }
          }
        `,
        variables: {
          id: user.id,
          name: user.name,
          email: user.email
        }
      })
      .pipe(
        map(res => res.data!.updateUser) // assert data is non-null
      );
  }

  deleteUser(id: string): Observable<boolean> {
    return this.apollo
      .mutate<{ deleteUser: boolean }>({
        mutation: gql`
          mutation DeleteUser($id: ID!) {
            deleteUser(id: $id)
          }
        `,
        variables: { id }
      })
      .pipe(
        map(res => res.data!.deleteUser)
      );
  }
}
