from machine import Pin
from machine import Timer
import time



a = Pin(23, Pin.OUT)
b = Pin(22, Pin.OUT)
c = Pin(21, Pin.OUT)
d = Pin(19, Pin.OUT)
e = Pin(18, Pin.OUT)
f = Pin(5, Pin.OUT)
g = Pin(4, Pin.OUT)
pinArr = [a,b,c,d,e,f,g]

def all_off():
    for i in range(7):
        pinArr[i].off()
    

def all_on():
    for i in range(7):
        pinArr[i].on()
    
def num0():
    all_on()
    g.off()

def num1():
    all_off()
    b.on()
    c.on()
    
def num2():
    all_on()
    c.off()
    f.off()
    
def num3():
    all_on()
    f.off()
    e.off()

def num4():
    all_on()
    a.off()
    d.off()
    e.off()

def num5():
    all_on()
    e.off()
    b.off()

def num6():
    all_on()
    b.off()

def num7():
    all_on()
    d.off()
    e.off()
    f.off()
    
def num8():
    all_on()

def num9():
    all_on()
    d.off()
    e.off()
    
numsArr = [num0,num1,num2,num3,num4,num5,num6,num7,num8,num9]