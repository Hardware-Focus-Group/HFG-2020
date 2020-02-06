//int count;
//
//int main() {
//  DDRB |= 1 << PB5;
//  TCCR1B |= (1 << CS11) | (1 << CS10);
//  TIMSK1 |= 1 << TOIE1;
//  sei();
//  while (1);
//  return 0;
//}
//
//ISR(TIMER1_OVF_vect) {
//  count ++;
//  if (count >= 2) {
//    PORTB ^= (1 << PB5);
//    count = 0;
//  }
//  
//}

int main() {
  DDRB |= 1 << PB7;
  while (1){
    PORTB ^= (1<<PORTB7);
    _delay_ms(500);
    }
  return 0;
}
