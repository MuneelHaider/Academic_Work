import { Injectable } from '@angular/core';
import { Blog } from './blog.model';

@Injectable({
  providedIn: 'root'
})
export class BlogService {
  private blogs: Blog[] = [
    {
      id: 1,
      title: 'Welcome to the Blog!',
      content: 'This is the first blog post.',
      author: 'Admin',
      date: new Date().toLocaleDateString()
    }
  ];

  getBlogs(): Blog[] {
    return this.blogs;
  }

  addBlog(blog: Blog) {
    blog.id = this.blogs.length + 1;
    blog.date = new Date().toLocaleDateString();
    this.blogs.push(blog);
  }
}