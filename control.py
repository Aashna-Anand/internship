import requests
import time

ESP_IP = "192.168.1.13"

print("Moving Servo to 180°")
response = requests.get(f"http://{ESP_IP}/on")
print(response.text)

time.sleep(5)

print("Moving Servo to 0°")
response = requests.get(f"http://{ESP_IP}/off")
print(response.text)

print("Completed")

# import requests
# import time

# # ESP32 IP Address
# ESP_IP = "192.168.1.13"

# print("Turning LED ON")

# response = requests.get(f"http://{ESP_IP}/on")
# print(response.text)

# time.sleep(5)

# print("Turning LED OFF")

# response = requests.get(f"http://{ESP_IP}/off")
# print(response.text)

# print("Completed")