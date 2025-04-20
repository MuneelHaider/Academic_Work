import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { CommonModule } from '@angular/common';
import { BlogService } from '../blog.service';
import { Blog } from '../blog.model';

@Component({
  selector: 'app-blog-form',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './blog-form.component.html'
})
export class BlogFormComponent {
  newBlog: Blog = {
    id: 0,
    title: '',
    content: '',
    author: '',
    date: ''
  };

  constructor(private blogService: BlogService) {}

  addBlog() {
    this.blogService.addBlog({ ...this.newBlog });
    this.newBlog = {
      id: 0,
      title: '',
      content: '',
      author: '',
      date: ''
    };
  }
}
