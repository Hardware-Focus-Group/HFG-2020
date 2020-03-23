import math
import time
import pandas as pd
import numpy as np

#Data is in the respective manner :-light,temp,humidity

x=pd.DataFrame(data=[[0.532,0.08,0.45],       
                     [0.667,0.11,0.56],       
                     [0.701,0.33,0.32],      
                     [0.621,0.32,0.66],
                     [0.599,0.30,0.55],
                     [0.832,0.35,0.76],
                     [0.893,0.62,0.28],
                     [0.749,0.95,0.86],
                     [0.911,0.91,0.39],
                     [0.455,0.31,0.19]])
    
"""
These are the desired o/p we expect our model to learn
0->cloudy
1->rainy
2->sunny
3->windy

"""

y=pd.DataFrame(data=[[1],
                     [3],
                     [2],
                     [0],
                     [1],
                     [2],
                     [0],
                     [1],
                     [3],
                     [0]])

#Use model_selection.train_test_split from sklearn to split the data into training and testing sets. 

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=101)

#Training the model

from sklearn.linear_model import LinearRegression     #** Import LinearRegression from sklearn.linear_model **
lm = LinearRegression()                               #Create an instance of a LinearRegression() model named lm.
lm.fit(X_train,y_train)                               #** Train/fit lm on the training data.**

#To predict the o/p for new data
#Here it is used to predict the test dataset
predictions = lm.predict(X_test)

# calculate these metrics by hand!
from sklearn import metrics

print('MAE:', metrics.mean_absolute_error(y_test, predictions))
print('MSE:', metrics.mean_squared_error(y_test, predictions))
print('RMSE:', np.sqrt(metrics.mean_squared_error(y_test, predictions)))

#--------------------------------------------------------------------------------------

from pyfirmata import Arduino, util
import time

#Board configuration 
#board = Arduino('/dev/cu.usbmodem######') #Serial port connected on MAC
board = Arduino('COM#') #COM port connected on Windows

it = util.Iterator(board)
it.start()

analog0 = board.get_pin('a:0:i') #T from arduino
analog1 = board.get_pin('a:1:i') #H from arduino
analog2 = board.get_pin('a:2:i') #L from arduino


#Fucntion to predict the weather based on slave(arduino) output
def predict_weather():
    weather = {0:'Cloudy',
                1:'Rainy',
                2:'Sunny',
                3:'Windy'}
    
    time.sleep(1)  #Arduino.pass_time(t)
    t = analog0.read()
    h = analog1.read()
    l = analog2.read()
    
    print("Current T:{0}, H:{1}, L:{2}".format(t,h,l))
    prediction = lm.predict([[l,t,h]])
    print("Predicted weather {0}".format(weather[math.ceil(prediction[0][0])]))


while(1):
    predict_weather()
    time.sleep(10) #predict weather every 10sec
