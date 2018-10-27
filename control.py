# Code for the Knight Rider Lunchbox Robot
# Made by: WvdK
# Visit http://www.instructables.com/member/Weseley/ for contact or more instructables.

import tkinter
import serial

#Sending all keypresses to serial
def key(event):
    print("Sending", repr(event.char))
    ser.write(event.char.encode('ascii'))

#Forward
def w_press():
    print("Sending 'w'")
    ser.write('w'.encode('ascii'))

#Backward
def s_press():
    print("Sending 's'")
    ser.write('s'.encode('ascii'))

#Left
def a_press():
    print("Sending 'a'")
    ser.write('a'.encode('ascii'))

#Right
def d_press():
    print("Sending 'd'")
    ser.write('d'.encode('ascii'))

def z_press():
    print("'Signal light left'")
    ser.write('z'.encode('ascii'))

def x_press():
    print("'Signal light right'")
    ser.write('x'.encode('ascii'))

def k_press():
    print("'Knight Rider mode initiated'")
    ser.write('k'.encode('ascii'))

def l_press():
    print("'Lights on'")
    ser.write('l'.encode('ascii'))

def o_press():
    print("'Lights off'")
    ser.write('o'.encode('ascii'))

def p_press():
    print("'Signal'")
    ser.write('p'.encode('ascii'))

def c_press():
    print("'Hazard lights'")
    ser.write('c'.encode('ascii'))

# Open first serial port
ser = serial.Serial('/dev/ttyUSB0', 9600)

# Create a Tk GUI window
root = tkinter.Tk()
root.title("Knight Rider Lunchbox Control")

# Bind all keypresses to the "key" function (define above)
root.bind("<Key>", key)

# Buttons and functions
w = tkinter.Button(root, text='Forward', command=w_press)
s = tkinter.Button(root, text='Backward', command=s_press)
a = tkinter.Button(root, text='Left', command=a_press)
d = tkinter.Button(root, text='Right', command=d_press)
z = tkinter.Button(root, text='Signal left', command=z_press)
x = tkinter.Button(root, text='Signal right', command=x_press)
k = tkinter.Button(root, text='Knight Rider', command=k_press, activeforeground="red")
l = tkinter.Button(root, text='Lights on', command=l_press)
o = tkinter.Button(root, text='Lights off', command=o_press)
p = tkinter.Button(root, text='Signal', command=p_press)
c = tkinter.Button(root, text='Hazard lights', command=c_press)

# Lay out of the buttons in the GUI
w.grid(row=0, column=1, sticky='EW')
s.grid(row=2, column=1, sticky='EW')
a.grid(row=2, column=0, sticky='EW')
d.grid(row=2, column=2, sticky='EW')
z.grid(row=4, column=0, sticky='EW')
x.grid(row=4, column=2, sticky='EW')
k.grid(row=0, column=4, sticky='EW')
l.grid(row=6, column=3, sticky='EW')
o.grid(row=6, column=4, sticky='EW')
p.grid(row=7, column=3, sticky='EW')
c.grid(row=7, column=4, sticky='EW')
root.columnconfigure(0, weight=1)


# Enter the Tkinter main event loop.
root.mainloop()

# Close serial port
ser.close()
