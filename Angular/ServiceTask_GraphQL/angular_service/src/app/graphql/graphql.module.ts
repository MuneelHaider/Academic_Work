// src/app/graphql/graphql.module.ts
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';
import { ApolloModule, APOLLO_OPTIONS } from 'apollo-angular';
import { InMemoryCache } from '@apollo/client/core';
import { HttpLink } from 'apollo-angular/http';

@NgModule({
  imports: [ApolloModule, HttpClientModule],
  providers: [{
    provide: APOLLO_OPTIONS,
    useFactory: (httpLink: HttpLink) => ({
      cache: new InMemoryCache(),
      link: httpLink.create({
        uri: 'https://graphqlzero.almansi.me/api'
      })
    }),
    deps: [HttpLink]
  }]
})
export class GraphQLModule {}
