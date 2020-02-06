unsigned int adc_v;

int main() {
  Serial.begin(115200);
  DDRC &= 0x00;
  PORTC |= 0x11;

  ADMUX |= 1 << REFS0; //avcc
  ADMUX |= (1 << MUX0) | (1 << MUX2);
  ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
  ADCSRA |= 1 << ADEN; //adc enable
  ADCSRA |= 1 << ADIE;
  ADCSRA |= 1 << ADSC; //call adc

  sei();
  while (1);
  return 0;
}

ISR(ADC_vect) {
  adc_v = ADC;
  Serial.println(adc_v);
  _delay_ms(100);
  ADCSRA |= 1 << ADSC;

}
