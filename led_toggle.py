from machine import Pin, Timer

led = Pin(25, Pin.OUT)
timer = Timer()

def blink(timer):
    led.toggle()
    print('here!')

timer.init(freq=2.0, mode=Timer.PERIODIC, callback=blink)