class Parent(): #Parent class
    def __init__(self,first_name,last_name): #initializing variables
        self.first_name = first_name
        self.last_name = last_name
         
    def printname(self): #method
        print(self.first_name + " " + self.last_name)

class Child(Parent): #Child class
    def __init__(self,first_name,last_name,year): #adding another property
        self.graduationyear = year

    def welcome(self):
        print("Welcome " + self.first_name + " " + self.last_name + " to the class " + str(self.graduationyear))


x = lambda a,b,c: a+b*c
print(x(2,4,3))
