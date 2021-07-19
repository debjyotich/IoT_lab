import urequests
import utime

ssid = 'guest'
password = 'guest123'

def do_connect():
    import network
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect(ssid, password)
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())


def main():
    do_connect()
    url = "http://consentiuminc.online:80/update?send_key=PHKKXV5B3UIX-SRFPZCPIQ&sensor1=23.2&info1='test'"
    for i in range(0, 4):
        response = urequests.get(url)
        utime.sleep(1) # 1s delay
        print("Data sent at {}".format(i))
    response.close()

if __name__ == '__main__':
    main()