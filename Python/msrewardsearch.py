from random_word import RandomWords
import time
import pyautogui
import sys
r = RandomWords()
time.sleep(5)
i = 0
numofsearches = int(sys.argv[1])
while i < numofsearches: 
    word = r.get_random_word()
    pyautogui.typewrite(word)
    pyautogui.press("Enter")
    time.sleep(2)
    print(word)
    print(i)
    i += 1
    pyautogui.hotkey("alt","d")

