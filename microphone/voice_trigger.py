import speech_recognition as sr
from pyfirmata import Arduino
import serial

port = "COM8"

board = Arduino(port)
# ser = serial.Serial(port, 115200, timeout=0)
r = sr.Recognizer()


def highPin(pin):
    board.digital[pin].write(1)

def lowPin(pin):
    board.digital[pin].write(0)


while True:
    with sr.Microphone() as mic:
        try:
            print("Silence please, calibrating...")
            r.adjust_for_ambient_noise(mic, duration=2)
            print("calibrated, speak now...")
            audio = r.listen(mic)
            text = r.recognize_google(audio)
            text = text.lower()
            print("You said "+text+"\n")
            # ser.write(str.encode(text))
            if "red" in text:
                highPin(9)
                lowPin(7)
                lowPin(3)
            elif "green" in text:
                highPin(3)
                lowPin(9)
                lowPin(7)
            elif "blue" in text:
                highPin(7)
                lowPin(9)
                lowPin(3)
            else:
                lowPin(9)
                lowPin(7)
                lowPin(3)
            
        
            
        except sr.UnknownValueError:
            print("Could not understand audio")
            
        except sr.RequestError as e:
            print("Request error; {0}".format(e))

# import speech_recognition as sr
# from pyfirmata import Arduino

# from time import sleep

# r = sr.Recognizer()
# mic = sr.Microphone(device_index=1)

# port = "COM8"
# pin = 9
# board = Arduino(port)

# def highPin(pin):
#     board.digital[pin].write(1)

# def lowPin(pin):
#     board.digital[pin].write(0)

# with mic as source:
#     r.adjust_for_ambient_noise(source)
#     while True:
#         audio = r.listen(source)
#         try:
#             if r.recognize_google(audio) == "red":
#                 highPin(9)
#                 print("red")
#             if r.recognize_google(audio) == "blue":
#                 highPin(7)
#                 print("blue")
#             if r.recognize_google(audio) == "green":
#                 highPin(3)
#                 print("green")
#             else:
#                 print("something")
#                 lowPin(9)
#                 lowPin(7)
#                 lowPin(3)
#         except:
#             print("no audio")