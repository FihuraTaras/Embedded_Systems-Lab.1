/*#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5 // buildin led

int main(void)
{
    DDRB |= 1 << LED_PIN; 

    while (1) 
    {
        PORTB |= 1 << LED_PIN;    // включити світлодіод
        _delay_ms(100);           // затримка
        PORTB &= ~(1 << LED_PIN); // виключити світлодіод
        _delay_ms(400);     
    }

  return 0;
}
*/

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5  // вбудований в Arduino nano світлодіод

// Функція для короткого блимання
void short_blink() {
    PORTB |= (1 << LED_PIN);  // включити світлодіод
    _delay_ms(100);           // короткий імпульс
    PORTB &= ~(1 << LED_PIN); // виключити світлодіод
    _delay_ms(100);           // пауза між імпульсами
}

// Функція для довгого блимання
void long_blink() {
    PORTB |= (1 << LED_PIN);  // включити світлодіод
    _delay_ms(350);           // довгий імпульс
    PORTB &= ~(1 << LED_PIN); // виключити світлодіод
    _delay_ms(150);           // пауза між імпульсами
}

int main(void) {
    DDRB |= (1 << LED_PIN);  // Налаштувати PB5 як вихід
    
    while (1) {
        // SOS сигнал: три коротких, три довгих, три коротких
        for (int i = 0; i < 3; i++) short_blink();  // Три короткі
        for (int i = 0; i < 3; i++) long_blink();   // Три довгі
        for (int i = 0; i < 3; i++) short_blink();  // Три короткі
        
        // Затримка між сигналами SOS
        _delay_ms(1000); // 1 секунда
    }
}