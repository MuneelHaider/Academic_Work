import { bootstrapApplication } from '@angular/platform-browser';
import { provideHttpClient } from '@angular/common/http';

import { provideApollo } from 'apollo-angular';
import { HttpLink } from 'apollo-angular/http';
import { InMemoryCache } from '@apollo/client/core';
import { inject } from '@angular/core';

import { AppComponent } from './app/app.component';

bootstrapApplication(AppComponent, {
  providers: [
    provideHttpClient(),                          // HttpClient under the hood
    provideApollo(() => {                         // Apollo client setup
      const httpLink = inject(HttpLink);          // ← inject the HttpLink service
      return {
        cache: new InMemoryCache(),
        link: httpLink.create({
          uri: 'https://graphqlzero.almansi.me/api'
        })
      };
    })                                            // :contentReference[oaicite:0]{index=0}
  ]
}).catch(err => console.error(err));
