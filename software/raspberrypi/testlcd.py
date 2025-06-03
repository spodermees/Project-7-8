from RPLCD.i2c import CharLCD
from time import sleep

# Adjust the address (use `i2cdetect -y 1` to find it)
lcd = CharLCD(i2c_expander='PCF8574', address=0x27, port=1,
              cols=16, rows=2, dotsize=8,
              charmap='A00', auto_linebreaks=True)

lcd.write_string("Hello, World!")
sleep(2)
lcd.clear()
lcd.write_string("Line 1\nLine 2")
