#include <libintech/utils.h>
#include <libintech/uart.hpp>
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>

int main() 
{
    //Initialisation série
    uart0::init();
    uart0::change_baudrate(9600);
    sei();
    
    // ------------------
    // Test des print
    // ------------------
    
    // Envoie une chaine
    char string[10] = "char*";
    uart0::print(string);
        
    _delay_ms(500);

    // Envoie un char (code ASCII 97)
    unsigned char uint8 = 'a';
    uart0::send_char(uint8);
    uart0::send_ln();
        
    _delay_ms(500);
    
    // Envoie un uint8_t
    uart0::print(uint8);
    
    _delay_ms(500);
    
    // Envoie un int 8 bit négatif
    int8_t int8 = -8;
    uart0::print(int8);
        
    _delay_ms(500);
    
    // Envoie un int 16 bits
    uint16_t uint16 = 1616;
    uart0::print(uint16);
    
    _delay_ms(500);
    
    // Envoie un int 16 bits négatif
    int16_t int16 = -1616;
    uart0::print(int16);
    
    _delay_ms(500);
    
    // Envoie un int 32 bits
    uint32_t uint32 = 32323232;
    uart0::print(uint32);
    
    _delay_ms(500);
    
    // Envoie un int 32 bits négatif
    int32_t int32 = -32323232;
    uart0::print(int32);
    
    _delay_ms(500);
        
    // Envoie un booléen
    bool test = true;
    uart0::print(test);
        
    _delay_ms(500);

    // Envoie un entier en binaire
    uint8_t binary = 0;
    uart0::print_binary(binary);
    
    _delay_ms(500);
    
    // Envoie un entier en binaire
    binary = 255;
    uart0::print_binary(binary);
        
    _delay_ms(500);
    uart0::print("-----------");
    _delay_ms(500);
    
    // ------------------
    // Test des read
    // ------------------
    
    while(1)
    {
        // Réception d'une chaine
        uart0::print("string:");
        char buffer[10];
        if (uart0::read(buffer, 3000) == uart0::READ_TIMEOUT) uart0::print("timeout");
        else uart0::print(buffer);
        
        // Réception d'un float
        uart0::print("float (renvoie x1000):");
        float float_val;
        uart0::read(float_val);
        uart0::print(float_val * 1000);
        
        // Réception d'un int8
        uart0::print("int 8 bits:");
        int8_t int8_val;
        if (uart0::read(int8_val, 3000) == uart0::READ_TIMEOUT) uart0::print("timeout");
        else uart0::print(int8_val);
        
        // Réception d'un int16
        uart0::print("int 16 bits:");
        int16_t int16_val;
        uart0::read(int16_val);
        uart0::print(int16_val);
        
        // Réception d'un int32
        uart0::print("int 32 bits:");
        int32_t int32_val;
        uart0::read(int32_val);
        uart0::print(int32_val);
        
        // Réception d'un octet brut
        uart0::print("octet:");
        unsigned char octet;
        uart0::read_char(octet);
        uart0::send_char(octet);
        uart0::send_ln();
    }
    
    return 0;
}
