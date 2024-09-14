import tkinter as tk

def hello():
    print("Hello, Tkinter!")

root = tk.Tk()
root.title("Test Tkinter")

label = tk.Label(root, text="Hello, Tkinter!")
label.pack(pady=20)

button = tk.Button(root, text="Click Me", command=hello)
button.pack(pady=20)

root.mainloop()
