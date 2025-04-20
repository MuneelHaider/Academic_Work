import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { FormsModule } from '@angular/forms';
import { BlogListComponent } from './blog-list/blog-list.component';
import { BlogFormComponent } from './blog-form/blog-form.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, BlogListComponent, BlogFormComponent, FormsModule],
  templateUrl: './app.component.html'
})
export class AppComponent {
  title = 'blog-app';
}
