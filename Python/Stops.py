from turtle import left, position
import geocoder
from geopy import distance
import tkinter as tk

from numpy import pad
from pyscreeze import center

#currentLocation = geocoder.ip('me').latlng
currentLocation = [12,12]
print(f"Current Location: {currentLocation}")

stopsList = {"Ganapathy Main Bus Stop":[11.0361,76.9781], "Gandhipuram Central Bus Stand":[11.020522, 76.966698], "Home":[11.031946711858872, 76.98018989978615]}

window = tk.Tk()
window.title("Distances")
window.geometry("600x250")

calc_button = tk.Button(window, text="Calculate Distances", font=("Montserrat, 20"))
calc_button.pack()

frame_left = tk.Frame(window)
frame_left.pack(side="left")

frame_right = tk.Frame(window)
frame_right.pack(side="right")

label = tk.Label(frame_left, text="Stop:", font=("Montserrat, 16"))
label.pack()

label = tk.Label(frame_right, text="Distance:", font=("Montserrat, 16"))
label.pack()

for stop in stopsList:
    label = tk.Label(frame_left, text=stop, font=("Montserrat, 14"), padx=10)
    label.pack()
    label = tk.Label(frame_right, text=distance.distance(currentLocation,stopsList.get(stop)), font=("Montserrat, 14"), padx=10)
    label.pack()

window.mainloop()