from machine import Pin
import utime

led_pin = Pin(25, Pin.OUT) # Pin(GPIO No., status)

while True:
    led_pin.value(1) # pull high
    print("Led ON!")
    utime.sleep(2)   # 2 sec
    led_pin.value(0) # pull low
    print("Led OFF!")
    utime.sleep(2)   # 2 sec