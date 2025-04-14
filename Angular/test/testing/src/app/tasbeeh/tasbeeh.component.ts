import { Component } from '@angular/core';

@Component({
  selector: 'app-tasbeeh',
  templateUrl: './tasbeeh.component.html',
  styleUrls: ['./tasbeeh.component.css']
})
export class TasbeehComponent {
  count: number = 0;

  increment() {
    this.count++;
  }

  decrement() {
    if (this.count > 0) this.count--;
  }

  reset() {
    this.count = 0;
  }
}
