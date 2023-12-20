import psutil
import serial
import time

ser = serial.Serial('COM3', 9600)  # Replace 'COM3' with your port

while True:
    cpu_usage = psutil.cpu_percent()
    ram_info = psutil.virtual_memory()

    # Sending information to Arduino
    ser.write(f"{cpu_usage},{ram_info.used / (1024 * 1024)}\n".encode())

    time.sleep(2)