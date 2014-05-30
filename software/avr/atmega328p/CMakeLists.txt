include(atmega328p.cmake)
set(MICROCONTROLEURS compteur asservissement codeuse formation-ex1 formation-ex2 formation-ex3 formation-ex4 print_serial test_capteur_couleurs lanceur robot_2)
add_microcontrolers(m328p "${MICROCONTROLEURS}")
