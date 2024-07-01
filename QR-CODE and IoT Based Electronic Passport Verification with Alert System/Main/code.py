import digitalio
import board
import busio
from lcd.lcd import LCD
from lcd.i2c_pcf8574_interface import I2CPCF8574Interface
from time import sleep

i2c = busio.I2C(board.GP1, board.GP0)
# Talk to the LCD at I2C address 0x27.

lcd = LCD(I2CPCF8574Interface(i2c, 0x27), num_rows=2, num_cols=16)

lcd.set_cursor_pos(0,3)
lcd.print("Passport")
lcd.set_cursor_pos(1,1)
lcd.print("Authentication")
sleep(2)

redled = digitalio.DigitalInOut(board.GP10)
redled.direction = digitalio.Direction.OUTPUT
greenled = digitalio.DigitalInOut(board.GP11)
greenled.direction = digitalio.Direction.OUTPUT
buzzer = digitalio.DigitalInOut(board.GP12)
buzzer.direction = digitalio.Direction.OUTPUT

count = 0

def get_data(txt):
    if(txt == "auth"):
        print("Authorized")
        redled.value = False
        greenled.value = True
        buzzer.value = False
        lcd.clear()
        lcd.set_cursor_pos(0,3)
        lcd.print("Authorized")
        sleep(5)
    elif(txt == "unauth"):
        print("Unauthorized")
        redled.value = True
        greenled.value = False
        buzzer.value = True
        lcd.clear()
        lcd.set_cursor_pos(0,3)
        lcd.print("UnAuthorized")
        sleep(1)
    else:
        print("Waiting input")
        redled.value = False
        greenled.value = False
        buzzer.value = False
        lcd.clear()
        lcd.set_cursor_pos(0,5)
        lcd.print("Scan Qr")
        lcd.set_cursor_pos(1,3)
        lcd.print("To get Data")

uart = busio.UART(board.GP4, board.GP5, baudrate=115200)

while True:
    data = uart.read(1)
    print(str(data))
    if data == b'1':
        print("1 user")
        get_data("auth")
    elif data == b'2':
        print("2 user")
        get_data("auth")
    elif data == b'3':
        print("3 user")
        get_data("auth")
    elif data == b'4':
        print("4 user")
        get_data("auth")
    elif data == b'5':
        print("5 user")
        get_data("unauth")
    elif data == b'6':
        print("6 user")
        get_data("unauth")
    else:
        get_data("ex")