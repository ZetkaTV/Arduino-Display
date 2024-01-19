import psutil
import serial
import time

ser = serial.Serial('COM6', 9600, timeout=1)

while True:
    # Get CPU and memory usage percentage
    cpu_percent = psutil.cpu_percent(interval=1)
    mem_percent = psutil.virtual_memory().percent

    # Print CPU and memory usage for debugging
    print("CPU Usage:", cpu_percent, "%")
    print("Memory Usage:", mem_percent, "%")

    # Send CPU and memory usage to Arduino
    data_to_send = f"{int(cpu_percent)} {int(mem_percent)}\n"
    ser.write(data_to_send.encode())

    time.sleep(1)
