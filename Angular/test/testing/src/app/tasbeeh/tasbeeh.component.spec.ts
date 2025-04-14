import { ComponentFixture, TestBed } from '@angular/core/testing';

import { TasbeehComponent } from './tasbeeh.component';

describe('TasbeehComponent', () => {
  let component: TasbeehComponent;
  let fixture: ComponentFixture<TasbeehComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [TasbeehComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(TasbeehComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
